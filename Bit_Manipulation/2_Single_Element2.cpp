/*
 Given an array where every element occurs three times, except one element which occurs only once. Find the element that occurs once.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;

        for(int i =0 ;i <32 ; i++){
            long long int sum = 0;

            for(int j=0;j<n;j++){
                sum += (nums[j] & (1<<i));
            }

            if(sum%3){
                ans |=(1<<i);
            }
        }

        return ans;
        
    }
};