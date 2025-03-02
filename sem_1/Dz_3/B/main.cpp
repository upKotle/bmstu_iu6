#include <iostream>
#include <fstream>

int main()
{
    std::string str;
    std::ifstream f1("F.txt");
    std::fstream f2("G.txt");
    std::cout << "File F: " << std::endl;
    while(std::getline(f1,str)) {
        std::cout << str << " ";
        if (stoi(str) % 2 != 0) {
            f2 << str << std::endl;
        }
    }
    std::cout << std::endl;
    f2.seekg(0);
    std::cout << "File G: " << std::endl;
    while(std::getline(f2,str)) {
        std::cout << str << " ";
    }
    return 0;
}
