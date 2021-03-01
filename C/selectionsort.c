#include <stdio.h>
#include <malloc.h>

int* selectionsort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int minimum = arr[i];
        int minimum_index = i;
        for (int j = i + 1; j < size; j ++) {
            if (arr[j] < minimum) {
                minimum = arr[j];
                minimum_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = minimum;
        arr[minimum_index] = temp;
    }
    return arr;
}

void show(int* arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return;
}

int main(int argc, char* argv[]) {
    int size;
    int* arr;
    printf("Enter the number of elememts you want to enter in the array\n");
    scanf("%d", &size);
    arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    printf("The elements in sorted array is: \n");
    arr = selectionsort(arr, size);
    show(arr, size);
    return 0;
}