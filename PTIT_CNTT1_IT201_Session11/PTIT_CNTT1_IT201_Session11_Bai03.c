#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* insert(Node* head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;

}
int search(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printNode(Node* head) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Node %d: %d \n <-> ", count,current->data);
        current = current->next;
        count++;
    }
}

int main() {
    Node *head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    int numberTosreach;
    printf("Moi ban nhap so muon tim kiem");
    scanf("%d",&numberTosreach);
    if (search(head, numberTosreach)) {
        printf("True\n");
    }else {
        printf("False\n");
    }
    return 0;
}