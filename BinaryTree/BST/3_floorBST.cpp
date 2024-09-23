
/*
Floor in BST
Difficulty: MediumAccuracy: 51.06%Submissions: 74K+Points: 4
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Example:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output:
87
Explanation:
87 is present in tree so floor will be 87.
Example 2:

Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output:
9
Your Task:-
You don't need to read input or print anything. Complete the function floor() which takes the integer n and BST and integer x returns the floor value.

Constraint:
1 <= Noda data <= 109
1 <= n <= 105

Expected Time Complexity: O(height of tree)
Expected Space Complexity: O(height of tree)


*/







#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


class Solution{

public:

    void inorder(Node * root , vector<int> & res){
    if(!root){
        return;
    }
    
    inorder(root->left ,res);
    res.push_back(root->data);
    inorder(root->right , res);
}
    int floor(Node* root, int x) {
        // Code here
        if (root == NULL) return -1;
    
    vector<int> res;
    
    inorder( root , res);
    int ans =-1;
    
    int low =0 , high = res.size()-1 ;
    
    while(low<=high){
        int mid = low + (high - low)/2;
        
        if(res[mid] ==x){
            return res[mid];
        }
        else if(res[mid] >x){
            high = mid-1;
        }
        else{
            ans = res[mid];
            low = mid+1;
        }
    }
    return ans;
    }
};