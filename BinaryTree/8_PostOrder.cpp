
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


vector<int> postOrder(Node* root) {
        // code here
        vector<int> res;
        if(!root) return res;
        
        stack<Node *> st;
        Node * last = nullptr;
        
    
        while(!st.empty() || root != nullptr){
            
            if(root!=nullptr){
                st.push(root);
                root = root->left;
            }
            else{
                Node * top = st.top();
                if(top->right !=nullptr && last != top->right){
                    root = top->right;
                }
                else{
                    res.push_back(top->data);
                    last = top;
                    st.pop();
                }
            }
        }
        return res;
    }