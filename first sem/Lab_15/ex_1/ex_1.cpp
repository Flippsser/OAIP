#include <stdio.h>	
#include <stdlib.h>

void main()
{
	int* ptr, i, n;
	printf("Input size of massiv, n<30 \n");
	scanf_s("%d", &n);

	if (!(ptr = (int*)malloc(n * sizeof(int))))   //выделение памяти и проверка, 
	{	                                      //достаточно ли для нее места
		puts("Not enough memory");
		return;
	}
	for (i = 0; i < n; i++)
	{
		printf("Input element [%d]\n", i + 1);
		scanf_s("%d", ptr + i);
	}
	printf("\nMassiv: \n", i + 1);
	for (i = 0; i < n; i++)
		printf("%d ", *(ptr + i));

	free(ptr);     //освобождение динамической памяти

}

