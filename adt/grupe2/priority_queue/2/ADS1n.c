#include <stdlib.h>
#include "ADS1n.h"

void sukurimas(eile *e){
    e->ilgis = 0;
    e->pradzia = NULL;
}

int arTuscia(eile *e){
    return e->ilgis==0;
}

int arPilna(eile *e){
    return 0;
}

int iterpimas(eile *e, tipas reiks, int pr){


    elementas* naujasel;

    if((naujasel = malloc(sizeof(elementas))) == NULL){
        return 0;
    }

    naujasel->reiksme = reiks;
    naujasel->prior = pr;
    naujasel->next = NULL;

    elementas *dabartinis = e->pradzia;
    elementas *sekantis = NULL;

    while(dabartinis!=NULL){
        sekantis = dabartinis->next;

        if(e->pradzia->prior < naujasel->prior){ // lygina su pirmuoju prior
            sekantis = dabartinis;
            dabartinis = NULL;
            break;
        }
        if(sekantis == NULL ){ //pabaiga
            break;
        }

        if(sekantis->prior < naujasel->prior){
            break;
        }
        dabartinis = dabartinis->next; // pereina prie kito elem
    }
    if(dabartinis==NULL){ // iterpinejam i pradzia
        e->pradzia = naujasel;
        naujasel->next = sekantis;
        e->ilgis++;
    }
    else if(sekantis!=NULL){ // iterpinejam i viduri
        dabartinis->next = naujasel;
        naujasel->next = sekantis;
        e->ilgis++;
    }
    else{ // iterppinejam i pabaiga
        dabartinis->next = naujasel;
        naujasel->next = NULL;
        e->ilgis++;
    }

    return 1;
}

elementas* isimtiElementa(eile *e){
    if(e->ilgis >0){
        elementas *grazinamas = e->pradzia;
        free(e->pradzia);
        e->pradzia = e->pradzia->next;
        e->ilgis--;

        return grazinamas;
    }
    return NULL;
}

void istrinti(eile *e){
    elementas *dabartinis = e->pradzia;
    elementas *sekantis = NULL;

    while(dabartinis!=NULL){
        sekantis = dabartinis->next;
        free(dabartinis);
        dabartinis = sekantis;
    }
    free(e);
}
