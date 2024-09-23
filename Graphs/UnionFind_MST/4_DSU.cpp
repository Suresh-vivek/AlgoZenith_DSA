#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;


class UnionFind{
        public:
        int *par , *rank;

        UnionFind(int n=N){
                par = new int[n+1];
                rank = new int[n+1];

                for(int i =0 ;i<=n;i++){
                        par[i] = i;
                        rank[i] =1;

                }

        }

        int find(int idx){
                int x = idx;
                while(x !=par[x]){
                        par[x] = par[par[x]];
                        x = par[x];
                }
                return x;
        }

        bool merge(int x ,int y){
                int xroot= find(x) , yroot = find(y);
                if(par[xroot] < par[yroot]){
                        swap(x,y);

                }
                if(xroot!=yroot ){
                        par[yroot] =xroot;
                        rank[xroot] += rank[yroot];
                        rank[yroot] =0;
                        return false;


                }

                return true;
        }

        bool check(int x , int y){
                return find(x) == find(y);
        }
};



signed main()
{
 

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    UnionFind W(n);

    for(int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if(!com) W.merge(x, y);
        else cout << W.check(x, y) << "\n";
    }

    return 0;
}