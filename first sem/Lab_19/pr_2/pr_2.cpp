#include <iostream>
#include <stdio.h>  
int main()
{
	setlocale(LC_ALL, "ru");
	FILE* mf; char str[50];   errno_t err;
	char* estr;
	printf("Введите текст ");
	fgets(str, sizeof(str), stdin);
	if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
	fopen_s(&mf, "tst.txt", "w");   
	fputs(str, mf); fputs("\n", mf);
	fclose(mf);
	err = fopen_s(&mf, "tst.txt", "r"); 
	if (err != NULL)              
	{
		printf("Ошибка открытия файла\n"); return -1;
	}
	else
		printf("\nСчитаны строки:\n");
	estr = fgets(str, sizeof(str), mf); 
	if (estr == NULL)        
		if (feof(mf) != 0)
			printf("\nЧтение файла закончено\n");
		else
		{
			printf("\nОшибка чтения из файла\n");
			return -1;
		}
	puts(str);
	if (fclose(mf) == EOF)
		printf("Ошибка закрытия\n");
	return 0;
}