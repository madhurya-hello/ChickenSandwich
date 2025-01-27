// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:

    // COULDN'T SOLVE MYSELF :) 
    // didn't thought of recursion
    // to be honest it was an unique approach, maybe could've solved myself if I tried a little more

    void solve(Node* root,map<int,vector<int>>& node,int diff){
        // base case
        if(root == NULL) return;
        
        // push the current node
        node[diff].push_back(root -> data);
        
        // there a reason why we called this recursive call first
        solve(root -> left,node,diff+2);
        // and this recursive call second
        solve(root -> right,node,diff);
    }

    vector<int> diagonal(Node *root) {
        vector<int> ans;
        map<int,vector<int>> node;
        
        solve(root,node,0);
        
        for(auto i : node){
            for(auto j : i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};
