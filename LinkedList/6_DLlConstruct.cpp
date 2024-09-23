/*
Geek is learning data structures and is familiar with linked lists, but he's curious about how to access the previous element in a linked list in the same way that we access the next element. His teacher explains doubly linked lists to him.

Given an integer array arr of size n. Construct the doubly linked list from arr and return the head of it.

Example 1:

Input:
n = 5
arr = [1,2,3,4,5]
Output:
1 2 3 4 5
Explanation: Linked list for the given array will be 1<->2<->3<->4<->5.
Example 2:

Input:
n = 1
arr = [1]
Output:
1
Explanation: Linked list for the given array will be 1.

*/

#include<bits/stdc++.h>
using namespace std;



class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

 Node* constructDLL(vector<int>& arr) {
        // code here
        Node * head = new Node(arr[0]);
        
        Node * cur = head;
        Node * prev =NULL;
        
        
        for(int i =1 ; i<arr.size() ;i++){
            cur->next = new Node(arr[i]);
            prev = cur;
            cur= cur->next;
            cur->prev = prev;
        }
        
        return head;
    }