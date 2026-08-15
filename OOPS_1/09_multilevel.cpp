#include<iostream>
#include<string>
using namespace std;

class Animal{
public:
   void eat(){
    cout << "Eats\n";
   }
   void breathe(){
    cout << "Breathes\n";
   }
};
class Mammal : public Animal{
public:
   string bloodType;
   Mammal(){
    bloodType = "warm";
   }
};
class Dog : public Mammal{
public:
   void tailWag(){
    cout << "a Dog wags its tail";
   }
};
int main(){
    Dog d1;
    d1.eat();
    d1.breathe();
    d1.tailWag();
    cout << d1.bloodType << endl;
    
    return 0;
}