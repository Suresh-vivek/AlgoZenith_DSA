/*
Description
You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).
Input Format
The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in the statement.

Output Format
Print Q lines as the answer to the Q queries, each on a new line.

Constraints
Sample Input 1
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
Sample Output 1
3
1
NO
2
YES
*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> g;



const int N = 100010;

int sz[N], id[N];
int CUR_ID = 1;
bool visited[N];


void dfs(int cur){
    if(visited[cur]) return;

    visited[cur] = true;
    id[cur] = CUR_ID;
    sz[CUR_ID]++;

    for(auto v : g[cur]){
        dfs(v);
    }
}



void solve(){
    int n , m ,q;
    cin>>n>>m>>q;
     g.resize(n+1);
    
   
    for(int i =0 ;i < m ;i++){
        int a , b;
        cin>>a>>b;
        g[a].push_back(b);
        // if undirected graph
        g[b].push_back(a);
    }
    

    for(int i =1 ;i<= n ;i++){
        if(!visited[i]){
            dfs(i);
            CUR_ID++;
        }
    }
    

    while(q--){
        int t ;
        cin>>t;
        if(t==1){
            int x ; cin>>x;

            cout<<sz[id[x]]<<"\n";
        }
        else if(t==2){
            int x, y;
            cin >> x >> y;
            if(id[x] == id[y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}