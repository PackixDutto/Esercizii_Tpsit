/*
programma che chiede una stringa e verifichi che sia palindroma o no
pila sarà con push e pop 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    String value;
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



int main(){
    string n ;
    Node* head = NULL;

        printf("inserisci una stringa per vedere se è palindroma ");
        scanf("%s", &n);
            Node* element = (Node*) malloc(sizeof(Node));
            element->value = n;
            push(&head, element);
        

    printPila(head);
    Node *removed = pop(&head);
    printPila(head);

    return 0;
}


