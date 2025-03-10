#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int dato;
    struct Nodo* prossimo;
} Nodo;

typedef struct {
    Nodo* inizio;
    Nodo* fine;
} Coda;

typedef struct {
    Nodo* cima;
} Pila;

void inizializzaCoda(Coda* coda) {
    coda->inizio = NULL;
    coda->fine = NULL;
}

void inizializzaPila(Pila* pila) {
    pila->cima = NULL;
}


void inserisciInCoda(Coda* coda, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = NULL;
    if (coda->inizio == NULL) {
        coda->inizio = nuovoNodo;
    } else {
        coda->fine->prossimo = nuovoNodo;
    }
    coda->fine = nuovoNodo;
}


int estraiDaCoda(Coda* coda) {
    if (coda->inizio == NULL) {
        printf("La coda è vuota\n");
        exit(1);
    }
    Nodo* temp = coda->inizio;
    int dato = temp->dato;
    coda->inizio = temp->prossimo;
    free(temp);
    return dato;
}


void inserisciInPila(Pila* pila, int dato) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuovoNodo->dato = dato;
    nuovoNodo->prossimo = pila->cima;
    pila->cima = nuovoNodo;
}

int estraiDaPila(Pila* pila) {
    if (pila->cima == NULL) {
        printf("La pila è vuota\n");
        exit(1);
    }
    Nodo* temp = pila->cima;
    int dato = temp->dato;
    pila->cima = temp->prossimo;
    free(temp);
    return dato;
}

//confronta due code e determinare se sono uguali
bool equals(Coda* coda1, Coda* coda2) {
    Nodo* nodo1 = coda1->inizio;
    Nodo* nodo2 = coda2->inizio;
    while (nodo1 != NULL && nodo2 != NULL) {
        if (nodo1->dato != nodo2->dato) {
            return false;
        }
        nodo1 = nodo1->prossimo;
        nodo2 = nodo2->prossimo;
    }
    return nodo1 == NULL && nodo2 == NULL;
}

int main() {

    Coda coda;
    Pila pila;
    inizializzaCoda(&coda);
    inizializzaPila(&pila);

    inserisciInCoda(&coda, 1);
    inserisciInCoda(&coda, 2);
    inserisciInCoda(&coda, 3);
    inserisciInPila(&pila, 1);
    inserisciInPila(&pila, 2);
    inserisciInPila(&pila, 3);

    printf("Elemento estratto dalla coda: %d\n", estraiDaCoda(&coda));
    printf("Elemento estratto dalla pila: %d\n", estraiDaPila(&pila));

    Coda coda2;
    inizializzaCoda(&coda2);
    inserisciInCoda(&coda2, 1);
    inserisciInCoda(&coda2, 2);
    inserisciInCoda(&coda2, 3);
    printf("Le due code sono uguali? %s\n", equals(&coda, &coda2) "Sì":"No");

    return 0;
}
