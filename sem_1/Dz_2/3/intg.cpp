#include "intg.h"

void intg(int n, float a, float b, float (*operation)(float x), float &s){
    s = 0;
    float h = (b - a) / n;
    for (int i = 0; i < n; i++) {
        float x = a + i * h;
        s += operation(x)*h;
    }
}

