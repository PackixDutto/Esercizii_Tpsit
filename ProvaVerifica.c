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


typedef struct Persona{
char cognome[DIM];
char nome [DIM];
int nascita;
}Persona;

/*
typedef struct Data{
int giorno;
int mese;
int anno;
}Data;
*/

void stampaFile(Persona u[], int n) {
    int k;
    for(k=0; k<n; k++) {
        printf("%s, %s, %d\n", &(u+k)->cognome, &(c+k)->nome, &(u+k)->nascita);

    }

}

int contaRighe(FILE *fp){

}

void malloc (Persona utente[], char riga){

while(fgets(riga, DIM, fp)){

            campo=strtok(riga, ",");
            (*(utente + counter)).cognome = strdup(campo);
            (utente+counter)->cognome = strdup(campo);

            campo=strtok(NULL, ",");
            (utente+counter)->nome = strdup(campo); //strdup ti ritorna la copia

            campo=strtok(NULL, ",");
            (utente+counter)->nascita = atoi(campo);

            counter = counter + 1;
            }else{
            counter = counter + 1;
            }

}



int main() {
    Persona utente[DIM];
    char riga[DIM];
    char* campo;
    int counter=0;
    int dim=0;
    int *vett;

    FILE *fp = fopen("ProvaVerifica","r");
    if(fp==NULL) {
        printf("file non esiste");
        exit(1);
    } else {

        cont = contaRighe(fp);

        //printf("inserisci la dimensione del vettore");
        //scanf("%d", dim);

        printf("inserisci la dimensione del vettore");
        //scanf("%d", dim);

        vett = (int*) malloc (cont*sizeof(int)); 

        

        stampaFile(utente, counter);

        fclose(fp);
    }


}



