#include <bits/stdc++.h>
using namespace std;


int main(){

        int a =10;
        int *b = &a;
        cout<<a<<" "<<*b<<"\n";

        int &c = a;
        cout<<a<<" "<<c<<"\n";

        int d=a;
        cout<<a<<" "<<d<<"\n";
        a=14;

        cout<<a<<" "<<c<<" "<<d<<"\n";
}