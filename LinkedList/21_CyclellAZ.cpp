/*
Cycle in Linked List
Hard

Difficulty

2 sec

Time Limit

256000KB

Memory

100

Score

Description
Given a non-empty linked list, your task is to find the cycle in the linked list. Return starting node of the cycle and length of the cycle. If there is no cycle, then return null as node and -1 as length.

Complete the function

pair<ListNode*,int> cycleInLinkedList(ListNode* head)
head is the pointer to the beginning node of the linked list.

Input Format
The first line contains n - the length of the linked list.
The second line contains the sequence of elements in linked list nodes.
The third line contains an integer LastLink - denoting to which node from the starting position the last node connects. If it is 0, then there is no cycle.

The following function translates the input.

ListNode* GetList(int n, vector<int> &num, int lastLink)
 

Output Format
Constraints
1 ≤ Length of the linked list ≤ 1000000
0 ≤ Value in node ≤ 109
1 ≤ LastLink ≤ Length of the linked list -1

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


pair<ListNode*,int> cycleInLinkedList(ListNode* head) {
    //Complete the function
    pair<ListNode* , int> ans= {nullptr , -1};

    if(head == nullptr or head->next == nullptr){
        return ans;
    }

    ListNode * slow = head , *fast = head;
    int length = 1;


    bool cycle = false;

    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cycle = true;

            while(slow->next != fast){
                slow = slow->next;
                length++;

            }
            break;
        }


    }

    if(cycle){
        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        ans.first = slow;
        ans.second = length;

        return ans;

    }
    return ans;
}


ListNode* GetList(int n, vector<int> &num, int lastLink) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < n; i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }

    if(lastLink) {
        ListNode* temp = head;
        for(int i = 0; i < lastLink - 1; i++) {
            temp = temp->next;
        }
        cur->next = temp;
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    int lastLink;
    cin >> lastLink;

    ListNode* head = GetList(n, num, lastLink);

    pair<ListNode*,int> ans = cycleInLinkedList(head);

    cout << (ans.first ? ans.first->val : -1) << " " << ans.second << "\n";
    
    return 0;
}
