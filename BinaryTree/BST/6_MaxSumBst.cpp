/*

1373. Maximum Sum BST in Binary Tree
Solved
Hard
Topics
Companies
Hint
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.
 

Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104
*/





  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 class NodeValue{
    public:
    int minNode , maxNode , maxSum;

    NodeValue(int minNode , int maxNode ,int maxSum ){
        this->minNode = minNode;
        this ->maxNode = maxNode;
        this->maxSum = maxSum;

    }
    NodeValue(){

    }

 };
class Solution {
    
public:

NodeValue largestSumBSTinBT(TreeNode * root , int & maxSum){

        // empty tree
        if(!root){
            return NodeValue(INT_MAX , INT_MIN , 0);
        }

        auto left = largestSumBSTinBT(root->left , maxSum);
        auto right = largestSumBSTinBT(root->right , maxSum);
        NodeValue cr_root;

        // check bst

        if(left.maxNode < root->val && root->val < right.minNode){
            // a valid bst
           cr_root.minNode = min(root->val , left.minNode);
           cr_root.maxNode = max(root->val , right.maxNode);
           cr_root.maxSum = left.maxSum + right.maxSum + root->val;
        }

        // not a valid bst
       else{
        cr_root.minNode = INT_MIN;
           cr_root.maxNode = INT_MAX;
           cr_root.maxSum = max(left.maxSum , right.maxSum);
        
       }

       maxSum = max(maxSum , cr_root.maxSum);
       return cr_root;
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;

        largestSumBSTinBT(root , maxSum );
        return maxSum;

       
        
    }
};