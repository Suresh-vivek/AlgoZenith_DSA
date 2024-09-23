/*
234. Palindrome Linked List
Solved
Easy
Topics
Companies
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
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
    bool isPalindrome(ListNode* head) {

        ListNode * start = head;
        string ll = "";

        while(start!=NULL){
            ll +=to_string(start->val);
            start = start->next;

        }
        // cout<<ll<<endl;


        
        int n = ll.length();

        for(int i =0 ;i <n/2 ;i++){
            if(ll[i] != ll[n-i-1]){
                return false;
            }
        }
        return true;


        
    }
};