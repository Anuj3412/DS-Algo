#include <bits/stdc++.h>
using namespace std;

/* This is giving error of overloading because of two copy constructor */

// only one constructor is required

class hero
{
public:
    int health;
    char *ch;

    hero()
    {

        ch = new char[100];
    }

    // This is a Shallow copy --> by default shallow copy is done

    hero(hero &temp)
    {
        this->health = temp.health;
        this->ch = temp.ch;
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
