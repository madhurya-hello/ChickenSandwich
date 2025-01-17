// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
  public:
    // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        // edge case
        if(root==NULL) return ans;
        
        // initialising the queue
        queue<TreeNode*> myQueue;
        
        // pushing the root
        myQueue.push(root);
        
        // looping
        while(!myQueue.empty()){
            // temporary array to store the elements of a particular row
            vector<int> temp;
            // running the loop n times, where n is the no of elements currently present in the queue
            int level = myQueue.size();
            for(int i=1; i<=level; i++){
                // 01. storing the front element of the queue
                TreeNode* Bob = myQueue.front();
                myQueue.pop();
                // 02. pushing the left and right (if exists)
                if(Bob->left != NULL) myQueue.push(Bob->left);
                if(Bob->right != NULL) myQueue.push(Bob->right);
                // 03. storing the data in a temporary array
                temp.push_back(Bob->val);
            }
            // pushing the temporary array to our answer array
            ans.push_back(temp);
        }
        
        return ans;
    }
};
