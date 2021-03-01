#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int* quicksort_helper(int* arr, int starting_index, int ending_index) {
    if (starting_index >= ending_index) 
        return arr;
    int pivot_index = starting_index;
    int left_index = starting_index + 1;
    int right_index = ending_index;
    while (right_index >= left_index) {
        if (arr[left_index] > arr[pivot_index] && arr[right_index] < arr[pivot_index]) {
            int temp = arr[left_index];
            arr[left_index] = arr[right_index];
            arr[right_index] = temp;
        }
        else if (arr[left_index] <= arr[pivot_index]) 
            left_index++;
        else if (arr[right_index] >= arr[pivot_index])
            right_index--;
    }
    int temp = arr[pivot_index];
    arr[pivot_index] = arr[right_index];
    arr[right_index] = temp;
    quicksort_helper(arr, starting_index, right_index - 1);
    quicksort_helper(arr, right_index + 1, ending_index);
    return arr;
}

int* quicksort(int* arr, int size) {
    return quicksort_helper(arr, 0, size - 1);
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
    arr = quicksort(arr, size);
    show(arr, size);
    return 0;
}