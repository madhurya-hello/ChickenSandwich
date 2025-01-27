// https://www.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1

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

class Solution{
public:
    
    // COULDN'T SOLVE MYSELF :) 
    // after reading the solution, I felt like giving up was a good decision indeed
    
    Node* buildTree(string str, int& index){
        
        if(index >= str.length()) return NULL;
        
        // agar shuruwat mein hi right-bracket mil jaye...
        if(str[index] == ')'){
            index++;
            return NULL;
        }
        
        // converting a number from "string" to "number"
        int data = 0;
        while(str[index] != '(' && str[index] != ')'){
            data = data*10 + str[index]-'0';
            index++;
            if(index >= str.length()) break;
        }
        
        Node* root = new Node(data);
        
        // first left-bracket for the "left" sub-tree, second left-bracket for the "right" sub-tree
        if(str[index] == '(') root->left = buildTree(str, ++index);
        if(str[index] == '(') root->right = buildTree(str, ++index);
        
        // right-bracket aane pey...
        if(str[index] == ')') index++;
        return root;
    }
      
    Node *treeFromString(string str){
        int index = 0;
        return buildTree(str, index);
    }
};
