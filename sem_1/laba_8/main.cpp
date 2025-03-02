#include <iostream>
#include <cmath>

class Cone {
private:
    double height;
    double radius;

public:
    Cone(double h, double r) : height(h), radius(r) {}

    void print(){
        std::cout << "Параметры конуса: " << std::endl
                  << "Высота конуса = " << height << std::endl
                  << "Радиус конуса = " << radius << std::endl;
    }

    double Volume(){
        return 1.0 / 3.0 * M_PI * radius * radius * height;
    }

    double BaseArea(){
        return M_PI * radius * radius;
    }

    double getHeight(){
        return height;
        }
    double getRadius(){
        return radius;
        }
};

class TrunCone : public Cone {
private:
    double up_radius;

public:
    TrunCone(double h, double r1, double r2) : Cone(h, r1), up_radius(r2) {}

    void print(){
        std::cout << "Параметры усечённого конуса: " << std::endl
                  << "Высота усечённого конуса = " << getHeight() << std::endl
                  << "Радиус нижнего основания усечённого конуса = " << getRadius() << std::endl
                  << "Радиус верхнего основания усечённого конуса = " << up_radius << std::endl;
    }

    double Volume(){
        return 1.0 / 3.0 * M_PI * getHeight() * (pow(getRadius(), 2) + getRadius() * up_radius + pow(up_radius, 2));
    }

    double FullArea(){
        double L = sqrt(pow(getHeight(), 2) + pow(getRadius() - up_radius, 2));
        return M_PI * (pow(getRadius(), 2) + pow(up_radius, 2) + (getRadius() + up_radius) * L);
    }
};

int main() {
    Cone object1(5, 3);
    object1.print();
    std::cout << "Объём конуса = " << object1.Volume() << std::endl
              << "Площадь основания конуса = " << object1.BaseArea() << std::endl;

    std::cout << std::endl;

    TrunCone object2(5, 3, 1);
    object2.print();
    std::cout << "Объём усечённого конуса = " << object2.Volume() << std::endl
              << "Полная площадь усечённого конуса = " << object2.FullArea() << std::endl
              << "Площадь основания усечённого конуса = " << object2.BaseArea() << std::endl;

    return 0;
}