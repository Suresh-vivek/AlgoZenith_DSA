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
class Home{

        public:
        Home(string address) : address_(address){
                
        }
        ~Home(){
            cout<<" ~Home of address "<< address_ <<endl;  
        }



        string address_;
};
class Person{
        public :

        Person(string person_name , Home *home ) :heart_(person_name) ,
         home_(home),
         person_name_(person_name){

                cout<<"Person "<<person_name_ <<endl;
        }

        void walk();
        void Breathe();
        ~Person(){
                cout<<"~Person"<<endl;
        }

        string GetAddress(){
                return home_->address_;
        }

        private:
        Heart heart_; // composition

        Home *home_; // Aggregation
        string person_name_;
};

// void Logic()


int main(){
        Home home("Sonipat");
        Person *person1  = new Person("A" , &home);
        Person *person2  = new Person("B" , &home);

        delete person1;

        cout<<person2->GetAddress() <<endl;

        delete person2;

  

        
        
        
  }