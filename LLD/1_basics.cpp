#include <bits/stdc++.h>
using namespace std;

class Person {
    public:

      // constructor
      Person( int age , string name , string address){
          cout<<"Person constructor called"<<endl;
        age_= age;
      
        name_ = name;
        address_ = address;


      }
         Person( int age , string name ){
          cout<<"Person constructor2 called"<<endl;
        age_= age;
      
        name_ = name;
        address_ = "NA";


      }

      // default constructor
      Person(){
        age_=0;
        name_=" ";
        address_=" ";
      }
        void SetAge(int age){
            age_ = age;
        }
        int GetAge(){
            return age_;
        }
        void SetName(string name){
            name_ = name;
        }

        string GetName() {
            return name_;
        }

        string GetAddress(){
            return address_;}
        
        void SetAddress(string address){
            address_ = address;
        }

        int GetAgeDays(){
            return age_ *365;

        }


    private:
        int age_;
        string name_;
        string address_;
};

int main(){
    // Person P1;
    // P1.SetAge(22);

    // P1.SetName("Vivek");
    // cout<<P1.GetName()<<endl;

    Person P2(25 , "Vivek" , "Delhi");
    cout<<P2.GetAddress() << " "<<P2.GetName()<< " "<<P2.GetAge()<< " "<<P2.GetAgeDays()<<endl;

    Person P3(25 , "Vivek");
    cout<<P3.GetAddress() << " "<<P3.GetName()<< " "<<P3.GetAge()<< " "<<P3.GetAgeDays()<<endl;
    return 0; 
}