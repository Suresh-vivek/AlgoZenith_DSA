/*
662. Maximum Width of Binary Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


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
   
  
    int widthOfBinaryTree(TreeNode* root) {
       if(!root ){
        return 0;
       }
       int maxwidth = 0;
       queue<pair<TreeNode* , unsigned long long>> q;
       q.push({root , 0});

       while(!q.empty()){

        int level = q.size();
    
        unsigned long long first , last;

        for(int i =0 ;i < level ; i++){
            unsigned long long curIndex = q.front().second ;
            TreeNode * node = q.front().first;
            q.pop();


            if(i==0) first = curIndex;
            if(i== level-1) last = curIndex;

            if(node->left) q.push({node->left , 2*curIndex +1});
            if(node->right) q.push({node->right , 2*curIndex +2});
        }

        maxwidth = max(maxwidth , int(last -first +1));
       }

       return maxwidth;




        
    }
};