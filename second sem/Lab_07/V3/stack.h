    #ifndef STACK_H
#define STACK_H

struct Node {
    int data;
    Node* next;
};

void push(Node** top, int data);
int pop(Node** top);
bool isEmpty(Node* top);
void printStack(Node* top);
void clearStack(Node** top);
bool removeFirstPositive(Node** top);

#endif