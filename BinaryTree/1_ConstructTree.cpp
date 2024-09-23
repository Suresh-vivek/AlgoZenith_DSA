//contruct tree from preorder and inorder

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        stack<TreeNode*> st;
        TreeNode * root = nullptr;

        int n= preorder.size();

        for(int i=n-1 , j=n-1; i>=0 ; i--){

            while(j>=0){
                if(preorder[i] == inorder[j]){
                    break;
                }
                if(!st.empty() && st.top()->val==preorder[i]){
                    break;
                }
                TreeNode * temp = new TreeNode(inorder[j]);
                temp->right=root;
                st.push(temp);
                root = nullptr;
                j--;
            }
            if(j>=0 && preorder[i] ==inorder[j]){
                TreeNode *  node = new TreeNode(preorder[i]);
                node->right = root;
                root = node;
                j--;
                 continue;
            }
            if(st.size() >0 && st.top()->val == preorder[i]){
                TreeNode * node = st.top();
                st.pop();
                node->left = root;
                root = node;
                continue;
            }
        }
        return root;
    }
};