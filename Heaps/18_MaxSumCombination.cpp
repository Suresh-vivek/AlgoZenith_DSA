/*

*/


#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {

        // sorting the vectors
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());


        // create a max heap
        priority_queue<pair<int , pair<int , int>>> maxh;

        // create a set to check indices

        set<pair<int , int>> visited;

        maxh.push({A[0] + B[0] , {0 , 0}});

        visited.insert({0,0});
        vector<int> ans;

        for(int i =0 ;i <C ;i++){

                auto top = maxh.top();
                maxh.pop();

                ans.push_back(top.first);
                
                // x and y indices
                int x = top.second.first;
                int y = top.second.second;

                // checking for x+1, y

                if(x+1 <A.size() && visited.find({x+1 , y}) == visited.end()){
                        maxh.push({A[x+1] + B[y] , {x+1 , y}});
                        visited.insert({x+1 , y});
                }


                // checking for  x , y+1

                if(y+1 < B.size() && visited.find({x, y+1}) == visited.end()){
                        maxh.push({A[x] + B[y+1] , {x , y+1}});
                        visited.insert({x , y+1});
                }




        }
        

       return ans;

}
