#include<bits/stdc++.h>
using namespace std;

using ii =  pair<int ,int>;
#define F first 
#define S second
#define INF 1e9


int n,m ,k;
string arr[1000];
/*
5 5
S#...
##.#.
...#.
####.
.F...
1
*/
int dx[] = {0, 1 ,0, -1};
int dy[] = {1 ,0,-1,0};

using state = pair<ii , int>;
int dist[1001][1001][11];

bool check_inside(int x , int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs01(state st ){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           for(int z =0 ; z<=k ;z++){
            dist[i][j][z] = INF;
           }
        }
    }
    queue<state> dq;

    dq.push(st);
    dist[st.F.F][st.F.S][st.S] =0;

    while(!dq.empty()){
        state cur = dq.front();
        dq.pop();


        for(int dir =0 ;dir<4;dir++){
            int nx = cur.F.F + dx[dir];
            int ny = cur.F.S + dy[dir];
            

            



            if(check_inside(nx , ny)){
                int nwall = cur.S + (arr[nx][ny] =='#' ? 1 :0);
                if(nwall>k) continue;

                if(dist[nx][ny][nwall] > dist[cur.F.F][cur.F.S][cur.S] +1){
                    dist[nx][ny][nwall] = dist[cur.F.F][cur.F.S][cur.S] +1;
                    dq.push({{nx, ny},nwall});
                }

                

                
            }
        }
    }




}

int main(){

    cin>>n>>m;
    ii st ,en;

    for(int i =0 ;i <n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S'){
                st = {i, j};
            }else if(arr[i][j]=='F'){
                en = {i ,j}; 
            }
        }
    }

    cin>>k;


    bfs01({st,0});
    // cout<<dist[en.F][en.S]<<endl;
    int ans = INF;

    for(int i =0 ;i<=k;i++){
        ans = min(ans, dist[en.F][en.S][i]);
    }
    cout<<ans<<endl;



}