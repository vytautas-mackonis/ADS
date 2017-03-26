#include <stdio.h>
#include <stdlib.h>

#include "StackHeader.h"

struct Elementai
{
	Type duom;
	StekoElem atgal;
};

int SukurtiSteka (StekoTipas *pb)
{
    if((pb -> ArSukurtas) == 1)
        return 1;
    else
    {
        pb -> kitas = NULL;
        pb -> ArTuscias = 1;
        pb -> ArSukurtas = 1;
        return 0;
    }
}

int IdetiReiksme (StekoTipas *pb, Type reiksme)
{
	StekoElem elem;
    if((pb -> ArSukurtas) == 0)
        return 1;

	else if((pb -> ArTuscias) == 1) // Jei stekas tuscias
	{
	    pb -> ArTuscias = 0;
	    elem = malloc(sizeof(struct Elementai));
	    if (elem == NULL)
        {
            return 2;
        }
        elem -> atgal = NULL;
        elem -> duom = reiksme;
        pb -> kitas = elem;
        return 0;
	}
	else // Jei stekas netuscias
    {
        elem = malloc(sizeof(struct Elementai));
        if (elem == NULL)
        {
            return 2;
        }
        elem -> duom = reiksme;
        elem -> atgal = pb -> kitas;
        pb -> kitas = elem;
        return 0;
    }
}

int IsimtiReiksme (StekoTipas *pb, Type *reiksme)
{
    StekoElem elem;
    if((pb -> ArSukurtas) == 0)
        return 1;

	if((pb -> ArTuscias) == 1) //Jei stackas tuscias
        return 2;

	elem = pb -> kitas;
    *reiksme = (pb -> kitas) -> duom;
    pb -> kitas = (pb -> kitas) -> atgal;
    free(elem);
    if ((pb -> kitas) == NULL)
    {
        pb -> ArTuscias = 1;
    }
    return 0;
}

int StekasTuscias (StekoTipas *pb)
{
    if((pb -> ArSukurtas) == 0)
        return 2;

    else if((pb -> ArTuscias) == 1) //Jei tuscias
        return 1;

    else return 0; //Jei netuscias
}

int StekasPilnas (StekoTipas *pb)
{
    if((pb -> ArSukurtas) == 0)
        return 1;

    else //skirta atmintis
    {
        return 0;
    }
}

int NaikintiSteka (StekoTipas *pb)
{
    StekoElem elem = NULL;
    if((pb -> ArSukurtas) == 0)
        return 1;
    if ((pb -> ArTuscias) == 1)
    {
        pb -> ArSukurtas = 0;
        return 0;
    }
	elem = pb -> kitas;
    while(elem -> atgal != NULL )
    {
        free(elem);
        elem = elem -> atgal;
	}
	free(elem);
    pb -> ArSukurtas = 0;
    return 0;
}
