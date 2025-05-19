#include "Hash_Chain.h"
#include <iostream>
#include "Lists.h"  // ��� ������� � ����������� ��������� ��������

// ��������� ��������� School, ����� ������������ � ��� �������� ������.
struct School {
    int schoolNumber;      // ����� ����� (����)
    char* directorName;    // ������� ���������
};

namespace hashTC {

    Object create(int size, int (*f)(void*)) {
        return *(new Object(size, f));
    }

    int Object::hashFunction(void* data) const {
        // ��������� ������ �� ������� �� ������� �� ������ �������.
        return (FunKey(data) % size);
    }

    bool Object::insert(void* data) {
        // ���������� ��������� ������� hashFunction (����� this, ��� ��� ������� ������ const)
        return (Hash[this->hashFunction(data)].insert(data));
    }

    bool Object::deleteByData(void* data) {
        return (Hash[this->hashFunction(data)].deleteByData(data));
    }

    listx::Element* Object::search(void* data) const {
        return Hash[this->hashFunction(data)].search(data);
    }

    void Object::Scan() const {
        std::cout << "\n=== ���-������� ===\n";
        for (int i = 0; i < size; i++) {
            std::cout << "������ " << i << ": ";
            listx::Element* e = Hash[i].getFirst();
            if (e == nullptr) {
                std::cout << "[�����]" << std::endl;
            }
            else {
                while (e != nullptr) {
                    std::cout << "("
                        << ((School*)e->data)->schoolNumber << ", "
                        << ((School*)e->data)->directorName << ") -> ";
                    e = e->getNext();
                }
                std::cout << "[�����]\n";
            }
        }
    }
}
