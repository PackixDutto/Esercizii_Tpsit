

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* value;
    struct node* next;
} Node;

int isEmpty(Node* head) {
    return head == NULL;
}

void push(Node** head, char* str) {
    Node* element = (Node*)malloc(sizeof(Node));
    element->value = strdup(str);
    element->next = *head;
    *head = element;
}

Node* pop(Node** head) {
    Node* ret = *head;
    if (!isEmpty(*head)) {
        *head = ret->next;
    }
    return ret;
}

void freeNode(Node* node) {
    free(node->value);
    free(node);
}

int main() {
    char n[100];
    Node* head = NULL;

    printf("Inserisci una stringa per vedere se è palindroma: ");
    scanf("%s", n);
    push(&head, n);

    Node* removed = pop(&head);
    printf("Stringa rimossa dalla pila: %s\n", removed->value);
    freeNode(removed);

    return 0;
}

