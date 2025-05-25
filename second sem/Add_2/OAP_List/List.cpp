#include "List.h"
#include <iostream>

Element::Element(Element* prev, void* data, Element* next) {
    Prev = prev;
    Data = data;
    Next = next;
}

Element* Element::GetNext() {
    return Next;
}

Element* Element::GetPrev() {
    return Prev;
}

Object::Object() {
    Head = nullptr;
}

Element* Object::GetFirst() {
    return Head;
}

Element* Object::GetLast() {
    Element* temp = Head;
    if (!temp)
        return nullptr;
    while (temp->Next != nullptr) {
        temp = temp->Next;
    }
    return temp;
}

bool Object::Insert(void* data) {
    if (Head == nullptr) {
        Head = new Element(nullptr, data, nullptr);
    }
    else {
        Element* newElement = new Element(nullptr, data, Head);
        Head->Prev = newElement;
        Head = newElement;
    }
    return true;
}

bool Object::InsertEnd(void* data) {
    if (Head == nullptr) {
        Head = new Element(nullptr, data, nullptr);
    }
    else {
        Element* last = GetLast();
        Element* newElement = new Element(last, data, nullptr);
        last->Next = newElement;
    }
    return true;
}

Element* Object::Search(void* data) {
    Element* temp = Head;
    while (temp != nullptr) {
        if (temp->Data == data)
            return temp;
        temp = temp->Next;
    }
    return nullptr;
}

bool Object::Delete(Element* e) {
    if (e == nullptr)
        return false;
    if (e->Prev != nullptr) {
        e->Prev->Next = e->Next;
    }
    else {
        Head = e->Next;
    }
    if (e->Next != nullptr) {
        e->Next->Prev = e->Prev;
    }
    delete e;
    return true;
}

bool Object::Delete(void* data) {
    Element* e = Search(data);
    if (e != nullptr) {
        return Delete(e);
    }
    return false;
}

bool Object::DeleteList() {
    while (Head != nullptr) {
        Element* temp = Head;
        Head = Head->Next;
        delete temp;
    }
    return true;
}

void Object::PrintList(void (*f)(void*)) {
    Element* temp = Head;
    while (temp != nullptr) {
        f(temp->Data);
        temp = temp->Next;
    }
}

void Object::PrintList(void (*f)(void*), Element* e) {
    if (e != nullptr) {
        f(e->Data);
    }
}

int Object::CountList() {
    int count = 0;
    Element* temp = Head;
    while (temp != nullptr) {
        count++;
        temp = temp->Next;
    }
    return count;
}

Object Create() {
    return Object();
}
