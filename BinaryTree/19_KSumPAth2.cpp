/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:
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
    vector<vector<int>> res;

    void paths(TreeNode* root, int targetSum , vector<int> path){
        if(!root){
            return ;
        }
        path.push_back(root->val);

        if(!root->left && !root->right){
            if(root->val == targetSum){
                res.push_back(path);
                return ;
            }
            return;
        }
        if(root->left){
            paths(root->left , targetSum - root->val , path);
        }
        if(root->right){
            paths(root->right , targetSum - root->val , path);
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<int> path;
       paths(root , targetSum , path);

       return res;
        
    }
};