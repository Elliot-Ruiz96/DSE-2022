/*
 * Vehicle.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: ERUIZ3
 */

#include "Vehicle.h"

/*-------------------------------------------------------
 *
 * Printing where the mouse is pointing in CMD window.
 *
 * ------------------------------------------------------
 */
void goTo_xy(int x, int y)
{

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

/*-------------------------------------------------------
 *
 * Declaration of Builder.
 *
 * ------------------------------------------------------
 */
Vehicle::Vehicle (int _x, int _y, vector<char> _Bodywork, vector<char> _Wheels)
{
    x        = _x;
    y        = _y;
    Bodywork = _Bodywork;
    Wheels   = _Wheels;
}

/*-------------------------------------------------------
 *
 * Color of the vehicle Body work and Wheels.
 *
 * ------------------------------------------------------
 */
void Vehicle::Paint()
{
    goTo_xy(x, y);
    printf("%c%c%c\n", Bodywork[0], Bodywork[1], Bodywork[2]);
    goTo_xy(x, y + 1);
    printf(" %c%c\n", Wheels[0], Wheels[1]);
}

/*-------------------------------------------------------
 *
 * Generation of Getters.
 *
 * ------------------------------------------------------
 */
const vector<char>& Vehicle::getBodywork() const
{
    return Bodywork;
}

const vector<char>& Vehicle::getWheels() const
{
    return Wheels;
}

int Vehicle::getX() const
{
    return x;
}

int Vehicle::getY() const
{
    return y;
}
