/*
Rotate a Linked List
Difficulty: MediumAccuracy: 39.95%Submissions: 247K+Points: 4
Given the head of a singly linked list, the task is to rotate the left shift of the linked list by k nodes, where k is a given positive integer smaller than or equal to the length of the linked list.

Examples:

Input: linkedlist: 2->4->7->8->9 , k = 3
Output: 8->9->2->4->7
Explanation:
Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

Input: linkedlist: 1->2->3->4->5->6->7->8 , k = 4
Output: 5->6->7->8->1->2->3->4

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 103
1 <= node -> data <= 104
1 <= k <= number of nodes 


*/


#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};



class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        
        if(head == NULL or head->next == NULL){
            return head;
        }

        Node * cur = head;

        int len = 0;

        while(cur){
            len++;
            cur= cur->next;
            
        }

        if(k>len){
           int n = k/len;
           k = k - len*n;
        }

        // find kth element from last
        cur = head;
        Node * prev = NULL;
        for(int i =0 ; i<k;i++){
            prev = cur;
            cur = cur->next;


        }
        
        if(prev && cur){
            prev->next = NULL;
            Node *curc = cur;
            
           while(cur->next){
            cur = cur->next;
           }
           cur->next = head;
           head = curc;
           
           
           
            return head;
        }
        return head;
    }
};