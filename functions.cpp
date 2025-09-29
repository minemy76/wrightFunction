#include "constants.h"
#include "header.h"
#include <cmath> 
#include <iostream>

//���������� ���������� 

unsigned long long mathFunctions::factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("��������� �� ��������� ��� ������������� �����.");
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

//���������� ����� ������� �� ������� [0, 1]

double mathFunctions::gammaBef1(double rac) {
    double gammaapx;
    gammaapx = (1 + a1 * rac + a2 * pow(rac, 2) + a3 * pow(rac, 3) + a4 * pow(rac, 4) + a5 * pow(rac, 5)) / rac;
    return gammaapx;
}

//��� ��� �(�) = �(�-1)*(�-1)=�(x-2)*(x-2)*(x-1)=..., �� ����� ����� �� ���� ������� ���� � ����� ������ � ��������� ����� 0 � 1, �����:
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

//�������� ��� ������� ������

double mathFunctions::wrightFunction() {
    int k = 0;
    double aprx = 0.0001, wrightFunction = 0, checker = 0;
    while (true) {
        wrightFunction += pow(z, k) / (mathFunctions::factorial(k) * mathFunctions::gamma(p * k + b));
        checker = pow(z, k) / (mathFunctions::factorial(k) * mathFunctions::gamma(p * k + b));
        if (checker <= aprx) {
            std::cout << "������� ������ ����� : " << wrightFunction;
            return wrightFunction;
        }
        k++;
    }
}

/*���� ���������� �������������*/

double userInput::userInput() {
    std::cout << "������� ����� z(-inf; +inf)"
        << std::endl;
    std::cin >> z;
    std::cout << "������� ���������� p > -1:"
        << std::endl;
    std::cin >> p;
    std::cout << "������� ����� b:"
        << std::endl;
    std::cin >> b;

    try {
        if (p <= -1) {
            throw "����� < -1";
        }
    }
    catch (const char* errorMessage) {
        std::cerr << errorMessage
            << std::endl;
    }

    return p, z, b;
}
