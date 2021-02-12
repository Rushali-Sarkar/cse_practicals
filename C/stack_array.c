#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Stack {
    int top;
    int capacity;
    int* array;
    int numElements;
};

struct Stack* createStack(int);
_Bool isFull(struct Stack*);
_Bool isEmpty(struct Stack*);
void push(struct Stack*, int);
int pop(struct Stack*);
int peek(struct Stack*);
void showStack(struct Stack*);
int getLength(struct Stack*);
void menu();
void destroyStack(struct Stack*);

struct Stack* createStack(int capacity) {

    struct Stack* stack = malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = malloc(stack -> capacity * sizeof(int));
    stack -> numElements = 0;
    return stack;

}

_Bool isFull(struct Stack* stack) {
    return stack -> top == stack -> capacity - 1;
}

_Bool isEmpty(struct Stack* stack) {
    return stack -> top == -1;
}

void push(struct Stack* stack, int item) {

    if (isFull(stack))
        return;

    stack -> numElements++;
    stack -> array[++(stack -> top)] = item;
    return;
}

int pop(struct Stack* stack) {

    if (isEmpty(stack))
        return -1;

    stack -> numElements--;
    return stack -> array[(stack -> top)--];
}

int peek(struct Stack* stack) {

    if (isEmpty(stack))
        return -1;

    return stack -> array[stack -> top];
}

void showStack(struct Stack* stack) {
        
    int i;
    for (i = 0; i <= stack -> top; i++)
        printf("%d\t", stack -> array[i]);
    printf("\n");
    return;
}

int getLength(struct Stack* stack) {
    return stack -> numElements;
}

void menu() {

    printf("1. Check if the stack is Full\n");
    printf("2. Check if the stack is Empty\n");
    printf("3. Push an element inside the stack\n");
    printf("4. Pop an element from the stack\n");
    printf("5. Get the number of elements in the stack\n");
    printf("6. Peek at the top element of the stack\n");
    printf("7. Show the stack\n");
    printf("8. Show the menu again\n");
    printf("9. Exit\n");
    return;
}

void destroyStack(struct Stack* stack) {
    free(stack);
    return;
}

int main(int argc, char* argv[]) {

    int size;
    int choice;
    int item, element, top, length;
    _Bool isExploring = true;
    _Bool check;

    printf("Enter the size of the Stack\n");
    scanf("%d", &size);
    struct Stack* stack = createStack(size);
    menu();

    do {

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
            check = isFull(stack);
            if (check)
                printf("The stack is full\n");
            else
                printf("No the stack is not yet full\n");
            break;

            case 2:
            check = isEmpty(stack);
            if (check)
                printf("The stack is empty\n");
            else
                printf("The stack is not empty\n");
            break;

            case 3:
            if (isFull(stack)) 
                printf("Stack Overflow\n");
            else {
                printf("Enter the element you want to push in the stack\n");
                scanf("%d", &item);
                push(stack, item);
            }
            break;

            case 4:
            if (isEmpty(stack))
                printf("Nothing to pop. Stack Underflow\n");
            else {
                element = pop(stack);
                printf("Poped %d out of the stack\n", element);
            }
            break;

            case 5:
            length = getLength(stack);
            printf("The stack has %d elements\n", length);
            break;

            case 6:
            if (isEmpty(stack))
                printf("There is nothing at the top of the stack. Stack underflow\n");
            else {
                top = peek(stack);
                printf("The top of the stack has %d\n", top);
            }
            break;

            case 7:
            showStack(stack);
            break;

            case 8:
            menu();
            break;

            case 9:
            printf("Exiting...\n");
            isExploring = false;
            break;
            
            default: 
            printf("Sorry you entered a wrong choice. Please try again\n");

        }
    }

    while (isExploring);
    destroyStack(stack);
    return 0;
}