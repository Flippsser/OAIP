#include <iostream>
using namespace std;

int main() {
    int a = 99;
    const int* const pa = &a;
    //*pa = 33; // ошибка (нельзя менять содержимое переменной а)
    int b = 44;
    //pa = &b; // ошибка (кон-стантный указатель на константу менять нельзя)
    cout << *pa;

}
