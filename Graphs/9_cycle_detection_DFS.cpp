 #include<bits/stdc++.h>
using namespace std;


vector<vector<int> > g;
vector<int> visited;
bool is_cycle = false;
void dfs(int node ,int par){
    visited[node] =1;

    for(auto v : g[node]){
        if(!visited[v]){
            dfs(v , node);
        }
        else if(v!=par){
            is_cycle = true;

        }
    }
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

    for(int i =1 ;i <=n;i++){
        if(!visited[i]){
            dfs(i , 0);
        }
    }

    cout<<is_cycle <<endl;
}