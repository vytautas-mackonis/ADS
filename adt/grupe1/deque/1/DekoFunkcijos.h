#ifndef MAINFUNKCIJOS_H_INCLUDED
#define MAINFUNKCIJOS_H_INCLUDED

typedef struct Dekas_Elementas
{
    int info;
    struct Dekas_Elementas *next;
    struct Dekas_Elementas *prev;

} Dekas;

typedef struct Dekas_Rodykles
{
    int kiekis;
    struct Dekas_Elementas *priekis;
    struct Dekas_Elementas *galas;
    struct Dekas_Elementas *pradinis;

} DekoRodykles;

void SukurtiDeka(DekoRodykles *duomenys);
//---------------------------
void IterptiTop(int data, DekoRodykles *zymiuData);
void IterptiBottom(int data, DekoRodykles *zymiuData);
//---------------------------
void IstrintiPirma(DekoRodykles *zymiuData);
void IstrintiPaskutini(DekoRodykles *zymiuData);
//---------------------------
int PradziosDuom(DekoRodykles zymiuData);
int PabaigosDuom(DekoRodykles zymiuData);
//---------------------------
void PerziuretiVisaDeka(DekoRodykles zymiuData);
//---------------------------
int DekoDuomKiekis(DekoRodykles zymiuData);
bool ArTuscias(DekoRodykles zymiuData);
//---------------------------
void Sunaikinti(DekoRodykles *zymiuData);

#endif // MAINFUNKCIJOS_H_INCLUDED
