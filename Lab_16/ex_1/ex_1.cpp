#include <iostream>
int  square(int);
void main()
{
    for (int x = 1; x <= 10; x++)
        std::cout << square(x) << ' ';
}
int square(int  y)
{
    return y * y;
}
