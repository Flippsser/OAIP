#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

union StudentData {
    char fullName[100];
    struct {
        int gradeNumber;
        char gradeLetter;
    };
    struct {
        char subjects[200];
        int grades[10];
    };
    double averageGrade;
};

struct Student {
    StudentData data;
    char fullName[100];
    int gradeNumber;
    char gradeLetter;
    vector<string> subjects;
    vector<int> grades;
    double averageGrade;
};

Student inputStudent() {
    Student student;
    cout << "Введите ФИО ученика: ";
    cin.ignore();
    cin.getline(student.fullName, 100);
    cout << "Введите номер класса (1-11): ";
    cin >> student.gradeNumber;
    cout << "Введите букву класса: ";
    cin >> student.gradeLetter;
    int subjectCount;
    cout << "Введите количество предметов: ";
    cin >> subjectCount;
    cin.ignore();
    student.subjects.clear();
    student.grades.clear();
    for (int i = 0; i < subjectCount; ++i) {
        string subject;
        int grade;
        cout << "Введите название предмета: ";
        getline(cin, subject);
        student.subjects.push_back(subject);
        cout << "Введите оценку по предмету: ";
        cin >> grade;
        cin.ignore();
        student.grades.push_back(grade);
    }
    double gradeSum = 0;
    for (const auto& grade : student.grades) {
        gradeSum += grade;
    }
    student.averageGrade = gradeSum / student.grades.size();
    return student;
}

void writeToFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }
    for (const auto& student : students) {
        outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
    outFile.close();
    cout << "Данные успешно записаны в файл." << endl;
}

void readFromFile(vector<Student>& students, const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return;
    }
    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        students.push_back(student);
    }
    inFile.close();
    cout << "Данные успешно считаны из файла." << endl;
}

void printStudent(const Student& student) {
    cout << "ФИО: " << student.fullName << endl;
    cout << "Класс: " << student.gradeNumber << student.gradeLetter << endl;
    cout << "Предметы и оценки: " << endl;
    for (size_t i = 0; i < student.subjects.size(); ++i) {
        cout << "  " << student.subjects[i] << ": " << student.grades[i] << endl;
    }
    cout << "Средний балл: " << fixed << setprecision(2) << student.averageGrade << endl;
}

void searchByLastName(const vector<Student>& students, const string& lastName) {
    bool found = false;
    for (const auto& student : students) {
        if (string(student.fullName).find(lastName) != string::npos) {
            printStudent(student);
            cout << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Ученик с указанной фамилией не найден." << endl;
    }
}

void printAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "Список учеников пуст." << endl;
        return;
    }
    for (const auto& student : students) {
        printStudent(student);
        cout << endl;
    }
}

int main() {
    system("chcp 1251");
    vector<Student> students;
    string filename = "students.dat";
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить ученика\n";
        cout << "2. Показать всех учеников\n";
        cout << "3. Найти ученика по фамилии\n";
        cout << "4. Записать данные в файл\n";
        cout << "5. Считать данные из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1:
            students.push_back(inputStudent());
            break;
        case 2:
            printAllStudents(students);
            break;
        case 3: {
            string lastName;
            cout << "Введите фамилию ученика для поиска: ";
            cin.ignore();
            getline(cin, lastName);
            searchByLastName(students, lastName);
            break;
        }
        case 4:
            writeToFile(students, filename);
            break;
        case 5:
            readFromFile(students, filename);
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);
    return 0;
}
