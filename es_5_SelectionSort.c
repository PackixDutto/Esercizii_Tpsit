/*
author: Patrick Dutto
date:14/10/2023
es.5
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


void selectionSort(int v[],int n) {
int k,kmin,j;
for(k = 0;k < n-1; k++) {
kmin = k;
for(j = k+1; j < n; j++){
if(v[kmin] > v[j])
kmin = j;

}
if(kmin != k)
swap(&v[k], &v[kmin]);
}
return;
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

    selectionSort(vet, DIM);

    stampaVett(vet, DIM);

}
