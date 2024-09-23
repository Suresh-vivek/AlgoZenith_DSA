/*
437. Path Sum III
Solved
Medium
Topics
Companies
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

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

 int pathsum2(TreeNode* root, long long targetSum){
    if(!root){
            return 0;
        }
    int res =0;
    if(root-> val == targetSum){
        res++;
    }
    res += pathsum2(root->left, targetSum - root->val);
    res += pathsum2(root->right, targetSum - root->val);

    return res;
   }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + pathsum2(root, targetSum);
    }
};

// time 