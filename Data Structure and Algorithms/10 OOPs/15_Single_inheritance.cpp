#include<bits/stdc++.h>
using namespace std;

class animal {

    public:
    string name;
    int age;

    void eat(){
        cout<<"eating"<<endl;
    }

    void sleep(){
        cout<<"sleeping"<<endl;
    }
};

// this is a child class --> which is inheriting animal class (single inheritance) --> only on parent-child relation
class dog : public animal{

};

int main(int argc, char const *argv[])
{


    dog D;
    D.eat();
    D.sleep();
    cout<<D.age;

    return 0;
}
