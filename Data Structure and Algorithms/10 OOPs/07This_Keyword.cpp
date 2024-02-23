#include <bits/stdc++.h>
using namespace std;

/* "This" keyword is used to access the object in the class */
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
    Hero(string name)
    {

        this->name = name;  // here "This" keyword is used as pointer pointing to the object created
        cout << this->name; // it is used to differentiate between object property and parameter
    }

    void setname(string s){
        name = s;
    }



private:
    int health;
    float speed;
};

int main(int argc, char const *argv[])
{
    Hero *C = new Hero;  // this  is a dynamic object 
    (*C).setname("Anuj");
    cout<<endl<<C->name;

    return 0;
}
