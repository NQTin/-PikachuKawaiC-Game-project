#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

//Mã ASCII các phím điều khiển từ bàn phím
#define KeyUp 72
#define KeyDown 80
#define KeyLeft 75
#define KeyRight 77
#define Space 32
#define Esc 27

void getEvents(int &line, int &col, int &Choice, int &roundSelect);
void printMenu(int roundSelect, int Choice);
void clearScreen();
void generateMeny (int &line, int &col, int &roundSelect, int &Choise);

