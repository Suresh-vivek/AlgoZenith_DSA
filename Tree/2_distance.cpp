  #include<bits/stdc++.h>
using namespace std;


vector<int> g[1001000];
int dep[100100];
int par[100100];
bool isLeaf[100100];
int subtreeSize[100100];
int numChild[100100];

// given two nodes u and v find the distance between them and path from u to v  


void dfs (int node , int parent , int depth){
        dep[node]= depth;
        par[node] = parent;
        numChild[node] =0;
        subtreeSize[node] =1; // set this  value as if it is single node
        
        for(auto v: g[node]){
                if(v!=parent){
                        numChild[node]++;
                        
                        dfs(v, node , depth+1);
                        subtreeSize[node] += subtreeSize[v];

                }
        }
        if(numChild[node] ==0){
                isLeaf[node] =1;

        }

}
void solve(){
        int n;
        cin>>n;

        for (int i = 1; i <= n; i++) {
        g[i].clear();
        dep[i] = 0;
        par[i] = 0;
        isLeaf[i] = false;
        subtreeSize[i] = 0;
        numChild[i] = 0;
    }

        for(int i=0;i<n-1;i++){
                int a ,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }

        int u , v;
        cin>>u>>v;
        dfs(u,0,0);

        //  distance between u and v
        int dist = dep[v];

        // path from u to v
        vector<int> path;
        while(v!=u){
                path.push_back(v);
                v = par[v];
        }

        path.push_back(u);
        reverse(path.begin(),path.end());

        // distance between u and v
        cout<<dist<<endl;

        // path from u to v
        for(auto v : path){
                cout<<v<<" ";
        }
        cout<<endl;





}
signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();
}