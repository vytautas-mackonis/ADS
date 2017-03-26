#ifndef STACKHEADER_H_INCLUDED
#define STACKHEADER_H_INCLUDED

typedef struct Stekas StekoTipas;
typedef struct Elementai *StekoElem;

typedef char Type;
// noredami pakeisti steko tipa, tiesiog pakeiciame char i pavyzdziui, int, double ir kt.
// jei norime saugoti strukturas, klases, string (C++), naudojame rodykles ir jomis operuojame

struct Stekas{
    int ArSukurtas;
    int ArTuscias;
    StekoElem kitas;
};
    ///Steko sukurimas. Return 0 jei pavyko sukurti steka, return 1 jei stekas jau buvo sukurtas anksciau.
int SukurtiSteka (StekoTipas *pb);
    ///Reiksmes idejimas. Return 0 jei reiksme ideta, return 1 jei stekas dar nesukurtas, return 2 jei nepavyko isskirti atminties.
int IdetiReiksme (StekoTipas *pb, Type reiksme);
    ///Reiksmes isemimas. Return 0 jei reiksme isimta, return 1 jei stekas dar nesukurtas, return 2 jei steke jokiu elementu nera.
int IsimtiReiksme (StekoTipas *pb, Type *reiksme);
    ///Tikrina ar tuscias. Return 0 jei stekas netuscias, return 1 jei stekas tuscias, return 2 jei stekas dar nesukurtas.
int StekasTuscias (StekoTipas *pb);
    ///Tikrina ar pilnas. Return 0 jei stekas nepilnas, return 1 jei stekas dar nesukurtas.
int StekasPilnas (StekoTipas *pb);
    ///Steko naikinimas. Return 0 jei stekas sunaikintas, return 1 jei stekas dar nesukurtas.
int NaikintiSteka (StekoTipas *pb);

#endif // STACK_H_INCLUDED
