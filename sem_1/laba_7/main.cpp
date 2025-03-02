#include <iostream>
#include <Windows.h>

class Flashlight{
    private:
        bool State;
    public:
        Flashlight(bool State): State(State) {}
        void Now(){
            if (State){
                std::cout << "Фонарик включён" << std::endl;
            } else {
                std::cout << "Фонарик выключен" << std::endl;
            }
        };
        void TurnOn(){
            State = true;
        };
        void TurnOff(){
            State = false;
        }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Flashlight Fonarik(false);
    Fonarik.Now();
    Fonarik.TurnOn();
    Fonarik.Now();
    Fonarik.TurnOff();
    Fonarik.Now();
    return 0;
}