#include "Heap.h"
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2) {
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL;
    if (A1->x > A2->x) rc = heap::GREAT;
    else if (A2->x > A1->x) rc = heap::LESS;
    return rc;
#undef A2
#undef A1 
}

int main() {
    setlocale(LC_ALL, "rus");
    int k, choice;
    heap::Heap* h1 = heap::create(30, cmpAAA);
    heap::Heap* h2 = heap::create(30, cmpAAA);

    for (;;) {
        cout << "1 - ����� ������ ���� �� �����" << endl;
        cout << "2 - ����� ������ ���� �� �����" << endl;
        cout << "3 - �������� ������� � ������ ����" << endl;
        cout << "4 - ������� ������������ ������� �� ������ ����" << endl;
        cout << "5 - ������� ����������� ������� �� ������ ����" << endl;
        cout << "6 - ������� i-�� ������� �� ������ ����" << endl;
        cout << "7 - �������� ������� �� ������ ����" << endl;
        cout << "8 - ���������� ��� ����" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� �����" << endl;
        cin >> choice;

        switch (choice) {
        case 0: exit(0);
        case 1: h1->scan(); break;
        case 2: h2->scan(); break; 
        case 3: {
            AAA* a = new AAA;
            cout << "������� ����" << endl;
            cin >> k;
            a->x = k;
            h1->insert(a);
        } break;
        case 4: h1->extractMax(); break;
        case 5: {
            void* minElement = h1->extractMin();
            if (minElement) {
                cout << "������ ����������� �������: " << ((AAA*)minElement)->x << endl;
                delete (AAA*)minElement;
            }
        } break;
        case 6: {
            cout << "������� ������ ��� ��������" << endl;
            cin >> k;
            void* removedElement = h1->extractI(k);
            if (removedElement) {
                cout << "������ ������� � �������� " << k << ": " << ((AAA*)removedElement)->x << endl;
                delete (AAA*)removedElement;
            }
            else {
                cout << "������������ ������!" << endl;
            }
        } break;
        case 7: { 
            AAA* a = new AAA;
            cout << "������� ���� ��� ������ ����" << endl;
            cin >> k;
            a->x = k;
            h2->insert(a);
        } break;
        case 8: {
            heap::Heap* newHeap = h1->unionHeap(h2);
            delete h1; 
            h1 = newHeap; 
            cout << "���� ����������." << endl;
        } break;
        default: cout << "������� �������� �������!" << endl;
        }
    }
    return 0;
}