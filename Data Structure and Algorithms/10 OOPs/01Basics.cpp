#include<bits/stdc++.h>
using namespace std;

class hero{

    // Access modifiers
    public:

    //data member or properties
    string name;
    int age;


    //getter
    int getage(){
        return age;
    }
    string getname(){
        return name;
    }

    //setter
    void setname(string temp){
        name = temp;
    }
    void setage(int temp){
        age = temp;
    }


    //Member funaction
    void print(){
        cout<<this->name<<endl;
        cout<<this->age<<endl;
    }

    //default constructor 
    hero(){
        cout<<"New object is constructed "<<endl;
    }

    //parameteised constructor
    hero(int age){

        // "THIS" keyword is used as a pointer to the object  and  to differentiate between names
        this->age=age;
    }

    //copy constructor
    hero(hero & temp){

        cout<<"Default copy constructor is eliminated"<<endl;
        this->name = temp.name;
        this->age = temp.age;
    }

};







int main(int argc, char const *argv[])
{   
    //Static object creation
    hero A;
    A.setname("Anuj");
    A.setage(21);
    cout<<"A: "<<endl;
    cout<<A.getname()<<endl;
    cout<<A.getage()<<endl;

    //dynamic object creation
    hero *B = new hero;
    B->setname("Aman");
    (*B).setage(23);
    cout<<"B: "<<endl;
    B->print();

    // copying a object 
    hero C(A);
    cout<<"C: "<<endl;
    C.print();

    return 0;
}
