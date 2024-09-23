/*
61. Rotate List
Solved
Medium
Topics
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]

*/


//Roatte list right


#include<bits/stdc++.h>
using namespace std;



 struct ListNode {

    
     int val;
     ListNode *next;


     ListNode() : val(0), next(nullptr) {}

   
     ListNode(int x) : val(x), next(nullptr) {}

     
     ListNode(int x, ListNode *next) : val(x), next(next) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // to rotate find kth node from end

        //length of linked list

        if(head == NULL or head->next == NULL){
            return head;
        }

        ListNode * cur = head;

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
        ListNode * prev = NULL;
        for(int i =0 ; i<len -k;i++){
            prev = cur;
            cur = cur->next;


        }
        
        if(prev && cur){
            prev->next = NULL;
            ListNode *curc = cur;
            
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