// https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class Node {
public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};


// MY SOLUTION (solved without any help)

class Solution {
    public:
      
        Node* solve01(Node* temp, Node* parent, int direction){
            
            // there are two base cases
            
            // base-case 01
            if(temp==NULL) return NULL;
            
            // base-case 02 - leaf nodes
            if(temp->left==NULL && temp->right==NULL && direction==0) {
                // agar left side ka leaf node hai, then...
                temp->right = parent;
                return temp;
            }
            else if(temp->left==NULL && temp->right==NULL && direction==1) {
                // agar right side ka leaf node hai, then...
                temp->left = parent;
                return temp;
            }
            
            // apple should contain the left-most node
            // mango should contain the right-most node
            Node* apple = solve01(temp->left, temp, 0);
            Node* mango = solve01(temp->right, temp, 1);
            
            // CASE 01 - if its a left node but not a leaf node...
            if(direction==0) {
                // if right-most node doesn't exist, then obviously the current node will itself be the right-most node
                if(mango==NULL) mango=temp;
                // right-most node aur parent ke beech mein rishta banao...
                mango->right = parent;
                parent->left = mango;
                // left-most node ko return karo...
                return apple==NULL? temp : apple; 
            }
            
            // CASE 02 - if its a right node but not a leaf node...
            if(direction==1) {
                // if left-most node doesn't exist, then obviously the current node will itself be the left-most node
                if(apple==NULL) apple=temp;
                // left-most node aur parent ke beech mein rishta banao...
                apple->left=parent;
                parent->right=apple;
                // right-most node ko return karo...
                return mango==NULL? temp : mango;
            }
            
            // BASICALLY
            // ek left-node, apne mango aur parent ke beech mein rishta banta hai, and apple ko return karta hai
            // ek right-node, apne apple aur parent ke beech mein rishta banta hai, and mango ko return karta hai
        }
        
        Node* bToDLL(Node* root) {
            // code here
            solve01(root->left, root, 0);
            solve01(root->right, root, 1);
            // root ko head pe leke jaao...
            while(root->left != NULL) root=root->left;
            return root;
        }
};


// STANDARD SOLUTION (by Kunal Kushwaha)

class Solution
{
    public:
        Node* head=NULL;
        Node* tail=NULL;
        Node* bToDLL(Node* root)
        {
            if(root==NULL){
                return NULL;
            }
            inorder(root);
            return head;
        }
        void inorder(Node* root){
            if(root==NULL){
                return;
            }
            inorder(root->left);
            if(head==NULL){
                head=root;
                tail=root;
            }else{
                tail->right=root;
                root->left=tail;
                tail=root;
            }
            inorder(root->right);
        }
    
};
