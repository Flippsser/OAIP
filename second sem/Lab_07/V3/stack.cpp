#include "stack.h"
#include <iostream>

void push(Node** top, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (isEmpty(*top)) {
        std::cerr << "Стек пуст!" << std::endl;
        return -1;
    }
    Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    delete temp;
    return poppedData;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

void printStack(Node* top) {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void clearStack(Node** top) {
    while (!isEmpty(*top)) {
        pop(top);
    }
}

bool removeFirstPositive(Node** top) {
    if (isEmpty(*top)) {
        return false;
    }


    if ((*top)->data > 0) {
        Node* temp = *top;
        *top = (*top)->next;
        delete temp;
        return true;
    }


    Node* current = *top;
    while (current->next != nullptr) {
        if (current->next->data > 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        current = current->next;
    }

    return false;
}