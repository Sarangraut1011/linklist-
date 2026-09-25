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

    printf("Enter number of nodes: ");
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

    printf("Linked List created successfully!\n");
}

// Display Linked List
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at beginning
void insertBeginning(struct Node **head) {
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted successfully!\n");
}

// Insert at end
void insertEnd(struct Node **head) {
    int value;

    printf("Enter value: ");
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

    printf("Node inserted successfully!\n");
}

// Delete from beginning
void deleteBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("Linked List is empty!\n");
        return;
    }

    struct Node *temp = *head;

    *head = (*head)->next;

    free(temp);

    printf("Node deleted successfully!\n");
}

int main() {
    struct Node *head = NULL;
    int choice;

    do {
        printf("\n========== SINGLY LINKED LIST ==========\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Exit\n");
        printf("=========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                create(&head);
                break;

            case 2:
                display(head);
                break;

            case 3:
                insertBeginning(&head);
                break;

            case 4:
                insertEnd(&head);
                break;

            case 5:
                deleteBeginning(&head);
                break;

            case 6:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
