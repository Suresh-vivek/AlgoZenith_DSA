/*
Given a binary tree, determine if it is 
height-balanced
.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

*/

#include<bits/stdc++.h>
using namespace std;

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

    int depth(TreeNode * root){
        if(!root) return 0;
        return max(depth(root->left) , depth(root->right)) +1;
        
    }
    bool isBalanced(TreeNode* root) {

        if(!root)
        return true;

        int left = depth(root->left);
        int right = depth(root->right);

        return abs(left -right) <=1 && isBalanced(root->left) && isBalanced(root->right);
        
    }
};