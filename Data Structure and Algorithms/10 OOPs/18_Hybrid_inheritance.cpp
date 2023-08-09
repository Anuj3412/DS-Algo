#include <bits/stdc++.h>
using namespace std;


/* this is a combination of two or more than two types of inheritance */

class A
{

public:
    void func0()
    {
        cout << "This is class A" << endl;
    }
};

class B
{

public:
    void func1()
    {
        cout << "This is class B" << endl;
    }
};

class A1 : public A
{
public:
    void func2()
    {
        cout << "This is class A1" << endl;
    }
};

class A2 : public A, public B
{
public:
    void func3()
    {
        cout << "This is class A2" << endl;
    }
};

class A11 : public A1
{
public:
    void func4()
    {
        cout << "This is class A11" << endl;
    }
};

int main()
{
    A11 object1;
    A2 object2;
    object1.func2();
    object2.func0();
    object2.func1();

    return 0;
}