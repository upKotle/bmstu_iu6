#include <iostream>
#include <Windows.h>

struct Node {
    int data;
    Node* next;
};

void addUniq(Node* &head, int value) {
    Node* current = head;
    Node* last = nullptr;
    bool flag_ununiq = false;
    while (current != nullptr) {
        if (current -> data == value) {
            flag_ununiq = true;
        }
        last = current;
        current = current -> next;
    }
    if (flag_ununiq == false) {
        Node* newNode = new Node{value,nullptr};
        if (last == nullptr) {
            head = newNode;
        }else {
            last -> next = newNode;
        }
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head -> data << " ";
        head = head -> next;
    }
    std::cout << std::endl;
}

void removeMax(Node* &head) {
    if (head == nullptr) {
        std::cout << "Список пустой" << std::endl;
    }
    else {
        Node* current = head;
        Node* previous = nullptr;
        Node* maxNode = head;
        Node* prevMax = nullptr;

        while (current != nullptr) {
            if (current -> data > maxNode -> data) {
                maxNode = current;
                prevMax = previous;
            }
            previous = current;
            current = current -> next;
        }

        int MaxValue = maxNode -> data;
        std::cout << "Максимальное значение: " << MaxValue << std::endl;
        if (maxNode == head) {
            head = head -> next;
        }else
        if (maxNode -> next == nullptr) {
            prevMax -> next = nullptr;
        }else {
            prevMax -> next = maxNode -> next;
        }
        delete maxNode;
    }
}

void clearList(Node* &head) {
    while (head != nullptr) {
        Node* current = head;
        head = head -> next;
        delete current;
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Node* head = nullptr;

    std::cout << "Введите целые числа (\"end\" для завершения ввода): " << std::endl;

    bool flag = true;
    std::string input;
    while (flag) {
        std::cin >> input;
        if (input == "end") {
            flag = false;
        } else {
            int value = std::stoi(input);
            addUniq(head, value);
        }
    }

    std::cout << "Список без повторений: " << std::endl;
    printList(head);

    removeMax(head);

    std::cout << "Список без максимального элемента: " << std::endl;
    printList(head);

    clearList(head);
    return 0;
}
