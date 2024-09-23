/*
658. Find K Closest Elements
Solved
Medium
Topics
Companies
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         vector<int> ans;
        
        // maxheap
        priority_queue<pair<int , int>> maxh;
        
        for(auto val : arr){
          
                maxh.push({abs(val - x) , val});
           
            
            if(maxh.size() >k){
                maxh.pop();
                
            }
        }
        
        for(int i =0 ;i <k ;i++){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
        
    }
};