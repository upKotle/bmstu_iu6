#include <iostream>
#include <Windows.h>
#include <iomanip>

int main() {
    SetConsoleOutputCP(CP_UTF8); //для русского языка в терминале Clion
    int arr[3][12];
    std::cout << "Введите матрицу" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 12; j++) {
            std::cin >> arr[i][j];
        }
    }
    std::cout << "Введенный массив" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Преобразованный вывод" << std::endl;
    for (int j = 0; j < (12/3); j++) {
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i][j] << " " ;
        }
        std::cout << "\t";
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i][j+4] << " " ;
        }
        std::cout << "\t";
        for (int i = 0; i < 3; i++) {
            std::cout << arr[i][j+8] << " " ;
        }
        std::cout << std::endl;
    }
    return 0;
}
