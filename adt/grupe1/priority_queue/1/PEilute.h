/*
 * 1uzd.h
 *
 *  Created on: 2017-02-16
 *      Author: Aidas
 */

typedef int d_tipas;

// Struktura kurioje laikomas pirmasis eilutes elementas bei elemtu skaicius
struct pqueue;
typedef struct pqueue *PQueue;

// Priskiriama atmintis. Grazinama rodykle i eilutes pradzios struktura. Jei grazina NULL, reiskia kad priskirti atminties nepavyko
PQueue Sukurti();

// Grazina -1, jei eilutes pradzios struktura tuscia(NULL). Grazina 0, jei nepavyko priskirti atminties naujam eilutes elementui.
// Grazina 1 jei iterpti elementa pavyko
int Iterpti(PQueue eil, d_tipas data, int priority);

// Panaikina visa eilute. Grazina 1 jei panaikinti pavyko, grazina -1 jei duota eilutes pradzios struktura tuscia(NULL).
int Sunaikinti(PQueue eil);

// Grazina 1, jeigu eilute netuscia, grazina 0, jeigu eilute tuscia, grazina -1, jei eilutes pradzios struktura tuscia(NULL).
int Ar_Tuscia(PQueue eil);

// Grazina int tipo reiksme kuri lygi eilutes elementu skaiciui. Grazina -1, jei eilutes pradzios struktura tuscia(NULL).
int Suma(PQueue eil);

// Panaikina seniausia elementa su didziausiu prioritetu bei perduoda jo duomenis. Grazina 1 jei panaikinti pavyko. Grazina 0 jei nera ka panaikinti.
// Grazina -1, jei eilutes pradzios struktura tuscia(NULL).
int Panaikinti(PQueue eil, d_tipas *data);

// Perduoda didziausio prioriteto elemento duomenis. Grazina 1, jei perduoti pavyko, grazina 0, jei nera jokiu elementu, grazina -1, jei eilutes pradzios struktura tuscia(NULL).
int Patikrinti(PQueue eil, d_tipas *data);

// Spausdina eilute. Grazina 1, jei spausdinti pavyko, grazina -1, jei eilutes pradzios struktura tuscia(NULL).
int Spausdinti(PQueue eil);
