#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8); //для русского языка в терминале
    float x=10,y=10;
    cout << "Введите X и Y" << endl;
    cin >> x >> y;
    if ((x*x + y*y <= 1) && ((x+1) * (x+1) + y*y) <= 1)
        cout << "Точка входит в заштрихованную область" << endl;
    else
        cout << "Точка не входит в заштрихованную область" << endl;
    return 0;
}

