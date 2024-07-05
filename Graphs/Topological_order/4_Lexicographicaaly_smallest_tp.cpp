#include<bits/stdc++.h>
using namespace std;

// Kahn's Algorithm

// add node with indegree 0 to the topological sort and delete it from graph , keep doing this

vector<vector<int>> g;
vector<int> indeg;

vector<int> topo;

void kahn(int n){
    priority_queue<int> q;

    for(int i =1 ; i<=n ;i++){
        if(indeg[i]==0){
            q.push(-i);
        }
    }

    while(!q.empty()){
        int cur = -q.top();
        q.pop();
        topo.push_back(cur);

        for(auto v: g[cur]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }

        }

    }


}

signed main(){

    int n,m;
    cin>>n>>m;

    g.resize(n+1);
    indeg.resize(n+1, 0);

    for(int i =0 ;i <m ;i++){
        int a , b;
        cin>>a>>b;
        g[a].push_back(b);
        // maintained indegree
        indeg[b]++;
    }
    kahn(n);

    for(auto v: topo){
        cout<<v<<" ";
    }

    


}