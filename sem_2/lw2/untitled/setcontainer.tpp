#ifndef SETCONTAINER_TPP
#define SETCONTAINER_TPP

#include "setcontainer.h"

template <typename T>
void SetContainer<T>::addElement(const T& element) {
    if (this->elements.find(element) != this->elements.end()) {
        throw ElementAlreadyExistsException("Элемент уже существует в множестве.");
    }
    this->elements.insert(element);
}

template <typename T>
void SetContainer<T>::removeElement(const T& element) {
    if (this->elements.find(element) == this->elements.end()) {
        throw ElementNotFoundException("Элемент не найден в множестве.");
    }
    this->elements.erase(element);
}

template <typename T>
bool SetContainer<T>::contains(const T& element) const {
    return this->elements.find(element) != this->elements.end();
}

template <typename T>
QString SetContainer<T>::toString() const {
    QString result = "{ ";
    for (const auto& e : this->elements) {
        result += QString::number(e) + " ";
    }
    result += "}";
    return result;
}

#endif
