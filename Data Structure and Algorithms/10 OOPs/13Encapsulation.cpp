#include<bits/stdc++.h>
using namespace std;



// wrapping up of properties (keeping them private ) and behaviour in one a group is encapsulation

// in such a manner that no other class can access the data of encapsulated class

// Fully encapsulated class has all its data in private 

class student {

private:

    string name;
    int age;
    int marks;

    public:

    string getname(){
        return this->name;
    }

    int getmarks(){
        return this->marks;
    }

    int getage(){
        return this->age;
    }


};




int main(int argc, char const *argv[])
{
    student A;
    cout<<A.getname()<<" "<<A.getage();
    return 0;
}
