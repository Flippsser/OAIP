#include "Heap.h"
#include <iostream>
#include <iomanip>

void AAA::print() {
    std::cout << x;
}

namespace heap {
    Heap create(int maxsize, CMP(*f)(void*, void*)) {
        return *(new Heap(maxsize, f));
    }

    int Heap::left(int ix) {
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
    }

    int Heap::right(int ix) {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
    }

    int Heap::parent(int ix) {
        return (ix + 1) / 2 - 1;
    }

    void Heap::swap(int i, int j) {
        void* buf = storage[i];
        storage[i] = storage[j];
        storage[j] = buf;
    }

    void Heap::heapify(int ix) {
        int l = left(ix), r = right(ix), largest = ix;
        if (l != -1 && isGreat(storage[l], storage[largest])) {
            largest = l;
        }
        if (r != -1 && isGreat(storage[r], storage[largest])) {
            largest = r;
        }
        if (largest != ix) {
            swap(ix, largest);
            heapify(largest);
        }
    }

    void Heap::insert(void* x) {
        if (!isFull()) {
            int i = size;
            storage[i] = x;
            size++;
            while (i > 0 && isLess(storage[parent(i)], storage[i])) {
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }

    void* Heap::extractMax() {
        if (isEmpty())
            return nullptr;
        void* maxVal = storage[0];
        storage[0] = storage[size - 1];
        size--;
        heapify(0);
        return maxVal;
    }

    void* Heap::extractMin() {
        if (isEmpty())
            return nullptr;
        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (isLess(storage[i], storage[minIndex])) {
                minIndex = i;
            }
        }
        void* minVal = storage[minIndex];
        storage[minIndex] = storage[size - 1];
        size--;
        heapify(minIndex);
        return minVal;
    }

    void* Heap::extractI(int i) {
        if (i < 0 || i >= size)
            return nullptr;
        void* val = storage[i];
        storage[i] = storage[size - 1];
        size--;
        heapify(i);
        return val;
    }

    void Heap::unionHeap(Heap& other) {
        for (int i = 0; i < other.size; i++) {
            insert(other.storage[i]);
        }
    }

    void Heap::scan(int i) const {
        if (size == 0) {
            std::cout << "Куча не содержит элементов.\n";
            return;
        }
        int level = 0;
        int index = 0;
        while (index < size) {
            int levelCount = 1 << level; 
            std::cout << "Уровень " << level << ": ";
            for (int j = 0; j < levelCount && index < size; j++, index++) {
                ((AAA*)storage[index])->print();
                std::cout << " ";
            }
            std::cout << "\n";
            level++;
        }
    }
}
