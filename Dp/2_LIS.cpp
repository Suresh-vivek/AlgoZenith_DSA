#include<bits/stdc++.h>
using namespace std;

int n,x;
int arr[1001];

int dp[1010];
int rec(int i ){
    //pruning
    if(i<0){
        return 0;
    }
   

    //basechaeck
   

    //cache check
    if(dp[i]!=-1){
        return dp[i];
    }
    


    // transition
    int ans =1;
    for(int j=i-1 ; j>=0 ; j--){
        if(arr[j]<arr[i]){
            ans = max(ans , 1+ dp[j]);
        }
    }
   

    //save and return
    return dp[i] = ans;
   

  

}

int main(){

    cin>>n;
    for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

memset(dp , -1 , sizeof(dp));

   int ans =0;

   for(int i=0;i<n;i++){
    ans = max(ans , rec(i));
   }
  cout<<ans<<endl;






}