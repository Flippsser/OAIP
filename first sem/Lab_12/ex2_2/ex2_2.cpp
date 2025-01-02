#include <iostream>
using namespace std;

int main() {
    int a = 99;
    int* const pa = &a;
    int b = 44;
    //pa = &b; // ошибка (константный указатель ме-нять нельзя)
    *pa = 12;
    cout << *pa;
}