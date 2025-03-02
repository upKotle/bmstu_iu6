#include <iostream>
#include <Windows.h>
#include <cmath>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    float x, eps, prev, sum = 0;
    int iter_count = 0, k=1, stepen=0;
    std::cout << "Введите x: " << std::endl;
    std::cin >> x;
    std::cout << "Введите эпсилон" << std::endl;
    std::cin >> eps;
    prev = sum-1;
    while (fabs(sum - prev) > eps) {
        prev = sum;
        sum = sum + (pow(x, k)/k) * pow(-1,stepen);
        stepen ++;
        iter_count++;
        k += 2;
    }
    std::cout << "arctg = " << sum << std::endl;
    std::cout << "Кол-во итераций: " << iter_count << std::endl;
    return 0;
}


