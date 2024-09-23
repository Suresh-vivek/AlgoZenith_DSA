/*
Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.

Examples :

Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 1->2->3->4->5->6
Explanation: 

We can see that 6 is inserted at the end of the linkedlist.
Input: LinkedList: 5->4 , x = 1
Output: 5->4->1
Explanation: 

We can see that 1 is inserted at the end of the linkedlist.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

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


   
Node *insertAtEnd(Node *head, int x) {
        // Code here
        
        if(!head){
            head = new Node(x);
            return head;
        }
        
        Node * cur = head;
        
        while(cur->next){
            cur = cur->next;
        }
        cur->next = new Node(x);
        
        return head;
    }