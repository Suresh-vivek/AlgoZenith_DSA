 #include<bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using lli = long long;
#define F first 
#define S second 

class prioritze{
    public : bool operator()(ii &p1 , ii &p2){
        return p1.S > p2.S;
    }
};

int n,m;
vector<ii> g[100100];

lli dist[100100];
int vis[100100];

void dijkstra(int sc){

    for(int i=1 ;i<=n ;i++){
        dist[i] = 1e18;
        vis[i] =0;
    }

    priority_queue<ii > pq;
    dist[sc] =0;
    pq.push({-0 ,sc});

    while(!pq.empty()){
        ii fs = pq.top();
        pq.pop();

        if(vis[fs.S]) continue;
        vis[fs.S]=1;

        for(auto v: g[fs.S]){
            int neigh = v.S;
            int wt = v.F;

            if(dist[neigh] > dist[fs.S] + wt){
                dist[neigh] = dist[fs.S] + wt;
                pq.push({-dist[neigh] , neigh});

            }



            
    }
    }

}

void solve(){

    cin>>n>>m;
    for(int i=0 ;i<m ;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dijkstra(1);
    for(int i=1 ;i<=n ;i++){
        cout<<dist[i]<<" ";
    }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}