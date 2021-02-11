#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Queue {

    int front;
    int back;
    int capacity;
    int numElements;
    int* array;
};

struct Queue* createQueue(int);
_Bool isEmpty(struct Queue*);
_Bool isFull(struct Queue*);
void enqueue(struct Queue*, int);
int dequeue(struct Queue*);
int getLength(struct Queue*);
int front(struct Queue*);
int back(struct Queue*);
void showQueue(struct Queue*);
void destroyQueue(struct Queue*);
void menu();

struct Queue* createQueue(int capacity) {

    struct Queue* queue = malloc(sizeof(struct Queue));
    queue -> front = -1;
    queue -> back  = 0;
    queue -> numElements = 0;
    queue -> capacity = capacity;
    queue -> array = malloc(capacity * sizeof(int));
    return queue;
}

_Bool isEmpty(struct Queue* queue) {
    return queue -> numElements == 0;
}

_Bool isFull(struct Queue* queue) {
    return queue -> numElements == queue -> capacity;
}

void enqueue(struct Queue* queue, int item) {

    if (isFull(queue))
        return;

    if (queue -> front == queue -> capacity - 1)
        queue -> front = -1;

    queue -> array[++queue -> front] = item;
    queue -> numElements++;
    return;
}

int dequeue(struct Queue* queue) {

    if (isEmpty(queue))
        return -1;

    if (queue -> back == queue -> capacity) {
       queue -> back = 0;
    }

    queue -> numElements--;
    int element = queue -> array[queue -> back++];
    return element;
}

int getLength(struct Queue* queue) {
    return queue -> numElements;
}

int front(struct Queue* queue) {

    if (isEmpty(queue))
        return -1;
    
    return queue -> array[queue -> front];

}

int back(struct Queue* queue) {

    if (isEmpty(queue))
        return -1;
    if (queue -> back == queue -> capacity)
        return queue -> array[0];
    return queue -> array[queue -> back];

}


void showQueue(struct Queue* queue) {

    if (queue -> numElements == 0) {
        printf("Queue Underflow\n");
        return;
    }
    
    int end = queue -> front > queue -> back ? queue -> front: queue -> capacity - 1;

    for (int i = queue -> back; i <= end; i++)
        printf("%d\t", queue -> array[i]);
    
    if (queue -> front < queue -> back) {
        for (int i = 0; i <= queue -> front; i++)
            printf("%d\t", queue -> array[i]);
    }

    printf("\n");
    return;
}

void destroyQueue(struct Queue* queue) {
    free(queue);
    return;
}

void menu() {

    printf("1. See if the Queue is full\n");
    printf("2. See if the Queue is empty\n");
    printf("3. Enqueue an element in the Queue\n");
    printf("4. Dequeue an element from the Queue\n");
    printf("5. Get the number of elements in the Queue\n");
    printf("6. See the element at the front of the Queue\n");
    printf("7. See the element at the back of the Queue\n");
    printf("8. Show the Queue\n");
    printf("9. Show the menu Again\n");
    printf("10. Exit\n");
    return;
}



int main(int argc, char* argv[]) {

    int choice, item, element, length, frnt, bck, size;
    _Bool check;
    _Bool isExploring = true;

    printf("Enter the size of the Queue\n");
    scanf("%d", &size);

    struct Queue* queue = createQueue(size);
    menu();

    do {
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
            check = isFull(queue);
            if (check)
                printf("The Queue is full\n");
            else
                printf("The Queue is not yet full\n");
            break;

            case 2:
            check = isEmpty(queue);
            if (check)
                printf("The Queue is empty\n");
            else
                printf("The Queue has some elements, it is not empty\n");
            break;

            case 3:
            if (isFull(queue))
                printf("The Queue is already full, you cannot enter an element\n");
            else {
                printf("Enter the element you want to enqueue in the Queue\n");
                scanf("%d", &item);
                enqueue(queue, item);
            }
            break;

            case 4:
            if (isEmpty(queue))
                printf("There are no elements to dequeue from the Queue\n");
            else {
                element = dequeue(queue);
                printf("Dequeed %d from the Queue\n", element);
            }
            break;

            case 5:
            length = getLength(queue);
            printf("The queue as %d elements\n", length);
            break;

            case 6:
            if (isEmpty(queue))
                printf("There is nothing in the front of the Queue\n");
            else {
                frnt = front(queue);
                printf("%d is in the front of the Queue\n", frnt);
            }
            break;

            case 7:
            if (isEmpty(queue))
                printf("There is nothing at the back of the Queue\n");
            else {
                bck = back(queue);
                printf("%d is at the back of the Queue\n", bck);
            }
            break;

            case 8:
            showQueue(queue);
            break;

            case 9:
            menu();
            break;

            case 10:
            printf("Exiting...\n");
            isExploring = false;
            break;

            default:
            printf("Sorry you have entered a Wrong Choice. Please Try Again.\n");
        }

    }
    while (isExploring);

    destroyQueue(queue);

    return 0;
}
