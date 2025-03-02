#include <iostream>
#include <Windows.h>

struct Node {
    int data;
    Node* next;
};

void addEl(Node* &top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void deleteKrat5(Node*& top) {
    if (top == nullptr) {
        std::cout << "Пустой список" << std::endl;
        return;
    }

    while (top != nullptr && top->data % 5 == 0) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    Node* current = top;
    while (current->next != nullptr) {
        if (current->next->data % 5 == 0) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

void printList(Node* top) {
    if (top == nullptr) {
        std::cout << "Список пустой" << std::endl;
    }
    while (top != nullptr) {
        std::cout << top->data << " ";
        top = top->next;
    }
}

void deleteList(Node*& top) {
    while (top != nullptr) {
        Node* temp = top -> next;
        delete top;
        top = temp;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Node* top = nullptr;
    bool flag = true;
    std::string input;
    std::cout << "Введите числа в список (end для завершения ввода)" << std::endl;
    while (flag) {
        std::cin >> input;
        if (input == "end") {
            flag = false;
        } else {
            int value = std::stoi(input);
            addEl(top, value);
        }
    }
    std::cout << "Введённый список" << std::endl;
    printList(top);
    std::cout << std::endl << "Список без чисел, кратных 5" << std::endl;
    deleteKrat5(top);
    printList(top);
    deleteList(top);
    return 0;
}
