#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;
    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void split(Node* source, Node** front, Node** back) {
    Node* slow = source;
    Node* fast = source->next;
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void sort(Node** headRef) {
    if (!*headRef || !(*headRef)->next) return;
    Node* head = *headRef;
    Node* left = NULL;
    Node* right = NULL;
    split(head, &left, &right);
    sort(&left);
    sort(&right);
    *headRef = merge(left, right);
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
    Node* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original List:\n");
    printList(head);

    sort(&head);

    printf("Sorted List:\n");
    printList(head);

    return 0;
}