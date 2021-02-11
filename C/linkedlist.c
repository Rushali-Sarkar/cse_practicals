#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct LinkedList* createLinkedList();
struct LinkedList* intialiseWithElements(struct LinkedList*, int*, int); 
void insertAtHead(struct LinkedList*, int);
void insertAtTail(struct LinkedList*, int);
_Bool isPresent(struct LinkedList*, int);
void insertBeforeNode(struct LinkedList*, int, int);
void insertAfterNode(struct LinkedList*, int, int);
void insertAtPosition(struct LinkedList*, int, int);
int getLength(struct LinkedList*);
void deleteAtHead(struct LinkedList*);
void deleteAtTail(struct LinkedList*);
void deleteAtPosition(struct LinkedList*, int);
void delete(struct LinkedList*, int);
void deleteAll(struct LinkedList*, int);
int* traverse(struct LinkedList*); 
void showtraverse(struct LinkedList*);
void print(struct LinkedList*);
void freeLinkedList(struct LinkedList*);
void menu();


struct LinkedList* createLinkedList() {

    struct LinkedList* list = malloc(sizeof(struct LinkedList));
    list -> head = malloc(sizeof(struct Node));
    list -> head -> value = 0;
    list -> head -> next = NULL;
    return list;
}

struct LinkedList* intialiseWithElements(struct LinkedList* list, int* arr, int size) {
    
    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head;
    for (int i = 0; i < size; i++) {
        currentNode -> next = malloc(sizeof(struct Node));
        currentNode -> next -> value = arr[i];
        currentNode = currentNode -> next;
    }
    return list;

}

void insertAtHead(struct LinkedList* list, int item) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode -> value = item;
    currentNode -> next = list -> head -> next;
    list -> head -> next = currentNode;
    return;

}

void insertAtTail(struct LinkedList* list, int item) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;

    if (currentNode == NULL) {  
        insertAtHead(list, item);
        return;
    }

    while (currentNode -> next != NULL)
        currentNode = currentNode -> next;
    currentNode -> next = malloc(sizeof(struct Node));
    currentNode -> next -> value = item;
    return;

}

_Bool isPresent(struct LinkedList* list, int item) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    while (currentNode != NULL) {
        if (currentNode -> value == item)
            return true;
        currentNode = currentNode -> next;
    }

    return false;
}

void insertBeforeNode(struct LinkedList* list, int node, int insert) {

    if (!isPresent(list, insert)) {
        insertAtHead(list, insert);
        return;
    }
    
    struct Node* previousNode = malloc(sizeof(struct Node));
    struct Node* currentNode = malloc(sizeof(struct Node));
    struct Node* newNode = malloc(sizeof(struct Node));

    previousNode = list -> head;
    currentNode = list -> head -> next;
    newNode -> value = insert;

    while (currentNode != NULL) {

        if (currentNode -> value == node) {
            previousNode -> next = newNode;
            newNode -> next = currentNode;
            return;
        }

        previousNode = currentNode;
        currentNode = currentNode -> next;
    }
    return;
}

void insertAfterNode(struct LinkedList* list, int node, int insert) {

     if (!isPresent(list, insert)) {
        insertAtTail(list, insert);
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    struct Node* newNode = malloc(sizeof(struct Node));

    currentNode = list -> head -> next;
    newNode -> value = insert;

    while (currentNode != NULL) {
        if (currentNode -> value == node) {
            newNode -> next = currentNode -> next;
            currentNode -> next = newNode;
            return;
        }
        currentNode = currentNode -> next;
    }

    return;
}

void insertAtPosition(struct LinkedList* list, int position, int item) {
    
    struct Node* currentNode = malloc(sizeof(struct Node*));
    struct Node* previousNode = malloc(sizeof(struct Node*));
    struct Node* newNode = malloc(sizeof(struct Node*));
    
    previousNode = list -> head;
    currentNode = list -> head -> next;
    newNode -> value = item;
    int current_position = 1;

    while (currentNode != NULL) {

        if (current_position == position) {
            previousNode -> next = newNode;
            newNode -> next = currentNode;
            return;
        }

        previousNode = currentNode;
        currentNode = currentNode -> next;
        current_position++;
    }

    int length = getLength(list);

    if (position > length)
        insertAtTail(list, item);
    
    if (position < 1)
        insertAtHead(list, item);
    
    return;
}

int getLength(struct LinkedList* list) {

    int length = 0;
    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    
    while (currentNode != NULL) {
        length++;
        currentNode = currentNode -> next;
    }

    return length;
}

void deleteAtHead(struct LinkedList* list) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    if (currentNode == NULL)
        return;
    
    list -> head -> next = list -> head -> next -> next;
    free(currentNode);
    return;

}

void deleteAtTail(struct LinkedList* list) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;

    if (currentNode == NULL)
        return;

    if (currentNode -> next == NULL) {
        deleteAtHead(list);
        return;
    }

    struct Node* parentNode = malloc(sizeof(struct Node));
    parentNode = currentNode;
    while (currentNode -> next != NULL ){
        parentNode = currentNode;
        currentNode = currentNode -> next;
    }
    parentNode -> next = NULL;
    free(currentNode);
    return;

}

void deleteAtPosition(struct LinkedList* list, int position) {

    struct Node* previousNode = malloc(sizeof(struct Node));
    struct Node* currentNode = malloc(sizeof(struct Node));
    
    previousNode = list -> head;
    currentNode = list -> head -> next;
    int current_position = 1;

    while (currentNode != NULL) {

        if (current_position == position) {
            previousNode -> next = currentNode -> next;
            return;
        }

        previousNode = currentNode;
        currentNode = currentNode -> next;
        current_position++;

    }

    return;
}

void delete(struct LinkedList* list, int item) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;

    if (currentNode == NULL)
        return;
    
    if (currentNode -> value == item) {
        list -> head -> next = currentNode -> next;
        free(currentNode);
        return;
    }

    struct Node* parentNode = malloc(sizeof(struct Node*));
    parentNode = currentNode;
    currentNode = currentNode -> next;

    while (currentNode != NULL) {

        if (currentNode -> value == item) {
            parentNode -> next = currentNode -> next;
            free(currentNode);
            return;
        }

        parentNode = currentNode;
        currentNode = currentNode -> next;
    }
    return;

}

void deleteAll(struct LinkedList* list, int item) {

    struct Node* parentNode = malloc(sizeof(struct Node*));
    struct Node* currentNode = malloc(sizeof(struct Node*));
    parentNode = list -> head;
    currentNode = parentNode -> next;

    while (currentNode != NULL) {

        if (currentNode -> value == item) {
            parentNode -> next = currentNode -> next;
            currentNode = currentNode -> next;
        }

        else {
            parentNode = currentNode;
            currentNode = currentNode -> next;
        }
    }
    return;
}



int* traverse(struct LinkedList* list) {
   
    int* arr = malloc(getLength(list) * sizeof(int));
    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    int index = 0;

    while (currentNode != NULL) {
        arr[index] = currentNode -> value;
        currentNode = currentNode -> next;
        ++index;
    }
    return arr;

}

void showtraverse(struct LinkedList* list) {

    int* arr = traverse(list);
    int arr_size = getLength(list);

    for (int i = 0; i < arr_size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
    return;
}

void print(struct LinkedList* list) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode -> value);
        currentNode = currentNode -> next;
    }
    printf("NULL\n");
    return;

}

void freeLinkedList(struct LinkedList* list) {
    free(list);
    return;
}

void menu() {

    printf("1. Initialise LinkedList with elements\n");
    printf("2. Insert an element at head of the linked list\n");
    printf("3. Insert an element at tail of the linked list\n");
    printf("4. Search an element within the linked list\n");
    printf("5. Insert an element before a node in the linked list\n");
    printf("6. Insert an element after a node in the linked list\n");
    printf("7. Insert an element in a given position in the linked list\n");
    printf("8. Get the lenght of the linked list\n");
    printf("9. Delete the head element of the linked list\n");
    printf("10. Delete the tail element of the linked list\n");
    printf("11. Delete a given element of the linked list\n");
    printf("12. Delete all occurence of an element in the linked list\n");
    printf("13. Show the elements in the Linked List\n");
    printf("14. Print the linked list\n");
    printf("15. Show Menu Again\n");
    printf("16. Exit\n");
    return;

}

int main(int argc, char* argv[]) {

    _Bool isExploring = true;
    struct LinkedList* list = createLinkedList();
    int choice;
    int elements, item, element, node, position, length;
    int* arr;
    _Bool found;
    
    menu();

    do {

        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {
            
            case 1: 
            printf("Enter the number of elements you want to enter\n");
            scanf("%d", &elements);
            printf("Enter %d elements\n", elements);
            arr = malloc(elements * sizeof(int));
            for (int i = 0; i < elements; i++)
                scanf("%d", &arr[i]);
            intialiseWithElements(list, arr, elements);
            break;

            case 2:
            printf("Enter the element you want to insert at head\n");
            scanf("%d", &item);
            insertAtHead(list, item);
            break;

            case 3:
            printf("Enter the element you want to insert at tail\n");
            scanf("%d", &item);
            insertAtTail(list, item);
            break;

            case 4:
            printf("Enter the element you want to search for\n");
            scanf("%d", &element);
            found = isPresent(list, element);
            if (found)
                printf("%d is present in the Linked List\n", element);
            else
                printf("%d is not present in the linked list\n", element);
            break;

            case 5:
            printf("Enter the node before which you want to enter the element\n");
            scanf("%d", &node);
            printf("Enter the item you want to insert\n");
            scanf("%d", &item);
            insertBeforeNode(list, node, item);
            break;

            case 6:
            printf("Enter the node after which you want to enter the element\n");
            scanf("%d", &node);
            printf("Enter the item you want to insert\n");
            scanf("%d", &item);
            insertAfterNode(list, node, item);
            break;

            case 7:
            printf("Enter the position where you want to enter the element\n");
            scanf("%d", &position);
            printf("Enter the item you want to insert\n");
            scanf("%d", &item);
            insertAtPosition(list, position, item);
            break;

            case 8:
            length = getLength(list);
            printf("The length of the linked list is %d\n", length);
            break;

            case 9:
            deleteAtHead(list);
            break;

            case 10:
            deleteAtTail(list);
            break;

            case 11:
            printf("Enter the element you want to delete\n");
            printf("Note: Only first occurence of the element will be deleted\n");
            element;
            scanf("%d", &element);
            delete(list, element);
            break;

            case 12:
            printf("Enter the element you want to delete\n");
            printf("Note: All occurence of the element will be deleted\n");
            element;
            scanf("%d", &element);
            deleteAll(list, element);
            break;

            case 13:
            showtraverse(list);
            break;

            case 14:
            print(list);
            break;

            case 15:
            menu();
            break;

            case 16:
            printf("Exiting....\n");
            isExploring = false;
            break;
            
            default: printf("Sorry Wrong Choice. Try Again.\n");
        }

    }
    while (isExploring);

    freeLinkedList(list);
    return 0;
}