#include <bits/stdc++.h>
using namespace std;


// Virtual Destrutor

class Animal{
        public:
         virtual void Sound(){
                cout<<"No sound"<<endl;
         }
        virtual ~Animal(){
                cout<<"~Animal"<<endl;
         }
};
class Cat : public Animal{
        public:
          void Sound() override{
                cout<<"Meow"<<endl;
         }

         ~Cat(){
                cout<<"~Cat "<<endl;
         }
};
class Dog : public Animal{
        public:
       void Sound() final   {
                cout<<"Bark"<<endl;
         }
         ~Dog(){
                cout<<"~Dog"<<endl;
         }
};
class Kitten : public Cat{
        public:
        void Sound(){
                cout<<"mmmeoowww"<<endl;
         }

         ~Kitten(){
                cout<<"~Kitten"<<endl;
         }

};
void playSound(Animal &animal){
        animal.Sound();
}
int main(){
       Cat *cat_ptr = new Cat();

       Animal &animal = *cat_ptr; // this is pointing to Animal portion of Cat class

       Animal *animal_ptr = &animal;

       animal_ptr ->Sound();
       delete animal_ptr;






        
}