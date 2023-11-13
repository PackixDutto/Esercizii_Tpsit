/*
author: Patrick Dutto
date:30/10/2023
es.
testo:
    Scrivi un programma in linguaggio C che
gestisca un archivio di libri. Il programma deve utilizzare una struttura Libro per rappresentare ciascun libro, con le seguenti
informazioni:
-Titolo (massimo 100 caratteri)
-Autore (massimo 100 caratteri)
-Anno di pubblicazione
Il programma deve consentire all'utente
di eseguire le seguenti operazioni:
-Stampare l'archivio dei libri:
-Stampa tutte le informazioni sui libri presenti nell'archivio.
-Stampa l’archivio dei libri pubblicati in un certo anno.
-Stampa tutti i libri pubblicati in ordine di anno.
Assicurati che il programma gestisca
correttamente la memoria dinamica e che non ci siano perdite di memoria.
Inoltre, gestisci eventuali errori nell'apertura del file CSV.
Ricorda di fornire un'interfaccia utente
chiara e intuitiva per consentire all'utente di eseguire queste operazioni.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define MAX 100


typedef struct {
    char titolo[MAX];
    char autore[MAX];
    int annoPubblicazione;
} Libro;

// Funzione per stampare un libro
void stampaLibro(Libro libro) {
    printf("Titolo: %s\n", libro.titolo);
    printf("Autore: %s\n", libro.autore);
    printf("Anno di pubblicazione: %d\n", libro.annoPubblicazione);
}

int main() {
    int nLibri;
    int scelta;
    int anno;

    printf("Inserisci il numero di libri nell'archivio: ");
    scanf("%d", &nLibri);

    Libro *archivio = (struct Libro *)malloc(nLibri * sizeof(Libro)); // Allocazione dinamica dell'array di libri

    if (archivio == NULL) {
        printf("Errore nell'allocazione di memoria dinamica.\n");
        return 1;
    }

    //Inserimento
    for (int k = 0; k < nLibri; k++) {
        printf("inserisci i dati per il libro %d:\n", k + 1);
        printf("titolo: ");
        scanf("%s", archivio[k].titolo);
        printf("autore:  ");
        scanf("%s", archivio[k].autore);
        printf("anno di pubblicazione: ");
        scanf("%d", &archivio[k].annoPubblicazione);
    }

    // Menu delle operazioni
    do {
        printf("\nOperazioni disponibili:\n");
        printf("1. Stampare l'archivio dei libri\n");
        printf("2. Stampare l'archivio dei libri pubblicati in un certo anno\n");
        printf("3. Stampare tutti i libri pubblicati in ordine di anno\n");
        printf("4. Uscire\n");
        printf("Scegli un'operazione: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf("Archivio dei libri:\n");
                for (int k = 0; k < nLibri; k++) {
                    stampaLibro(archivio[k]);
                }
                break;
            case 2:
                printf("Inserisci l'anno di pubblicazione: ");
                scanf("%d", &anno);
                printf("Libri pubblicati nell'anno %d:\n", anno);
                for (int k = 0; k < nLibri; k++) {
                    if (archivio[k].annoPubblicazione == anno) {
                        stampaLibro(archivio[k]);
                    }
                }
                break;
            case 3:
                printf("Libri pubblicati in ordine di anno:\n"); //ordinamento
                for (int k = 0; k < nLibri - 1; k++) {
                    for (int j = 0; j < nLibri - k - 1; j++) {
                        if (archivio[j].annoPubblicazione > archivio[j + 1].annoPubblicazione) {
                            Libro temp = archivio[j];      //scambio
                            archivio[j] = archivio[j + 1];
                            archivio[j + 1] = temp;
                        }
                    }
                }

                for (int k = 0; k < nLibri; k++) {
                    stampaLibro(archivio[k]);
                }
                break;
            case 4:
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 4);

    free(archivio);

    return 0;
}
