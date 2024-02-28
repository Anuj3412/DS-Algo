#include<bits/stdc++.h>
using namespace std;

class Human {

public: 
int age;
int height;
int weight;

};

class man : public Human{

    string name;

};
int main(int argc, char const *argv[])
{
    man A;
    cout<<A.age; // age is defined in parent class (Human)--> inherited to child class (Man)
    return 0;
}
