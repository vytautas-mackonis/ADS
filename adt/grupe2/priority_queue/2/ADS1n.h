#ifndef ADS1N_H_INCLUDED
#define ADS1N_H_INCLUDED
#endif // ADS1N_H_INCLUDED

typedef int tipas;

typedef struct elementas{
    tipas reiksme;
    int prior;
    struct elementas *next;
}elementas;

typedef struct eile{
    int ilgis;
    elementas *pradzia;
}eile;

void sukurimas(eile *e);

int arTuscia(eile *e);

int arPilna(eile *e);

int iterpimas(eile *e, tipas reiks, int pr);

elementas* isimtiElementa(eile *e);

void istrinti(eile *e);
