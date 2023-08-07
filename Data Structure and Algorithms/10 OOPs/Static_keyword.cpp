#include<bits/stdc++.h>
using namespace std;

class hero {
    public:

    int time;
    static int age;         // static keyword is used to access that data member outside the class without object


};

int hero::age = 22;         // syntax for initialising the static value is -->  (data type) (class_name) :: (data member name) = (value) 

int main(int argc, char const *argv[])
{
    // both ways can be used --> preferd is first one

    cout<<hero::age<<endl;


    hero A;
    cout<<A.age;

    return 0;
}
