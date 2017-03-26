//Martynas Zilionis Programu sistemos 1 kursas, 1 grupe, 2 pogrupis
//7 uzduotis - Stekas
///Demo programos failas
#include <stdio.h>
#include <stdlib.h>
#include "funkcijos.h"

int main()
{
    Tipas a;
    int i, x;
    struct Stack *Nr1 = NULL;
    struct Stack *Nr2 = NULL;
    printf ("Sukuria tuscia ir ivedimas\n");
    x = Sukurti_Tuscia(&Nr1);
    x = Sukurti_Tuscia(&Nr2);
    printf ("Pirmo steko ivedimas:\n");
    for (i = 0; i < 5; i++)
    {
        scanf ("%d", &a);
        x = Ideti_I_Steka(&Nr1, a);
    }
    printf ("Antro steko ivedimas:\n");
    for (i = 0; i < 5; i++)
    {
        scanf ("%d", &a);
        x = Ideti_I_Steka(&Nr2, a);
    }
    printf ("\n\nAr pilnas: %d\n", x = Ar_Pilnas_Stekas(&Nr1));
    printf ("Ar tuscias: %d\n", x = Ar_Tuscias_Stekas(&Nr1));

    printf ("\nIsvedimas is steko\n");

    for (i = 0; i < 5; i++)
    {
        x = Isimti_Is_Steko(&Nr1,&a);
        printf ("%d ", a);
    }


    printf ("\nAr pilnas: %d\n", x = Ar_Pilnas_Stekas(&Nr1));
    printf ("Ar tuscias: %d\n", x = Ar_Tuscias_Stekas(&Nr1));

    x = Isimti_Is_Steko(&Nr1,&a);
    printf ("Skaitymas is tuscio steko: %d", x);

    printf ("\n\nSteko istrinimas:\n");
    x = Istrinti_Steka(&Nr1);
    printf ("%d", x);
    x = Istrinti_Steka(&Nr1);
    printf ("\n%d", x);

    printf ("\nKas buna, kai nera steko:\n");
    printf ("Ar pilnas: %d\n", x = Ar_Pilnas_Stekas(&Nr1));
    printf ("Ar tuscias: %d\n", x = Ar_Tuscias_Stekas(&Nr1));
    x = Isimti_Is_Steko(&Nr1, a);
    printf ("Skaitymas is steko: %d\n", x);
    printf ("Idejimas i steka: %d\n", x = Ideti_I_Steka(&Nr1,a));
    printf ("Steko istrinimas: %d\n", x = Istrinti_Steka(&Nr1));
    printf ("Steko sukurimas: %d\n", x = Sukurti_Tuscia(&Nr1));

    printf ("\nKai kuri steka kai jau stekas sukurtas: %d\n", x = Sukurti_Tuscia(&Nr1));
    ///----------------------------------------------------------------------------------
    printf ("\n\nDarbas su antru steku: \n");

    printf ("Ar pilnas: %d\n", x = Ar_Pilnas_Stekas(&Nr2));
    printf ("Ar tuscias: %d\n", x = Ar_Tuscias_Stekas(&Nr2));

    printf ("\nIsvedimas is steko\n");

    for (i = 0; i < 5; i++)
    {
        x = Isimti_Is_Steko(&Nr2,&a);
        printf ("%d ", a);
    }


    printf ("\nAr pilnas: %d\n", x = Ar_Pilnas_Stekas(&Nr2));
    printf ("Ar tuscias: %d\n", x = Ar_Tuscias_Stekas(&Nr2));

    x = Isimti_Is_Steko(&Nr2,&a);
    printf ("Skaitymas is tuscio steko: %d", x);

    printf ("\n\nSteko istrinimas:\n");
    x = Istrinti_Steka(&Nr2);
    printf ("%d", x);
    x = Istrinti_Steka(&Nr2);
    printf ("\n%d", x);

    printf ("\nKas buna, kai nera steko:\n");
    printf ("Ar pilnas: %d\n", x = Ar_Pilnas_Stekas(&Nr2));
    printf ("Ar tuscias: %d\n", x = Ar_Tuscias_Stekas(&Nr2));
    x = Isimti_Is_Steko(&Nr2, a);
    printf ("Skaitymas is steko: %d\n", x);
    printf ("Idejimas i steka: %d\n", x = Ideti_I_Steka(&Nr2,a));
    printf ("Steko istrinimas: %d\n", x = Istrinti_Steka(&Nr2));
    printf ("Steko sukurimas: %d\n", x = Sukurti_Tuscia(&Nr2));

    printf ("\nKai kuri steka kai jau stekas sukurtas: %d\n", x = Sukurti_Tuscia(&Nr2));
    return 0;
}
