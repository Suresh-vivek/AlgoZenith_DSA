/*
Given a full binary expression tree consisting of basic binary operators (+, -,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100

*/

#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};



int evalTree(node* root) {
        // Your code here
        
        if(!root) return 0;
        
        if(!root->left && !root->right) return stoi(root->data);
        
        int lval = evalTree(root->left);
        int rval = evalTree(root->right);
        
        if(root->data == "+") return lval+rval;
        if(root->data == "-") return lval-rval;
        
        if(root->data == "*" ) return lval*rval;
        
        return lval/rval;
    }