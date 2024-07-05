#include<bits/stdc++.h>
using namespace std;

using ii =  pair<int ,int>;
#define F first 
#define S second
#define INF 1e9


int n,m ;
string arr[1000];
/*
5 5
S#...
##.#.
...#.
####.
.F...
*/
int dx[] = {0, 1 ,0, -1};
int dy[] = {1 ,0,-1,0};

using state = ii;
int dist[1001][1001];

bool check_inside(int x , int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs01(state st ){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j] = INF;
        }
    }
    deque<state> dq;

    dq.push_front(st);
    dist[st.F][st.S] =0;

    while(!dq.empty()){
        state cur = dq.front();
        dq.pop_front();


        for(int dir =0 ;dir<4;dir++){
            int nx = cur.F + dx[dir];
            int ny = cur.S + dy[dir];

            if(check_inside(nx , ny)){
                if(arr[nx][ny] =='#'){
                    if(dist[nx][ny] > dist[cur.F][cur.S] +1){
                        dist[nx][ny] = dist[cur.F][cur.S] +1;
                        dq.push_back({nx, ny});
                    }
                  

                }
                else{
                     if(dist[nx][ny] > dist[cur.F][cur.S] ){
                        dist[nx][ny] = dist[cur.F][cur.S] ;
                        dq.push_front({nx, ny});
                    }

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


    bfs01(st);
    cout<<dist[en.F][en.S]<<endl;



}