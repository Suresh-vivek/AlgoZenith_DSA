#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i<n ;i++){    
     cin>>arr[i];
     }

     for(int mask = 0; mask < (1<<n) ; mask++){
        cout<<mask<<" ";
        // mask -> 2 --> 010
        for(int i=0; i<n; i++ ){
            if((mask>>i)&1){
                cout<<arr[i]<<" ";
            }



        }
        cout<<endl;
     }
   
    
}