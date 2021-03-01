#include <stdio.h>
#include <malloc.h>


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
    arr = heapsort(arr, size);
    show(arr, size);
    return 0;
}