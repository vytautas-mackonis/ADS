#include <stdio.h>
#include <stdlib.h>

#include "StackHeader.h"
//#include "Funkcijos.c"
#define STEKOFORMATAS " %c"

int main()
{
    int pasirinkimas = 1;
    StekoTipas pab;
    Type reiksme;

    int funkc_rez = 0;

    while(pasirinkimas != 0)
    {
        printf("Baigti darba - 0 \n");
        printf("Sukurti steka - 1 \n");
        printf("Ideti reiksme - 2 \n");
        printf("Isimti reiksme - 3\n");
        printf("Patikrinti ar stekas tuscias - 4\n");
        printf("Patikrinti ar stekas pilnas - 5\n");
        printf("Naikinti steka - 6\n");

        scanf(" %d", &pasirinkimas);
        switch (pasirinkimas)
        {
        case 0 :
            printf("Programa baigia darba. \n\n");
            NaikintiSteka(&pab);
            break;

        case 1 :
            funkc_rez = SukurtiSteka(&pab);
            if(funkc_rez == 1)
            {
                printf("Stekas jau buvo sukurtas.\n\n");
                break;
            }
            else
                printf("Stekas sukurtas.\n\n");
            break;

        case 2:
            printf("Iveskite reiksme:\n");
            scanf(STEKOFORMATAS, &reiksme);
            funkc_rez = IdetiReiksme(&pab, reiksme);
            if(funkc_rez == 0)
                printf("Reiksme ideta.\n\n");
            else if(funkc_rez == 1)
            {
                printf("Nesukurtas stekas, reiksmes ideti neina.\n\n");
                break;
            }
            else if (funkc_rez == 2)
            {
                printf("Error: Nepavyko isskirti atminties.\n\n");
                break;
            }
            break;

        case 3:
            funkc_rez = IsimtiReiksme(&pab, &reiksme);
            if(funkc_rez == 0)
            {
                printf(STEKOFORMATAS, reiksme);
                printf(" Reiksme isimta.\n\n");
            }
            else if(funkc_rez == 1)
                printf("Nesukurtas stekas.\n\n");
            else if(funkc_rez == 2)
                printf("Stekas tuscias. \n\n");
            break;

        case 4:
            funkc_rez = StekasTuscias(&pab);
            if(funkc_rez == 2)
                printf("Stekas nesukurtas.\n\n");
            if(funkc_rez == 1)
                printf("Stekas tuscias.\n\n");
            if(funkc_rez == 0)
                printf("Stekas netuscias.\n\n");
            break;

        case 5:
            funkc_rez = StekasPilnas(&pab);
            if(funkc_rez == 1)
                printf("Stekas nesukurtas.\n\n");
            if(funkc_rez == 0)
                printf("Stekas nepilnas.\n\n");
            break;

        case 6:
            funkc_rez = NaikintiSteka(&pab);
            if(funkc_rez == 0)
            {
                printf("Stekas sunaikintas.\n\n");
            }
            if(funkc_rez == 1)
            {
                printf("Stekas nebuvo sukurtas, todel nebuvo ka naikinti.\n\n");
            }
            break;

        default:
            printf("Neatpazinta komanda.\n\n");
            break;

        }
    }
    return 0;
}
