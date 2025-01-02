#include <stdio.h>
#include <iostream>
int main()
{
    setlocale(LC_ALL, "");
    int a; errno_t err;
    FILE* f;
    err = fopen_s(&f, "test.txt", "w");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (a = 0; a < 70; a += 3)
    {
        fprintf(f, "%d, ", a);
    }
    printf("Данные записаны в файл test.txt\n");
    fclose(f);
    // Открытие файла для чтения
    err = fopen_s(&f, "test.txt", "r");
    if (err != 0)
    {
        perror("Невозможно открыть файл для чтения\n");
        return EXIT_FAILURE;
    }
    // Чтение и вывод содержимого файла
    printf("Содержимое файла test.txt:\n");
    char ch;
    while ((ch = fgetc(f)) != EOF)
    {
        putchar(ch);
    }
    fclose(f);
    return 0;
}
