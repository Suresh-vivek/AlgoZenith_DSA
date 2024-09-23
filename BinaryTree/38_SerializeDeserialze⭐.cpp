/*

297. Serialize and Deserialize Binary Tree
Solved
Hard
Topics
Companies
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 
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

class Codec {
public:


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root){
        return "null";
       }
       queue<TreeNode *>q;
       string s;

       q.push(root);

       while(!q.empty()){

        TreeNode * node = q.front();

        q.pop();

        if(node){
                s += to_string(node->val) +",";
                q.push(node->left);
                q.push(node->right);
        }else{
                s+="null,";
        }
       }

       // remove trailling comma

       if(!s.empty()){
        s.pop_back();
       }


       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data =="null"){
                return nullptr;
        }

        stringstream ss(data);
        string item;
        getline(ss, item ,',');
        queue<TreeNode*> q;
        TreeNode * root = new TreeNode(stoi(item));

        q.push(root);

        while(!q.empty()){
                TreeNode * node = q.front();
                q.pop();

                if(getline(ss, item ,',')){
                        if(item!= "null"){
                                TreeNode * leftNode = new TreeNode(stoi(item));
                                node ->left = leftNode;
                                q.push(leftNode);

                        }
                }

                if(getline(ss, item ,',')){
                        if(item!= "null"){
                                TreeNode * rightNode = new TreeNode(stoi(item));
                                node ->right = rightNode;
                                q.push(rightNode);

                        }
                }
        }
          
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));