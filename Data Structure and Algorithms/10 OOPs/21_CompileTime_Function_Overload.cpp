#include <bits/stdc++.h>
using namespace std;

/* Function overloading means : declaring other functions with same name 
    but different arrguments/no. of arrguments */

class A
{
public:
    int age;

    // Form - 1
    void print()
    {
        cout << "Age is : " << this->age << endl;
    }

    // Form - 2
    void print(int a)
    {
        cout << "The number is " << a << endl;
    }

    void print(string name)
    {
        cout << "The name is " << name << endl;
    }
};

int main()
{

    A object1;

    object1.print();
    object1.print(10);
    object1.print("Anuj");

    return 0;
}