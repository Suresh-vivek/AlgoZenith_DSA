#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;
bool is_cyle = 0;
vector<int> parent;

vector<int> any_cycle;
vector<int> cntcycle;

 
vector<int> prefixorder;


void dfs(int node , int par ){
    col[node] =2;
    parent[node] = par;


    for(auto v: g[node]){

        if(col[v]==1){

            //node -v is a forward edge
            dfs(v , node);
        }
        else if(col[v]==2){
            // node -v is a back edge
            // we found a cycle 

            if(is_cyle ==0){
                int temp = node;
                while(temp !=v){
                    any_cycle.push_back(temp);
                    temp = parent[temp];
                }
                any_cycle.push_back(temp);
                reverse(any_cycle.begin() , any_cycle.end());

            }
            cntcycle[node]++;
            cntcycle[parent[v]]--;

            is_cyle = true;



        }
        else if(col[v]==3){
            // node -v is a cross edge
            
        }

    }
    col[node] =3;
    prefixorder.push_back(node);
    
}
int main(){

    int n, m;

    cin>>n>>m;
    g.resize(n+1);
    col.resize(n+1 ,1);
    parent.resize(n+1 ,0);
    cntcycle.resize(n+1,0);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        g[x].push_back(y);
    }

   for(int i=1;i<=n ;i++){
    if(col[i]==1){
        dfs(i ,0);
    }
   }

   // print any cycle
   for(auto v: any_cycle){
    cout<<v<<" ";
   }
   for(auto v:prefixorder){
    cntcycle[parent[v]] += cntcycle[v];

   }
   int cntnode=0;

   for(int i=1;i<=n;i++){
    if(cntcycle[i] >0){
        cntnode++;
    }
   }
   cout<<cntnode<<endl;


    
}