#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > g;
vector<int> visited;

void bfs(int src_node){
    queue<int> q;
    visited[src_node] =1;
    q.push(src_node);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto v: g[node]){
            if(!visited[v]){
                visited[v] =1;
                q.push(v);
            }
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
    bfs(1);

    for(int  i=1 ;i<= n ; i++){
        cout<<i<<" "<<visited[i]<<endl;
    }
    cout<<endl;

  

 
}

int main(){

    solve();
}