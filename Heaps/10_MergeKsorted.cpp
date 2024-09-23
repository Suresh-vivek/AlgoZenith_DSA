/*
Merge k Sorted Arrays
Difficulty: MediumAccuracy: 67.25%Submissions: 97K+Points: 4
Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


Examples :

Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
 
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
      
        
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> ,
         greater<pair<int , pair<int , int>>> > minh;
         
        
       for(int i =0 ; i<K ;i++){
           if(arr[i].size() > 0){
               minh.push({arr[i][0] , {i , 0}});
           }
       }
       
       
       vector<int> ans;
       
       while(!minh.empty()){
           auto current = minh.top();
           minh.pop();
           
           int value = current.first;
           int arrayIndex = current.second.first;
           int elementIndex = current.second.second;
           
           ans.push_back(value);
           
           if(elementIndex + 1 < arr[arrayIndex].size()){
               minh.push({arr[arrayIndex][elementIndex +1] , {arrayIndex , elementIndex +1}});
           }
       }
       
       return ans;
    }
};