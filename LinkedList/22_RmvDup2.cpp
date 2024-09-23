/*
82. Remove Duplicates from Sorted List II
Solved
Medium
Topics
Companies
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/


#include <bits/stdc++.h>

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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode * cur = head;
        ListNode * prev = NULL;

        while(cur){
            if(cur->next &&  cur->val == cur->next->val){
                int v = cur->val;

                while(cur && cur->val == v){
                    cur = cur->next;
                }
                if(prev){
                    prev ->next = cur;

                }else{
                    head = cur;
                }
            }
            else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};