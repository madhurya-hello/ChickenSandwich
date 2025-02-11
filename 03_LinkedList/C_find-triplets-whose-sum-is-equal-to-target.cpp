// https://www.geeksforgeeks.org/problems/count-triplets--141631/1

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next, *prev;
};

class Solution {
    public:
        int countTriplets(struct Node* head, int x) {
            // code here.
            
            // edge case
            if(head==NULL || head->next==NULL || head->next->next==NULL) return 0;
            
            // creating a hasmap to get the parent node of each node (we are kind of making it a doubly-liked-list)
            // we are also storing the tail pointer (ek teer se do nishane!!)
            unordered_map<Node*, Node*> myMap;
            Node* tail = head;
            while(tail->next!=NULL) {
                myMap[tail->next] = tail;
                tail = tail->next;
            }
            
            int ans = 0;
            
            Node* left = head;
            
            while(left->next->next != NULL){
                Node* right = tail;
                Node* mid = left->next;
                
                while( mid!=right && right->next != mid ){
                    int sum = left->data + mid->data + right->data;
                    if(sum == x){
                        ans++;
                        mid = mid->next;
                        right = myMap[right];
                    }
                    else if(sum > x){
                        mid = mid->next;
                    }
                    else if(sum < x){
                        right = myMap[right];   
                    }
                }
                
                left = left->next;
            }
            
            return ans;
        }
};
