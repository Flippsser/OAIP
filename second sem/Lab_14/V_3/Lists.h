#pragma once

namespace listx {

    // Элемент связного списка.
    struct Element {
        Element* prev;
        Element* next;
        void* data;

        Element(Element* pr, void* dat, Element* nt) {
            prev = pr;
            data = dat;
            next = nt;
        }

        Element* getNext() const { return next; }
        Element* getPrev() const { return prev; }
    };

    // Структура, описывающая связный список (цепочку).
    struct Object {
        Element* head;

        Object() { head = nullptr; }

        // Получение первого элемента списка.
        Element* getFirst() const { return head; }

        // Получение последнего элемента списка.
        Element* getLast() const;

        // Поиск элемента по данным.
        Element* search(void* data) const;

        // Вставка элемента в список.
        bool insert(void* data);

        // Удаление указанного элемента.
        bool deleteByElement(Element* e);

        // Удаление элемента по данным.
        bool deleteByData(void* data);

        // Вывод содержимого списка.
        void scan() const;
    };

    // Функция создания нового списка.
    Object create();
}
