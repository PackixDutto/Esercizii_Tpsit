/*
author: Patrick Dutto
date:3/10/2023
es.33
testo:funzione calcola lunghezza
chiedi all utente un numero intero e lo aggiungi in fondo alla lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#includere <stdio.h>
#includere <stdlib.h>
#includere <string.h>

nodo della struttura typedef {
    valore int ;
    nodo struttura * successivo ;
} Nodo ;

int calcolaLunghezza ( Nodo * lista ) {
    Nodo * l = lista ;
    int polmone = 0 ;
    mentre ( l != NULL ) {
        polmone ++;
        l = l -> successivo ;
    }
    polmone di ritorno ;
}

int ricorsivaLunghezza ( Nodo * lista, int lung ) {
    Nodo * l = lista ;
    se ( l != NULL ) {
        polmone ++;
        polmone = ricorsivaLunghezza ( l -> successivo, polmone );
    }
    polmone di ritorno ;
}

int ricorsivaLunghezza2 ( Nodo * Lista ) {
    if ( Lista -> next != NULL ) {
        return 1 + ricorsivaLunghezza2 ( Lista -> next );
    }
    ritorno 1 ;
}

void stampaLista ( Nodo * lista ) {
    Nodo * l = lista ;
    printf ( " \nLista valori:" );
    mentre ( l != NULL ) {
        printf ( " %d ", l -> valore );
        l = l -> successivo ;
    }
}

void stampaListaRicorsiva ( Nodo * lista ) {
    Nodo * l = lista ;
    se ( l != NULL ) {
        printf ( " %d ", l -> valore );
        stampaListaRicorsiva ( l -> successiva );
    }
}

void aggiungiElementoInizio ( Node ** lista, int num ) {
    Nodo * testa ;
    head = ( Nodo *) malloc ( sizeof ( Nodo ));
    testa -> successivo = * lista ;
    testa -> valore = num ;
    * lista = testa ;
}

void aggiungiElementoFondo ( Nodo ** lista, int num ) {
    Nodo * l =* lista ;
    while ( l -> successivo != NULL ) {
        l = l -> successivo ;
    }
    l -> next = ( Nodo *) malloc ( sizeof ( Nodo ));
    l = l -> successivo ;
    l -> valore = numero ;
    l -> successivo = NULL ;
}

void eliminaUltimoElemento ( Node ** lista ) {
    Nodo * l =* lista ;
    Nodo * l2 = l ;
    while ( l -> successivo != NULL ) {
        l2 = l ;
        l = l -> successivo ;
    }
    l2 -> successivo = NULL ;
}

int principale () {
    intero n ;
    int polmone = 0 ;
    Nodo * lista = NULL ;
    Nodo * l ;
    Fare {
        printf ( "inserire un numero naturale o -1 per terminare: " );
        scanf ( " %d ", & n );
        se ( n >= 0 ) {
            se ( lista == NULL ) {
                lista = ( Nodo *) malloc ( sizeof ( Nodo ));
                l = lista ;
            }
            altro {
                l -> next = ( Nodo *) malloc ( sizeof ( Nodo ));
                l = l -> successivo ;
            }
            l -> valore = n ;
            l -> successivo = NULL ;
        }
    } mentre ( n >= 0 );

    l = lista ;
    printf ( "numeri inseriti:" );
    printf ( " \n " );
    mentre ( l != NULL ) {
        printf ( " %d - %p \n ", l -> valore, l -> successivo );
        l = l -> successivo ;
    }
    printf ( " \n " );
    printf ( "Numero di elementi: %d ", calcolaLunghezza ( lista ));
    printf ( " \n Numero di elementi con ricorsiva: %d ", ricorsivaLunghezza ( lista, lung ));
    printf ( " \n Numero di elementi con ricorsiva: %d ", ricorsivaLunghezza2 ( lista ));
    stampaLista ( lista );
    printf ( " \ nValori lista ricorsiva:" );
    stampaListaRicorsiva ( lista );
    printf ( " \n Inserisci un nuovo valore: " );
    scanf ( " %d ", & n );
    aggiungiElementoFondo (& lista, n );
    stampaLista ( lista );
    aggiungiElementoInizio (& lista, n );
    stampaLista ( lista );
    eliminaUltimoElemento (& lista );
    stampaLista ( lista );
    ritorno 0 ;
}/*
autore: Leonardo Pollicino
data: 13/11/2023
es. lista
testo creazione di una lista
*/

#includere <stdio.h>
#includere <stdlib.h>
#includere <string.h>

nodo della struttura typedef {
    valore int ;
    nodo struttura * successivo ;
} Nodo ;

int calcolaLunghezza ( Nodo * lista ) {
    Nodo * l = lista ;
    int polmone = 0 ;
    mentre ( l != NULL ) {
        polmone ++;
        l = l -> successivo ;
    }
    polmone di ritorno ;
}

int ricorsivaLunghezza ( Nodo * lista, int lung ) {
    Nodo * l = lista ;
    se ( l != NULL ) {
        polmone ++;
        polmone = ricorsivaLunghezza ( l -> successivo, polmone );
    }
    polmone di ritorno ;
}

int ricorsivaLunghezza2 ( Nodo * Lista ) {
    if ( Lista -> next != NULL ) {
        return 1 + ricorsivaLunghezza2 ( Lista -> next );
    }
    ritorno 1 ;
}

void stampaLista ( Nodo * lista ) {
    Nodo * l = lista ;
    printf ( " \nLista valori:" );
    mentre ( l != NULL ) {
        printf ( " %d ", l -> valore );
        l = l -> successivo ;
    }
}

void stampaListaRicorsiva ( Nodo * lista ) {
    Nodo * l = lista ;
    se ( l != NULL ) {
        printf ( " %d ", l -> valore );
        stampaListaRicorsiva ( l -> successiva );
    }
}

void aggiungiElementoInizio ( Node ** lista, int num ) {
    Nodo * testa ;
    head = ( Nodo *) malloc ( sizeof ( Nodo ));
    testa -> successivo = * lista ;
    testa -> valore = num ;
    * lista = testa ;
}

void aggiungiElementoFondo ( Nodo ** lista, int num ) {
    Nodo * l =* lista ;
    while ( l -> successivo != NULL ) {
        l = l -> successivo ;
    }
    l -> next = ( Nodo *) malloc ( sizeof ( Nodo ));
    l = l -> successivo ;
    l -> valore = numero ;
    l -> successivo = NULL ;
}

void eliminaUltimoElemento ( Node ** lista ) {
    Nodo * l =* lista ;
    Nodo * l2 = l ;
    while ( l -> successivo != NULL ) {
        l2 = l ;
        l = l -> successivo ;
    }
    l2 -> successivo = NULL ;
}

int principale () {
    intero n ;
    int polmone = 0 ;
    Nodo * lista = NULL ;
    Nodo * l ;
    Fare {
        printf ( "inserire un numero naturale o -1 per terminare: " );
        scanf ( " %d ", & n );
        se ( n >= 0 ) {
            se ( lista == NULL ) {
                lista = ( Nodo *) malloc ( sizeof ( Nodo ));
                l = lista ;
            }
            altro {
                l -> next = ( Nodo *) malloc ( sizeof ( Nodo ));
                l = l -> successivo ;
            }
            l -> valore = n ;
            l -> successivo = NULL ;
        }
    } mentre ( n >= 0 );

    l = lista ;
    printf ( "numeri inseriti:" );
    printf ( " \n " );
    mentre ( l != NULL ) {
        printf ( " %d - %p \n ", l -> valore, l -> successivo );
        l = l -> successivo ;
    }
    printf ( " \n " );
    printf ( "Numero di elementi: %d ", calcolaLunghezza ( lista ));
    printf ( " \n Numero di elementi con ricorsiva: %d ", ricorsivaLunghezza ( lista, lung ));
    printf ( " \n Numero di elementi con ricorsiva: %d ", ricorsivaLunghezza2 ( lista ));
    stampaLista ( lista );
    printf ( " \ nValori lista ricorsiva:" );
    stampaListaRicorsiva ( lista );
    printf ( " \n Inserisci un nuovo valore: " );
    scanf ( " %d ", & n );
    aggiungiElementoFondo (& lista, n );
    stampaLista ( lista );
    aggiungiElementoInizio (& lista, n );
    stampaLista ( lista );
    eliminaUltimoElemento (& lista );
    stampaLista ( lista );
    ritorno 0 ;
}
