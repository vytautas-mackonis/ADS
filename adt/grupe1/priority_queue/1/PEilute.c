/*
 * PEilute.c
 *
 *  Created on: 2017-02-16
 *      Author: Aidas
 */

#include <stdio.h>
#include <stdlib.h>
#include "PEilute.h"


typedef struct list {
    d_tipas duomuo;
    int prioritetas;
    struct list* next;
} *LIST;

struct pqueue {
    LIST head;
    int elem_suma;
};

PQueue Sukurti() {
    PQueue eil = malloc(sizeof(PQueue));
    if (eil != NULL) {
        eil->head = NULL;
        eil->elem_suma = 0;
    }
    return eil;
}

int Iterpti(PQueue eil, d_tipas duom, int prioritetas) {
	if(eil == NULL) return -1;
	LIST current = malloc(sizeof(LIST));
	if(current == NULL) return 0;
	else {
		current->duomuo = duom;
		current->prioritetas = prioritetas;
		current->next = NULL;
		eil->elem_suma += 1;
	}
	if(eil->head == NULL) eil->head = current;
	else if (eil->head->prioritetas < prioritetas) {
		current->next = eil->head;
		eil->head = current;
	} else {
		LIST temp;
		for (temp = eil->head; temp; temp = temp->next) {
			if(temp->prioritetas >= prioritetas && temp->next == NULL) {
				temp->next = current;
				break;
			}
			if(temp->prioritetas >= prioritetas && temp->next->prioritetas < prioritetas) {
				current->next = temp->next;
				temp->next = current;
				break;
			}
		}
	} return 1;
}

int Sunaikinti(PQueue eil) {
	if(eil == NULL) return -1;
	LIST temp = eil->head;
	LIST temp2 = eil->head;
	while (temp != NULL){
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(eil);
	return 1;
}

int Suma(PQueue eil) {
	if(eil == NULL) return -1;
	return eil->elem_suma;
}

int Panaikinti(PQueue eil, d_tipas *data) {
	if(eil == NULL) return -1;
	if(eil->head != NULL) {
		*data = eil->head->duomuo;
		LIST temp = eil->head;
		eil->head = eil->head->next;
		free(temp);
		eil->elem_suma -= 1;
		return 1;
	}
	return 0;
}

int Ar_Tuscia(PQueue eil) {
	if(eil == NULL) return -1;
	if(eil->elem_suma != 0) return 1;
	return 0;
}

int Patikrinti(PQueue eil, d_tipas *data) {
	if(eil == NULL) return -1;
	if(eil->head != NULL) {
		*data = eil->head->duomuo;
		return 1;
	}
	return 0;
}

int Spausdinti(PQueue eil) {
	if(eil == NULL) return -1;
	printf("Prioritetine eilute:\n");
	LIST temp;
	for(temp = eil->head;temp;temp = temp->next) {
		printf("Elem: %d, prio: %d \n", temp->duomuo, temp->prioritetas);
	}
	printf("\n");
	return 1;
}
