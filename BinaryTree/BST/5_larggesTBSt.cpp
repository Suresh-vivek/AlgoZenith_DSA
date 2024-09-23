/*
Largest BST
Difficulty: MediumAccuracy: 29.73%Submissions: 151K+Points: 4
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/

#include<bits/stdc++.h>
using namespace std;



struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeValue{
    
    public:
    int minNode , maxNode , maxSize;
    
    NodeValue(int minNode , int maxNode , int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
    
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue largestBSTinBT(Node * root ){
        
        // empty node;
        if(!root){
            return NodeValue(INT_MAX , INT_MIN , 0);
        }
        
        auto left = largestBSTinBT(root->left);
        auto right = largestBSTinBT(root->right);
        
        
        // if bst
        
        if(left.maxNode < root->data and root->data < right.minNode){
            
            // a valid bst
            
            return NodeValue(min(root->data , left.minNode) , max(root->data , right.maxNode),
             left.maxSize + right.maxSize +1            );
        }
        
        // if not bst
        
        return NodeValue(INT_MIN , INT_MAX , max(left.maxSize , right.maxSize));
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	return largestBSTinBT(root).maxSize;
    }
};
