#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to reverse the linked list
Node* reverse(Node* head) {
    Node* prev = NULL;    // Previous pointer
    Node* current = head; // Current pointer
    Node* next = NULL;    // Next pointer

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev one step ahead
        current = next;       // Move current one step ahead
    }
    return prev; // New head of the reversed list
}

// Utility function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Utility function to print a linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the reverse function
int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> 4 -> NULL
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List:\n");
    printList(head);

    // Reverse the linked list
    head = reverse(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}