#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DekoFunkcijos.h"

void main()
{
    int operacija, data;
    DekoRodykles zymiuData;

    zymiuData.priekis = NULL;
    zymiuData.galas = NULL;

    printf(" Operacijos: \n");

    printf("\n 1 - Sukurti deka");
    printf("\n 2 - Iterpti duomenis deko pradzioje");
    printf("\n 3 - Iterpti duomenis deko pabaigoje");
    printf("\n 4 - Istrinti elementa deko gale");
    printf("\n 5 - Istrinti elementa deko pradzioje");
    printf("\n 6 - Perziureti deko pradzios duomenis");
    printf("\n 7 - Perziureti deko pabaigos duomenis");
    printf("\n 8 - Perziureti viso deko duomenis");
    printf("\n 9 - Deko duomenu kiekis");
    printf("\n 10 - Patikrinti, ar dekas tuscias");
    printf("\n 11 - Sunaikinti deka");
    printf("\n 12 - Exit");
    printf("\n\n");

    //zymiuData.pradinis = SukurtiDeka(&zymiuData);

    while (1)
    {
        printf("\n Pasirinkite operacija: ");
        scanf("%d", &operacija);

        switch(operacija)
        {
            case 1:

                if (zymiuData.priekis != NULL || zymiuData.galas != NULL)
                {
                    printf(" Dekas jau yra sukurtas \n");
                    break;
                }

                SukurtiDeka(&zymiuData);

                if (zymiuData.pradinis == NULL) printf(" Klaida isskiriant atminti \n");
                else printf(" Dekas sukurtas \n");

                break;

            case 2:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }
                printf(" Iveskite informacija: ");
                scanf("%d", &data);
                IterptiTop(data, &zymiuData);
                break;

            case 3:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }
                printf(" Iveskite informacija: ");
                scanf("%d", &data);
                IterptiBottom(data, &zymiuData);
                break;

            case 4:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }
                else if (zymiuData.kiekis == 0)
                {
                    printf(" Deke neivesta duomenu \n");
                    break;
                }

                IstrintiPirma(&zymiuData);
                break;

            case 5:

               if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }
                else if (zymiuData.kiekis == 0)
                {
                    printf(" Deke neivesta duomenu \n");
                    break;
                }

                IstrintiPaskutini(&zymiuData);
                break;

            case 6:
                if (PradziosDuom(zymiuData) != 0) printf(" Duomenys deko pradzioje: %d ", PradziosDuom(zymiuData));
                else printf(" Dekas yra tuscias \n");
                break;

            case 7:
                if (PabaigosDuom(zymiuData) != 0) printf(" Duomenys deko pabaigoje: %d ", PabaigosDuom(zymiuData));
                else printf(" Dekas yra tuscias \n");
                break;

            case 8:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }

                PerziuretiVisaDeka(zymiuData);
                printf("\n");
                break;

            case 9:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }

                if (DekoDuomKiekis(zymiuData) == 0) printf(" Deke duomenu neivesta \n");
                else if (DekoDuomKiekis(zymiuData) == 1)printf(" Deke ivestas 1 duomuo \n");
                else printf(" Deke ivesti %d duomenys \n", DekoDuomKiekis(zymiuData));
                break;

            case 10:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }

                if (ArTuscias(zymiuData) == true) printf(" Dekas yra tuscias \n");
                else printf(" Dekas netuscias, jame yra ivestu elementu \n");
                break;

            case 11:

                if (zymiuData.priekis == NULL || zymiuData.galas == NULL)
                {
                    printf(" Dekas nera sukurtas \n");
                    break;
                }

                Sunaikinti(&zymiuData);
                break;

            case 12:
                exit(0);
                break;

            default :
                printf(" Tokia operacija neegzistuoja\n");
                break;
        }
    }
}
