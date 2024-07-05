/*
Description
You have N magical candy bag. The i-th bag contains Ai candies. In each minute you can eat all the candies, Ai of one bag, after that, the candies become [Ai / 2] where [x] is the greatest integer less than x. You have K minutes, find the maximum number of candies you can eat.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, K - the number of bags and the number of minutes.

The second line of each test case contains N space-separated integers.

Output Format
For each test case, print the maximum number of candies you can eat.

Constraints
1≤ T ≤ 105

1≤ N ≤ 105

0≤ K ≤ 105

1≤ Ai ≤ 109

It is guaranteed that the sum of K over all test cases does not exceed 106.

Sample Input 1
3
4 2
4 3 5 1
1 2
4
6 3
3 2 2 5 1 2
Sample Output 1
9
6
10

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n , k;
    cin>>n>>k;
    priority_queue<int> pq;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    int ans = 0;

    for(int i =0;i<k;i++){
        if(!pq.empty()){
            int max = pq.top();
            pq.pop();

            ans +=max;
            max /=2;
            pq.push(max);



        }


    }

    cout <<ans<<"\n";


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