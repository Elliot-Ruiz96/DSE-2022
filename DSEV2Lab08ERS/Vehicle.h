/*
 * Vehicle.h
 *
 *  Created on: Apr 1, 2022
 *      Author: ERUIZ3
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <conio.h>
#include <windows.h>

#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class Vehicle
{

private:
    //Attributes
    int x, y;
    vector<char> Bodywork;
    vector<char> Wheels;

public:
    //Builders
    Vehicle(int _x, int _y, vector<char> _Bodywork, vector<char> _Wheels);
    const vector<char>& getBodywork() const;
    const vector<char>& getWheels() const;
    int getX() const;
    int getY() const;
    void Paint();
};


#endif /* VEHICLE_H_ */
