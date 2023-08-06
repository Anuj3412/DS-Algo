#include <bits/stdc++.h>
using namespace std;

/* Constrcutor is used to initialise the properties of the class when a object is created */



class Hero 
{
  

public:
    string name;
    bool alive = true;


    // this is a made constructor which remove the default constructor
    Hero()
    {
        cout << "Overwritten Constructor" << endl;
    }

    // this is a parameterised constructor 
    Hero(string name){

        this->name = name;         // here "This" keyword is used as pointer pointing to the object created
        cout<<this->name;               // it is used to differentiate between obejct property ans parameter
    }

    // in absence of made constructor .... (parameteised constructor) dont work 

private:
    int health;
    float speed;
};

int main(int argc, char const *argv[])
{
    Hero A;             // this is constructed with the defalut constructor

    Hero B;             // this is constructed using the overwitten constructor

    return 0;
}
