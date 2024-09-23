#include<bits/stdc++.h>
using namespace std;


struct Unionfind{

        int n , set_size , *parent , *rank;
        Unionfind(){}

        Unionfind(int a){
                n= set_size = a;
                parent = new int[n+1];
                rank = new int[n+1];

                for(int i=1 ;i <=n ;i++){
                        parent[i] =i;
                        rank[i] =1;
                }
        }

        int find(int x){
                if(x == parent[x]){
                        return x;
                }else{
                        return parent[x] = find(parent[x]);
                }
        }

        int merge(int x , int y){

                int xroot = find(x) , yroot = find(y);

                if(xroot != yroot){
                        if(rank[x] < rank[y]){
                                parent[xroot] = yroot;
                                rank[yroot] += rank[xroot];
                        }
                        else{
                                parent[yroot] = xroot;
                                rank[xroot] += rank[yroot];
                        }
                        set_size -=1;
                }
        }

        void reset(){
                set_size = n;
                for(int i =1 ; i<=n ;i++){
                        parent[i] =i;
                        rank[i] =1;
                }
        }

        int size(){
                return set_size;
        }
        
        void print(){
                for(int i =1; i<=n ;i++){
                        cout<<i <<" " <<"-> " <<parent[i] <<endl;
                }
        }
};
vector<pair<int ,int>> g[100100];
int main(){
        int n,m ;
        cin>>n>>m;

        Unionfind uf(n);
        int a , b ,c;

        //edgelist
        vector<pair<int , pair<int , int>>> edgelist;

        for(int i =0 ; i<m ;i++){
                cin>>a>>b>>c;
                edgelist.push_back({c ,{a,b}});
        }
        sort(edgelist.begin() , edgelist.end());

        int mst_cost = 0;
        int cnt_edges = 0;

        for(auto edge : edgelist){
                int x= edge.second.first;
                int y = edge.second.second;

                if(uf.find(x) != uf.find(y)){
                        mst_cost += edge.first;
                        uf.merge(x,y);
                        cnt_edges++;

                        // for final graph

                        g[x].push_back({y , edge.first});
                        g[y].push_back({x , edge.first});

                
                }
        }

        if(cnt_edges != n-1){
                cout<<"No MST posssible"<<endl;
        }else{
                 cout<<mst_cost<<endl;
        }
}