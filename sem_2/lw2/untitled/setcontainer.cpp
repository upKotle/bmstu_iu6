#include "setcontainer.h"

void SetContainer::addElement(QChar element) {
    if (elements.find(element) != elements.end()) {
        throw ElementAlreadyExistsException("Элемент уже существует в множестве.");
    }
    elements.insert(element);
}

void SetContainer::removeElement(QChar element) {
    if (elements.find(element) == elements.end()) {
        throw ElementNotFoundException("Элемент не найден в множестве.");
    }
    elements.erase(element);
}

bool SetContainer::contains(QChar element) const {
    return elements.find(element) != elements.end();
}

QString SetContainer::toString() const {
    QString result = "{ ";
    for (const QChar& e : elements) {
        result += QString(e) + " "; // Исправленный вариант
    }
    result += "}";
    return result;
}

