#include <iostream>
int main()
{
setlocale(LC_CTYPE, "Russian");
int k;
puts("Вы хотите купить автомобиль? (1-да, 2-нет)");
std::cin >> k;
switch (k)
{
case 1: {
    puts("Какой? (1-.Майбах,. 2-Тойота,. З-BMW)");
    std::cin >> k;
    switch (k)
    {
    case 1: puts("Нe слишком дорого?"); break;
    case 2: puts("Хорoший sыбoр"); break;
    case 3: puts("Отличный выбор");break;
    }
    break;
        }
    case 2: puts("Полезно ходить пешком"); break;
    default: puts("Некорректный вариант"); break;
    }
    return 0;
}