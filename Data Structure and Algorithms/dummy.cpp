#include <bits/stdc++.h>
using namespace std;

class hero{
public:
string name;
int age;

hero(){
    cout<<"default constructor is dead "<<endl;
}

hero(string name , int age){
    this->name = name;
    this->age = age;
}

hero(hero & temp){
    this->name = temp.name;
    this->age = temp.age;
}

void setName(string name){
    this->name = name;
}

void setAge(int age){
    this->age = age;
}




};



int main()
{   

    hero A("Anuj" , 22);
    cout<<"A- "<<A.name<<" "<<A.age<<endl;
    hero B(A);
    cout<<"B- "<<B.name<<" "<<B.age<<endl;
    A.setAge(23);
    A.setName("Anuj Bajaj");
    cout<<"A- "<<A.name<<" "<<A.age<<endl;
    cout<<"B- "<<B.name<<" "<<B.age<<endl;

    return 0;
}