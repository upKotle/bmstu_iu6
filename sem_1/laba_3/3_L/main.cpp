#include <iostream>
#include <Windows.h>
#include <cmath>

int main() {
    SetConsoleOutputCP(CP_UTF8); //для русского языка в терминале
    int x, num, len = 0, count_while = 0, count_for = 0, count_do = 0, k_while = 0, k_do = 0, k_for = 0;
    std::cout << "Введите число: " << std::endl;
    std::cin >> num;

    x = num;
    while (fabs(x) > 0) {
        if ((x%10)%2!=0)
            count_while++;
        x /= 10;
        k_while++;
    }

    std::cout << "Количество нечётных цифр: " << count_while << std::endl;

    return 0;
}
