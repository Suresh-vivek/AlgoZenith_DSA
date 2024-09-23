   #include<bits/stdc++.h>
using namespace std;

// no of diameters
vector<int> g[2001000];
int dep[200100];
int par[200100];

int D;
int cnt =0;
void dfs (int node , int parent , int depth){
        dep[node]= depth;
        par[node] = parent;
       
    
        for(auto v: g[node]){
                if(v!=parent){
                        
                        
                        dfs(v, node , depth+1);
                        

                }
        }
      
}
void dfs2 (int node  , int parent ,int depth){
        dep[node]= depth;
     
        par[node] = parent;
      
        if(dep[node] == D) cnt++;
        // cout<<"count "<<cnt<<endl;
    
        for(auto v: g[node]){
                if(v!=parent){
                    // cout<<"v "<<v<<endl;
                        
                        
                        dfs2(v, node , depth+1);
                        

                }
        }
      
}
void solve(){
        int n;
        cin>>n;

        for(int i=0;i<n-1;i++){
                int a ,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }
        dfs(1,0,0);
        int maxch = 1;
        for(int j=2;j<=n ;j++){
                if(dep[j] > dep[maxch]){
                        maxch=j;
                }
        }
        dfs(maxch , 0 ,0);
        int maxch2 =1;
        for(int j=2;j<=n ;j++){
                if(dep[j] > dep[maxch2]){
                        maxch2=j;
                }
        }
        // cout<<dep[maxch2];


        // The diameter of the tree is D = dep[maxch2]
        int dia = dep[maxch2];
        int d;
        int centre;
        pair<int , int> centres ;
        bool one;
        int d2;
        // cout<<"Diameter "<<dia<<endl;
        if(dia%2==0){
                d = dia/2;
                d2=d;
                 while(d!=0){
                maxch2 = par[maxch2];
                d--;
        }
        centre = maxch2;
        one = true;
        }else{
                d = (dia-1)/2;
                d2=d;
                  while(d!=0){
                maxch2 = par[maxch2];
                d--;
        }
        centres.first = maxch2;
        centres.second = par[maxch2];
        one = false;
        }
       vector<int> points;
 

       if(one){
        D= d2-1;
        
        
       
       for(auto v: g[centre]){
        // cout<<"V "<<v<<endl;
        dfs2(v , centre , 0);
        points.push_back(cnt);
       // cout<<cnt<<endl;
        cnt=0;


       }
        long long sum =0;
        int n= points.size();

        for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sum += points[i] * points[j];
        }
    }

        cout << sum<<endl;



       }
       else{
        D=d2;
       // cout<<D<<endl;
        //cout<<centres.first <<" "<<centres.second<<endl;
        int a ,b;
         dfs2(centres.first , centres.second ,0);
        //  cout<<cnt<<endl;

         a = cnt;
         //cout<<a<<endl;
         cnt =0;
         dfs2(centres.second , centres.first , 0);
         b = cnt;
         //out<<b<<endl;
         cnt =0;

         long long sum = a*b;
         cout<<sum<<endl;




       }
        

        

       

     



}
signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        solve();
} 