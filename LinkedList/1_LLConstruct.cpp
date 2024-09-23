/*
Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list.

Examples:

Input: arr = [1, 2, 3, 4, 5]
Output: LinkedList: 1->2->3->4->5
Explanation: Linked list for the given array will be

Input: arr = [2, 4, 6, 7, 5, 1, 0]
Output: LinkedList: 2->4->6->7->5->1->0
Explanation: Linked list for the given array will be

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
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

 Node* constructLL(vector<int>& arr) {
        // code here
     Node * head = new Node(arr[0]);
     
     Node * cur = head;
     
     for(int i =1 ; i< arr.size() ;i++){
         cur->next = new Node(arr[i]);
         cur = cur->next;
     }
     
     return head;
    }