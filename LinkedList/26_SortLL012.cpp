/*
Sort a linked list of 0s, 1s and 2s
Difficulty: EasyAccuracy: 60.75%Submissions: 194K+Points: 2
Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= no. of nodes <= 106
0 <= node->data <= 2


*/



#include <bits/stdc++.h>

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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        vector<int> arr(3,0);
        
        Node * cur = head;
        
        while(cur){
            arr[cur->data]++;
            cur = cur->next;
        }
        
        Node * dummy = new Node(0);
        Node * temp = dummy;
        
       for(int i =0 ; i<3 ;i++){
           
           while(arr[i]){
               temp->next = new Node(i);
               arr[i]--;
               temp = temp->next;
           }
       }
       
       return dummy->next;
        
    }
     





     // More efficient method
     

     Node* segregate2(Node* head) {

        // Add code here
       if(head== NULL or head->next== NULL){
           return head;
       }
       
       // thhree heads
       
       Node * zerohead = new Node(-1) , *zero = zerohead;
       Node * onehead = new Node(-1) , *one = onehead;
       Node * twohead = new Node(-1) , *two = twohead;
       
       
       Node * temp = head;
       
       while(temp){
           
           if(temp->data ==0){
               zero->next = temp;
               zero = zero->next;
           }
           else if(temp->data ==1){
               one->next = temp;
               one = one ->next;
           }else{
               two->next = temp;
               two = two->next;
           }
           
           temp = temp->next;
       }
       
       // connect all three
       
       zero->next = onehead->next ? onehead->next : twohead->next;
       one->next = twohead->next;
       two->next = NULL;
       
       return zerohead->next;
        
    }
};