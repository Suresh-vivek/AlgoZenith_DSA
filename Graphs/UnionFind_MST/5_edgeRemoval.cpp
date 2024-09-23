#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


class UnionFind{
        public:
        int *par , *rank;
        int cnt=0;

        UnionFind(int n=N){
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


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n , m , q;
    cin>>n>>m >>q;

    bool marked[m+1];
    memset(marked , false , sizeof(marked));

    pair<int , int> query[q];
    pair<int,int> edges[m+1];

    for(int i=1 ; i<=m;i++){
        int u , v;
        cin>>u>>v;
        edges[i] = {u,v};
    }
    

    // taking queries

    for(int i =0 ; i<q ;i++){
        int t; cin>>t;

        if(t==2)
            query[i]= {2 ,-1};
        else{
            int x;
            cin>>x;
            query[i] = {1 ,x};
            marked[x] = true;

        }
    }
    
    UnionFind uf(n);

    // initila graph 

    for(int i=1; i<=m ;i++){
        if(!marked[i]){
            int u = edges[i].first;
            int v = edges[i].second;
            uf.merge(u ,v);
        }
    }

    vector<int> ans;

    for(int i = q-1 ; i>=0 ; i--){
        // count query
        if(query[i].first ==2){
            ans.push_back(uf.cnt);

        }
        //add edge
        else{
            int u = query[i].second;
            uf.merge(edges[u].first , edges[u].second);

        }
    }
    reverse(ans.begin() , ans.end());
    for(int u:ans){
        cout<<u<<"\n";
        
    }

    return 0;


}

