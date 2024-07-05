/*
Description
You are given Q queries and have to perform the following operations:

add x - add element x at the top of Priority Queue
remove - delete top element of the Priority Queue, if Priority Queue is not empty
print - print the element at top of the Priority Queue, if Priority Queue is not empty, otherwise print 0
Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer Q - the number of queries.

Each of the next Q ines contains queries.

Output Format
For each test case, print the required queries.

Constraints
1≤ T ≤ 105

1≤ Q ≤ 105

1≤ X ≤ 106

It is guaranteed that the sum of Q over all test cases does not exceed 106.

Sample Input 1
1
6
add 4
add 5
add 3
print
remove
print
Sample Output 1
5
4
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int q;
    cin>>q;

    priority_queue <int> pq;
    string s;

    while(q--){
        cin>>s;

        if(s=="add"){
            int x;
            cin>>x;
            pq.push(x);
        }
        else if(s=="remove"){
            if(!pq.empty()){
                pq.pop();
            }
        }
        else if(s=="print"){
            if(!pq.empty()){
                cout<<pq.top()<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
    }
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