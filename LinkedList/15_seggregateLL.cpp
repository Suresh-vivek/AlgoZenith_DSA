/*
Segregate even and odd nodes in a Linked List
Difficulty: MediumAccuracy: 49.8%Submissions: 87K+Points: 4
Given a link list, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be the same as that in the original list.

NOTE: Don't create a new linked list, instead rearrange the provided one.

Examples:

Input: Linked list: 17->15->8->9->2->4->6
Output: 8->2->4->6->17->15->9

Explaination: 8,2,4,6 are the even numbers so they appear first and 17,15,9 are odd numbers that appear later.
Input: Linked List: 1 -> 3 -> 5 -> 7
Output: 1->3->5->7

Explaination: There is no even number. So no need for modification.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 ≤ size of linked list ≤ 105
1 ≤ Each element of the list ≤ 105
*/



#include<bits/stdc++.h>
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
    Node* divide(Node* head) {
        // code here
        
        Node * cur = head;
        
        vector<int> list;
        
        while(cur){
            if(cur->data %2==0){
                list.push_back(cur->data);
            }
            cur= cur->next;
        }
        cur= head;
        while(cur){
            if(cur->data %2){
                list.push_back(cur->data);
            }
            cur= cur->next;
        }
        
        cur=head;
        
        for(auto val : list){
            cur->data = val;
            cur= cur->next;
        }
        
        return head;
           
        
        
        
        
        
    }
};