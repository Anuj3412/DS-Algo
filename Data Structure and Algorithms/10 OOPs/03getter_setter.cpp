#include <bits/stdc++.h>
using namespace std;

/* A class is a blueprint for the object */

// A class is defined as

class Hero /* this is the name of the class*/
{

private:
    int health;
    float speed;

    // since the private values cannot be accessed --> we can use functions in public
public:
    int gethealth()
    {
        return health;
    }
    void sethealth(int h)
    {
        health = h;
    }

    float getSpeed()
    {
        return speed;
    }
    void setSpeed(float s)
    {
        speed = s;
    }

    // by using these kind of functions we can modify or access the private class values
};

int main(int argc, char const *argv[])
{

    Hero A;
    A.sethealth(100);                             // like this the values can be changed
    cout << "healh is " << A.gethealth() << endl; // like this the values can be accessed
    A.setSpeed(93.4230);
    cout << "Speed is " << A.getSpeed() << endl;

    return 0;
}

/* Uses of the getter and setter are : */

// to change a value from outside the object we can use the password type key

/*

getHealth(int pass){
    if(pass == key ){
        return health;
    }
    else return -1;
}

*/
