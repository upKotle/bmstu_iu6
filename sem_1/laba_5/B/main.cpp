#include <iostream>
#include <Windows.h>
#include <vector>

void swapRows(int n, int m, std::vector<std::vector<int>> &arr) {
    int index_negative = -1, index_max = 0;
    int max_elem = arr[0][0];
    bool flag_swap = true, flag_negative = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max_elem) {
                max_elem = arr[i][j];
                index_max = i;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if ((arr[i][j] < 0) && (flag_negative)) {
                index_negative = i;
                flag_negative = false;
            }
        }
    }

    if (index_negative == -1) {
        std::cout << "Отрицательных элементов нет" << std::endl;
        flag_swap = false;
    }
    if (index_negative == index_max) {
        std::cout << "Строки совпадают" << std::endl;
        flag_swap = false;
    }
    if (flag_swap) {
        std::swap(arr[index_max], arr[index_negative]);
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n,m;

    std::cout << "Введите количество строк в матрице: (<=10)" << std::endl;
    std::cin >> n;
    std::cout << "Введите количество столбцов в матрице: (<=10)" << std::endl;
    std::cin >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));

    std::cout << "Введите элементы матрицы: " << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }


    std::cout << "Оригинальный массив" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    swapRows(n,m,a);
    std::cout << std::endl;

    std::cout << "Измененный массив" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}