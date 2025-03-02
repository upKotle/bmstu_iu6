#include <iostream>
#include "intg.h"
#include <cmath>

float first_f(float x) {
    return sin(x)/x;
}

float second_f(float x) {
    return tan(x+1)/(x+1);
}

int main() {
    int n;
    float s, a, b;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;

    s = 0, a = 0.1, b = 1;
    intg(n,a,b,first_f,s);
    std::cout << "Integral of sin(x)/x" << std::endl;
    std::cout << s << std::endl;

    s = 0, a = 1, b = 2;
    intg(n,a,b,second_f,s);
    std::cout << "Integral of tg(x+1)/(x+1)" << std::endl;
    std::cout << s << std::endl;

    return 0;
}
