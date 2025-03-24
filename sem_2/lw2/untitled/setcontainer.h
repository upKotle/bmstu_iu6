#ifndef SETCONTAINER_H
#define SETCONTAINER_H

#include <set>
#include <stdexcept>
#include <QString>

class ElementAlreadyExistsException : public std::runtime_error {
public:
    explicit ElementAlreadyExistsException(const QString& message)
        : std::runtime_error(message.toStdString()) {}
};

class ElementNotFoundException : public std::runtime_error {
public:
    explicit ElementNotFoundException(const QString& message)
        : std::runtime_error(message.toStdString()) {}
};

template <typename T>
class SetContainer {
protected:
    std::set<T> elements;

public:
    void addElement(const T& element) {
        if (elements.find(element) != elements.end()) {
            throw ElementAlreadyExistsException("Элемент уже существует в множестве.");
        }
        elements.insert(element);
    }

    void removeElement(const T& element) {
        if (elements.find(element) == elements.end()) {
            throw ElementNotFoundException("Элемент не найден в множестве.");
        }
        elements.erase(element);
    }

    bool contains(const T& element) const {
        return elements.find(element) != elements.end();
    }

    QString toString() const {
        QString result = "{ ";
        for (const auto& e : elements) {
            result += QString(e) + " ";
        }
        result += "}";
        return result;
    }

};

template <typename T>
class ExtendedSetContainer : public SetContainer<T> {
public:
    int getSize() const { return this->elements.size(); }
};

#endif
