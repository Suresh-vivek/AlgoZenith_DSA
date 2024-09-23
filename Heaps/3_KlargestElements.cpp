/*
k largest elements
Difficulty: MediumAccuracy: 53.56%Submissions: 159K+Points: 4
Given an array arr of n positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

Examples

Input: arr[] = {12, 5, 787, 1, 23}, n = 5, k = 2
Output: 787 23
Explanation: 1st largest element in the array is 787 and second largest is 23.
Input: arr[] = {1, 23, 12, 9, 30, 2, 50}, n = 7, k = 3 
Output: 50 30 23
Explanation: 3 Largest element in the array are 50, 30 and 23.
Expected Time Complexity: O(k+(n-k)*logk)
Expected Auxiliary Space: O(k+(n-k)*logk)

Constraints:
1 ≤ k ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/



#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    // min heap
	    
	    priority_queue<int , vector<int> , greater<int>> minh;
	    
	    for(int i =0 ; i< n ;i++){
	        
	        minh.push(arr[i]);
	        
	        if(minh.size()>k){
	            minh.pop();
	        }
	    }
	    vector<int> ans;
	    for(int i =0 ; i< k ;i++){
	        ans.insert(ans.begin() , minh.top());
	        minh.pop();
	    }
	    
	    return ans;
	}

};