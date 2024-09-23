#include <bits/stdc++.h>
using namespace std;



class Heart{

        public:

        Heart(string person_name) :person_name_(person_name){
                cout<<"Heart"<<endl;
        }
        void beats();
        ~Heart(){
                cout<<"~Heart of "<< person_name_ <<endl;
        }

        private:
        string person_name_;
};

class Person{
        public :

        Person(string person_name ) :heart_(person_name){

                cout<<"Person"<<endl;
        }

        void walk();
        void Breathe();
        ~Person(){
                cout<<"~Person"<<endl;
        }

        private:
        Heart heart_;
};

int main(){
        Person person("Vivek");
        Person person2("Vinay");
        
        }