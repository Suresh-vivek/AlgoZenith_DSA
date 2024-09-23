#include<bits/stdc++.h>
using namespace std;


set<int> bfs(int B , vector<vector<int>> & adj , int N , int A){

        vector<bool> visited(N+1 , false);
        set<int> reach ;

        queue<int> q;
        vector<int> parent (N+1 , -1);
        parent[B] = 0;

        q.push(B);
        visited[B] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto v: adj[node]){

                if(!visited[v]){
                    visited[v] = true;
                    parent[v] = node;
                    q.push(v);

                    if(v == A){
                        reach.insert(parent[v]);
                }
            }

                
          }

      
}
 return reach;
}


int  main(){
        int N,E;
        cin>>N;

        vector<int> members(N+1 );
        int maxi =0;

        for(int i =0; i< N ;i++){
                cin>>members[i];
                maxi = max(members[i] , maxi);
        }

        cin >>E;

        vector< vector<int>> adj(maxi+1);

        for(int i =0; i< E ;i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
                
        }

        int A ,B;
        cin>>A>>B;


        set<int> reach = bfs(B , adj , N , A);

        cout<< reach.size() <<endl;

        for(auto v: reach){     
                cout<<v<<" ";
        }
}