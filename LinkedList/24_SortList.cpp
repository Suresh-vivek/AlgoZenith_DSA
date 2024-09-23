/*
148. Sort List
Solved
Medium
Topics
Companies
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?


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
    ListNode* sortList(ListNode* head) {

        vector<int> list;
        ListNode * cur = head;

        while(cur){
            list.push_back(cur->val);
            cur= cur->next;
        }

        ListNode * dummy = new ListNode(0);
        ListNode * temp = dummy;

        sort(list.begin() , list.end());

        for(auto val : list){
            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return dummy->next;
        
    }
};