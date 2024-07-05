#include<bits/stdc++.h>
using namespace std;

int n,x;
int arr[1001];

int dp[1010][1010];
int rec(int i , int sum_taken){
    //pruning
    if(sum_taken>x){
        return 0;
    }

    //basechaeck
    if(i==n){
        if(sum_taken==x){
            return 1;
        }
        return 0;
    }

    //cache check
    if(dp[i][sum_taken]!=-1){
        return dp[i][sum_taken];
    }


    // transition
    int ans = 0;
    if(rec(i+1, sum_taken + arr[i]))
    ans=1;

    if(rec(i+1, sum_taken))
    ans=1;

    //save and return
    dp[i][sum_taken] = ans;

    return ans;

}

int main(){

    cin>>n;
    for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

cin>>x;

memset(dp , -1 , sizeof(dp));

cout<<rec(0,0);


}