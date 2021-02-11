#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    struct Node* tail;
};

struct LinkedList* createLinkedList();
void insertAtTail(struct LinkedList*, int);
int deleteAtHead(struct LinkedList*);
void destroyLinkedList(struct LinkedList*);

struct LinkedList* createLinkedList() {

    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list -> head = malloc(sizeof(struct Node));
    list -> head -> value = 0;
    list -> head -> next = NULL;
    list -> tail = malloc(sizeof(struct Node));
    list -> tail = list -> head;
    return list;
}

void insertAtTail(struct LinkedList* list, int item) {
    
    list -> tail -> next = malloc(sizeof(struct Node));
    list -> tail -> next -> value = item;
    list -> tail -> next -> next = NULL;
    list -> tail = list -> tail -> next;
    return;

}

int deleteAtHead(struct LinkedList* list) {

    if (list -> head -> next == NULL)
        return -1;

    int element = list -> head -> next -> value;
    if (list -> head -> next == list -> tail) {
        list -> head -> next == NULL;
        free(list -> tail);
        list -> tail = malloc(sizeof(struct Node));
        list -> tail = list -> head;
        return element;
    }

    struct Node* delete = malloc(sizeof(struct Node));
    delete = list -> head -> next;
    list -> head -> next = list -> head -> next -> next;
    free(delete);
    return element;

}

void destroyLinkedList(struct LinkedList* list) {
    free(list);
    return;
}

struct Queue {
    struct LinkedList* list;
    int numElements;
};

struct Queue* createQueue();
_Bool isEmpty(struct Queue*);
void enqueue(struct Queue*, int item);
int dequeue(struct Queue*);
int front(struct Queue*);
int back(struct Queue*);
int getLength(struct Queue*);
void showQueue(struct Queue*);
void destroyQueue(struct Queue*);
void menu();

struct Queue* createQueue() {

    struct Queue* queue = malloc(sizeof(struct Queue));
    queue -> list = createLinkedList();
    queue -> numElements = 0;
    return queue;

}

_Bool isEmpty(struct Queue* queue) {
    return queue -> numElements == 0;
}

void enqueue(struct Queue* queue, int item) {
    insertAtTail(queue -> list, item);
    queue -> numElements = queue -> numElements + 1;
    return;
}

int dequeue(struct Queue* queue) {

    if (isEmpty(queue))
        return -1;

    int element = deleteAtHead(queue -> list);
    queue -> numElements = queue -> numElements - 1;
    return element;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) 
        return -1;
    return queue -> list -> tail -> value;
}

int back(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue -> list -> head -> next -> value;
}

int getLength(struct Queue* queue) {
    return queue -> numElements;
}

void showQueue(struct Queue* queue) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = queue -> list -> head -> next;

    while (currentNode != NULL) {
        printf("%d -> ", currentNode -> value);
        currentNode = currentNode -> next;
    }

    printf("NULL\n");
    return;
}

void destroyQueue(struct Queue* queue) {
    destroyLinkedList(queue -> list);
    free(queue);
    return;
}

void menu() {

    printf("1. See if the Queue is empty\n");
    printf("2. Enqueue an element intp the Queue\n");
    printf("3. Dequeue an element from the Queue\n");
    printf("4. See the front of the Queue\n");
    printf("5. See the back of the Queue\n");
    printf("6. Get the number of elements in the Queue\n");
    printf("7. Show the Queue\n");
    printf("8. Show the menu again\n");
    printf("9. Exit\n");
    return;

}

int main(int argc, char* argv[]) {

    int choice;
    int item, element, length, frnt, bck;
    _Bool check;
    _Bool exploring = true;

    struct Queue* queue = createQueue();
    menu();

    do {

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
            check = isEmpty(queue);
            if (check)
                printf("The Queue is empty\n");
            else
                printf("The Queue is not empty, it has some elements in it\n");
            break;

            case 2:
            printf("Enter the item you want to enqueue in the queue\n");
            scanf("%d", &item);
            enqueue(queue, item);
            break;

            case 3:
            if (isEmpty(queue))
                printf("Queue Underflow\n");
            else {
                element = dequeue(queue);
                printf("Dequeued %d out of the queue\n", element);
            }
            break;

            case 4:
            if (isEmpty(queue))
                printf("Queue Underflow\n");
            else {
                frnt = front(queue);
                printf("%d is at the front of the Queue\n", frnt);
            }
            break;
            
            case 5:
            if (isEmpty(queue))
                printf("Queue Underflow\n");
            else {
                bck = back(queue);
                printf("%d is at the back of the Queue\n", bck);
            }
            break;

            case 6:
            length = getLength(queue);
            printf("The queue has %d elements\n", length);
            break;

            case 7:
            showQueue(queue);
            break;

            case 8:
            menu();
            break;

            case 9:
            exploring = false;
            printf("Exititng...\n");
            break;

            default: 
            printf("Sorry Wrong Choice. Please Try Again\n");

        }

    }
    while (exploring);

    destroyQueue(queue);
    return 0;

}

