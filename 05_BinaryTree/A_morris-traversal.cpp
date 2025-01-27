// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// Inorder-Traversal

// Explanation:
// Agar kisi tarike se left subtree ke rightmost node ko temporarily current node se connect kar dein, toh hum root pe wapas aane ke liye stack ya recursion ki jarurat nahi hai! "Return ticket" free mein mil gaya. Iska matlab har node ka left ka rightmost node ka right pointer temporarily current node se connect kar do. (Isko bolte hain thread banana). Aur jab kaam ho jaye, thread tod do. Easy-peasy lemon squeezy! 

// Why Morris Traversal?
// Space complexity in morris traversal is O(1) while in recursive method, its O(n) due to the formation of new recursion stacks created in the backend
// Time complexity in morris traversal is 2 times than in recursive method, because in morris traversal we are reaching some of the nodes 2 times (once for creating the dummy link and once for removing it)


// METHOD 01 (recursive)
class Solution {
public:
    vector<int> ans;
    void recursiveInorder(TreeNode* root) {
        // base case
        if (root==NULL) return;
        recursiveInorder(root->left);
        ans.push_back(root->val);
        recursiveInorder(root->right);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        recursiveInorder(root);
        return ans;
    }
};


// METHOD 02 (morris traversal)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        morrisTraversal(root, ans);
        return ans;
    }

    TreeNode* getLeftRightmost(TreeNode* node, TreeNode* parent) {
        while (node->right != NULL && node->right != parent) {
            node = node->right;
        }
        return node;
    }

    void morrisTraversal(TreeNode* node, vector<int>& ans) {
        TreeNode* curr = node;
        // loop to traverse entire tree (in-order)
        while (curr != NULL) {
            TreeNode* left = curr->left;
            // case 01
            if (left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            // case 02 
            else {
                TreeNode* res = getLeftRightmost(left, curr);
                if (res->right == NULL) {
                    res->right = curr; // create thread
                    curr = curr->left;
                } else {
                    res->right = NULL; // remove thread
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
};