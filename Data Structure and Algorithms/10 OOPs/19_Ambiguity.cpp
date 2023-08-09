#include<bits/stdc++.h>
using namespace std;

/* this occur when two class have same function name in multiple inheritance */

class A {

    public:
    void func(){
        cout<<"I am A"<<endl;
    }
};


class B {
    public:
    void func(){

        cout<<"I am B"<<endl;
    }
};

class C : public A , public B{


};



int main(){

    C obj1;

    //obj1.func();        // this is giving a error --> for what to call

    obj1.A::func();        // caling from A

    obj1.B::func();        // caling from B


    return 0;
}