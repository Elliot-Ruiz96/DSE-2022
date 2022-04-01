/*
 * main.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: ERUIZ3
 */

#include "Vehicle.h"

int main()
{
    system("cls");

    char Bodyw = 178;
    char Whee = 184;

    char Bodyw1 = 179;
    char Whee1 = 229;

    vector<char> Bodywork = {Bodyw, Bodyw, Bodyw};
    vector<char> Wheels = {Whee, Whee};

    vector<char> Bodywork1 = {Bodyw1, Bodyw1, Bodyw1};
    vector<char> Wheels1 = {Whee1, Whee1};

    Vehicle Vehicle(10, 10, Bodywork, Wheels);
    Vehicle.Paint();

    Vehicle Vehicle1(20, 20, Bodywork1, Wheels1);
    Vehicle1.Paint();

    return 0;
}
