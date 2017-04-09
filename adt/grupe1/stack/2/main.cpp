//Zilvinas Skuodys, 1 grupe 2 pogrupis
//1 uzduotis - Stekas
#include <iostream>
#include <stdlib.h>
#include "stekas.h"
using namespace std;

void Pilnumas (int result);

int main()
{
    int result;
    Tipas a;
    struct Stekas *st = NULL;

    result = SukurtiSteka(&st);
    if (result == 2)
        cout << "nebera atminties" << endl;

    cout << "Steko duomenys " << endl;
    for (int i = 0; i < 4; i++) {
        cin >> a;
        result = Push(&st, a);
        if (result == 1) {
            cout << "stekas neegzistuoja" << endl;
            break;
        }
        if (result == 2) {
            cout << "nebera atminties" << endl;
        }
    }

    cout << "Steko ispopinimas: ";
    for (int i = 0; i < 4; i++) {
        result = Pop(&st, &a);
        if (result == 1) {
            cout << "stekas neegzistuoja" << endl;
            break;
        }
        cout << a << " ";
    }

    result = Pilnas(&st);
    cout << endl << "Ar stekas pilnas? ";
    Pilnumas(result);

    result = Tuscias(&st);
    cout << "Ar stekas tuscias? ";
    Pilnumas(result);

    return 0;
}
void Pilnumas (int result)
{
    switch(result)
    {
        case 0:
            cout << "NE" << endl;
            break;
        case 1:
            cout << "TAIP" << endl;
            break;
        case 2:
            cout << "Stekas neegzistuoja" << endl;
    }
}
