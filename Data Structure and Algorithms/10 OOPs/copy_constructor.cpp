#include <bits/stdc++.h>
using namespace std;

class hero
{
public:
    int health;
    string name;

    // new default constructor
    hero()
    {
        cout << "default constructor is dead " << endl;
    }

    // to set the values
    void sethealth(int a)
    {
        health = a;
    }

    void setname(string name)
    {
        this->name = name; // here we are using THIS keyword to avoid confussion between names
    }

    // copy constructor
    hero(hero &temp) // here it is passed by refrence because of infinite loop
                     // pass by value would have called copy constructor again and again
    {
        this->health = temp.health;
        this->name = temp.name;
    }



};

int main(int argc, char const *argv[])
{
    hero A;
    A.sethealth(99);
    A.setname("Anuj");
    cout << A.name << " A " << A.health<<endl;
    hero B(A);
    cout << B.name << " B " << B.health<<endl;
    return 0;
}
