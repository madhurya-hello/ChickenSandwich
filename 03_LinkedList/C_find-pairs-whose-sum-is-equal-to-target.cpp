// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next, *prev;
};

class Solution {
    public:
        vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
        {
            // code here
            vector<pair<int, int>> ans;
            
            Node* trav1 = head;
            Node* trav2 = trav1->next;
            if(trav2 == NULL) return ans;
            
            while(trav2->next != NULL) trav2 = trav2->next;
            
            while(trav1 != trav2 && trav1->prev != trav2){
                if(trav1->data + trav2->data == target){
                    pair<int, int> myPair = make_pair(trav1->data, trav2->data);
                    ans.push_back(myPair);
                    trav1 = trav1->next;
                    trav2 = trav2->prev;
                }
                else if(trav1->data + trav2->data > target ) {
                    trav2 = trav2->prev;
                }
                else if(trav1->data + trav2->data < target ) {
                    trav1 = trav1->next;
                }
            }
            
            return ans;
        }
};
