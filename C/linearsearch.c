#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

_Bool linearsearch(int* arr, int size, int item) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == item)
            return true;
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
        if (linearsearch(arr, size, item))
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