/*
author: Patrick Dutto
date:3/10/2023
es.33
testo:

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM 30


typedef struct node{
int valore;
struct node* next;
}Node;

int main(){
int n;
Node* lista = NULL;
Node* l;

do{
    printf("Inserisci un naturale o -1 per terminare\n");
    scanf("%d", &n);
    if(n>=0){
        if(lista==NULL) // prima iterazione
        {
            lista = (Node*) malloc(sizeof(Node));
            l = l->next;
        }
        l->valore = n;
        l->next = NULL;
    }
}while (n>=0);

l=lista;
printf("numeri inseriti: ");
while (l!=NULL)
{
    printf("%d - %p \n", l->valore, l->next);
    l=l->next;
}
printf("\n");
return 0;
}
