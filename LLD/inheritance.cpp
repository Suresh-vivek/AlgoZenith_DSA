#include <bits/stdc++.h>
using namespace std;


class Person{

        public:
        Person(int age , string name): age_(age), name_(name){
                
        } 

        private:
        int age_;
        string name_;

};

class Employee : public Person{

        public:
        Employee(int age , string name , string company_name , string company_address) : Person(age_ , name_){
            company_name_ = company_name;
            company_address_ = company_address;
         
        }

    private:
    string company_name_;
    string company_address_;
    
    
};

class SoftwareEngineer: public Employee{

        public:
        SoftwareEngineer(string project_name , string project_address_) : Employee(company_name , company_address){
            project_name_ = project_name;
            project_address_ = project_address;
        }

    private:
    string project_name_;
    string project_address_;
};


int main() {

    SoftwareEngineer se1;
    se1.company_name_ = "ABC";
    se1.company_address_ = "Delhi";
    se1.project_name_ = "XYZ";
    se1.project_address_ = "Mumbai";
    se1.age_ = 25;
    se1.name_ = "Vivek";
}