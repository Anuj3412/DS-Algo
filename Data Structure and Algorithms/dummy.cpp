#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Car
{
    // Write your constructor and printCarInfo method here.
public:
    int noOfGear;
    string color;
};

class RaceCar : public Car
{
    // Write your constructor and printRaceCarInfo method here.
public:
    int maxSpeed;

    RaceCar(int gear, string color, int speed)
    {
        this->noOfGear = gear;
        this->color = color;
        this->maxSpeed = speed;
    }

    void printInfo()
    {
        cout << "noOfGear: " << this->noOfGear << endl;
        cout << "color: " << this->color << endl;
        cout << "maxSpeed: " << this->maxSpeed << endl;
    }
};

int main()
{
    int noOfGear, maxSpeed;
    string color;
    cin >> noOfGear >> color >> maxSpeed;
    RaceCar raceCar(noOfGear, color, maxSpeed);
    raceCar.printInfo();
    return 0;
}