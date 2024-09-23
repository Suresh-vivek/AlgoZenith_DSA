   #include<bits/stdc++.h>
using namespace std;

// no of diameters
vector<int> g[2001000];
int dep[200100];
int par[200100];

int D;
int cnt =0;
void dfs (int node , int parent , int depth){
        dep[node]= depth;
        par[node] = parent;
       
    
        for(auto v: g[node]){
                if(v!=parent){
                        
                        
                        dfs(v, node , depth+1);
                        

                }
        }
      
}
void dfs2 (int node , int parent , int depth){
        dep[node]= depth;
        par[node] = parent;
        if(dep[node] == (D/2 -1)) cnt++;
    
        for(auto v: g[node]){
                if(v!=parent){
                        
                        
                        dfs(v, node , depth+1);
                        

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
        int maxch = 1;
        for(int j=2;j<=n ;j++){
                if(dep[j] > dep[maxch]){
                        maxch=j;
                }
        }
        dfs(maxch , 0 ,0);
        int maxch2 =1;
        for(int j=2;j<=n ;j++){
                if(dep[j] > dep[maxch2]){
                        maxch2=j;
                }
        }
        // cout<<dep[maxch2];


        // The diameter of the tree is D = dep[maxch2]
        int dia = dep[maxch2];
        int d;
        if(dia%2==0){
                d = dia/2;
        }else{
                cout<<-1<<endl;
                return;
        }
       
       

        // find centre 
        int centre ;

        while(d!=0){
                maxch2 = par[maxch2];
                d--;
        }

        cout<<maxch2<<endl;

     



}
signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();
} 