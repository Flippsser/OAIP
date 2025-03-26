#include <iostream>
using namespace std;

const int MAX_EXAMS = 10;

struct Student {
    string name;
    int numExams;
    int marks[MAX_EXAMS];
};

bool allMarksAboveThree(const Student& student) {
    for (int i = 0; i < student.numExams; ++i) {
        if (student.marks[i] < 4) return false;
    }
    return true;
}

double calculatePerformance(const Student students[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (allMarksAboveThree(students[i])) ++count;
    }
    return (double(count) / size) * 100;
}

int main() {
    system("chcp 1251");
    Student students[] = {
        {"Иван Иваныч", 3, {5, 4, 4}},
        {"Анна Иванова", 4, {4, 5, 5, 4}},
        {"Петр Петров", 2, {3, 4}}
    };

    cout << "Успеваемость: "
        << calculatePerformance(students, 3) << "%" << endl;
    return 0;
}
