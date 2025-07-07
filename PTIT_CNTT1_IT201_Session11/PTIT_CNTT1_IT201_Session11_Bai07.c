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
Node* insertToPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Vi tri khong hop le");
        return head;
    }
    if (position ==1) {
        return insertLast(head, data);
    }
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node* current = head;
    int currentposition = 0;
    while (current != NULL&& currentposition < position-1) {
        current = current->next;
        currentposition++;
    }
    if (current == NULL) {
        printf("Vi tri vuot qua danh sach");
        free(newNode);
        return head;

    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next == NULL) {
        current->next ->prev = newNode;
    }
    current->next= newNode;
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
    int value, pos;
    head = insertLast(head, 10);
    head = insertLast(head, 20);
    head = insertLast(head, 30);
    head = insertLast(head, 40);
    head = insertLast(head, 50);
    printf("Nhap gia tri can them");
    scanf("%d", &value);
    printf("Nhap vi tri muon chen");
    scanf("%d", &pos);
    printf("\nHi \n");
    printNode(head);
    head = insertToPosition(head, value, pos);
    printf("\nHi \n");
    printNode(head);
    return 0;

   
}
