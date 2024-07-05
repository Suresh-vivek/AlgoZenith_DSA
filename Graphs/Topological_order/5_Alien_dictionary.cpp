#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V , vector<int> adj[]){
        int indeg[V] = {0};
        
        for(int i =0 ;i <V ;i++){
           for(auto it : adj[i]){
               indeg[it]++;
           }
        }
        
        queue<int> q;
        for(int i =0 ;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            topo.push_back(cur);
            
            for(auto v : adj[cur]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return topo;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        for(int i= 0; i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            // compare 
            int len = min(s1.size() , s2.size());
            
            for(int ptr =0 ; ptr < len ;ptr++){
                if(s1[ptr] !=  s2[ptr]){
                    adj[s1[ptr] -'a'].push_back(s2[ptr]-'a');
                    break;
                }
                
            }
        }
        
        vector<int> topo = topoSort(K , adj);
        string ans ="";
        for(auto it : topo){
            ans = ans+ char(it + 'a');
            
        }
        
        return ans;
        
    }