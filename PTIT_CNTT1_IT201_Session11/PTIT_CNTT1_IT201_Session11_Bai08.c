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
Node* deleteAtPos(Node* head,int position) {
    if (head == NULL) {
        printf("Danh sach rong\n");
        return NULL;
    }
    if (position < 1) {
        printf("Vi tri khong hop le");
        return head;
    }
    Node* nodeDelete=head;
    if (position == 1) {
        head=nodeDelete->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(nodeDelete);
        return head;
    }
    int currentPos = 1;
    while (nodeDelete != NULL&&currentPos < position) {
        nodeDelete = nodeDelete->next;
        currentPos++;
    }
    if (nodeDelete == NULL) {
        printf("Vi tri %d vuot qua kich thuoc danh sach \n",position);
        return head;
    }
    nodeDelete->prev->next = nodeDelete->next;
    if (nodeDelete->next != NULL) {
        nodeDelete->next->prev = nodeDelete->prev;
    }
    free(nodeDelete);
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
    int  pos;
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);
    head = insert(head, 50);
    printf("Moi ban nhap vi tri muon xoa");
    scanf("%d",&pos);
    printf("\nHi \n");
    printNode(head);
    head =deleteAtPos(head, pos);
    printf("\nHi \n");
    printNode(head);
    return 0;

    
}
