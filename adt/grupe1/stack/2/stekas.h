#ifndef STEKAS_H_INCLUDED
#define STEKAS_H_INCLUDED
#include <iostream>
using namespace std;

typedef int Tipas;
struct Stekas;

int SukurtiSteka (struct Stekas **Pointer);
int Push (struct Stekas** Pointer, Tipas a);
int Pop (struct Stekas** Pointer, Tipas *a);
int Tuscias (struct Stekas **Pointer);
int Pilnas (struct Stekas **Pointer);

#endif // STEKAS_H_INCLUDED
