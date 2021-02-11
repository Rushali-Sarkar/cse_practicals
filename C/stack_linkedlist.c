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
int deleteAtTail(struct LinkedList*);
void destroyLinkedList(struct LinkedList*);

struct LinkedList* createLinkedList() {

    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list -> head = malloc(sizeof(struct Node));
    list -> head -> value = 0;
    list -> head -> next = NULL;
    list -> tail = malloc(sizeof(struct LinkedList));
    list -> tail = list -> head;
    return list;

}

void insertAtTail(struct LinkedList* list, int item) {

    list -> tail -> next = malloc(sizeof(struct Node*));
    list -> tail -> next -> value = item;
    list -> tail -> next -> next = NULL;
    list -> tail = list -> tail -> next;
    return;

}

int deleteAtTail(struct LinkedList* list) {

    if (list -> head == list -> tail) 
        return -1;

    int element = list -> tail -> value;
    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head;

    while (currentNode -> next != list -> tail)
        currentNode = currentNode -> next;
    
    currentNode -> next = NULL;
    free(list -> tail);
    list -> tail = malloc(sizeof(struct Node*));
    list -> tail = currentNode;
    return element;

}

void destroyLinkedList(struct LinkedList* list) {
    free(list);
    return;
}

struct Stack {
    struct LinkedList* list;
    int numElements;
};

struct Stack* createStack();
_Bool isEmpty(struct Stack*);
void push(struct Stack*, int);
int pop(struct Stack*);
int peek(struct Stack*);
int getLength(struct Stack*);
void showStack(struct Stack*);
void destroyStack(struct Stack*);
void menu();

struct Stack* createStack() {
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack -> list = createLinkedList();
    stack -> numElements = 0;
    return stack;
}

_Bool isEmpty(struct Stack* stack) {
    return stack -> numElements == 0;
}

void push(struct Stack* stack, int item) {
    insertAtTail(stack -> list, item);
    stack -> numElements = stack -> numElements + 1;
    return;
}

int pop(struct Stack* stack) {
    int element = deleteAtTail(stack -> list);
    stack -> numElements = stack -> numElements - 1;
    return element;
}

int peek(struct Stack* stack) {

    if (isEmpty(stack))
        return -1;
    return stack -> list -> tail -> value;
}

int getLength(struct Stack* stack) {
    return stack -> numElements;
}

void showStack(struct Stack* stack) {

    struct Node* currentNode = stack -> list -> head -> next;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode -> value);
        currentNode = currentNode -> next;
    }
    printf("NULL\n");
    return;
}

void destroyStack(struct Stack* stack) {
    destroyLinkedList(stack -> list);
    free(stack);
    return;
}

void menu() {

    printf("1. Check if the Stack is empty\n");
    printf("2. Push an element inside the stack\n");
    printf("3. Pop an element out of the stack\n");
    printf("4. Peek at the top of the stack\n");
    printf("5. Get the number of elemens in the stack\n");
    printf("6. Show the stack\n");
    printf("7. Show the menu again\n");
    printf("8. Exit\n");
    return;

}



int main(int argc, char* argv[]) {

    _Bool exploring = true;
    int choice, item, element, top, length;
    _Bool check;

    struct Stack* stack = createStack();
    menu();

    do {
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
            check = isEmpty(stack);
            if (check)
                printf("The Stack is Empty\n");
            else
                printf("The Stack has some elements, the stack is not empty\n");
            break;

            case 2:
            printf("Enter the item you want to push\n");
            scanf("%d", &item);
            push(stack, item);
            break;

            case 3:
            if (isEmpty(stack))
                printf("Stack Underflow\n");
            else {
                element = pop(stack);
                printf("Poped %d out of the stack\n", element);
            }
            break;

            case 4:
            if (isEmpty(stack))
                printf("The stack is empty. Nothing is there at the top\n");
            else {
                top = peek(stack);
                printf("%d is at the top of the stack\n", top);
            }
            break;

            case 5:
            length = getLength(stack);
            printf("The Stack has %d elements\n", length);
            break;

            case 6:
            showStack(stack);
            break;

            case 7:
            menu();
            break;

            case 8:
            printf("Exiting...\n");
            exploring = false;
            break;

            default:
            printf("Sorry Wrong Choice. Try Again\n");
            
        }

    }

    while (exploring);

    destroyStack(stack);
    return 0;

}