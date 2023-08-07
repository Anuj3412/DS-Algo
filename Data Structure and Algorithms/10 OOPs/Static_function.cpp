#include <bits/stdc++.h>
using namespace std;

class hero
{
public:
    int time;
    static int age; // static keyword is used to access that data member outside the class without object

    static int function(){

        return age;
    }
};

int hero::age = 22; // syntax for initialising the static value is -->  (data type) (class_name) :: (data member name) = (value)

int main(int argc, char const *argv[])
{

    cout << hero::age << endl;          // this is direct call from class -->  prefered way

    hero A;
    cout << A.age<<endl;                // calling via object 

    cout<<hero::function();             // calling via static function

    return 0;
}
