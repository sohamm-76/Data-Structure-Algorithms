#include<iostream>
#include<string>
using namespace std;

class Car{
    string name;
    string color;

public:
    Car(string nameValue, string colorValue) {//constructor
        cout << "constructor is called. object being created..\n";
        name = nameValue;
        color = colorValue;
    }
    void start(){
        cout << "car has started..\n" ;
    }

    void stop(){
        cout << "car has stopped\n";
    }

    //Getter
    string getName(){
        return name;
    }
    string getColor(){
        return color;
    }
};

int main(){
    Car c1("mercedes GLC 220d", "navy blue");

    cout << "car name: " << c1.getName() << endl;
    cout << "color name: " << c1.getColor() << endl;
    return 0;
}
