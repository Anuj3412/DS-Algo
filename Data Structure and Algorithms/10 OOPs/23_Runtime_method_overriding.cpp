#include<bits/stdc++.h>
using namespace std;

/* Here function deined in parent class is over written in child class as desired */

// works only in case of inheritance and function name and parameter should be same

class parent {
    public:
    int age;

    void tell(){
        cout<<"Age is "<<age<<endl;
    }

    void set(int a){
        this->age = a;
    }
};

class child : public parent{

    public:
    string name;


    // parent function is overwritten here
    void tell(){
        cout<<"Name is "<<name<<endl;
    }

    void set(string name){
        this->name = name;
    }

    // parent funciton is over written here
    void set(int a){
        this->age = a + 10;
    }
};

int main(){

    child chris;
    chris.set("Chris");
    chris.tell();
    chris.set(22);
    chris.parent::tell();       // scope resolution is used to specify class to be used


    return 0;
}
