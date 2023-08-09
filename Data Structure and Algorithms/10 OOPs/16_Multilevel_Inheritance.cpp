#include <bits/stdc++.h>
using namespace std;

class animal
{

public:
    string name;
    int age;

    void eat()
    {
        cout << "eating" << endl;
    }

    void sleep()
    {
        cout << "sleeping" << endl;
    }
};

// LEVEL 1

class dog : public animal
{
};

// LEVEL 2 

class bulldog : public dog{

};


int main(int argc, char const *argv[])
{

    dog D;
    D.eat();
    D.sleep();
    cout << D.age<<endl;

    bulldog BD;
    BD.eat();
    BD.sleep();
    cout<<BD.age<<endl;

    return 0;
}
