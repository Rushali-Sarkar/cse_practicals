#include <stdio.h>
#include <malloc.h>

int* merge(int* arr1, int size1, int* arr2, int size2) {
    int index1 = 0;
    int index2 = 0;
    int* sorted_arr = malloc((size1 + size2) * sizeof(int));
    int sorted_index = 0;
    while (index1 < size1 && index2 < size2) {
        if (arr1[index1] < arr2[index2])
            sorted_arr[sorted_index++] = arr1[index1++];
        else if(arr2[index1] < arr1[index1])
            sorted_arr[sorted_index++] = arr2[index2++];
        else if(arr1[index1] = arr2[index2]) {
            sorted_arr[sorted_index++] = arr1[index1++];
            sorted_arr[sorted_index++] = arr2[index2++];
        }
    }
    while (index1 < size1)
        sorted_arr[sorted_index++] = arr1[index1++];
    while (index2 < size2)
        sorted_arr[sorted_index++] = arr2[index2++];
    return sorted_arr;
}

int* initialize(int* arr, int start, int end) {
    int* new_arr = malloc((end - start) * sizeof(int));
    int index = 0;
    for (int i = start; i < end; i++)
        new_arr[index++] = arr[i];
    return new_arr;
}

int* mergesort(int* arr, int size) {
    if (size <= 1)
        return arr;
    int middle_index = size / 2;
    int* left_half = initialize(arr, 0, middle_index);
    int* right_half = initialize(arr, middle_index, size);
    return merge(mergesort(left_half, middle_index), middle_index, mergesort(right_half, (size - middle_index)), (size - middle_index));
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
    arr = mergesort(arr, size);
    show(arr, size);
    return 0;
}