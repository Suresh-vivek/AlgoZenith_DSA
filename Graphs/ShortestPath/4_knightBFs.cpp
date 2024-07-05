#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second


int n,m ,x,y,a,b;
// shortest distance bw x,y and a,b

bool check(int i , int j){
    return i>=0 && i<n && j>=0 && j<m;
}
int dx[] = {1 ,2 ,2,1 ,-1 , -2 , -2, -1};
int dy[] = {2 ,1 , -1 , -2 , -2 , -1 , 1 , 2};

int dis[1010][1010];

using state = pair<int ,int>;

int bfs(int stx , int sty){
    for(int i=1;i<=n;i++){
        for(int j=1; j<=m ;j++){
            dis[i][j] = 1e9;
        }

    }

    queue<state> q;
    q.push({stx ,sty});
    dis[stx][sty] = 0;

    while(!q.empty()){
        state cur = q.front();
        q.pop();

        for(int k=0 ;k<8 ;k++){
            int nx = cur.F + dx[k];
            int ny = cur.S + dy[k];

            if(check(nx ,ny)){
                if(dis[nx][ny] > dis[cur.F][cur.S] +1){
                    dis[nx][ny] = dis[cur.F][cur.S] +1;
                    q.push({nx ,ny});
                }
            }





        }
        
    }



}

void solve (){
    cin>>n>>m>>x>>y>>a>>b;
    bfs(x ,y);
    for(int i=1 ;i <=n ;i++){
        for(int j=1;j <=m ;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    solve();
}

// Time Complexity : O(N*M)