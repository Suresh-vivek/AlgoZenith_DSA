/*
19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]

*/

#include<bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head ==NULL ){
            return head;
        }
        if(head->next == NULL){
            return NULL;
        }

        ListNode * p1 = head , *p2= head;

        for(int i =0 ;i<n;i++){
            p2 = p2->next;
        }
        ListNode * prev = NULL;

        while(p2){
            prev =p1;
            p1 = p1->next;
     
            p2 = p2->next;
        }
       if(prev){
         prev ->next = prev->next->next;
       }
       else{
        head= head->next;
       }

        return head;


        
    }
};