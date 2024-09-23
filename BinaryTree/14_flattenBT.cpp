
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
   TreeNode * prev;

   void preorder(TreeNode * cur){
    if(!cur) return;

    if(prev){
        prev->left = nullptr;
        prev->right = cur;
    }

    TreeNode * r = cur->right;
    prev= cur;

    preorder(cur->left);
    preorder(r);
   }
    void flatten(TreeNode* root) {
        prev= nullptr;
        preorder(root);
        
    }
};