#pragma once
#include "Lists.h"  // Для доступа к спискам

namespace hashTC {

    // Структура хеш-таблицы с цепочками.
    struct Object {
        int size;                        // Размер хеш-таблицы (количество цепочек)
        int (*FunKey)(void*);            // Функция, вычисляющая ключ из данных
        listx::Object* Hash;             // Массив объектов списка (цепочек)

        Object(int siz, int (*f)(void*)) {
            size = siz;
            FunKey = f;
            Hash = new listx::Object[size];  // Выделение памяти для массива цепочек
        };

        // Вычисление индекса в таблице по хеш-функции.
        int hashFunction(void* data) const;

        // Вставка элемента в таблицу (в цепочку, соответствующую вычисленному индексу).
        bool insert(void* data);

        // Поиск элемента; объявлена как const, так как не изменяет состояние объекта.
        listx::Element* search(void* data) const;

        // Удаление элемента по данным.
        bool deleteByData(void* data);

        // Вывод всей таблицы (каждая цепочка выводится отдельно).
        void Scan() const;
    };

    // Функция создания хеш-таблицы.
    Object create(int size, int (*f)(void*));
}
