#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void calculateProductAndSum(float* array, int size, float* product, float* sum) {
    *product = 1;
    *sum = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            *product *= array[i];
        }
        if (i < maxIndex && array[i] > 0) {
            *sum += array[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int p;
    printf("Введите количество элементов массива: ");
    scanf_s("%d", &p);

    float* array = (float*)malloc(p * sizeof(float));
    if (array == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < p; i++) {
        scanf_s("%f", &array[i]);
    }

    float product, sum;
    calculateProductAndSum(array, p, &product, &sum);

    printf("Произведение отрицательных элементов: %.2f\n", product);
    printf("Сумма положительных элементов до максимального: %.2f\n", sum);

    free(array);
    return 0;
}
