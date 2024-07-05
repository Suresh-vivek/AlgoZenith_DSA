#include<bits/stdc++.h>
using namespace std;


vector<int> sp;
vector<int> prime_factors(int x){
    vector<int> ans;

    while(x>1){
        ans.push_back(sp[x]);
        x = x/sp[x];
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the max range "<<endl;
    cin>>n;
    sp.resize(n+1);

   

    for(int i=2;i<=n;i++){
        sp[i] =i;
    }

    for(int i=2;i<=n;i++){
        if(sp[i]==i){
            for(int j=2*i ; j<=n ;j+=i){
                sp[j]=i;
            }
        }
    }

    cout<<"Enter the number "<<endl;
    int x ;
    cin>>x;
    vector<int> ans = prime_factors(x);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}