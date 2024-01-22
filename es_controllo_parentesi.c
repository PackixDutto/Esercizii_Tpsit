#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    struct node* next;
} Node;

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

    char *stringa = "{[3+(5+6)*2]+1}";
    char *stringaAperte = "{[(";
    char *stringaChiuse = "}])";
    Node* element = (Node*) malloc(sizeof(Node));
    char el;

    for(int k=0; k<strlen(stringa); k++){
        el = *(stringa + k);
        for(int j=0; j<3; j++){
            if(el == *(stringaAperte + j)){
                element->value = *(stringa + k);
                push(&head, element);
            }
            if(el == *(stringaChiuse + j)){
                Node *removed = pop(&head);
            }
        }
    }

    printPila(head);

    return 0;
}
