// https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

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

    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        // just remove the loop without losing any nodes
        
        if (!head || !head->next) return;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; 
        }
        

        // if no loop exists

        if (slow != fast) return;
        
        // loop exists
        
        slow = head;
        // when the last_node is connected with the head, then both slow and fast will be pointing at the head (by observation)
        if (slow == fast) {                 
            while (fast->next != slow) {
                fast = fast->next;
            }
        }
        // when the last_node is connected with a middle_node
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        fast->next = NULL;
    }
};