#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int* bubblesort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]= temp;
            }
        }
    }
    return arr;
}

_Bool binarysearch(int* arr, int size, int item) {
    arr = bubblesort(arr, size);
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == item)
            return true;
        else if (item < arr[middle])
            right = middle - 1;
        else if (item > arr[middle])
            left = middle + 1; 
    }
    return false;
}

int main(int argc, char* argv[]) {
    int size;
    int* arr;
    printf("Enter the number of elememts you want to enter in the array\n");
    scanf("%d", &size);
    arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    int item;
    bool isExploring = true;
    while (isExploring) {
        int item;
        printf("Enter the item you want to search for:\n");
        scanf("%d", &item);
        if (binarysearch(arr, size, item))
            printf("%d is present in the array.\n", item);
        else
            printf("%d is not present in the array.\n", item);
        printf("Press any number to continue 0 to exit!\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 0)
            isExploring = false;
    }
    return 0;
}

