#include <iostream>
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int const n=100;
    int A[n],sz,i,max;
    cout <<"Размер?";
    cin >> sz;
   
    for (i = 0; i < sz; i++) {
        A[i] = rand() % 99;
        cout << A[i]<<endl;
    }
    for (i = 1; i < sz; i++) {
        if (A[i] > A[i - 1]) {
            max = A[i];
        }
        
    }
    cout << endl << max << endl;
}
