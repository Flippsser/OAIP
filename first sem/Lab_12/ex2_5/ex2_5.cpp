#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int const n = 100;
    int A[n], sz, i;
    cout << "Размер?";
    cin >> sz;

    for (i = 0; i < sz; i++) {
        *(A + i) = rand() % 99;
        cout << *(A + i) << endl;
    }
    
    int* ptr = A;
    int max = *ptr;
    for (int i = 1; i < sz; ++i) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }
    cout << endl << max << endl;
}
