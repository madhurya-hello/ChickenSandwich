//

#include <bits/stdc++.h>
using namespace std;

// 

class Solution {
  
  public:
    
    // data structure
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    };

    // function to reverse a linked list
    struct node* reverse(struct node* head) {
        
        // base case
        if(head->next==NULL){
            return head;
        }
        
        // reversing the head->next list
        struct node* newHead = reverse(head->next);
        
        // joining the head at the end of the reversed list
        struct node* trav = newHead;
        while(trav->next!=NULL){
            trav=trav->next;
        }
        trav->next=head;
        head->next=NULL;
        
        // returning 
        return newHead;
        
    };
    
    // function to reverse list in k groups
    struct node *reverseKGroup(struct node *head, int k) {
        
        // base case
        if(head->next==NULL){
            return head;
        }
        
        // locating the (k+1)th node
        struct node* temp = head;
        for(int i=0; i<k && temp!=NULL; i++){
            if(temp!=NULL){
                temp=temp->next;
            }
        }
        
        if(temp!=NULL){
            
            // spliting the list
            struct node* trav = head;
            while(trav->next!=temp){
                trav=trav->next;
            }
            trav->next=NULL;
            
            // reversing the first part
            struct node* firstHead = reverse(head);
            struct node* firstEnd = firstHead;
            while(firstEnd->next!=NULL){
                firstEnd=firstEnd->next;
            }
            
            // recursive call for the second call
            struct node* secondHead = reverseKGroup(temp, k);
            
            // joining the first and second part
            firstEnd->next = secondHead;
            
            // returning 
            return firstHead;
        }
        
        else {
            struct node* firstHead = reverse(head);
            return firstHead;
        }
    }
    
};

class Solution {
  public:

    // data structure
    struct node
    {
        int data;
        struct node* next;
        node(int x){
            data = x;
            next = NULL;
        }
    };

    // function to reverse a linked list
    struct node* reverse(struct node* head, struct node* tail) {
        
        node* prev = NULL;
        node* curr = head;
        node* next;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;    
    };
    
    // function to reverse list in k groups
    struct node *reverseKGroup(struct node *head, int k) {
        
        // base case
        if(head->next==NULL){
            return head;
        }
        
        // locating the (k)th node
        struct node* temp = head;
        for(int i=0; i<k && temp!=NULL; i++){
            if(temp!=NULL){
                temp=temp->next;
            }
        }
        
        if(temp!=NULL){
            
            // spliting the list
            struct node* trav = head;
            while(trav->next!=temp){
                trav=trav->next;
            }
            trav->next=NULL;
            
            // reversing the first part
            struct node* firstHead = reverse(head,trav);
            struct node* firstEnd = firstHead;
            while(firstEnd->next!=NULL){
                firstEnd=firstEnd->next;
            }
            
            // recursive call for the second call
            struct node* secondHead = reverseKGroup(temp, k);
            
            // joining the first and second part
            firstEnd->next = secondHead;
            
            // returning 
            return firstHead;
        }
        
        else {
           
            // locating the last node
            struct node* trav = head;
            while(trav->next!=NULL){
                trav=trav->next;
            }
           
            // simply reversing and returning
            struct node* firstHead = reverse(head,trav);
            return firstHead;
        }
    }
    
};