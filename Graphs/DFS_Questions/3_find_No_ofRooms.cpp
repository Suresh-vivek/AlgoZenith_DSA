/*
Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input Format
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).

Output Format
Print one integer: the number of rooms.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 1
3

*/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using state = pair<int , int>;

int n , m;
int dx[] ={1 , 0 , -1 ,0};
int dy[] = {0 , 1 , 0 ,-1};

vector<string> arr;

bool visited[1000][1000];

bool is_valid(int x , int y){
    if(x<0 || x>=n || y<0 || y>=m ){
        return 0;
    }
    else{
        return 1;
    }
}

void dfs(state k){
    int x = k.F , y = k.S;

    visited[x][y] = true;
    for(int i =0 ; i<4 ; i++){
        if(is_valid(x+dx[i] , y+ dy[i]) && arr[x + dx[i]][y+ dy[i]]=='.'){
            if(!visited[x+dx[i]][y+dy[i]]){
                dfs({x + dx[i] , y+ dy[i]});
            }
        }
    }
}

signed main(){

     ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    arr.resize(n + 1);

    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }

    for(int i = 0 ; i<n ;i++){
        for(int j =0 ;j<m ;j++){
            visited[i][j] = false;
        }
    }

    int ans =0;

    for(int i =0 ;i<n ;i++){
        for(int j =0 ; j<m;j++){
            if(!visited[i][j] && arr[i][j] =='.'){
                dfs({i,j});
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}