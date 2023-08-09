#include<bits/stdc++.h>
using namespace std;

class hero{

    public:
    int age;

    private:
    string name;

    protected:
    int marks;

    void setage(int a){
        this->age = a;
    }

    void setname(string a){
        this->name = a;
    }

    void setmarks(int a){
        this->marks = a;
    }

    int getage(){
        return age;
    }
    int getmarks(){
        return marks;
    }
    string getname(){
        return name;
    }
};






int main(int argc, char const *argv[])
{
    hero anuj;
    
    return 0;
}
