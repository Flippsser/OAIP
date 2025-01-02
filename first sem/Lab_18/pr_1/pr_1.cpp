#include <iostream>
using namespace std;
int f1 (const char *s)
{  cout << s <<" \nВыполняется тест №1" << endl;
   return 1;
}
int f2 (const char *s)
{  cout << s<<" \nВыполняется тест №2" << endl;
   return 2;
}
void callfun (const char *s, int (*f)(const char *))
{  cout << " f() = " << f(s) << '\n';
}
int main ()
{  setlocale(0, "Rus");
   callfun("Тест №1 вызван", f1);
   callfun("Тест №2 вызван", f2);
}
