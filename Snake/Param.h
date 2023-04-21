#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#define random(a,b) (a + rand()%(b+1-a))
using namespace std;

const int SPEED = 100;
const int SIZE_FIELD = 10;
const int MARGIN = 5;
const int MIN_SIZE_SNAKE = 3;