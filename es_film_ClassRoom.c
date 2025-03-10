#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct Film{
    char* titolo;
    char* genere;
    int anno;
    struct Film* next;
}Film;

bool isEmpty(Film** top){
    if(*top == NULL){
        return true;
    }
    return false;
}

Film* creaFilm(char* titolo, char* genere, int anno){
    Film* f = (Film*) malloc(sizeof(Film));
    strcpy(f->titolo, titolo); //titolo struct , titolo funzione
    f->anno = anno;
    strcpy(f->genere, genere);
    f->next = NULL;
    return f;
}


void push(Film** top, char* titolo, char* genere, int anno){
    Film* f2 = creaFilm(titolo, genere, anno);
    f2->next = *top; //* top = top[0] come se prendessi il primo
    *top = f2;
}

Film* pop(Film** top){ //prende il primo elem
    Film* temp = NULL; // server per restituire l'elemento tolto
    if(isEmpty(top) == false){
        temp = *top;
        *top = (*top)->next; //parentesi per definire un ordine
        temp->next = NULL;
    }
return temp;
}

void StampaFilm(Film* f){
    printf("%s %d %s", f->titolo, f->anno, f->genere);
}

int main() {
    Film* top = NULL;
    push(&top, "titolo2", "horror", 2000);
    Film* f1= pop(&top);
    StampaFilm(f1);

}

