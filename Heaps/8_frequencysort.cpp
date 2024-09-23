/*
Sorting Elements of an Array by Frequency
Difficulty: MediumAccuracy: 44.93%Submissions: 76K+Points: 4
Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]
Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.
Expected Time Complexity: O(n*logn)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{

        public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
   unordered_map<int, int> m;

    // Function used in sorting vector elements first according to frequency
    // and if it is same for both values, then smaller number comes first.
    static bool sortByVal(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }

    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {

        int n = arr.size();
        vector<pair<int, int>> v;

        // using map to keep count of the elements.
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }

        // copying the elements and their count from map to vector.
        copy(m.begin(), m.end(), back_inserter(v));

        // sorting the vector according to frequency.
        sort(v.begin(), v.end(), sortByVal);
        vector<int> ans;

        for (int i = 0; i < v.size(); i++) {
            // storing elements as many times as their count in output vector.
            for (int j = 0; j < v[i].second; j++) {
                ans.push_back(v[i].first);
            }
        }
        m.clear();

        // returning the output.
        return ans;
    }
};