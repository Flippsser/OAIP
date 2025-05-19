#pragma once

namespace listx {

    // ������� �������� ������.
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

    // ���������, ����������� ������� ������ (�������).
    struct Object {
        Element* head;

        Object() { head = nullptr; }

        // ��������� ������� �������� ������.
        Element* getFirst() const { return head; }

        // ��������� ���������� �������� ������.
        Element* getLast() const;

        // ����� �������� �� ������.
        Element* search(void* data) const;

        // ������� �������� � ������.
        bool insert(void* data);

        // �������� ���������� ��������.
        bool deleteByElement(Element* e);

        // �������� �������� �� ������.
        bool deleteByData(void* data);

        // ����� ����������� ������.
        void scan() const;
    };

    // ������� �������� ������ ������.
    Object create();
}
