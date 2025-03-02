#include <iostream>
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n;
    float temp;
    std::cout << "Введите длину массива: " << std::endl;
    std::cin >> n;
    float arr[n];
    std::cout << "Введите элементы массива: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    std::cout << "Введённый массив: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[j] > arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }

    std::cout << std::endl << "Отсортированный массив: " << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    return 0;
}
