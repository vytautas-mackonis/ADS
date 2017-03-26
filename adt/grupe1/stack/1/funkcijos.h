//Martynas Zilionis Programu sistemos 1 kursas, 1 grupe, 2 pogrupis
//7 uzduotis - Stekas
///Funkciju aprasu failas

#ifndef Stekas
#define Stekas

typedef int Tipas;              //Pakeisti i toki, kokio reikes
struct Stack;
/// Pries naudojant Steka, ji reikia sukurti savo programoje. Pvz: struct Stack *Nr1 = NULL; Nepamirsti prilyginti NULL!!!
/// Rasant steko pavadinima i funkcija, butinai reikia rasyti su & zenklu. Pvz: x = Sukurti_Tuscia (&Stack);
int Sukurti_Tuscia (struct Stack **StackPointer);               //0 - pavyko, 1 - Nebera vietos, 2 - stekas jau sukurtas
int Ideti_I_Steka (struct Stack **StackPointer, Tipas x);       //0 - ideta, 1 - nebera vietos atminty, 2 - stekas neegzistuoja // i funkcija paduodame reiksme
int Isimti_Is_Steko (struct Stack **StackPointer, Tipas *y);    //0 - kai viskas gerai, 1 - kai stekas tuscias, 2 - stekas neegzistuoja // i funkcija paduodame kintamaji, per kuri gausime reiksme
int Ar_Pilnas_Stekas (struct Stack **StackPointer);             //0 - nepilnas, 1 - pilnas, 2 - stekas neegzistuoja
int Ar_Tuscias_Stekas (struct Stack **StackPointer);            //0 - netuscias, 1 - tuscias, 2 - stekas neegzistuoja
int Istrinti_Steka (struct Stack **StackPointer);               //0 - istrinta, 2 - stekas neegzistuoja

#endif
