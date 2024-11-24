#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int findKthLargest(Node* head, int k) {
    Node* current;
    int max;
    for (int i = 0; i < k; i++) {
        current = head;
        max = -2147483648;
        Node* maxNode = NULL;
        while (current) {
            if (current->data > max) {
                max = current->data;
                maxNode = current;
            }
            current = current->next;
        }
        if (maxNode) maxNode->data = -2147483648;
    }
    return max;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(3);
    head->next = createNode(1);
    head->next->next = createNode(4);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(5);

    printf("Original List:\n");
    printList(head);

    int k = 2;
    int result = findKthLargest(head, k);
    printf("The %d-th largest element is: %d\n", k, result);

    return 0;
}