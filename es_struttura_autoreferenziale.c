/*
author: Patrick Dutto
date:3/10/2023
es.33
testo:funzione calcola lunghezza
chiedi all utente un numero intero e lo aggiungi in fondo alla lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct node{
    int valore;
    struct node* next;
}Node;

int calcolaLunghezzaRicorsiva(Node* lista){ // return di 1+ calcola ricorsiva di head->next
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore)
        lung = calcolaLunghezzaRicorsiva(l->next);
    }
return lung;
}

contaElementiRicorsivi(Node* head){
    if(head->next != NULL){
        return 1+ contaElementiRicorsivi(head->next);
    }
    return 1;
}


int CalcolaLunghezzaLista(Node* head){
    Node* l = head;
    int k = 0;

    while (l != NULL){
        k++;
        l = l->next;
    }

    return k;

}

int addInFondo(Node* head, int x){
    Node* l = *head;

    while(l->next != NULL){
        l = l->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l= l->next;
    l->valore = x;
    l->next = NULL;
}

int main (){

    int n;

    Node* lista = NULL;

    Node* l;

    do{
        printf ("Inserisci un naturale o -1 per terminare\n");
        scanf ("%d", &n);
        if (n >= 0){
            if (lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {

                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;

            }

            l->valore = n;
            l->next = NULL;
        }
    }while (n >= 0);

    l = lista;
    printf("numeri inseriti: ");
    while (l != NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    printf("\n");

    printf("%d", CalcolaLunghezzaLista(lista));

    int k = contaElementiRicorsivi(lista);
    printf("%d", k);

    int x,
    printf("inserisci il numero da aggiungere alla fine");
    scanf("%d", x);
    addInFondo(lista, x);

    return 0;

}
