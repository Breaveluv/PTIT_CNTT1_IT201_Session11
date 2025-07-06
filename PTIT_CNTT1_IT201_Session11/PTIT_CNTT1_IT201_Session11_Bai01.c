#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

}Node;
Node* insert(Node* head, int data) {
    Node*newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = NULL;
        return newNode;
    }
    Node*current = head;
    while (current->next != NULL) {
        current = current->next;

    }
    current->next = newNode;
    newNode->prev = current;
    newNode->next = NULL;
    return head;

;
};
Node* display(Node* head) {
    Node*current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL");
    return head;
}
int main() {
    Node* head = NULL;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    head=display(head);
}