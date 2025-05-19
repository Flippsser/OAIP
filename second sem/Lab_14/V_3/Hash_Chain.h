#pragma once
#include "Lists.h"  // ��� ������� � �������

namespace hashTC {

    // ��������� ���-������� � ���������.
    struct Object {
        int size;                        // ������ ���-������� (���������� �������)
        int (*FunKey)(void*);            // �������, ����������� ���� �� ������
        listx::Object* Hash;             // ������ �������� ������ (�������)

        Object(int siz, int (*f)(void*)) {
            size = siz;
            FunKey = f;
            Hash = new listx::Object[size];  // ��������� ������ ��� ������� �������
        };

        // ���������� ������� � ������� �� ���-�������.
        int hashFunction(void* data) const;

        // ������� �������� � ������� (� �������, ��������������� ������������ �������).
        bool insert(void* data);

        // ����� ��������; ��������� ��� const, ��� ��� �� �������� ��������� �������.
        listx::Element* search(void* data) const;

        // �������� �������� �� ������.
        bool deleteByData(void* data);

        // ����� ���� ������� (������ ������� ��������� ��������).
        void Scan() const;
    };

    // ������� �������� ���-�������.
    Object create(int size, int (*f)(void*));
}
