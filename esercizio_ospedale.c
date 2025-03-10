#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int eta;
    char colore[10];
} Paziente;


typedef struct {
    Paziente *pazienti;
    int front;
    int rear;
    int size;
} Coda;

Coda* creaCoda(int size) {
    Coda* coda = (Coda*)malloc(sizeof(Coda));
    coda->pazienti = (Paziente*)malloc(size * sizeof(Paziente));
    coda->front = coda->rear = -1;
    coda->size = size;
    return coda;
}


int codaVuota(Coda* coda) {
    return coda->front == -1;
}


int codaPiena(Coda* coda) {
    return (coda->rear + 1) % coda->size == coda->front;
}


void aggiungiPaziente(Coda* coda, Paziente paziente) {
    if (codaPiena(coda)) {
        printf("La coda è piena\n");
        return;
    }
    if (coda->front == -1) coda->front = 0;
    coda->rear = (coda->rear + 1) % coda->size;
    coda->pazienti[coda->rear] = paziente;
}


Paziente rimuoviPaziente(Coda* coda) {
    if (codaVuota(coda)) {
        printf("La coda è vuota\n");
        exit(1);
    }
    Paziente paziente = coda->pazienti[coda->front];
    if (coda->front == coda->rear) coda->front = coda->rear = -1;
    else coda->front = (coda->front + 1) % coda->size;
    return paziente;
}


void visualizzaCoda(Coda* coda) {
    if (codaVuota(coda)) {
        printf("La coda è vuota\n");
        return;
    }
    printf("Pazienti nella coda:\n");
    int i = coda->front;
    while (i != coda->rear) {
        printf("Nome: %s, Età: %d, Colore: %s\n", coda->pazienti[i].nome, coda->pazienti[i].eta, coda->pazienti[i].colore);
        i = (i + 1) % coda->size;
    }
    printf("Nome: %s, Età: %d, Colore: %s\n", coda->pazienti[i].nome, coda->pazienti[i].eta, coda->pazienti[i].colore);
}

int main() {
    //Creazione delle code per i diversi colori
    Coda* rosso = creaCoda(10);
    Coda* giallo = creaCoda(10);
    Coda* verde = creaCoda(10);
    Coda* bianco = creaCoda(10);

    //Aggiunta di alcuni pazienti alle code
    Paziente p1 = {"Mario", 40, "rosso"};
    Paziente p2 = {"Luigi", 30, "giallo"};
    Paziente p3 = {"Giuseppe", 50, "verde"};
    Paziente p4 = {"Giovanni", 60, "bianco"};
    aggiungiPaziente(rosso, p1);
    aggiungiPaziente(giallo, p2);
    aggiungiPaziente(verde, p3);
    aggiungiPaziente(bianco, p4);

    //Visualizzazione delle code
    printf("Code iniziali:\n");
    printf("Rosso:\n");
    visualizzaCoda(rosso);
    printf("Giallo:\n");
    visualizzaCoda(giallo);
    printf("Verde:\n");
    visualizzaCoda(verde);
    printf("Bianco:\n");
    visualizzaCoda(bianco);

    //Rimozione di un paziente dalla coda verde
    rimuoviPaziente(verde);

    // Visualizzazione delle code dopo la rimozione
    printf("Code dopo la rimozione:\n");
    printf("Rosso:\n");
    visualizzaCoda(rosso);
    printf("Giallo:\n");
    visualizzaCoda(giallo);
    printf("Verde:\n");
    visualizzaCoda(verde);
    printf("Bianco:\n");
    visualizzaCoda(bianco);

    return 0;
}
