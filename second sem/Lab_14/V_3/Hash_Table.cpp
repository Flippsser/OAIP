#include "Hash_Chain.h"
#include <iostream>
#include "Lists.h"  // Для доступа к определению списочных объектов

// Объявляем структуру School, чтобы использовать её для хранения данных.
struct School {
    int schoolNumber;      // Номер школы (ключ)
    char* directorName;    // Фамилия директора
};

namespace hashTC {

    Object create(int size, int (*f)(void*)) {
        return *(new Object(size, f));
    }

    int Object::hashFunction(void* data) const {
        // Вычисляем индекс по остатку от деления на размер таблицы.
        return (FunKey(data) % size);
    }

    bool Object::insert(void* data) {
        // Используем результат функции hashFunction (через this, так как функция теперь const)
        return (Hash[this->hashFunction(data)].insert(data));
    }

    bool Object::deleteByData(void* data) {
        return (Hash[this->hashFunction(data)].deleteByData(data));
    }

    listx::Element* Object::search(void* data) const {
        return Hash[this->hashFunction(data)].search(data);
    }

    void Object::Scan() const {
        std::cout << "\n=== Хеш-таблица ===\n";
        for (int i = 0; i < size; i++) {
            std::cout << "Индекс " << i << ": ";
            listx::Element* e = Hash[i].getFirst();
            if (e == nullptr) {
                std::cout << "[Пусто]" << std::endl;
            }
            else {
                while (e != nullptr) {
                    std::cout << "("
                        << ((School*)e->data)->schoolNumber << ", "
                        << ((School*)e->data)->directorName << ") -> ";
                    e = e->getNext();
                }
                std::cout << "[Конец]\n";
            }
        }
    }
}
