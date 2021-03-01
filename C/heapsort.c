#include <stdio.h>
#include <malloc.h>

int* shiftdown(int* arr, int current_index, int ending_index) {
    int first_child_index = current_index * 2  + 1;
    while (first_child_index <= ending_index) {
        int second_child_index = current_index * 2 + 2;
        int index_to_swap = first_child_index;
        if (second_child_index > ending_index)
            second_child_index = -1;
        if (second_child_index != -1 && arr[second_child_index]> arr[first_child_index])
            index_to_swap = second_child_index;
        if (arr[current_index] < arr[index_to_swap]) {
            int temp = arr[current_index];
            arr[current_index] = arr[index_to_swap];
            arr[index_to_swap] = temp;
            current_index = index_to_swap;
            first_child_index = 2 * current_index + 1;
        }
        else
            break;
    }
    return arr;
}

int* maxheapify(int* arr, int size) {
    int first_parent_index = ((size - 1) - 1) / 2;
    for (int current_index = first_parent_index; current_index >= 0; current_index--)
        shiftdown(arr, current_index, size - 1);
    return arr;
}

int* heapsort(int* arr, int size) {
    arr = maxheapify(arr, size);
    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        shiftdown(arr, 0, i - 1);
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
    arr = heapsort(arr, size);
    show(arr, size);
    return 0;
}