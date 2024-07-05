/*

Description
There are N students in section A. The i-th student got Ai marks. The class teacher of section B was absent so sections A and B were merged. The students of section B did not want to humiliate themselves, so they decided to sit with students having the same marks as them. You are given the marks of students of section B in order of their entry in the class. You have to tell whether the i-th student of section B can sit with a student with the same marks as him. If there is at least 1 person in the room with the same marks, print ‘YES’ else print ‘NO’. (without the quotes)

See Sample Test Cases.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains two space-separated integers N and M - the number of students in sections A and B respectively.
The second line of each test case contains N space-separated integers A1, A2, …, AN - the grades of students of section A.
The third line of each test case contains M space-separated integers B1, B2, …, BM - the grades of students of section B.

Output Format
For each test case, print M strings on a new line. Print ‘YES’ if there is at least 1 person in the room with the same IQ. Otherwise, print ‘NO’. (without the quotes)

Constraints
1≤ T ≤ 10
1≤ N, M ≤ 105
1≤ Ai , Bi ≤ 1012

Sample Input 1
2
3 5
2 5 4
7 4 1 4 5
4 4
1 1 8 2
8 3 3 5
Sample Output 1
NO
YES
NO
YES
YES
YES
NO
YES
NO

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long




void solve(){
    int n ,m ;
    cin>>n>>m;
    set<int> st;
    int arr[m];

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }

    for(int i =0 ;i<m;i++){
        int x;
        cin>>x;
        if(st.find(x) != st.end()){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<endl;
        }
        st.insert(x);
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