// https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // data structure
    struct Node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };

    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        
        Node* slow = head;
        Node* fast = head;
        
        if(head->next==NULL){
            return false;
        }
        else if(head->next->next==NULL){
            return false;
        }
        else{
            slow = head->next;
            fast = head->next->next;
        }
        
        
        while(true){
            
            // slow: one step ahead
            slow=slow->next;
            
            // fast: one step ahead
            if(fast->next!=NULL){
                fast=fast->next;
            }
            else{
                return false;
            }
            
            // check
            if(fast==slow){
                return true;
            }
            
            // fast: another step ahead
            if(fast->next!=NULL){
                fast=fast->next;
            }
            else{
                return false;
            }
            
            // check
            if(fast==slow){
                return true;
            }
        }
    }
};