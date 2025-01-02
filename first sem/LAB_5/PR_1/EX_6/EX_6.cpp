#include <iostream>
int main()
{
    setlocale(LC_CTYPE, "Russian");
    int k;
    puts("Как себя чувствуете? (1-хорошо, 2-не оч)");
    std::cin >> k;
    switch (k)
    {
    case 2: {
        puts("Чего? (1-Да какое то недомогание. 2-Обожаю свой уник. З-Оч длиный сон)");
        std::cin >> k;
        switch (k)
        {
        case 1: puts("Покажись врачу"); break;
        case 2: puts("Сам(а) выбрал(а)"); break;
        case 3: puts("ну, тут как бы на этом мои полномочия всё"); break;
        }
        break;
            }
    case 1: puts("Завидую"); break;
    default: puts("Некорректный вариант"); break;
    }
    return 0;
}