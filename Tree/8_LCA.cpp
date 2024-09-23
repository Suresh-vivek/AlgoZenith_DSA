#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>g;
vector<int> dep;
vector<vector<int>>par;

void dfs(int node , int prev , int depth){
    par[node][0] = prev;
    dep[node] = depth;

    for(int i=1;i<=20 ;i++){
       if(par[node][i-1]!=0)
        {
            par[node][i]=par[par[node][i-1]][i-1];
        }
    }

    for(auto v: g[node]){
        if(v!=prev){
            dfs(v,node , depth+1);
        }
    }
}

int lca(int u , int v){
    if(dep[u] < dep[v]){
        swap(u,v);
    }

    for(int i=20 ;i>=0;i--){

        if((dep[u] -dep[v])&(1<<i)){
            u=par[u][i];
        }
    }
    if(u==v){
        return u;
    }

    for(int i=20;i>=0;i--){
        if(par[v][i]!= par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }

    return par[v][0];
}

void solve(){
    int n;
    cin>>n;

     g.assign(n + 1, vector<int>());
    dep.assign(n + 1, 0);
    par.assign(n + 1, vector<int>(21, 0));
    

    for(int i=0;i<n-1;i++){
        int u , v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // taking queries
    dfs(1,0,0);
    int q;
    cin>>q;

    while(q--){
      int u,v,z;
        cin>>u>>v>>z;
        int x=lca(u,v),a=lca(u,z),b=lca(v,z);
        if(a == x)
           cout<<b<<endl;
        else if(b == x)
           cout<<a<<endl;
        else
           cout<<x<<endl;
    }
}








signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int t;
        cin>>t;
        while(t--){
            solve();
        }
}