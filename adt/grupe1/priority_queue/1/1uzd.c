/*
 ============================================================================
 Name        : 1uzd.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "PEilute.h"


int main(void)
{
    PQueue eil=NULL;
    printf("Prioritetine eilute\n");
    printf("Funkcijos:\n");
    printf("1. Sukurti prioritetine eilute\n");
    printf("2. Patikrinti ar eilute tuscia\n");
    printf("3. Iterpti nauja elementa\n");
    printf("4. Patikrinti didziausio prioriteto elementa\n");
    printf("5. Gauti eilutes elementu skaiciu\n");
    printf("6. Panaikinti elementa kurio prioritetas didziausias\n");
    printf("7. Sunaikinti eilute\n");
    printf("8. Isspausdinti eilute\n");
    printf("9. Uzbaigti programa\n");

    int i = 0;

    while(1) {
    	printf("Iveskite norimos funkcijos numeri \n");
    	scanf("%d", &i);

        if (i == 1) {
            eil = Sukurti();
            if(eil != NULL) {
            	printf("Prioritetine eilute sukurta\n\n");
            } else {
            	printf("Prioritetines eilutes sukurti nepavyko\n\n");
            }
        }
        else if (i == 2) {
            int er = Ar_Tuscia(eil);
            if(er == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
            else if(er == 0) printf("Eilute tuscia\n");
            else if(er == 1) printf("Eilute nera tuscia\n");
        }
        else if (i == 3) {
        	int duom,prio;
        	printf("Koki elementa norite iterpti?   ");
        	scanf("%d", &duom);
        	printf("\nKoks iterpiamo elemento prioritetas?   ");
        	scanf("%d", &prio);
            int er = Iterpti(eil, duom, prio);
            if(er == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
            else if(er == 0) printf("Priskirti atminties naujam elementui nepavyko\n");
            else if(er == 1) {
            	printf("Elementas iterptas\n");
               	er = Spausdinti(eil);
            }
        }
        else if (i == 4) {
            d_tipas data;
            int er = Patikrinti(eil, &data);
            if(er == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
            else if(er == 0) printf("Nera elementu\n");
            else if(er == 1) printf("Didziausio prioriteto elementas: %d \n", data);
        }
        else if (i == 5) {
            int sum = Suma(eil);
            if(sum == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
            else printf("Elementu suma: %d \n", sum);
        }
        else if (i == 6) {
        	d_tipas data;
            int er = Panaikinti(eil,&data);
            if(er == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
            else if(er == 0) printf("Nera elementu\n");
            else if(er == 1) printf("Panaikintas elementas: %d \n", data);
        }
        else if (i == 7) {
        	int er = Sunaikinti(eil);
        	if(er == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
        	else if(er == 1) {
        		printf("Eilute sunaikinta\n");
        		eil = NULL;
        	}
        }
        else if (i == 8) {
        	int er = Spausdinti(eil);
        	if(er == -1) printf("Eilutes pradzios struktura tuscia (NULL)\n");
        }
        else if (i == 9) {
        	break;
        }
        else {
            printf("Tokios funkcijos nera \n");
        }
    }
    return 0;
}
