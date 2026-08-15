#include<iostream>
using namespace std;

class Student{
    //Properties
    private:
       string name;
    public:
       float cgpa;

    //Methods
       void getPercentage(){
        cout << (cgpa * 10) << "% \n"; 
       }
};

class User{
    int id;
    string username;
    string password;
    string bio;

    void deactivate(){
        cout << "Deleting account\n";
    }

    void editBio(string newBio){
        bio = newBio;
    }
};

int main(){
    Student s1; // object
    // s1.name = "Soham";
    s1.cgpa = 9.0;
    cout << s1.cgpa << endl;
    
    Student s2;
    return 0;
}