#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> vis;

vector<int> topo;

void dfs(int node){
    vis[node]=1;

    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v);
            }
    }
    topo.push_back(node);
}



signed main(){
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    
    for(int i= 1; i<=n;i++){
        if(!vis[i]){
            dfs(i);
    }
    }
    reverse(topo.begin(), topo.end());
    for(auto v: topo){
        cout<<v<<" ";
    } 



}