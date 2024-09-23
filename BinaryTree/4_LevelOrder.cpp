
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int l = q.size();

            vector<int> level;

            for(int i=0;i<l;i++){
                TreeNode * front = q.front();
                q.pop();

                if(front!=nullptr){
                    level.push_back(front->val);
                    if(front->left!= nullptr){
                        q.push(front->left);
                    }
                    if(front->right !=nullptr){
                        q.push(front->right);
                    }
                }
            }
            res.push_back(level);
        }

      
        return res;
        
    }
};