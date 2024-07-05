#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indeg(numCourses ,0) ,topo;

        for(auto it :prerequisites ){
            g[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }

        queue<int> q;
        for(int i=0 ;i < numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            topo.push_back(cur);


            for(auto v: g[cur]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }

        if(topo.size()==numCourses){
            return true;
        }
        else{
            return false;
        }

        
    }
};