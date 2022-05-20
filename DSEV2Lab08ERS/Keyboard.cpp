/*
 * Keyboard.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: ERUIZ3
 */

#include "Keyboard.h"

Keyboard::Keyboard(char _Up, char _Down, char _Left, char _Right)
{
    Up = _Up;
    Down = _Down;
    Left = _Left;
    Right = _Right;
}

/*-------------------------------------------------------
 *
 * Capture key pressed
 *
 * ------------------------------------------------------
 */
char Keyboard::getKeyPressed() const
{
    return getch();
}

/*-------------------------------------------------------
 *
 * Generation of Getters and Setters.
 *
 * ------------------------------------------------------
 */
char Keyboard::getDown() const
{
    return Down;
}

void Keyboard::setDown(char down)
{
    Down = down;
}

char Keyboard::getLeft() const
{
    return Left;
}

void Keyboard::setLeft(char left)
{
    Left = left;
}

char Keyboard::getRight() const
{
    return Right;
}

void Keyboard::setRight(char right)
{
    Right = right;
}

char Keyboard::getUp() const
{
    return Up;
}

void Keyboard::setUp(char up)
{
    Up = up;
}
