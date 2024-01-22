/*
author: Patrick Dutto
date:3/10/2023
es.2
testo: Supponendo
date le seguenti definizioni:
typedef
struct El {int s;
      struct El *next;}
ElementoLista;
 typedef ElementoLista *ListaDiInteri;
• definire una funzione FirstEven che, data
una ListaDiInteri restituisce la posizione (puntatore) del primo elemento pari
nella lista (restituisce NULL se la lista non contiene elementi pari).
ListaDiInteri FirstEven(ListaDiInteri lis) {
 while (lis != NULL) {
     if (lis->s % 2 == 0)
            return lis;
   il primo pari è in lis
       else
        lis = lis ->next;
     }
     return NULL;
 }

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define DIM 30


typedef struct El {
    int s;
    struct El *next;
} El;

ListaDiInteri FirstEven(ListaDiInteri lis) {
    while (lis != NULL) {
        if (lis->s % 2 == 0)
            return lis;
        /* il primo pari è in lis */
        else
            lis = lis ->next;
    }

    ElementoLista;
    typedef ElementoLista *ListaDiInteri;



int main(){



}
