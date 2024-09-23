/*
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
   vector<vector<int>> res;
   
   void dfs(Node* root , vector<int> path){
       path.push_back(root->data);
       
       if(root->left == NULL && root->right == NULL){
           res.push_back(path);
           return ;
           
       }
       if(root->left !=NULL) dfs(root->left , path);
       if(root->right !=NULL) dfs(root->right , path);
   }
    vector<vector<int>> Paths(Node* root) {
        // code here
        if(root==NULL)
        return res;
        vector<int> p;
        
        dfs(root ,p );
        
        return res;
    }
};