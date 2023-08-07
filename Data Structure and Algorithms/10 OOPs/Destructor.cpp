#include <bits/stdc++.h>
using namespace std;

class hero
{

public:
    string name;
    int health;
    int points;


    //Destructor --> by default is called --> for Static Memory
    ~hero(){
        cout<<"Destructor is called "<<endl;
    }
};

int main(int argc, char const *argv[])
{
    hero A;             // static declarartion
    hero *B = new hero; // dynamic declaration

    cout << "Health is: " << A.health << endl;   // accessing properties in static
    cout << "Point is: " << B->points << endl;   // accesing properties in dynamic -1
    cout << "Point is: " << (*B).points << endl; // accesing properties in dynamic -2 (using derefrence operator)


    delete B;           //For Dynamic memory it is called manually
    return 0;
}
