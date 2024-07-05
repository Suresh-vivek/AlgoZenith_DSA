/*
Description
You are given N blocks. You have to build towers by placing blocks on top of each other with the condition that the upper block must be smaller than the lower block. You have to process the blocks in the given order. Find the minimum possible number of towers you can create.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the minimum possible number of towers you can create.

Constraints
1≤ T ≤ 105

1≤ N ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1
3
5
3 2 5 1 4
4
1 1 1 1
5
5 4 5 3 2 
Sample Output 1
2
4
2

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long







void solve(){
    int n;
    cin>>n;
    multiset<int> ml;
    int arr[n];

    for(int i =0 ;i<n ;i++){
        cin>> arr[i];
    }

    for(int i =0 ; i<n;i++){
        auto it = ml.upper_bound(arr[i]);
        if(it == ml.end()){
            ml.insert(arr[i]);
        }
        else{
            ml.erase(it);
            ml.insert(arr[i]);

        }
    }
    cout<<ml.size()<<endl;
}




signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        solve();
    }
}