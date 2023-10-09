/*
author: Patrick Dutto
date:18/09/2023
es.3
testo: Scrivere un programma in C che calcoli la somma degli
        elementi di un array utilizzando l'aritmetica dei puntatori. Nel programma deve
        essere implementata una funzione calcolaSomma()
        che riceva due argomenti (la lunghezza dell'array e un puntatore), calcola la
        somma degli elementi dell'array utilizzando un puntatore e
        restituisce la somma calcolata. Il main()
        dichiara un array, utilizza la funzione calcolaSomma() e stampa il risultato
        restituito dalla funzione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM 10

int calcolaSomma(int* vet, int n) {
    int somma;
    for(int k=0; k<n; k++) {
        somma = *(vet + k) + somma;
    }
    return somma;
}



int main() {
    int *vet[DIM]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int somma;
    somma = calcolaSomma(vet, DIM);
    printf("la somma e %d", somma);

    return 0;
}
