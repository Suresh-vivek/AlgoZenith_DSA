/*
Add 1 to a Linked List Number
Difficulty: MediumAccuracy: 31.91%Submissions: 249K+Points: 4
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9

Seen this question in a real interview before ?
Yes
No
Company Tags
Amazon

*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};



class Solution {
  public:
   int rec(Node * temp ){
       
       // got to the end and return carry
       
       if(temp==NULL){
           return 1;
       }
       
       int carry = rec(temp->next);
       
       temp->data = temp->data + carry;
       
       if(temp->data < 10){
           return 0;
       }
       
           temp->data =0;
           return 1;
       
   }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        
        int carry = rec(head);
        
        if(carry){
            Node * car = new Node(1);
            car -> next= head;
            return car;
        }
        return head;
        
        
    }
};