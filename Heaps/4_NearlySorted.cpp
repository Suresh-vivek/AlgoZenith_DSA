/*
Nearly sorted
Difficulty: MediumAccuracy: 75.25%Submissions: 44K+Points: 4
Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10
Example 2:

Input:
n = 5, k = 2
arr[] = {3,1,4,2,5}
Output: 1 2 3 4 5 
Note: DO NOT use STL sort() function for this question.

Your Task:
You are required to complete the method nearlySorted() which takes 3 arguments and returns the sorted array.

Expected Time Complexity : O(nlogk)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ n ≤ 106
1 ≤ k < n
1 ≤ arri ≤ 107


*/

#include <bits/stdc++.h>
using namespace std;
class Solution {



         public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int K){
        // Your code here
        
        //Min heap
        
        priority_queue<int , vector<int> , greater<int>> minh;
        
        vector<int> ans;
        
        for(int i =0 ; i< num ;i++){
            
            minh.push(arr[i]);
            
            if(minh.size() > K){
                ans.push_back(minh.top());
                minh.pop();
            }
        }
        
        for(int i =0 ;i < K ;i++){
            ans.push_back(minh.top());
                minh.pop();
            
        }
        return ans;
    }
};