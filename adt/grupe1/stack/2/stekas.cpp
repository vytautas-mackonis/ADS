#include<iostream>
#include <stdlib.h>
#include "stekas.h"
using namespace std;

struct Stekas {
    Tipas x;
    struct Stekas *kitas;
};

int SukurtiSteka (struct Stekas **Pointer)
{
    if (*Pointer != NULL)
        return 1;        // stekas jau sukurtas

    *Pointer = (Stekas*)malloc(sizeof(struct Stekas));
    if (*Pointer == NULL)
        return 2;         //nebera vietos

    (*Pointer)->x = 0;
    (*Pointer)->kitas = NULL;

    return 0;
}

int Push (struct Stekas **Pointer, Tipas a)
{
    if (*Pointer == NULL)           //tokio steko nera
        return 1;

    struct Stekas *Naujas = (Stekas*)malloc(sizeof(struct Stekas));
    if (Naujas == NULL)
        return 2;               //nebera vietos

    Naujas->x = a;
    Naujas->kitas = *Pointer;
    *Pointer = Naujas;
    return 0;
}

int Pop (struct Stekas **Pointer, Tipas *a)
{
    if (*Pointer == NULL)
        return 1;                       //tokio steko nera

    if ((*Pointer)->kitas == NULL)
        return 2;                       //stekas tuscias

    *a = (*Pointer)->x;

    struct Stekas *Temp = *Pointer;
    *Pointer = (*Pointer)->kitas;

    free (Temp);
    return 0;
}

int Tuscias (struct Stekas **Pointer)
{
    if (*Pointer == NULL)
        return 2;                   //tokio steko nera

    if ((*Pointer)->kitas == NULL)
        return 1;                   //tuscias
    return 0;                       //netuscias
}

int Pilnas (struct Stekas **Pointer)
{
    if (*Pointer == NULL)      //tokio steko nerea
        return 2;

    struct Stekas *Naujas = (Stekas*)malloc(sizeof(struct Stekas));
    if (Naujas == NULL)
    {
        free (Naujas);
        return 1;                   //pilnas
    }
    free (Naujas);
    return 0;                       //nepilnas
}
