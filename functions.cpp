#include "constants.h"
#include "header.h"
#include <cmath> 
#include <iostream>

//Вычисление факториала 

unsigned long long mathFunctions::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Факториал не определен для отрицательных чисел.");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

//Вычисление гамма функции на отрезке [0, 1]

double mathFunctions::gammaBef1(double rac) {
    double gammaapx;
    gammaapx = (1 + a1 * rac + a2 * pow(rac, 2) + a3 * pow(rac, 3) + a4 * pow(rac, 4) + a5 * pow(rac, 5)) / rac;
    return gammaapx;
}

//Так как Г(х) = Г(х-1)*(х-1)=Г(x-2)*(x-2)*(x-1)=..., то можно дойти до того момента пока х будет лежать в интервале между 0 и 1, тогда:
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

//Собираем все формулы вместе

double mathFunctions::wrightFunction() {
    int k = 0;
    double aprx = 0.0001, wrightFunction = 0, checker = 0;
    while (true) {
        wrightFunction += pow(z, k) / (mathFunctions::factorial(k) * mathFunctions::gamma(p * k + b));
        checker = pow(z, k) / (mathFunctions::factorial(k) * mathFunctions::gamma(p * k + b));
        if (checker <= aprx) {
            std::cout << "Функция Райтта равна : " << wrightFunction;
            return wrightFunction;
        }
        k++;
    }
}

/*Ввод переменных пользователем*/

double userInput::userInput() {
    std::cout << "Введите число z(-inf; +inf)"
        << std::endl;
    std::cin >> z;
    std::cout << "Введите переменную p > -1:"
        << std::endl;
    std::cin >> p;
    std::cout << "Введите число b:"
        << std::endl;
    std::cin >> b;

    try {
        if (p <= -1) {
            throw "Число < -1";
        }
    }
    catch (const char* errorMessage) {
        std::cerr << errorMessage
            << std::endl;
    }

    return p, z, b;
}
