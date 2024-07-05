/*
Description
You are given an array of N integers. In one operation, remove any two elements in the array and add their sum to the array. The cost of this operation will be the sum of the two elements. Print the minimum cost till the size of the array does not become 1.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array. 

The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the minimum cost till the size of the array does not become 1.

Constraints
1≤ T ≤ 106

1≤ N ≤ 106

1≤ Ai ≤ 109

It is guaranteed that the sum of N over all test cases does not exceed 106.

Sample Input 1
3
4
3 1 4 2
3
1 1 1
4
2 3 1 3
Sample Output 1
19
5
18
*/

#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;

    priority_queue<long long, vector<long long>, greater<long long>>pq;
    for(int i=0 ;i< n;i++){
        long long x;
        cin>>x;
        pq.push(x);
    }
    long long ans =0;
    while(pq.size()>1){
        long long a = pq.top();
        ans+= pq.top();
        pq.pop();
        long long b = pq.top();
        ans+= pq.top();
        pq.pop();
        pq.push(a+b);

    }

    cout<<ans<<endl;
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