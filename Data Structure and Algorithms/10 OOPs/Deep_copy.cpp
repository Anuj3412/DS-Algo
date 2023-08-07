#include <bits/stdc++.h>
using namespace std;

/* This is giving error of overloading because of two copy constructor */

// only one costructor is required

class hero
{
public:
    int health;
    char *ch;

    hero()
    {

        ch = new char[100];
    }

    // This is a Deep copy 

    hero(hero &temp)
    {
       char *ch = new char[strlen(temp.ch)+1];      // create new heap memory with same length 
       strcpy(ch , temp.ch);            // (uske andar temp ki string copy kari)  ye string copy karegi na ki address
       this->ch = ch;                   // us copied string ko naye object ka address de do
        this->health = temp.health;
    }

    void sethealth(int health)
    {
        this->health = health;
    }
    void setname(char name[])
    {
        strcpy(this->ch, name);
    }

    void print()
    {
        cout << this->health << " " << this->ch << endl;
    }
};

int main(int argc, char const *argv[])
{

    hero A;
    A.sethealth(20);
    char name[5] = "Anuj";
    A.setname(name);
    A.print();

    hero B(A);
    B.print();
    cout << endl;

    A.ch[0] = 'T';
    A.print();
    B.print();
}
