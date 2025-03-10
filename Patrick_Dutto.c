#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*
abbiamo due strutture: uno di tipo CODA e una di tipo PILA
sia la struttura pila che la struttura coda sono composti da 5 elementi questi elementi sono composti da un NUMERO_ARRIVO
(quindi da 1 a 5 dato dall'ordine di arrivo) e un numero causale tra 1 e 10 chiamato VALORE
prendi il valore del primo elemento che dovra uscire dalla struttura pila (pop) e confrontarlo con il valore del primo che dovra uscire dalla struttura Coda(dequeue)
chi avra il valore minore vera eliminato
chi avra il valore maggiore verra rimesso nella stessa struttura (Enqueue o push) diminuito del valore dell' elemento della struttura avversaria
se pari verranno entrambi eliminati
stampare ad ogni scontro numero_arrivo e valore degli elementi interessati e il vincitore (se presente) con il nuovo Valore
perde la struttura che rimane senza elementi
stampare tutti gli elementi (numero_arrivo, valore) della struttura vincente
*/


typedef struct elemento {
    int numero_arrivo;
    int valore;
    struct elemento* next;
} Elemento;

typedef struct pila_coda {
    Elemento* pila;
    Elemento* coda;
} PilaCoda;

int isEmpty(Elemento* head) {
    return head == NULL;
}

void push(Elemento** head, int numero_arrivo, int valore) {
    Elemento* ele = (Elemento*)malloc(sizeof(Elemento));
    ele->numero_arrivo = numero_arrivo;
    ele->valore = valore;
    ele->next = *head;
    *head = ele;
}

Elemento* pop(Elemento** head) {
    Elemento* r = *head;
    if (!isEmpty(*head)) {
        *head = r->next;
    }
    return r;
}

void enqueue(Elemento** head, int numero_arrivo, int valore) {
    Elemento* ele = (Elemento*)malloc(sizeof(Elemento));
    ele->numero_arrivo = numero_arrivo;
    ele->valore = valore;
    ele->next = NULL;

    if (*head == NULL) {
        *head = ele;
    } else {
        Elemento* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ele;
    }
}

Elemento* dequeue(Elemento** head) {
    Elemento* r = *head;
    if (!isEmpty(*head)) {
        *head = r->next;
    }
    return r;
}

void visualizzaPila_Coda(Elemento* head) {
    Elemento* temp = head;
    while (temp != NULL) {
        printf("Numero arrivo%d, Valore%d\n", temp->numero_arrivo, temp->valore);
        temp = temp->next;
    }
}

int main() {
    PilaCoda pila_coda = { NULL, NULL };
    int valore=0;
    int numero_arrivo=0;

    for (int k= 0; k< 5; k++) {
        numero_arrivo = k + 1;
        valore = rand() % 10 + 1; // Genera un valore casuale tra 1 e 10
        push(&pila_coda.pila, numero_arrivo, valore);
        valore = rand() % 10 + 1; // Genera un valore casuale tra 1 e 10
        enqueue(&pila_coda.coda, numero_arrivo, valore);
    }

     while (!isEmpty(pila_coda.pila) && !isEmpty(pila_coda.coda)) {
        Elemento* pila_elemento = pop(&pila_coda.pila);
        Elemento* coda_elemento = dequeue(&pila_coda.coda);

        printf("Pila: Numero arrivo: %d, Valore: %d\n", pila_elemento->numero_arrivo, pila_elemento->valore);
        printf("Coda: Numero arrivo: %d, Valore: %d\n", coda_elemento->numero_arrivo, coda_elemento->valore);

        if (pila_elemento->valore < coda_elemento->valore) {
            printf("Vince Pila\n");
            coda_elemento->valore -= pila_elemento->valore;
            if (coda_elemento->valore > 0) {
                enqueue(&pila_coda.coda, coda_elemento->numero_arrivo, coda_elemento->valore);
                }else{
                    coda_elemento->valore = 0;
                }
        } else if (pila_elemento->valore > coda_elemento->valore) {
            printf("Vince Coda\n");
            pila_elemento->valore -= coda_elemento->valore;
            if (pila_elemento->valore > 0) {
                push(&pila_coda.pila, pila_elemento->numero_arrivo, pila_elemento->valore);
            }else{
                    pila_elemento->valore = 0;
                }

        } else {
            printf("Pari\n");
        }


        free(pila_elemento);
        free(coda_elemento);
     }

    printf("Pila\n");
    visualizzaPila_Coda(pila_coda.pila); //stampa ordine e numero random
    printf("\nCoda\n");
    visualizzaPila_Coda(pila_coda.coda); //stampa ordine numero random

    return 0;
}

