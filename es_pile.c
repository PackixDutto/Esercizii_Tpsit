#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    struct node* next;   
}Node;

int isEmpty(Node *head){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(Node **head, Node *element){
    if(isEmpty(*head)){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node **head){
    Node *ret = *head;
    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void printPila(Node *head){
    Node* l = head;
    while (l != NULL)
    {
        printf("%d ", l->value);
        l = l ->next;
    }
}

int main(){
    int n;
    Node* head = NULL;

    do{
        printf("Inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            Node* element = (Node*) malloc(sizeof(Node));
            element->value = n;
            push(&head, element);
        }
    } while (n >= 0);

    printPila(head);
    Node *removed = pop(&head);
    printPila(head);

    return 0;
}