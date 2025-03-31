#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Перечисление для предметов
enum Subject {
    MATH,
    PHYSICS,
    CHEMISTRY,
    BIOLOGY,
    HISTORY,
    GEOGRAPHY,
    ENGLISH,
    SUBJECT_COUNT // Количество предметов
};

// Структура для хранения оценок
struct Grade {
    Subject subject;
    int value;
};

// Структура для хранения информации о классе
struct ClassInfo {
    int gradeNumber : 4 ; // Номер класса (1-11)
};
int clin;
// Структура для хранения информации об ученике
struct Student {
    string fullName;
    ClassInfo admissionGrade;
    char gradeLetter; // Буква класса
    vector<Grade> grades;
    double averageGrade;
};

// Функция для преобразования предмета в строку
string subjectToString(Subject subject) {
    switch (subject) {
    case MATH: return "Math";
    case PHYSICS: return "Physics";
    case CHEMISTRY: return "Chemistry";
    case BIOLOGY: return "Biology";
    case HISTORY: return "History";
    case GEOGRAPHY: return "Geography";
    case ENGLISH: return "English";
    default: return "Unknown";
    }
}

// Функция для ввода информации об ученике с клавиатуры
Student inputStudent() {
    Student student;
    cout << "Введите ФИО ученика: ";
    getline(cin >> ws, student.fullName);
    cout << "Введите номер класса (1-11): ";
    cin >> clin;
    student.admissionGrade.gradeNumber = clin;
    cout << "Введите букву класса: ";
    cin >> student.gradeLetter;

    int numSubjects;
    cout << "Введите количество предметов: ";
    cin >> numSubjects;

    for (int i = 0; i < numSubjects; ++i) {
        Grade grade;
        int subjectIndex;
        cout << "Выберите предмет (0 - MATH, 1 - PHYSICS, ..., 6 - ENGLISH): ";
        cin >> subjectIndex;
        grade.subject = static_cast<Subject>(subjectIndex);
        cout << "Введите оценку: ";
        cin >> grade.value;
        student.grades.push_back(grade);
    }

    // Вычисление среднего балла
    double sum = 0;
    for (const auto& grade : student.grades) {
        sum += grade.value;
    }
    student.averageGrade = sum / student.grades.size();

    return student;
}

// Функция для вывода информации об ученике на экран
void printStudent(const Student& student) {
    cout << "ФИО: " << student.fullName << endl;
    cout << "Класс: " << student.admissionGrade.gradeNumber << student.gradeLetter << endl;
    cout << "Оценки:" << endl;
    for (const auto& grade : student.grades) {
        cout << "  " << grade.value << " (" << subjectToString(grade.subject) << ")" << endl;
    }
    cout << "Средний балл: " << fixed << setprecision(2) << student.averageGrade << endl;
}

// Функция для поиска ученика по фамилии
int findStudent(const vector<Student>& students, const string& fullName) {
    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].fullName == fullName) {
            return i;
        }
    }
    return -1; // Ученик не найден
}

// Функция для удаления ученика по фамилии
void deleteStudent(vector<Student>& students, const string& fullName) {
    int index = findStudent(students, fullName);
    if (index != -1) {
        students.erase(students.begin() + index);
        cout << "Ученик удален." << endl;
    }
    else {
        cout << "Ученик не найден." << endl;
    }
}

int main() {
    system("chcp 1251");
    vector<Student> students;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить ученика\n";
        cout << "2. Показать всех учеников\n";
        cout << "3. Найти ученика\n";
        cout << "4. Удалить ученика\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            students.push_back(inputStudent());
            break;
        case 2:
            for (const auto& student : students) {
                printStudent(student);
                cout << endl;
            }
            break;
        case 3: {
            string fullName;
            cout << "Введите ФИО ученика для поиска: ";
            getline(cin >> ws, fullName);
            int index = findStudent(students, fullName);
            if (index != -1) {
                printStudent(students[index]);
            }
            else {
                cout << "Ученик не найден." << endl;
            }
            break;
        }
        case 4: {
            string fullName;
            cout << "Введите ФИО ученика для удаления: ";
            getline(cin >> ws, fullName);
            deleteStudent(students, fullName);
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор." << endl;
        }
    } while (choice != 0);

    return 0;
}
