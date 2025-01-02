#include <iostream>   
#include <stdio.h>   
#include <string.h>  
int main(void)
{
    setlocale(LC_CTYPE, "ru");
    FILE* fp;
    errno_t err;
    char const* st = "привет";
    err = fopen_s(&fp, "a.bin", "w");
    if (err != 0)
    {
        perror("ошибка открытия a.bin");
        return EXIT_FAILURE;
    }
    fwrite(st, strlen(st), 1, fp);
    printf("Элемент записан\n");
    fclose(fp);
    // Открытие файла для чтения
    err = fopen_s(&fp, "a.bin", "r");
    if (err != 0)
    {
        perror("ошибка открытия a.bin для чтения");
        return EXIT_FAILURE;
    }
    // Чтение содержимого файла и вывод на экран
    char buffer[256];
    size_t bytesRead = fread(buffer, 1, sizeof(buffer) - 1, fp);
    if (bytesRead > 0)
    {
        buffer[bytesRead] = '\0';
        printf("Содержимое файла: %s\n", buffer);
    }
    else
    {
        printf("Файл пуст или произошла ошибка чтения\n");
    }
    fclose(fp);
    return 0;
}