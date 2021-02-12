#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
};

struct CircularLinkedList {
    struct Node* head;
    struct Node* tail;
};

struct CircularLinkedList* createCircularLinkedList();
void traverse(struct CircularLinkedList*);
void insertAtHead(struct CircularLinkedList*, int);
void insertAtTail(struct CircularLinkedList*, int);
_Bool search(struct CircularLinkedList*, int);
void insertBeforeNode(struct CircularLinkedList*, int, int);
void insertAfterNode(struct CircularLinkedList*, int, int);
void deleteAtHead(struct CircularLinkedList*);
void deleteAtTail(struct CircularLinkedList*);
void deleteNode(struct CircularLinkedList*, int);
void menu();

struct CircularLinkedList* createCircularLinkedList() {
    
    struct CircularLinkedList* list = malloc(sizeof(struct CircularLinkedList));
    list -> head = malloc(sizeof(struct Node));
    list -> head -> value = 0;
    list -> head -> next = NULL;
    list -> tail = malloc(sizeof(struct Node));
    list -> tail = list -> head;
    return list;

}

void traverse(struct CircularLinkedList* list) {

    if (list -> head == list -> tail) {
        printf("NULL\n");
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;

    while (currentNode != list -> tail) {
        printf("%d -> ", currentNode -> value);
        currentNode = currentNode -> next;
    }

    printf("%d -> %d\n", list -> tail -> value, list -> head -> next -> value);
    return;

}

void insertAtHead(struct CircularLinkedList* list, int item) {

    if (list -> head == list -> tail) {
        insertAtTail(list, item);
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode -> value = item;
    currentNode -> next = list -> head -> next;
    list -> head -> next = currentNode;
    list -> tail -> next = list -> head -> next;
    return;

}

void insertAtTail(struct CircularLinkedList* list, int item) {

    list -> tail -> next = malloc(sizeof(struct Node));
    list -> tail -> next -> value = item;
    list -> tail -> next -> next = list -> head -> next;
    list -> tail = list -> tail -> next;
    return;
}

_Bool search(struct CircularLinkedList* list, int item) {

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    if (currentNode == NULL)
        return false;

    if (list -> tail -> value == item || list -> head -> next -> value == item)
        return true;

    currentNode = currentNode -> next;
    while (currentNode != list -> head -> next) {
        if (currentNode -> value == item)
            return true;
        currentNode = currentNode -> next;
    }
    return false;

}

void insertBeforeNode(struct CircularLinkedList* list, int node, int item) {

    if (list -> head == list -> tail)
        return;

    if (list -> head -> next -> value == node) {
        insertAtHead(list, item);
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    struct Node* parentNode = malloc(sizeof(struct Node));
    currentNode = list -> head;

    while (currentNode != list -> tail) {

        if (currentNode -> value == node) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode -> value = item;
            newNode -> next = currentNode;
            parentNode -> next = newNode;
            return;
        }

        parentNode = currentNode;
        currentNode = currentNode -> next;

    }

    if (currentNode -> value == node) {
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode -> value = item;
        newNode -> next = currentNode;
        parentNode -> next = newNode;
    }

    return;

}

void insertAfterNode(struct CircularLinkedList* list, int node, int item) {

    if (list -> head -> next == NULL) 
        return;

    if (list -> tail -> value == node) {
        insertAtTail(list, item);
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;

    while (currentNode != list -> tail) {

        if (currentNode -> value == node) {
            struct Node* newNode = malloc(sizeof(struct Node));
            newNode -> value = item;
            newNode -> next = currentNode -> next;
            currentNode -> next = newNode;
            return;
        }
        currentNode = currentNode -> next;

    }

    return;
}

void deleteAtHead(struct CircularLinkedList* list) {

    if (list -> head -> next == NULL)
        return;

    if (list -> head -> next == list -> tail) {
        struct Node* delete = malloc(sizeof(struct Node));
        delete = list -> head -> next;
        list -> head -> next == NULL;
        list -> tail = list -> head;
        free(delete);
        return;
    }

    struct Node* delete = malloc(sizeof(struct Node));
    delete = list -> head -> next;
    list -> head -> next = list -> head -> next -> next;
    list -> tail -> next = list -> head -> next;
    free(delete);
    return;
}

void deleteAtTail(struct CircularLinkedList* list) {

    if (list -> head -> next == NULL)
        return;

    if (list -> head -> next == list -> tail) {
        struct Node* delete = malloc(sizeof(struct Node));
        delete = list -> head -> next;
        list -> head -> next == NULL;
        list -> tail = list -> head;
        free(delete);
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;

    while (currentNode -> next != list -> tail) 
        currentNode = currentNode -> next;

    struct Node* delete = malloc(sizeof(struct Node));
    delete = currentNode -> next;
    list -> tail = currentNode;
    currentNode -> next = list -> head -> next;
    free(delete);
    return;

}

void deleteNode(struct CircularLinkedList* list, int item) {

    if (list -> head -> next == NULL)
        return;

    if (list -> head -> next -> value == item) {
        deleteAtHead(list);
        return;
    }

    if (list -> tail -> value == item) {
        deleteAtTail(list);
        return;
    }

    struct Node* currentNode = malloc(sizeof(struct Node));
    currentNode = list -> head -> next;
    struct Node* parentNode = malloc(sizeof(struct Node));
    parentNode = list -> head;

    while (currentNode != list -> tail) {

        if (currentNode -> value == item) {
            struct Node* delete = malloc(sizeof(struct Node));
            delete = currentNode;
            parentNode -> next = currentNode -> next;
            free(delete);
            return;
        }

        parentNode = currentNode;
        currentNode = currentNode -> next;
    }

    return;
}

void menu() {

    printf("1. Traverse the list\n");
    printf("2. Insert at the head\n");
    printf("3. Insert at the tail\n");
    printf("4. Insert before a node\n");
    printf("5. Insert after a node\n");
    printf("6. Delete at head\n");
    printf("7. Delete at tail\n");
    printf("8. Delete a particular node\n");
    printf("9. Search for an element\n");
    printf("10. Show menu again\n");
    printf("11. Exit\n");
    return;

}

int main(int argc, char* argv[]) {

    int choice;
    int item, node, element;
    _Bool check;
    _Bool exploring = true;

    struct CircularLinkedList* list = createCircularLinkedList();
    menu();
    
    do {

        printf("Enter your choice\n");
        scanf("%d", &choice);
        
        switch(choice) {
    
        case 1:
        traverse(list);
        break;

        case 2:
        printf("Enter the element you want to enter\n");
        scanf("%d", &item);
        insertAtHead(list, item);
        break;

        case 3:
        printf("Enter the element you want to enter\n");
        scanf("%d", &item);
        insertAtTail(list, item);
        break;

        case 4:
        printf("Enter the node before which you want to enter\n");
        scanf("%d", &node);
        printf("Enter the element you want to enter\n");
        scanf("%d", &item);
        insertBeforeNode(list, node, item);
        break;

        case 5:
        printf("Enter the node after which you want to enter\n");
        scanf("%d", &node);
        printf("Enter the element you want to enter\n");
        scanf("%d", &item);
        insertAfterNode(list, node, item);
        break;

        case 6:
        deleteAtHead(list);
        break;

        case 7:
        deleteAtTail(list);
        break;

        case 8:
        printf("Enter the node which you want to delete\n");
        scanf("%d", &element);
        deleteNode(list, element);
        break;

        case 9:
        printf("Enter the element you want to search for\n");
        scanf("%d", &element);
        check = search(list, element);
        if (check)
            printf("%d is present in the circular linked list\n", element);
        else
            printf("%d is not present in the circular linked list\n", element);
        break;
        

        case 10:
        menu();
        break;

        case 11:
        printf("Exiting...\n");
        exploring = false;
        break;

        default:
        printf("Sorry Wrong Choice. Please try again.\n");
        }
        
    }
    while (exploring);

    free(list);
    return 0;

}