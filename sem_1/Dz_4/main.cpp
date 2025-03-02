#include <iostream>
#include <vector>

const int curr_year = 2024;

class Student {
private:
    std::string surname;
    int birthYear;
    float mark;

public:
    Student(std::string surname, int birthYear, float mark): surname(surname), birthYear(birthYear), mark(mark) {}

    void showInfo() {
        std::cout << "Ученик " << surname << " родился в " << birthYear
                  << " году. Средняя годовая оценка: " << mark << std::endl;
    }

    int Age() {
        return curr_year - birthYear;
    }

    float getMark() { 
        return mark;
    }
    std::string getSurname() {
        return surname;
    }
    float getBirthYear(){
        return birthYear;
    }
};

class Group {
private:
    std::vector<Student> students;

public:
    void addStudent(std::string surname, int birthYear, float mark) {
       students.emplace_back(surname, birthYear, mark);
    }

    void showGroupInfo(){
        std::cout << "Информация обо всех учениках группы: " << std::endl;
        for (auto& student : students) {
            student.showInfo();
        }
    }

    int countAdults(){
        int count = 0;
        for (auto& student : students) {
            if (student.Age() >= 18) {
                count++;
            }
        }
        return count;
    }

    float percentOfExcellent(){
        int excellentCount = 0;
        for (auto& student : students) {
            if (student.getMark() == 5) {
                excellentCount++;
            }
        }
        return (static_cast<float>(excellentCount) / students.size() * 100);
    }
};

int main() {
    Group group;

    group.addStudent("Земсков", 2007, 3.1);
    group.addStudent("Иванов", 2004, 2.9);
    group.addStudent("Петров", 1998, 5.0);

    group.showGroupInfo();

    std::cout << "Количество совершеннолетних в группе: "
              << group.countAdults() << std::endl;

    std::cout << "Процент отличников в группе: "
              << group.percentOfExcellent() << "%" << std::endl;

    return 0;
}
