#include<bits/stdc++.h>
using namespace std;

/* this is operator overloading --> changing fundamental operation of the operator to our desired one */

class hero{

    public:
    int num1;
    int num2;
    string name;


    void sum(hero &b){
        cout<<"Sum is "<<this->num1 + b.num1<<endl;
    }

    // Now use of '+' will give output as per defined
    void operator + (hero & b){
        cout<< "After changing operator, Sum is "<< this->num1 - b.num1<<endl;      
    }

    // now use of '()' will print something
    void operator() (){
        cout<<"parenthsis is used"<<endl;
    }

    void setnum1(int a){
        this->num1 = a;
    }
    void setnum2(int a){
        this->num2 = a;
    }
};



int main(int argc, char const *argv[])
{
    hero a;
    a.setnum1(10);
    a.setnum2(20);
    hero b;
    b.setnum1(5);
    b.setnum2(3);
    a.sum(b);
    a + b ;
    b();
    return 0;
}
