#include "constants.h"
#include "header.h"
#include <cmath> 
#include <iostream>

//Calculating the factorial

unsigned long long mathFunctions::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("The factorial is not defined for negative numbers.");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

//Calculating the gamma function on the interval [0, 1]

double mathFunctions::gammaBef1(double rac) {
    double gammaapx;
    gammaapx = (1 + a1 * rac + a2 * pow(rac, 2) + a3 * pow(rac, 3) + a4 * pow(rac, 4) + a5 * pow(rac, 5)) / rac;
    return gammaapx;
}

//G(x) = G(x-1)*(x-1)=G(x-2)*(x-2)*(x-1)=..., then you can reach the point where x lies in the interval between 0 and 1, then:
double mathFunctions::gamma(double a) {
    double k = a - 1;
    double x = a - 1;
    if (a - floor(a) == 0) {
        return factorial(a - 1);
    }
    if (a > 1) {
        while (x >= 1) {
            x--;
            k *= x;
        }
        a = a - floor(a);
        return k * gammaBef1(a);

    }
    else {
        return gammaBef1(a);
    }
}

//Putting all the formulas together

double mathFunctions::wrightFunction() {
    int k = 0;
    double aprx = 0.0001, wrightFunction = 0, checker = 0;
    while (true) {
        wrightFunction += pow(z, k) / (mathFunctions::factorial(k) * mathFunctions::gamma(p * k + b));
        checker = pow(z, k) / (mathFunctions::factorial(k) * mathFunctions::gamma(p * k + b));
        if (checker <= aprx) {
            std::cout << "The Wright function is equal to: " << wrightFunction;
            return wrightFunction;
        }
        k++;
    }
}

//Input

double userInput::userInput() {
    std::cout << "Enter the number z(-inf; +inf)"
        << std::endl;
    std::cin >> z;
    std::cout << "Enter the variable p > -1:"
        << std::endl;
    std::cin >> p;
    std::cout << "Enter the number b:"
        << std::endl;
    std::cin >> b;

    try {
        if (p <= -1) {
            throw "Number < -1 ";
        }
    }
    catch (const char* errorMessage) {
        std::cerr << errorMessage
            << std::endl;
    }

    return p, z, b;
}
