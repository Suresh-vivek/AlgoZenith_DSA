#include<bits/stdc++.h>
using namespace std;


/// LEETCODE 785

vector<vector<int> > g;
vector<int> visited;

bool is_bipartite = true;
void dfs(int node , int col ){
    visited[node] =col;
  

    for(auto v : g[node]){
        if(!visited[v]){
            dfs(v , 3-col);
        }
        else if(visited[v] == visited[node]){
            is_bipartite = false;
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

     
     for(int i =1 ; i<=n ;i++){
        if(!visited[i]){
            dfs(i ,1);
        }
     }

      cout<<is_bipartite<<endl;
 


 
}

int main(){

    solve();
}