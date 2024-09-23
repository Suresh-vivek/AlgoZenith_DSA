#include<bits/stdc++.h>
using namespace std;


vector<int> g[1001000];
int dep[100100];
int par[100100];

int subtreeSize[100100];



void dfs (int node , int parent , int depth){
        dep[node]= depth;
        par[node] = parent;
       
        subtreeSize[node] =1; // set this  value as if it is single node
        
        for(auto v: g[node]){
                if(v!=parent){
                       
                        
                        dfs(v, node , depth+1);
                        subtreeSize[node] += subtreeSize[v];

                }
        }
       

}
void solve(){
        int n;
        cin>>n;

        for(int i=0;i<n-1;i++){
                int a ,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        dfs(1,0,0);

        // count sum of distances
        int sum =0 ;
        for(int v =1 ;v<=n;v++){
                sum += subtreeSize[v] *(n-subtreeSize[v]);
        }
        cout<<sum<<endl;





}
signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();
}