#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create Linked List
void create(struct Node **head) {
    int n, i, value;
    struct Node *newNode, *temp;

    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->next = NULL;

        if (*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

// Display Linked List
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("\nFinal Linked List:\n");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at beginning
void insertBeginning(struct Node **head) {
    int value;

    printf("\nEnter value: ");
    scanf("%d", &value);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertEnd(struct Node **head) {
    int value;

    printf("\nEnter value: ");
    scanf("%d", &value);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete from beginning
void deleteBeginning(struct Node **head) {
    struct Node *temp;

    if (*head == NULL) {
        printf("\nLinked List is empty!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    free(temp);

    printf("\nFirst node deleted.\n");
}

int main() {
    struct Node *head = NULL;
    int choice;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Display Linked List\n");
        printf("6. Exit\n");
        printf("===========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                create(&head);
                break;

            case 2:
                insertBeginning(&head);
                break;

            case 3:
                insertEnd(&head);
                break;

            case 4:
                deleteBeginning(&head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 6);

    // Display linked list at the end
    printf("\n========== FINAL OUTPUT ==========\n");
    display(head);

    return 0;
}
