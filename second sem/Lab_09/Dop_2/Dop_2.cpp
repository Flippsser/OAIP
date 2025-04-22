#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int NAME_SIZE = 31;

struct Student {
    char lastName[NAME_SIZE];
    char firstName[NAME_SIZE];
    char patronymic[NAME_SIZE];
    int birthYear;
    int course;
    int group;
    float marks[5];
    Student* next;
    Student* prev;
};

void appendStudent(Student** pHead, Student** pTail, Student* newStudent) {
    newStudent->next = nullptr;
    newStudent->prev = nullptr;
    if (*pTail == nullptr) {
        *pHead = newStudent;
        *pTail = newStudent;
    }
    else {
        (*pTail)->next = newStudent;
        newStudent->prev = *pTail;
        *pTail = newStudent;
    }
}

Student* createStudent() {
    Student* s = new Student();
    if (!s) {
        cerr << "Ошибка выделения памяти" << endl;
        return nullptr;
    }
    cout << "Введите фамилию: ";
    cin.getline(s->lastName, NAME_SIZE);
    cout << "Введите имя: ";
    cin.getline(s->firstName, NAME_SIZE);
    cout << "Введите отчество: ";
    cin.getline(s->patronymic, NAME_SIZE);
    cout << "Введите год рождения: ";
    cin >> s->birthYear;
    cout << "Введите курс: ";
    cin >> s->course;
    cout << "Введите номер группы: ";
    cin >> s->group;
    cout << "Введите оценки по 5 предметам (через пробел): ";
    for (int i = 0; i < 5; i++) {
        cin >> s->marks[i];
    }
    cin.ignore();
    s->next = nullptr;
    s->prev = nullptr;
    return s;
}

void displayStudent(Student* s) {
    cout << s->lastName << " " << s->firstName << " " << s->patronymic
        << ", год рождения: " << s->birthYear
        << ", курс: " << s->course
        << ", группа: " << s->group
        << ", оценки: ";
    for (int i = 0; i < 5; i++) {
        cout << s->marks[i] << " ";
    }
    cout << endl;
}

void printList(Student* head) {
    Student* cur = head;
    while (cur) {
        displayStudent(cur);
        cur = cur->next;
    }
}

void sortStudents(Student** pHead, Student** pTail) {
    vector<Student*> vec;
    Student* cur = *pHead;
    while (cur) {
        vec.push_back(cur);
        cur = cur->next;
    }
    sort(vec.begin(), vec.end(), [](Student* a, Student* b) -> bool {
        if (a->course != b->course)
            return a->course < b->course;
        int cmp = strcmp(a->lastName, b->lastName);
        if (cmp != 0) return cmp < 0;
        cmp = strcmp(a->firstName, b->firstName);
        if (cmp != 0) return cmp < 0;
        return strcmp(a->patronymic, b->patronymic) < 0;
        });
    if (vec.empty()) {
        *pHead = nullptr;
        *pTail = nullptr;
        return;
    }
    *pHead = vec[0];
    (*pHead)->prev = nullptr;
    for (size_t i = 1; i < vec.size(); i++) {
        vec[i]->prev = vec[i - 1];
        vec[i - 1]->next = vec[i];
    }
    *pTail = vec.back();
    (*pTail)->next = nullptr;
}

struct GroupStats {
    double sum[5];
    int count;
    GroupStats() {
        for (int i = 0; i < 5; i++) sum[i] = 0.0;
        count = 0;
    }
};

void computeGroupAverages(Student* head) {
    map<int, GroupStats> stats;
    Student* cur = head;
    while (cur) {
        stats[cur->group].count++;
        for (int i = 0; i < 5; i++) {
            stats[cur->group].sum[i] += cur->marks[i];
        }
        cur = cur->next;
    }
    for (auto& entry : stats) {
        int group = entry.first;
        GroupStats& gs = entry.second;
        cout << "Группа " << group << ":" << endl;
        for (int i = 0; i < 5; i++) {
            double avg = (gs.count > 0 ? gs.sum[i] / gs.count : 0);
            cout << "  Предмет " << i + 1 << " - средний балл: " << avg << endl;
        }
    }
}

void findOldestYoungest(Student* head) {
    if (!head) {
        cout << "Список студентов пуст." << endl;
        return;
    }
    Student* oldest = head;
    Student* youngest = head;
    Student* cur = head;
    while (cur) {
        if (cur->birthYear < oldest->birthYear)
            oldest = cur;
        if (cur->birthYear > youngest->birthYear)
            youngest = cur;
        cur = cur->next;
    }
    cout << "Самый старший студент:" << endl;
    displayStudent(oldest);
    cout << "Самый младший студент:" << endl;
    displayStudent(youngest);
}

void findBestStudentsPerGroup(Student* head) {
    map<int, pair<Student*, float>> best;
    
    Student* cur = head;
    
    while (cur) {
        float avg = 0;
       
        for (int i = 0; i < 5; i++) {
            avg += cur->marks[i];
        }
        avg /= 5;
        if (best.find(cur->group) == best.end() || avg > best[cur->group].second)
            best[cur->group] = make_pair(cur, avg);
       
        cur = cur->next;
       
    }
    for (auto& entry : best) {
        int group = entry.first;
       
        Student* bestStudent = entry.second.first;
       
        float bestAvg = entry.second.second;
       
        cout << "Группа " << group << " - лучший студент: " << bestStudent->lastName << " "
            << bestStudent->firstName << " " << bestStudent->patronymic
            << " со средним баллом: " << bestAvg << endl;
    }
}


int main() {
    system("chcp 1251");
    Student* head = nullptr;
    Student* tail = nullptr;
    int choice;
    do {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Вывести список студентов" << endl;
        cout << "3. Отсортировать студентов (по курсу и алфавиту)" << endl;
        cout << "4. Вывести средний балл каждой группы по каждому предмету" << endl;
        cout << "5. Найти самого старшего и самого младшего студента" << endl;
        cout << "6. Найти лучшего студента каждой группы" << endl;
        cout << "7. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            Student* s = createStudent();
            appendStudent(&head, &tail, s);
            break;
        }
        case 2: {
            printList(head);
            break;
        }
        case 3: {
            sortStudents(&head, &tail);
            cout << "Список студентов отсортирован." << endl;
            break;
        }
        case 4: {
            computeGroupAverages(head);
            break;
        }
        case 5: {
            findOldestYoungest(head);
            break;
        }
        case 6: {
            findBestStudentsPerGroup(head);
            break;
        }
        case 7:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор, попробуйте ещё раз." << endl;
        }
    } while (choice != 7);
    Student* cur = head;
    while (cur) {
        Student* next = cur->next;
        delete cur;
        cur = next;
    }
    return 0;
}
