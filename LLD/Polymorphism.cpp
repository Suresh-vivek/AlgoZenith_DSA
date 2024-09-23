#include <bits/stdc++.h>
using namespace std;


class Animal{
        public:
         virtual void Sound(){
                cout<<"No sound"<<endl;
         }
         ~Animal(){
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
        // stored on the stack
        Animal animal;

        //this will allocate objct on heap
        Animal *ptr = new Animal;
        playSound(*ptr); //   
        playSound(animal);

        Kitten kitten;
         playSound(kitten);

        Cat cat;
         playSound(cat);

        Animal &temp = cat;
        temp.Sound();




        
}