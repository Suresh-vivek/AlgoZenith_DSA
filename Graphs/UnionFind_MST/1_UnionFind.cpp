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