#include <iostream>
#include <ctime>
#include <Windows.h>

float arr[20];
float min_dot,max_dot;
int min_num,max_num;
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));
    for (int i = 0; i < 20; i++) {
        arr[i] = rand()%100;
    }
    min_dot = arr[0];
    max_dot = arr[0];
    std::cout << "Исходный массив: ";
    for (int i = 0; i < 20; i++) {
        if (arr[i] < min_dot) {
            min_dot = arr[i];
            min_num = i + 1;
        }
        if (arr[i] > max_dot) {
            max_dot = arr[i];
            max_num = i + 1;
        }
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << "Координата наименьшей точки: " << min_dot << " Её номер: " << min_num << std::endl;
    std::cout << "Координата наибольшей точки: " << max_dot << " Её номер: " << max_num << std::endl;
    std::cout << "Расстояние между этими точками: " << max_dot - min_dot << std::endl;
    return 0;
}
