//Martynas Zilionis Programu sistemos 1 kursas, 1 grupe, 2 pogrupis
//7 uzduotis - Stekas
///Steko failas
#include <stdio.h>
#include <stdlib.h>
#include "funkcijos.h"

struct Stack {
    Tipas x;
    struct Stack *prev;
    };

int Sukurti_Tuscia (struct Stack **StackPointer)
{
    if (*StackPointer != NULL) return 2;

    *StackPointer = malloc(sizeof(struct Stack));

    if (*StackPointer == NULL)
        return 1;

    (*StackPointer)->x = 0;
    (*StackPointer)->prev = NULL;

    return 0;
}

int Ideti_I_Steka (struct Stack **StackPointer, Tipas y)
{
    if (*StackPointer == NULL) return 2;
    struct Stack *Naujas = malloc(sizeof(struct Stack));
    if (Naujas == NULL)
    {
        return 1;
    }
    Naujas->x = y;
    Naujas->prev = *StackPointer;
    *StackPointer = Naujas;
    return 0;
}

int Isimti_Is_Steko (struct Stack **StackPointer, Tipas *y)
{
    if (*StackPointer == NULL)
    {
        return 2;
    }
    if ((*StackPointer)->prev == NULL)
    {
        return 1;
    }
    *y = (*StackPointer)->x;

    struct Stack *Temp = *StackPointer;
    *StackPointer = (*StackPointer)->prev;

    free (Temp);
    return 0;
}

int Ar_Pilnas_Stekas (struct Stack **StackPointer)
{
    if (*StackPointer == NULL) return 2;
    struct Stack *Naujas = malloc(sizeof(struct Stack));
    if (Naujas == NULL)
    {
        free (Naujas);
        return 1;
    }
    free (Naujas);
    return 0;
}

int Ar_Tuscias_Stekas (struct Stack **StackPointer)
{
    if (*StackPointer == NULL) return 2;
    if ((*StackPointer)->prev == NULL) return 1;
    return 0;
}

int Istrinti_Steka (struct Stack **StackPointer)
{
    if (*StackPointer == NULL) return 2;
    struct Stack *Temp = *StackPointer;
    while (*StackPointer != NULL)
    {
        Temp = *StackPointer;
        *StackPointer = (*StackPointer)->prev;
        free (Temp);
    }
    free (*StackPointer);
    return 0;
}
