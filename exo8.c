#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* merge(Node* L1, Node* L2) {
    if (!L1) return L2;
    if (!L2) return L1;
    if (L1->data <= L2->data) {
        L1->next = merge(L1->next, L2);
        return L1;
    } else {
        L2->next = merge(L1, L2->next);
        return L2;
    }
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
    Node* L1 = createNode(1);
    L1->next = createNode(3);
    L1->next->next = createNode(5);

    Node* L2 = createNode(2);
    L2->next = createNode(4);
    L2->next->next = createNode(6);

    printf("List 1:\n");
    printList(L1);

    printf("List 2:\n");
    printList(L2);

    Node* mergedList = merge(L1, L2);

    printf("Merged List:\n");
    printList(mergedList);

    return 0;
}