#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int arr[], int n) {
    // Выбираем шаг
    int gap = n / 2;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            
            // Сдвигаем элементы на шаг вправо, пока не будет найдено место для вставки
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            
            arr[j] = temp;
        }
        
        // Уменьшаем шаг
        gap /= 2;
    }
}

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int* left = (int*)malloc(mid * sizeof(int));
    int* right = (int*)malloc((size - mid) * sizeof(int));

    if (left == NULL || right == NULL) {
        printf("Ошибка выделения памяти.\n");
        exit(1);
    }

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generateAscending(int* arr, int n) {
    srand(time(NULL));
    int step = 100000 / n;  // Шаг изменения значений

    for (int i = 0; i < n; i++) {
        arr[i] = i * step + rand() % step;
    }
}

void generateDescending(int* arr, int n) {
    srand(time(NULL));
    int step = 100000 / n;  // Шаг изменения значений

    for (int i = 0; i < n; i++) {
        arr[i] = (n - i - 1) * step + rand() % step;
    }
}

void generateRandom(int* arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}