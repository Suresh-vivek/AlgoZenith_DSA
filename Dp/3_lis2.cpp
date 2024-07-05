 #include<bits/stdc++.h>
using namespace std;


 
  int longestSubsequence(int n, int a[])
    {
       // your code here
       
        if (n == 0) return 0;

        vector<int> tails; // This will store the increasing subsequence

        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(tails.begin(), tails.end(), a[i]);
            if (it == tails.end()) {
                tails.push_back(a[i]);
            } else {
                *it = a[i];
            }
        }

        return tails.size();
    }