#include <stdio.h>
#include <stdlib.h>
#include "ADS1n.h"

int main()
{
    eile e1;
    sukurimas(&e1);
    iterpimas(&e1, 3, 7);
    iterpimas(&e1, 2, 7);
    iterpimas(&e1, 9, 5);
    iterpimas(&e1, 1, 9);
    isimtiElementa(&e1);
    isimtiElementa(&e1);
    elementas *pr = e1.pradzia;
    while(pr!=NULL){
        printf("%d ",pr->reiksme);
        pr = pr->next;
    }

    return 0;
}
