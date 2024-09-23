#include <bits/stdc++.h>
using namespace std;



class A{

        public:
        A(int a , int b) : a_(a) , b_(b) {
                mini_ = min(a_ , b_);

        }

        void print(){
            cout<<a_<<" "<<b_<<endl;
        }



        private:
        int a_;
        int b_;
        int mini_;
};  

int main(){

    A obj(3,4);
    A obj2{5,6};
    obj.print();
    obj2.print();
}