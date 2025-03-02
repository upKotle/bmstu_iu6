#include <iostream>
#include <string>

int main() {
    std::string str;
    int k = 0;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (65<=static_cast<int>(str[i]) && static_cast<int>(str[i])<=90) {
            k++;
        }
    }
    std::cout << "Number of capitalized words: " << k << std::endl;
    std::cout << "Capitalized words: " << std::endl;
    int i=0;
    while (i < str.length()) {
        if (65<=static_cast<int>(str[i]) && static_cast<int>(str[i])<=90) {
            while (str[i] != '.' && str[i] != ',') {
                std::cout << str[i];
                i++;
            }
            std::cout << std::endl;
        }
        i++;
    }
    return 0;
}