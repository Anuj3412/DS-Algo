#include <bits/stdc++.h>  #include<iostream>

#include <algorithm>

using namespace std;

class Fraction
{
    int nm;
    int dm;

public:
    Fraction(int nm, int dm)
    {
        this->nm = nm; // constructor
        this->dm = dm;
    }

    void simplify()
    {
        int gcd = __gcd(nm, dm);
        this->nm = this->nm / gcd;
        this->dm = this->dm / gcd;
    }

    void Add(Fraction f)
    {
        int d = this->dm * f.dm;
        int n = (d / this->dm) * this->nm + (d / f.dm) * f.nm;
        this->nm = n;
        this->dm = d;
        simplify();
    }

    void Multiply(Fraction f)
    {
        this->nm = this->nm * f.nm;
        this->dm = this->dm * f.dm;

        simplify();
    }

    void print() { cout << this->nm << "/" << this->dm << endl; }
};

int main()
{

    int n1, d1;
    cin >> n1 >> d1;
    Fraction f1(n1, d1);
    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        int choice, n2, d2;
        cin >> choice >> n2 >> d2;
        Fraction f2(n2, d2);

        if (choice == 1)
        {
            f1.Add(f2);
            f1.print();
        }
        else
        {
            f1.Multiply(f2);
            f1.print();
        }
    }

    return 0;
}