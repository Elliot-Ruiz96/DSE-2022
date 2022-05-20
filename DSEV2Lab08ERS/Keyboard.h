/*
 * Keyboard.h
 *
 *  Created on: Apr 2, 2022
 *      Author: ERUIZ3
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

class Keyboard
{
    
private:
    char Up;
    char Down;
    char Left;
    char Right;
    
public:
    Keyboard(char _Up, char _Down, char _Left, char _Right);
    char getKeyPressed() const;
    char getDown() const;
    void setDown(char down);
    char getLeft() const;
    void setLeft(char left);
    char getRight() const;
    void setRight(char right);
    char getUp() const;
    void setUp(char up);
};

#endif /* KEYBOARD_H_ */
