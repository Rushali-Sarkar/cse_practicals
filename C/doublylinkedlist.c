#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
};

struct doublylinkedlist {
    struct Node* head; 
};

struct doublylinkedlist* createDoublyLinkedList();
void traverse(struct doublylinkedlist*);
void insertAtHead(struct doublylinkedlist*, int);
void insertAtTail(struct doublylinkedlist*, int);
void insertBeforeNode(struct doublylinkedlist*, int, int);
void insertAfterNode(struct doublylinkedlist*, int, int);
void deleteAtHead(struct doublylinkedlist*);
void deleteAtTail(struct doublylinkedlist*);
void deleteParticularNode(struct doublylinkedlist*, int);
void menu();

struct doublylinkedlist* createDoublyLinkedList() {
    struct doublylinkedlist* dllist = malloc(sizeof(struct doublylinkedlist));
    dllist -> head = malloc(sizeof(struct Node));
    dllist -> head -> data = 0;
    dllist -> head -> previous = NULL;
    dllist -> head -> next = NULL;
    return dllist;
}

void traverse(struct doublylinkedlist* dllist) {
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head -> next;
    while (current_node -> next != NULL) {
        printf("%d <--> ", current_node -> data);
        current_node = current_node -> next;
    }
    printf("%d -> NULL\n", current_node -> data);
    return;
}

void insertAtHead(struct doublylinkedlist* dllist, int item) {
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head;
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node -> data = item;
    current_node = dllist -> head;
    if (current_node -> next == NULL) {
        new_node -> previous = dllist -> head;
        new_node -> next = NULL;
        dllist -> head -> next = new_node;
        return;
    }
    new_node -> next = current_node -> next;
    current_node -> next -> previous = new_node;
    new_node -> previous = current_node;
    current_node -> next = new_node;
    return;
}

void insertAtTail(struct doublylinkedlist* dllist, int item) {
    if (dllist -> head -> next == NULL) {
        insertAtHead(dllist, item);
        return;
    }
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node -> data = item;
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head;
    while (current_node -> next != NULL) 
        current_node = current_node -> next;
    current_node -> next = new_node;
    new_node -> next = NULL;
    new_node -> previous = current_node;
    return;
}

void insertBeforeNode(struct doublylinkedlist* dllist, int node, int item) {
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head -> next;
    while (current_node != NULL) {
        if (current_node -> data == node) {
            if (dllist -> head -> next -> data == node) {
                insertAtHead(dllist, item);
                return;
            }
            struct Node* new_node = malloc(sizeof(struct Node));
            new_node -> data = item;
            new_node -> next = current_node;
            new_node -> previous = current_node -> previous;
            current_node -> previous = new_node;
            new_node -> previous -> next  = new_node;
            return;
        }
        current_node = current_node -> next;
    }
    return;
}

void insertAfterNode(struct doublylinkedlist* dllist, int node, int item) {
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head -> next;
    while (current_node != NULL) {
        if (current_node -> data == node) {
            if (current_node -> next == NULL) {
                insertAtTail(dllist, item);
                return;
            }
            struct Node* new_node = malloc(sizeof(struct Node));
            new_node -> data = item;
            new_node -> previous = current_node;
            new_node -> next = current_node -> next;
            current_node -> next = new_node;
            new_node -> next -> previous = new_node;
            return;
        }
        current_node = current_node -> next;
    }
}

void deleteAtHead(struct doublylinkedlist* dllist) {
    if (dllist -> head -> next == NULL)
        return;
    struct Node* to_delete = malloc(sizeof(struct Node));
    to_delete = dllist -> head -> next;
    dllist -> head -> next = dllist -> head -> next -> next;
    if (dllist -> head -> next != NULL)
        dllist -> head -> next -> previous = dllist -> head;
    free(to_delete);
    return;
}

void deleteAtTail(struct doublylinkedlist* dllist) {
    if(dllist -> head -> next == NULL)
        return;
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist  -> head -> next;
    while (current_node -> next != NULL)
        current_node = current_node -> next;
    struct Node* to_delete = malloc(sizeof(struct Node));
    to_delete = current_node;
    current_node -> previous -> next = NULL;
    free(to_delete);
    return;    
}

void deleteParticularNode(struct doublylinkedlist* dllist, int node) {
    if (dllist -> head -> next == NULL)
        return;
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head -> next;
    if (current_node -> data == node) {
        deleteAtHead(dllist);
        return;
    }
    while (current_node -> next != NULL) {
        if (current_node -> data == node) {
            struct Node* to_delete = malloc(sizeof(struct Node));
            to_delete = current_node;
            current_node -> previous -> next = to_delete -> next;
            current_node -> next -> previous = to_delete -> previous;
            free(to_delete);
            return;
        }
        current_node = current_node -> next;
    }
    if (current_node -> data == node) {
        deleteAtTail(dllist);
        return;
    }
    return;
}

int isPresent(struct doublylinkedlist* dllist, int item) {
    struct Node* current_node = malloc(sizeof(struct Node));
    current_node = dllist -> head -> next;
    while (current_node == NULL) {
        if (current_node -> data == item)
            return 1;
        current_node = current_node -> next;
    }
    return 0;
}

void menu() {
    printf("1. Traverse the Doubly Linked List\n");
    printf("2. Insert at the Begining of the Doubly Linked List\n");
    printf("3. Insert at the End of the Doubly Linked List\n");
    printf("4. Insert Before a Particular Node of the Doubly Linked List\n");
    printf("5. Insert After a Particular Node of the Doubly Linked List\n");
    printf("6. Delete the Head Element of the Doubly Linked List\n");
    printf("7. Delete the Tail Element of the Doubly Linked List\n");
    printf("8. Delete a Particular Node of the Doubly Linked List\n");
    printf("9. See the Menu Again\n");
    printf("10. Exit\n");
    return;
}

int main(int argc, char* argv[]) {
    
    struct doublylinkedlist* dllist = malloc(sizeof(struct doublylinkedlist));
    dllist = createDoublyLinkedList();
    int choice, item, node;
    bool isExploring = true;
    menu();
    do {
        printf("Please enter your choice\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                traverse(dllist);
                break;
            case 2:
                printf("Enter the item you want to insert at the head\n");
                scanf("%d", &item);
                insertAtHead(dllist, item);
                break;
            case 3:
                printf("Enter the item you want to insert at the tail\n");
                scanf("%d", &item);
                insertAtTail(dllist, item);
                break;
            case 4:
                printf("Enter the node before which you wish to enter an item\n");
                scanf("%d", &node);
                printf("Enter the item you wish to insert\n");
                scanf("%d", &item);
                insertBeforeNode(dllist, node, item);
                break;
            case 5:
                printf("Enter the node after which you wish to enter an item\n");
                scanf("%d", &node);
                printf("Enter the item you wish to insert\n");
                scanf("%d", &item);
                insertAfterNode(dllist, node, item);
                break;
            case 6:
                deleteAtHead(dllist);
                break;
            case 7:
                deleteAtTail(dllist);
                break;
            case 8:
                printf("Enter the node you want to delete\n");
                scanf("%d", &node);
                deleteParticularNode(dllist, node);
                break;
            case 9:
                menu();
                break;
            case 10:
                printf("Exiting....\n");
                isExploring = false;
                break;
            default: printf("Sorry Wrong Choice. Please Try Again.\n");
        }
    }
    while (isExploring);
    free(dllist);
    return 0;
}