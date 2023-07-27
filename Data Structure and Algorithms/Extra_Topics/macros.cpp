#include <bits/stdc++.h>
using namespace std;

// the values of macros is replaced at the used poistions

#define PI 3.141592653589793238462 // single object is defined as macro

#define area(r) 3.141592653589793238462 * r *r // setting a function as macro

#define Area(r) PI *r *r // using expanding macros

int main(int argc, char const *argv[])
{
    int r;
    cin >> r;
    double peri = PI * r * 2;
    cout << "circumfrence is " << peri << endl;
    cout << "area is " << area(r) << endl;
    return 0;
}
