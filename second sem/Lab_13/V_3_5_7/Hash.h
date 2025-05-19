#pragma once

#include <iostream>

enum HashMethod { MULTIPLICATIVE, UNIVERSAL, MODULAR };

struct Object {
    void** data;
    int size;
    int N;
    int (*getKey)(void*);

    Object(int, int(*)(void*));
    bool insert(void*);
    int searchInd(int key);
    void* search(int key);
    void* deleteByKey(int key);
    bool deleteByValue(void*);
    void scan(void(*)(void*));
};

static void* DEL = (void*)-1; // Маркер удалённого элемента

Object create(int size, int(*getkey)(void*));
