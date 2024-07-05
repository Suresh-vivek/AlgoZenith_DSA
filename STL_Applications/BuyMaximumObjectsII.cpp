/*

Description
There are N objects, and each object has some price. The price of ith object is Ai.
You have been asked Q queries. In each query, you have been given total money M, and find the maximum number of objects that you can buy.

Input Format
The first line of each test case contains N, the number of objects, and Q, total queries.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.
Next, Q lines contain a number M, the total money.

Output Format
For each query, print a single number in a new line representing the maximum objects that you can buy.

Constraints
1 ≤ N, Q ≤ 105
1 ≤ Ai ≤ 108
1 ≤ M ≤ 108

Sample Input 1
5 4
1 4 2 9 6
1
5
10
25
Sample Output 1
1
2
3
5
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n , q ;
    cin>>n>>q;

    long long arr[n];

    for(long long i =0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr , arr+n);
    for(long long i =1;i<n;i++){
        arr[i] +=arr[i-1];
    }

    while(q--){
        long long m;
        cin>>m;

        cout<<upper_bound(arr , arr+n , m) - arr<<endl;
    }


}
