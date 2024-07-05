/*

S . # . . .
. . # . . .
# . # . # .
. . . . # .
# # # # . .
F . . . . .

*/

// find shortest distance from S to F in a matrix and also the path
// time complexity  -> O(n*m)
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
using state = pair<int, int>;
int n ,m ;
const int INF = 100;
vector<vector<char> > arr;

vector<vector<int>> dis;
vector<vector<state>> par;
//which cell is valid
bool is_valid(int x , int y){
    if(x>=0 && x<n && y>= 0 && y<m && arr[x][y]!='#'){
        return 1;
    }
    return 0;
}

int dx[] = {0 ,1 ,0, -1};
int dy[] ={1 ,0,-1,0};
vector<state> neighbours(state node){
    vector<state> neighs;
    for(int k =0 ; k<4 ;k++){
        int x  = node.F + dx[k];
        int y = node.S + dy[k];
        if(is_valid(x,y)){
            neighs.push_back({x,y});
        }

    }
    
    return neighs;
     


}
void bfs(state st_node){
    
    dis.resize(n , vector<int> (m ,INF));

    par.assign(n ,vector<state> (m ,{-1 ,-1}));

    queue<state> q;
    dis[st_node.F][st_node.S] =0 ;
   
    par[st_node.F][st_node.S] = {-1,-1};


    q.push(st_node);

    while(!q.empty()){
        state node = q.front();

        q.pop();

        for(state v :neighbours(node) ){
            if(dis[v.F][v.S] ==INF){
           
                dis[v.F][v.S] = dis[node.F][node.S] +1;
                par[v.F][v.S] = node;
                q.push(v);

            }

        }
    }





}

int main(){

    cin>>n>>m;
    arr.resize(n);
    state st , en;
    for(int i =0 ; i<n;i++){
        arr[i].resize(m);
        for(int j =0 ;j<m ;j++){
           cin>>arr[i][j];
           if(arr[i][j]=='S'){
            st = {i, j};
           }else if(arr[i][j] =='F'){
            en = {i ,j}; 
           }
        }
    }

    bfs(st);

    for(int i =0 ;i< n;i++){
        for(int j =0 ;j<m ;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    
    if(dis[en.F][en.S] == INF){
        cout<<"Finish is not reachable \n ";
    }
    else{
        cout<<dis[en.F][en.S]<<endl;
        state cur = en;
        vector<state> path;
        
        while(cur != make_pair(-1,-1)){
            path.push_back(cur);
            cur = par[cur.F][cur.S];

        }
        reverse(path.begin() , path.end());
        for(auto v: path){
            cout<<v.F <<" "<<v.S<<"\n";
        }
    }


}