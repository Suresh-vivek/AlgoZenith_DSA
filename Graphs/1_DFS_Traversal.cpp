/*
Problem statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and 'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal.

V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 

E is the number of edges present in graph G.
Note :
The Graph may not be connected i.e there may exist multiple components in a graph.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 10^3
1 <= E <= (5 * (10^3))

Time Limit: 1sec
Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 4
Explanation For Sample Input 1:
If we do a DFS traversal from vertex 0 we will get a component with vertices [0, 2, 1]. If we do a DFS traversal from 3 we will get another component with vertices [3, 4]

Hence,  we have two disconnected components so on the first line, print 2. Now, print each component in increasing order. On the first line print 0 1 2 and on the second line, print 3 4.

[0 1 2] comes before [3 4] as the first vertex 0 from the first component is smaller than the first vertex 3 from the second component.
Sample Input 2:
9 7
0 1
0 2
0 5
3 6
7 4
4 8
7 8
Sample Output 2:
3
0 1 2 5
3 6
4 7 8

*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int node , vector<int> &visited , vector<vector<int>> &adj , vector<int> &temp ){
    visited[node] =1;
    temp.push_back(node);

    for(auto v : adj[node]){
        if(!visited[v]){
            dfs(v , visited , adj , temp);
        }
        

    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{

    vector<vector<int>> adj(V);
    for(int i = 0 ;i < E ; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);

    }

    vector<int> visited(V+1);
    vector<vector<int>> ans;

    for(int i =0 ;i< V ; i++){
        

        if(!visited[i]){
            vector<int> temp;
            dfs(i ,visited , adj , temp);
             sort(temp.begin(), temp.end());
            ans.push_back(temp);

        }


    }
    return ans;

}