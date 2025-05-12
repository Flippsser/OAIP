#include "Heap.h"
#include <iostream>
#include <iomanip>

using namespace std;

void AAA::print() {
    cout << x;
}

namespace heap {
    Heap* create(int maxsize, CMP(*f)(void*, void*)) {
        return new Heap(maxsize, f);
    }

    Heap::Heap(int maxsize, CMP(*f)(void*, void*)) {
        size = 0;
        storage = new void* [maxSize = maxsize];
        compare = f;
    }

    int Heap::left(int ix) { return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1); }
    int Heap::right(int ix) { return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2); }
    int Heap::parent(int ix) { return (ix + 1) / 2 - 1; }

    void Heap::swap(int i, int j) {
        void* buf = storage[i];
        storage[i] = storage[j];
        storage[j] = buf;
    }

    void Heap::heapify(int ix) {
        int l = left(ix), r = right(ix), irl = ix;
        if (l >= 0) {
            if (isGreat(storage[l], storage[ix])) irl = l;
            if (r >= 0 && isGreat(storage[r], storage[irl])) irl = r;
            if (irl != ix) {
                swap(ix, irl);
                heapify(irl);
            }   
        }
    }

    void Heap::insert(void* x) {
        int i;
        if (!isFull()) {
            storage[i = size++] = x;
            while (i > 0 && isLess(storage[parent(i)], storage[i])) {
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }

    void* Heap::extractMax() {
        void* rc = nullptr;
        if (!isEmpty()) {
            rc = storage[0];
            storage[0] = storage[--size];
            heapify(0);
        }
        return rc;
    }

    void* Heap::extractMin() {
        if (isEmpty()) return nullptr;

        int minIndex = 0;
        for (int i = 1; i < size; i++) {
            if (isLess(storage[i], storage[minIndex])) {
                minIndex = i;
            }
        }

        void* minElement = storage[minIndex];
        storage[minIndex] = storage[--size];
        heapify(minIndex);
        return minElement;
    }

    void* Heap::extractI(int i) {
        if (i < 0 || i >= size) return nullptr;

        void* removedElement = storage[i];
        storage[i] = storage[--size];
        heapify(i);
        return removedElement;
    }

    Heap* Heap::unionHeap(Heap* other) {
        Heap* newHeap = new Heap(this->size + other->size, this->compare);
        for (int i = 0; i < this->size; i++) {
            newHeap->insert(this->storage[i]);
        }
        for (int i = 0; i < other->size; i++) {
            newHeap->insert(other->storage[i]);
        }
        return newHeap;
    }

    void Heap::scan() const {
        if (size == 0) {
            cout << "Куча пуста\n";
            return;
        }

        cout << "\nЭлементы кучи:\n";
        int level = 0;
        int count = 1;
        int currentCount = 0;

        for (int u = 0; u < size; u++) {
            cout << setw(4) << ((AAA*)storage[u])->x;
            currentCount++;

            if (currentCount == count) {
                cout << '\n';
                level++;
                count *= 2;
                currentCount = 0;
            }
        }
        cout << '\n';
    }

    bool Heap::isFull() const { return (size >= maxSize); }
    bool Heap::isEmpty() const { return (size <= 0); }
    bool Heap::isLess(void* x1, void* x2) const { return compare(x1, x2) == LESS; }
    bool Heap::isGreat(void* x1, void* x2) const { return compare(x1, x2) == GREAT; }
    bool Heap::isEqual(void* x1, void* x2) const { return compare(x1, x2) == EQUAL; }
}