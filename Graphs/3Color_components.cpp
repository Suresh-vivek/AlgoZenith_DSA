#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > g;
vector<int> visited;

int num_node;
void dfs(int node , int col ){
    visited[node] =col;
    num_node++;

    for(auto v : g[node]){
        if(!visited[v]){
            dfs(v , col);
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
    int col = 1;
    vector<int> comp_sizes;

    for(int i =1; i<=n ;i++){
        if(!visited[i]){
            num_node =0;
            dfs(i , col);
            num_comp++;
            comp_sizes.push_back(num_node);
            col++;
            
        }
    }
    // Time complexity - O(n+m)

    for(int i =1; i<=n;i++){
        cout<<visited[i]<<endl;
    }

    cout<<"Number of components - "<<num_comp<<endl;
    // component sizes

    cout<<"Component sizes - "<<endl;
    for(auto c : comp_sizes){
        cout<<c<<" ";
    }
    cout<<endl;
    int ans = 0 ,sum =0;

    for(int i =0 ;i<comp_sizes.size();i++){
        ans += sum * comp_sizes[i];
        sum += comp_sizes[i];
    }

    cout<<ans<<endl;


 
}

int main(){

    solve();
}