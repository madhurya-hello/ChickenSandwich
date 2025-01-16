// https://www.geeksforgeeks.org/problems/level-order-traversal/1

#include <bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        
        vector<vector<int>> ans;
        
        // edge case
        if(root==NULL) return ans;
        
        // initialising the queue
        queue<Node*> myQueue;
        
        // pushing the root
        myQueue.push(root);
        
        // looping
        while(myQueue.size() != 0){
            // temporary array to store the elements of a particular row
            vector<int> temp;
            // running the loop n times, where n is the no of elements currently present in the queue
            for(int i=1; i<=myQueue.size(); i++){
                // 01. storing the front element of the queue
                Node* Bob = myQueue.front();
                myQueue.pop();
                // 02. pushing the left and right (if exists)
                if(Bob->left != NULL) myQueue.push(Bob->left);
                if(Bob->right != NULL) myQueue.push(Bob->right);
                // 03. storing the data in a temporary array
                temp.push_back(Bob->data);
            }
            // pushing the temporary array to our answer array
            ans.push_back(temp);
        }
        
        return ans;
    }
};
