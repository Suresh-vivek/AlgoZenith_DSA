/*
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

Example:

Input:
n = 4
1->2->3->4
Key = 3
Output:
True
Explanation:
3 is present in Linked List, so the function returns true.
Your Task:
Your task is to complete the given function searchKey(), which takes a head reference and key as Input and returns true or false boolean value by checking the key is present or not in the linked list.

Constraint:
1 <= n <= 105
1 <= key <= 105

Expected Time Complexity: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
 bool searchKey(int n, struct Node* head, int key) {
        // Code here
        
        int res = false;
        
        Node * cur = head;
        
        while(cur){
            if(cur->data == key){
                res= true;
                break;
            }
            cur = cur->next;
        }
        return res;
    }
