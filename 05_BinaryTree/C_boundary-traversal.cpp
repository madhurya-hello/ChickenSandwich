// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
};

class Solution {
  public:
    
    vector<int> ans;
    
    // inserts all the left nodes except the leaf nodes
    void leftInsert(Node* root){
        // inserting the current node
        if(root->left!=NULL || root->right!=NULL) ans.push_back(root->data);
        // conditional recursive calls (base case handled)
        if(root->left!=NULL) leftInsert(root->left);
        else if(root->right!=NULL) leftInsert(root->right);
        else return;
    }
    
    // inserts all the leaf nodes
    void bottomInsert(Node* root){
        // base case
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        // recursive calls, first left then right
        if(root->left) bottomInsert(root->left);
        if(root->right) bottomInsert(root->right);
    }
    
    // inserts all the right nodes except the leaf nodes
    void rightInsert(Node* root){
        // conditional recursive calls (base case handled)
        if(root->right!=NULL) rightInsert(root->right);
        else if(root->left!=NULL) rightInsert(root->left);
        else return;
        // inserting the current node
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        if(root==NULL) return ans;
        
        ans.push_back(root->data);
        
        if(root->left==NULL && root->right==NULL) return ans;
        
        // left sub-tree exists ??
        if(root->left!=NULL){
            leftInsert(root->left);
        }
        
        bottomInsert(root);
        
        // right sub-tree exist??
        if(root->right!=NULL){
            rightInsert(root->right);
        }
                
        return ans;
    }
};
