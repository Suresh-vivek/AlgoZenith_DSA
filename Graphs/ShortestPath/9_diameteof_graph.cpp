 #include<bits/stdc++.h>
using namespace std;

int dist[404][404];
int par[404][404];

// void printpath(int i ,int j){
//     if(i!=j)printpath(i, par[i][j]);
//     cout<<j<<" "; 
// }
// find diameter of a graph - longest shortest path between any i and j

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           dist[i][j]=1e9;
        }

    }

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                dist[i][j] = min(dist[i][j] , (dist[i][k] + dist[k][j]));

            }
        }
    }
    
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j]!=1e9 && i!=j)ans = max(ans, dist[i][j]);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         par[i][j]=i;
    //     }
    // }


    // for(int k=0;k<n;k++){
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //            if(dist[i][j] > dist[i][k] + dist[k][j]){
    //             dist[i][j] = dist[i][k] + dist[k][j];
    //             par[i][j] = par[k][j];
    //            }
    //         }
    //     }
    // }



}

int main(){

    solve();
}