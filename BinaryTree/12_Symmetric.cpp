/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true


*/

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

  bool isSame(TreeNode * p , TreeNode *q){
     if(p==nullptr && q==nullptr){
            return true;
        }
        if(p==nullptr)
        return false;
        if(q==nullptr)
        return false;

        if(p-> val != q->val)
        return false;

        return isSame(p->left , q->right ) && isSame(p->right , q->left);

  }
    bool isSymmetric(TreeNode* root) {

        if(root==nullptr ||(root->left==nullptr and root->right == nullptr))
        return true;

        return isSame(root->left , root->right);

       




        
    }
};