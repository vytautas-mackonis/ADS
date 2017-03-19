#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DekoFunkcijos.h"

void SukurtiDeka(DekoRodykles *zymiuData)
{
    Dekas *naujas = (Dekas*)malloc(1*sizeof(Dekas));
    zymiuData->pradinis = naujas;

    if (naujas == NULL) return;

    naujas->next = NULL;
    naujas->prev = NULL;

    zymiuData->kiekis = 0;
    zymiuData->priekis = naujas;
    zymiuData->galas = naujas;

    //return naujas;
}

void IterptiTop(int data, DekoRodykles *zymiuData)
{
    if (zymiuData->kiekis == 0)
    {
        zymiuData->pradinis->info = data;
       (zymiuData->kiekis)++;
    }
    else
    {
        Dekas *naujasPrieky = (Dekas*)malloc(1*sizeof(Dekas));

        zymiuData->priekis->prev = naujasPrieky;
        naujasPrieky->next = zymiuData->priekis;
        naujasPrieky->info = data;
        zymiuData->priekis = naujasPrieky;

        naujasPrieky->prev = NULL;

        (zymiuData->kiekis)++;
    }
}

void IterptiBottom(int data, DekoRodykles *zymiuData)
{
    if (zymiuData->kiekis == 0)
    {
        zymiuData->pradinis->info = data;
       (zymiuData->kiekis)++;
    }
    else
    {
        Dekas *naujasGale = (Dekas*)malloc(1*sizeof(Dekas));

        zymiuData->galas->next = naujasGale;
        naujasGale->prev = zymiuData->galas;
        naujasGale->info = data;
        zymiuData->galas = naujasGale;

        naujasGale->next = NULL;

        (zymiuData->kiekis)++;
    }
}

void IstrintiPirma(DekoRodykles *zymiuData)
{
    Dekas *istrinti;
    istrinti = zymiuData->priekis;

    zymiuData->priekis = zymiuData->priekis->next;

    if (zymiuData->kiekis != 1) istrinti->next->prev = NULL;

    free(istrinti);

    (zymiuData->kiekis)--;

    if (zymiuData->kiekis == 0)
    {
        zymiuData->priekis = NULL;
        zymiuData->galas = NULL;
    }
}

void IstrintiPaskutini(DekoRodykles *zymiuData)
{
    Dekas *istrinti;
    istrinti = zymiuData->galas;

    zymiuData->galas = zymiuData->galas->prev;

    if (zymiuData->kiekis != 1) istrinti->prev->next = NULL;

    free(istrinti);

    (zymiuData->kiekis)--;

    if (zymiuData->kiekis == 0)
    {
        zymiuData->priekis = NULL;
        zymiuData->galas = NULL;
    }
}

int DekoDuomKiekis(DekoRodykles zymiuData)
{
    if(zymiuData.kiekis == 0) return 0;
    else if (zymiuData.kiekis == 1) return 1;
    else return zymiuData.kiekis;
}

int PradziosDuom(DekoRodykles zymiuData)
{
   if(zymiuData.kiekis == 0) return 0;
   else return zymiuData.priekis->info;
}

int PabaigosDuom(DekoRodykles zymiuData)
{
   if(zymiuData.kiekis == 0) return 0;
   else return zymiuData.galas->info;
}

void PerziuretiVisaDeka(DekoRodykles zymiuData)
{
    Dekas *spausdinimas = zymiuData.priekis;

    while(spausdinimas != NULL)
    {
		printf(" %d", spausdinimas->info);

		spausdinimas = spausdinimas->next;
	}
}

bool ArTuscias(DekoRodykles zymiuData)
{
    if(zymiuData.kiekis == 0) return true;
    else return false;
}

void Sunaikinti(DekoRodykles *zymiuData)
{
	Dekas *istrinti = zymiuData->priekis;
	Dekas *istrintiSekantis = NULL;

	while(istrinti != NULL)
    {
		istrintiSekantis = istrinti->next;
		free(istrinti);
		istrinti = istrintiSekantis;
	}

	zymiuData->kiekis = 0;

    zymiuData->priekis = NULL;
    zymiuData->galas = NULL;

	printf(" Dekas sunaikintas \n");
}
