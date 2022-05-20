/*
 * main.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: ERUIZ3
 */

#include "Keyboard.h"
#include "Vehicle.h"

int main()
{
    system("cls");

    // Refer to ASCII code
    char Bodyw = 178;
    char Whee = 166;

    vector<char> Bodywork = {Bodyw, Bodyw, Bodyw};
    vector<char> Wheels = {Whee, Whee};

    Vehicle Vehicle(10, 10, Bodywork, Wheels);
    Vehicle.Paint();

    Keyboard Key(72, 80, 75, 77);

    while (true)
    {
        Vehicle.Move(Key);
    }

    return 0;
}
