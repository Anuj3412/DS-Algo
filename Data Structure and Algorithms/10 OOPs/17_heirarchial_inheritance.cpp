#include <bits/stdc++.h>
using namespace std;

/* Having single parent class to multiple child class is heirarchial inheritance  */

// Parent Class
class human
{

public:
    int age;

    void speak()
    {
        cout << "Human is speaking" << endl;
    }
};

// Child Class - 1
class male : public human
{
public:
    void speak()
    {
        cout << "man is speaking" << endl;
    }
};

// Child Class - 2
class women : public human
{

public:
    void eat()
    {
        cout << "Women is eating" << endl;
    }
};

int main()
{

    male he;
    women she;

    cout << he.age << endl;
    he.speak();
    cout << she.age << endl;
    she.eat();

    return 0;
}