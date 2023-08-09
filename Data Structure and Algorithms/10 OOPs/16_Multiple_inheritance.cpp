#include<bits/stdc++.h>
using namespace std;

// Class - 1
class human{

    public:
    int age;

    void speak(){
        cout<<"Human is speaking"<<endl;
    }

};

// Class - 2
class wolf {

    public:
    int height;

    void howl(){
        cout<<"Wolf is here"<<endl;
    }
};

// Class 1 + 2 --> this class is inheriting multiple class
class hybrid : public human , public wolf{

};


int main(){

    hybrid werewolf;
    werewolf.howl();
    werewolf.speak();
    cout<<werewolf.age<<endl;


    return 0;
}