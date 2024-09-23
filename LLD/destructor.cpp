#include <bits/stdc++.h>
using namespace std;


class A{
        public:
        A(int a){
                cout<<"Contructor A is called"<<"\n";
                a_=a;
        }

        ~A(){
                cout<<"Destructor A is called"<<"\n";
        }

        int GetA(){
                return a_;
        }

        private:
        int a_;
};

int main(){
        A obj(3);  
        cout<<obj.GetA()<<"\n";
}

// object created -> called constructor , if not specified then called default constructor
// object deleted -> called destructor

//cleanup action
// Delete temporary files
// Release the pointers
// Close the connection
