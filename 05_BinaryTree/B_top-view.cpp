// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
};


// NOTE
// 01. Ofcourse we will maintain an unordered map which will store the nodes with their column number
// 02. An element appearing for the first time in a column will be selected as a top-view-element
// 03. The most important step, is that we must do a level order traversal to solve this problem 


class Solution {
  public:
    
    unordered_map<int, int> myMap;
    unordered_map<int, int> verify;
        
    void machine (Node* root, int col) {
        // base case
        if(root==NULL) return;
        
        // initialising the queue (it will store the node and also its column numbers)
        queue<pair<Node*,int>> myQueue;
        
        // pushing the root node along with the col_no
        myQueue.push({root,0});
        
        // looping
        while(!myQueue.empty()){
            // 01. extracting the front element of the queue
            Node* Bob = myQueue.front().first;
            int col = myQueue.front().second;
            myQueue.pop();
            // 02. pushing the left and right nodes along with col_no into the queue
            if(Bob->left != NULL) myQueue.push({Bob->left, col-1});
            if(Bob->right != NULL) myQueue.push({Bob->right, col+1});
            // 03. checking the node that we just extracted in step 01 
            if(verify[col]==0) {
                myMap[col] = Bob->data;
                verify[col] = 1;
            }
        }
    }
    
    vector<int> topView(Node *root) {
        // code here
        
        machine(root, 0);
        
        // finding the range
        int left = 0;
        int right = 0;
        while(verify[left]!=0) left--;
        left++;
        while(verify[right]!=0) right++;
        right--;
        
        // pushing into the ans 
        vector<int> ans;
        for(int i=left; i<=right; i++){
            ans.push_back(myMap[i]);
        }
        return ans;
        
    }
};
