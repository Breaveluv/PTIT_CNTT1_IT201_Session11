#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;
Node* insertLast(Node* head, int data) {
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
Node*deleteFirst(Node* head) {
    if (head == NULL) {
        printf("Danh sach trong");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

void printNode(Node* head) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf(" %d  <-> ",current->data);
        current = current->next;
        count++;
    }
    printf("NULL");
}
int main() {
    Node *head = NULL;
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    head = insertLast(head, 40);
    head = insertLast(head, 50);
    printf("\nHi \n");
    printNode(head);
    head = deleteFirst(head);
    printf("\nHi \n");
    printNode(head);
    return 0;


    
}
