#include<bits/stdc++.h>
using namespace std;


vector<int> g[1001000];

int ans[100100];
int val[100100];

void dfs(int node, int par , int maxVal , int minVal){
        ans[node] = max(abs(maxVal - val[node]) , abs(minVal - val[node]));
        for(auto v: g[node]){
                if(v!=par){
                        dfs(v, node , max(maxVal, val[node]) , min(minVal , val[node]));
                }
        }
}

void solve(){            
        int n;
        cin>>n;

        for(int i=0;i<n-1;i++){
                int a ,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        int root;
        cin>>root;
        
        dfs(root , 0 , -1e9 , 1e9);

}


signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();
}