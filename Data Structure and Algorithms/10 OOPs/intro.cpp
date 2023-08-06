#include <bits/stdc++.h>
using namespace std;

/* A class is a blueprint for the object */

// A class is defined as

class Hero /* this is the name of the class*/
{

public: // This is the type of properties --> this can be accessed by anyone
    // here we write properties of the class
    string name;
    bool alive = true;


private: // these properties cannot be accessed by anyone outside the class
    int health;
    float speed;
};

int main(int argc, char const *argv[])
{

    // Now we can make a object of class Node

    Hero A;
    A.name = "Anuj";
    A.alive = true;
    cout << A.name << " " << A.alive<<endl;
    cout<<"size is: "<<sizeof(A);
    return 0;
}
