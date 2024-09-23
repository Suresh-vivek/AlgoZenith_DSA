#include <bits/stdc++.h>
using namespace std;

class A {

        public :
        A(int a_public , int a_private , int a_protected): a_public_(a_public) ,a_private_(a_private) , a_protected_(a_protected){
                cout<<"Constructor A is called"<<"\n";
        }
        ~A(){
                cout<<"Destructor A is called"<<"\n";
        }
        int a_public_;
        void printA(){
                cout<<a_public_<<" "<<a_private_ <<" "<<a_protected_<<"\n";
        }

        private:
        int a_private_;

        protected:
        int a_protected_;
};

class B : public A {

        public:
        B(int a , int b , int c) : A(a,b,c){
                cout<<"Constructor B is called"<<"\n";
        }
        ~B(){
                cout<<"Destructor B is called"<<"\n";
        }
        void printB(){
                
        }


};


int main(){

        B obj(3,4,5);
        obj.printB();

}