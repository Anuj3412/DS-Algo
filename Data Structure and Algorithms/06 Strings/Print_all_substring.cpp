#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input)
{
    // Write your code here
    for (int i = 0; i < input.size(); i++)
    {
        int j = input.size() - 1;
        while (j >= i)
        {
            cout << input.substr(i, j - i + 1) << endl;
            j--;
        }
    }
}

int main()
{
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}