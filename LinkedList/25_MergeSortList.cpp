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
    
    // find Middle
    ListNode * findMiddle(ListNode * head){
        ListNode * slow = head;
        ListNode * fast = head -> next;

        while(fast != NULL and fast -> next != NULL){
                slow = slow -> next;
                fast = fast->next->next;
        }

        return slow;
    }


    // merge 2 list;

    ListNode * MergeList(ListNode * list1 , ListNode * list2){
        ListNode * dummy = new ListNode(0);
        ListNode * temp = dummy;

        while(list1 != NULL and list2 != NULL){

                if(list1 -> val < list2 ->val){
                        temp->next = list1;
                        temp =list1;
                        list1 = list1->next;
                }else{
                        temp -> next = list2;
                        temp = list2;
                        list2 = list2->next;
                }
        }

        // check for remainig list

        if(list1) temp->next = list1;
        else
        temp->next = list2;

        return dummy -> next;
    }
    ListNode* sortList(ListNode* head) {

        // base condition

        if(head == NULL or head->next == NULL){
                return head;
        }

        // left , right , middle

        ListNode * left = head;
        ListNode * middle = findMiddle(head);
        ListNode* right = middle->next;

        // breaking the link
        middle->next = NULL;


        left = sortList(left);
        right = sortList(right);

        return MergeList(left , right);

      
        
    }
};