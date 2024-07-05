/*
Description
You have been given a tree with N nodes and N - 1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour. 
Your task is to find the minimum number of colours required to accomplished this. 

Input Format
The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.

Output Format
Print the minimum number of colours require.

Constraints
1 ≤ N ≤ 105

Sample Input 1
4
1 2
4 3
2 3
Sample Output 1
3

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> degree;
vector<vector<int>> g;


void calc_degree(int node){
    int num_degree = 0;

    for(auto v : g[node]){
        num_degree++;
    }
    degree.push_back(num_degree);
}

signed main(){
     ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>> n;
    g.resize(n+1);

    for(int i = 0 ; i< n-1 ;i++){
        int x, y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    for(int i=1 ;i<=n;i++){
        calc_degree(i);
    }

    cout<<*max_element(degree.begin() , degree.end()) +1 <<endl;



    
}