#include <bits/stdc++.h>
using namespace std;

string getbitstr(int x){
    string curr="";
    while(x){
        if(x%2){
            curr+='1';
        }
        else{
            curr+='0';
        }
        x=x/2;
    }
    reverse(curr.begin(),curr.end());
    return curr;
}
int main(){

    string s="";
    int cnt =0;
    int curr_num =0;

    while(cnt<=10){
        string cur_bits = getbitstr(curr_num);
        int new_one = 0;
        for(auto v: cur_bits){
            if(v=='1'){
                new_one++;
            }
        }
        s+=cur_bits;
        cnt += new_one;
        curr_num++;

    }
    cout<<s<<endl;
}