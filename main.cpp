#include <iostream>
#include <complex>
#include <cmath> 
#include <math.h> 
#include "constants.h"
#include "header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    userInput::userInput();
    mathFunctions::wrightFunction();
    return 0;
}