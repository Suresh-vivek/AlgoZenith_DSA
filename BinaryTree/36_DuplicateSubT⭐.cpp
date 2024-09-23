/*
Leetcode 652
Time complexity - O(N^2)

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
 
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
    string subtreeStrings(TreeNode* root ,unordered_map<string , int> &mp , vector<TreeNode * > &res ){
        if(!root){
            return "N";
        }
        string s = to_string(root->val) + "," + subtreeStrings(root->left , mp , res) + "," + subtreeStrings(root->right , mp , res);

        if(mp[s] ==1 ){
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        unordered_map<string , int> mp;
        vector<TreeNode * > res;

        subtreeStrings(root , mp , res);
        return res;
        
    }
};