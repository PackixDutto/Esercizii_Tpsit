/*
author: Patrick Dutto
date:21/10/2023
es.1
testo:
    1) Valore interi
Scrivi un programma in linguaggio C che consenta all'utente di creare un array dinamico
di interi. Il programma dove avere una dimensione array specificata, usando la
funzione malloc per allocare in modo dinamico gli interi.
L’utente deve poter inserire valori interi, che verranno stampati. Assicurarsi di liberare la
memoria allocata dinamicamente utilizzando la funzione free alla fine del
programma per evitare perdite di memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM 30

void inizializzazione(int n, int *vett) {
    printf("Inserisci la dimensione dell'vett: ");
    scanf("%d", &n);


    vett = (int *)malloc(n * sizeof(int));


    if (vett == NULL) {    //Verifica se l'allocazione di memoria ha avuto successo
        printf("Errore nell'allocazione di memoria.");
        return 1; // Uscita con errore
    }

    printf("Inserisci %d valori interi:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vett[i]);
    }

}

void stampaVett(int n, int *vett) {

    printf("Valori inseriti:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vett[i]);
    }
    printf("\n");

}

int main() {
    int n;
    int *vett;


    inizializzazione(n, &vett);

    stampaVett(n, &vett);


    free(vett); //Libera la memoria allocata dinamicamente

    return 0;
}
