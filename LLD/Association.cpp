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
class Person;
class Home{

        public:
        Home(string address) : address_(address){
                
        }
        ~Home(){
            cout<<" ~Home of address "<< address_ <<endl;  
        }
         
         void AddPerson(Person * person){
                persons_.push_back(person);
         }


        string address_;

        private:
        vector<Person *> persons_; 
};
class Person{
        public :

        Person(string person_name ) :heart_(person_name) ,
     
         person_name_(person_name){

                cout<<"Person "<<person_name_ <<endl;
        }

        void walk();
        void Breathe();
        ~Person(){
                cout<<"~Person"<<endl;
        }
        
        void AddHome(Home *home){

                homes_.push_back(home);


        }

        private:
        Heart heart_; // composition

       vector<Home *>homes_; // Aggregation
        string person_name_;
};

// void Logic()


int main(){
        Home *home1 = new Home("Delhi");
        Home *home2 = new Home("Sonipat");
        Home *home3 = new Home("Faridabad");

        Person *person1 = new Person("A");
        Person *person2 = new Person("B");

        person1->AddHome(home1);
        home1->AddPerson(person1);

        person1->AddHome(home2);
        home2->AddPerson(person1);

        person2->AddHome(home2);
        home2->AddPerson(person2);

        person2->AddHome(home3);
        home3->AddPerson(person2);

  

        
        
        
  }