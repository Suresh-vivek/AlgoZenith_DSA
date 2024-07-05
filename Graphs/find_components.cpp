#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > g;
vector<int> visited;
void dfs(int node){
    visited[node] =1;

    for(auto v : g[node]){
        if(!visited[v]){
            dfs(v);
        }
    }
    // Time complexity - O(n+m)
}

void solve(){
    int n ,m ;

    cin>> n>> m;
    g.resize(n+1);
    visited.resize(n+1); 
    for(int i =0 ;i<m ;i++){
        int a , b;
        cin>>a>>b;
        g[a].push_back(b);
        // if undirected graph
        g[b].push_back(a);
    }

    int num_comp =0;

    for(int i =1; i<=n ;i++){
        if(!visited[i]){
            dfs(i);
            num_comp++;
            cout<<i<<" "<<num_comp<<endl;
        }
    }
    // Time complexity - O(n+m)

 
}

int main(){

    solve();
}