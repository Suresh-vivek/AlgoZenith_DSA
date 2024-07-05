/*
Description
You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases.
Your task is to find out the number of ways to add such edge.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such edge, described in the statement.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 4
1 2
2 3
1 3
4 5
Sample Output 1
6
Sample Input 2
4 3
1 2
2 3
3 4
Sample Output 2
0

*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int> > g;
vector<int> visited;

int num_node;

void dfs(int node){
    if(visited[node])
    return;

    visited[node] =1;
    num_node++;

    for(auto v : g[node]){
        if(!visited[v]){
            dfs(v);
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

   

    vector<int> comp_sizes;

    for(int i =1 ; i<=n ;i++){
        if(!visited[i]){
            num_node =0;
            dfs(i);
            comp_sizes.push_back(num_node);
        }
    }

   long long  int ans =0 , sum =0;

    for(int i =0 ;i <comp_sizes.size() ;i++){

        ans += sum * comp_sizes[i];
        sum +=comp_sizes[i];

    }

    cout<<ans<<"\n";

}

int main(){

     ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}