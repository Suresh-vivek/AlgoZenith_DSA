/*
Description
Given an array A of N positive integers, find the maximum of bitwise ANDs of all subsequences of A with length equal to X.

Input Format
The first line of the input contains a single integer T denoting the number of test cases, (1<=T<=100).

The first line of each test case contains two space-separated integer N, X, (2<=N<=100000), (1<=X<=N).

The second line contains N space-separated integers A1,A2,…,AN, (1<=Ai<=10^9).

 

Sum of N over all test cases does not exceed 10^6.

Output Format
For each test case print the maximum of bitwise ANDs of all subsequences of A with length equal to X.

Constraints
Sample Input 1
6
5 2
1 2 3 4 5
5 3
2 4 4 2 4
3 2
1 2 3
4 3
1 2 2 4
10 3
989098 987656790 989098765 234543 3456543 234567543 1234567 5678 56789 8909876
10 2
123 1234543 2345 6776 8787 8765467 234567 98765444 1234 4561
Sample Output 1
4
4
2
0
147862020
8454144

*/

#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n , x;

    cin>>n>>x;

    vector<int> arr(n);
    int a;

    for(int i =0 ;i<n;i++){
        cin>>a;
        arr.push_back(a);

    }
    int ans =0;


    for(int i=29 ;i >=0;i--){

        vector<int> elementbits;

        for(auto v: arr){
            if(v &(1LL <<i)){
                elementbits.push_back(v);

            }
        }

        if(elementbits.size() >=x){
            ans += (1LL << i);
            arr= elementbits;
        }

    }
    cout<<ans<<endl;

}
int main(){
    int t;
    cin>>t;

    while(t--){
        solve();

    }
    
}