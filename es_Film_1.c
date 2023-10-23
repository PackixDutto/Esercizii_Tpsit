/*
author: Patrick Dutto
date:18/09/2023
es.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM_RIGA 200
#define NUM_RIGHE 20000



//strtok funzione

typedef struct Film {
    int numero;
    char* titoloFilm;
    char* genere;
    int annoUscita;
    char* disponibilita;
} Film;


void stampaFile(Film c[], int n) {
    int k;
    for(k=0; k<n; k++) {
        printf("%d, %c, %c, %d, %c\n",c[k].numero, c[k].titoloFilm, c[k].genere, c[k].annoUscita, c[k].disponibilita);

    }

}


int main() {

    char riga[DIM_RIGA];
    char* campo;
    Film array_film[NUM_RIGHE];
    int counter=0;

    FILE *fp = fopen("Ciak_film.txt","r");
    if(fp==NULL) {
        printf("file non esiste");
        exit(1);
    } else {

        while(fgets(riga, DIM_RIGA, fp)){

            campo=strtok(riga, ",");
            array_film[counter].numero = atoi(campo);

            campo=strtok(NULL, ",");
            array_film[counter].titoloFilm = strdup(campo); //strdup ti ritorna la copia

            campo=strtok(NULL, ",");
            array_film[counter].genere = strdup(campo);

            campo=strtok(NULL, ",");
            array_film[counter].annoUscita = atoi(campo);

            campo=strtok(NULL, ",");
            array_film[counter].disponibilita = strdup(campo);

            counter = counter + 1;

        }

        stampaFile(array_film, counter);

        fclose(fp);
    }
    return 0;
}
