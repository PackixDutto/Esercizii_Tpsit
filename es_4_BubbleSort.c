/*
author: Patrick Dutto
date:3/10/2023
es.33
testo:
    Dato un file di testo "numeri.dat" contenente dei numeri reali, leggerli e infine salvare nel file
    "risultati.dat" il valore medio. Attenzione il file può non esistere o essere vuoto
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM 10
#define MIN 0
#define MAX 10

void caricaVett(int v[], int dim, int min, int max) {

    for(int k=0; k<dim; k++) {
        v[k]= rand() % (max - min + 1) + min;
    }

}


void bubbleSort(int vett[], int n) {
    int k, sup;
    for (sup = n-1; sup > 0; sup--) {
        for (k = 0; k < sup ; k++) {
            if (vett[k] > vett[k+1])
                swap(&vett[k], &vett[k + 1]);
        }
    }
}

void swap(int *v, int *j){
int temp = *v;
*v = *j;
*j = temp;
}


void stampaVett(int vet[], int dim){

for(int k=0; k<dim; k++){
    printf("%d ", vet[k]);

}

}

int main() {
    int vet[DIM];

    srand(time(NULL));

    caricaVett(vet, DIM, MIN, MAX);

    bubbleSort(vet, DIM);

    stampaVett(vet, DIM);

}
