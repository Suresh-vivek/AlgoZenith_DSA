/*

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define LD long double
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	

class UnionFind{
        public:
        int *par , *rank;
        int cnt=0;

        UnionFind(int n){
                par = new int[n+1];
                rank = new int[n+1];

                for(int i =0 ;i<=n;i++){
                        par[i] = i;
                        rank[i] =1;

                }
                cnt =n;

        }

        int find(int idx){
                int x = idx;
                while(x !=par[x]){
                        par[x] = par[par[x]];
                        x = par[x];
                }
                return x;
        }

        bool merge(int x ,int y){
                int xroot= find(x) , yroot = find(y);
                if(par[xroot] < par[yroot]){
                        swap(x,y);

                }
                if(xroot!=yroot ){
                    cnt--;
                        par[yroot] =xroot;
                        rank[xroot] += rank[yroot];
                        rank[yroot] =0;
                        return false;


                }

                return true;
        }

        bool check(int x , int y){
                return find(x) == find(y);
        }
};
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
         vector<pair<int, pair<int, int>>> edgelist;
    UnionFind uf(V);

    // Build the edge list from the adjacency list
    for (int i = 0; i < V; i++) {
        for (auto &edge : adj[i]) {
            int u = i;
            int v = edge[0];
            int weight = edge[1];
            edgelist.push_back({weight, {u, v}});
        }
    }

    // Sort the edges by weight
    sort(edgelist.begin(), edgelist.end());

    int mst_weight = 0;

    // Kruskal's algorithm
    for (auto &edge : edgelist) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (uf.find(u) != uf.find(v)) {
            mst_weight += weight;
            uf.merge(u, v);
        }
    }

    return mst_weight;
    }
};