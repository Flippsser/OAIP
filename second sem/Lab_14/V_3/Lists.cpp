#include "Lists.h"
#include <iostream>

// Для демонстрационных целей определим структуру School (такая же, как в Hash_Table.cpp)
struct School {
    int schoolNumber;
    char* directorName;
};

namespace listx {

    bool Object::insert(void* data) {
        // Если список пуст, создаём новый элемент и назначаем его head.
        if (head == nullptr)
            head = new Element(nullptr, data, head);
        else
            head = (head->prev = new Element(nullptr, data, head));
        return true;
    }

    Element* Object::search(void* data) const {
        Element* rc = head;
        // Ищем элемент, сравнивая поле schoolNumber.
        while ((rc != nullptr) && ((((School*)rc->data)->schoolNumber) != ((School*)data)->schoolNumber))
            rc = rc->next;
        return rc;
    }

    bool Object::deleteByElement(Element* e) {
        if (e == nullptr) return false;
        if (e->next != nullptr)
            e->next->prev = e->prev;
        if (e->prev != nullptr)
            e->prev->next = e->next;
        else
            head = e->next;
        delete e;
        std::cout << "Элемент удален" << std::endl;
        return true;
    }

    bool Object::deleteByData(void* data) {
        return deleteByElement(search(data));
    }

    Element* Object::getLast() const {
        Element* e = getFirst(), * rc = getFirst();
        while (e != nullptr) {
            rc = e;
            e = e->getNext();
        }
        return rc;
    }

    Object create() {
        return *(new Object());
    }

    void Object::scan() const {
        Element* e = getFirst();
        while (e != nullptr) {
            std::cout << ((School*)e->data)->schoolNumber << " - "
                << ((School*)e->data)->directorName << " / ";
            e = e->getNext();
        }
    }
}
