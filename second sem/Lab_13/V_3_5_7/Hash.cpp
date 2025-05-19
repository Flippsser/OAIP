#include "Hash.h"
#include <iostream>

// ћультипликативное хеширование
int HashFunctionMultiplicative(int key, int size) {
    double A = 0.6180339887499;
    return int(size * (key * A - int(key * A)));
}

// ”ниверсальное хеширование
int HashFunctionUniversal(int key, int size) {
    int a = 7, b = 3, p = 31;
    return ((a * key + b) % p) % size;
}

// Ћинейное пробирование
int Next_hashLinear(int hash, int size, int i) {
    return (hash + i) % size;
}

extern HashMethod selectedMethod;

int HashFunction(int key, int size) {
    if (selectedMethod == MULTIPLICATIVE)
        return HashFunctionMultiplicative(key, size);
    else if (selectedMethod == UNIVERSAL)
        return HashFunctionUniversal(key, size);
    else
        return key % size;
}

int Next_hash(int hash, int size, int i) {
    return Next_hashLinear(hash, size, i);
}

Object create(int size, int(*getkey)(void*)) {
    return *(new Object(size, getkey));
}

Object::Object(int size, int(*getkey)(void*)) {
    N = 0;
    this->size = size;
    this->getKey = getkey;
    data = new void* [size];
    for (int i = 0; i < size; i++)
        data[i] = NULL;
}

bool Object::insert(void* d) {
    int key = getKey(d);
    int hash = HashFunction(key, size);
    for (int i = 0; i < size; i++) {
        int index = Next_hash(hash, size, i);
        if (data[index] == NULL || data[index] == DEL) {
            data[index] = d;
            N++;
            return true;
        }
    }
    return false;
}

int Object::searchInd(int key) {
    int hash = HashFunction(key, size);
    for (int i = 0; i < size; i++) {
        int index = Next_hash(hash, size, i);
        if (data[index] == NULL)
            return -1;
        if (data[index] != DEL && getKey(data[index]) == key)
            return index;
    }
    return -1;
}

void* Object::search(int key) {
    int index = searchInd(key);
    return (index >= 0) ? data[index] : NULL;
}

void* Object::deleteByKey(int key) {
    int index = searchInd(key);
    if (index < 0)
        return NULL;
    void* t = data[index];
    data[index] = DEL;
    N--;
    return t;
}

bool Object::deleteByValue(void* d) {
    return (deleteByKey(getKey(d)) != NULL);
}

void Object::scan(void(*f)(void*)) {
    for (int i = 0; i < size; i++) {
        std::cout << "Ёлемент " << i;
        if (data[i] == NULL)
            std::cout << ": пусто" << std::endl;
        else if (data[i] == DEL)
            std::cout << ": удален" << std::endl;
        else
            f(data[i]);
    }
}
