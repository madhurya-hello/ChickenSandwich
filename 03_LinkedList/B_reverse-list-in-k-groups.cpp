// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    // function to reverse a linked list
    ListNode* reverse(ListNode* head, ListNode* tail) {
        // three pointer approach
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        // reversing
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        // returning head
        return prev;    
    };

    // function to reverse list in k groups
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        // locating the (k)th node
        struct ListNode* firstEnd = head;
        for(int i=0; i<k-1 && firstEnd!=NULL; i++){
            firstEnd=firstEnd->next;
        }
        
        if(firstEnd!=NULL){
            
            // spliting the list
            ListNode* secondStart = firstEnd->next;
            firstEnd->next=NULL;
            
            // reversing the first part
            ListNode* firstHead = reverse(head,firstEnd);
                        
            // recursive call for the second call
            ListNode* secondHead = reverseKGroup(secondStart, k);
            
            // joining the first and second part
            firstEnd = firstHead;
            while(firstEnd->next!=NULL){
                firstEnd=firstEnd->next;
            }
            firstEnd->next = secondHead;
            
            // returning 
            return firstHead;
        }
        
        else {
           
            return head;

            // // locating the last node
            // ListNode* trav = head;
            // while(trav->next!=NULL){
            //     trav=trav->next;
            // }
           
            // // simply reversing and returning
            // ListNode* firstHead = reverse(head,trav);
            // return firstHead;
        }
    } 
};