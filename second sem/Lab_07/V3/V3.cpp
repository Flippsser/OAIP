#include "stack.h"
#include <iostream>
#include <windows.h>
void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Добавить элемент в стек\n";
    std::cout << "2. Удалить элемент из стека\n";
    std::cout << "3. Вывести содержимое стека\n";
    std::cout << "4. Очистить стек\n";
    std::cout << "5. Удалить первый положительный элемент\n";
    std::cout << "6. Выход\n";
    std::cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Node* top = nullptr;
    int choice, value;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение: ";
            std::cin >> value;
            push(&top, value);
            break;
        case 2:
            value = pop(&top);
            if (value != -1) {
                std::cout << "Удалено: " << value << std::endl;
            }
            break;
        case 3:
            std::cout << "Содержимое стека: ";
            printStack(top);
            break;
        case 4:
            clearStack(&top);
            std::cout << "Стек очищен" << std::endl;
            break;
        case 5:
            if (removeFirstPositive(&top)) {
                std::cout << "Первый положительный элемент удален" << std::endl;
            }
            else {
                std::cout << "Положительные элементы не найдены" << std::endl;
            }
            break;
        case 6:
            std::cout << "Выход..." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 6);

    clearStack(&top);
    return 0;
}