/*
author: Patrick Dutto
date:17/10/2023
es.
testo: -Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
        -scorrere il file con la funzione FGETS e STRTOK
        -stampare in ordine DECRESCENTE (dal più grande al più piccolo)
         utilizzando i puntatori e allocazione dinamica (MALLOC)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM 50


int main() {
    int dim;

    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &dim);

    int *vet = (int *)malloc(dim * sizeof(int)); // Allocazione dinamica dell'array di interi

    printf("Inserisci %d valori interi:\n", dim);
    for (int i = 0; i < dim; i++) {
        scanf("%d", &vet[i]);
    }

    printf("Valori inseriti:\n");
    for (int i = 0; i < dim; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);

    return 0;
}
