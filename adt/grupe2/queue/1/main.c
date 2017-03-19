/*Andrejus Kuznecovas, ADT eile, 2017*/
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
void print(queue Q){
    node* x = Q.begin;
    if (x==NULL)
    {
        printf("Eile yra tuscia\n");
    }
    else{
    printf ("[");
    while(x != NULL){
        printf("%d", x->val);
        if (x->next != NULL) printf (", ");
        x = x->next;
    }
    printf("]\n");
    }
}
int main()
{
    //*ZEMIAU YRA FUNkCIJU TESTAVIMO PAVYZDZIAI, JAS GALIMA ISTRINTI.
    type x;
    type pirmas;
    queue Q = newQueue();
    printf ("Eiles dydis: %d\n", queueSize(Q));
    if (peek(&Q, &x) == 0) printf ("Pirmo elemento nera. \n");
    else printf("pirmas elementas: %d\n", x);
    push(&Q, 15);
    if (peek(&Q, &x) == 0) printf ("Pirmo elemento nera. \n");
    else printf("pirmas elementas: %d\n", x);
    print(Q);
    if (push(&Q, 91));
    else printf ("Nepavyko isskirti atminties ");
    pop(&Q, &pirmas);
    printf ("Isimtas pirmasis elementas:- %d\n", pirmas);
    if (peek(&Q, &x) == 0) printf ("Pirmo elemento nera. \n");
    else printf("pirmas elementas: %d\n", x);
    print(Q);
    push (&Q, -614);
    push(&Q, 15);
    push(&Q, 15);
    push(&Q, 1410);
    print(Q);
    printf ("Eiles dydis: %d\n", queueSize(Q));
    pop(&Q, &pirmas);
    printf ("Isimtas pirmasis elementas:- %d\n", pirmas);
    print(Q);
    clear(&Q);
    print(Q);
    printf ("Eiles dydis: %d\n", queueSize(Q));
    //*

    return 0;
}
