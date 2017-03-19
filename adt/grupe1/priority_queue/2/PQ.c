#include <stdio.h>
#include <stdlib.h>

#include "PQ.h"

int main()
{

    struct Node *a= NULL;
    struct Node *b= NULL;

    Insert_Queue(&a, 55555, 9);
    Insert_Queue(&a, 55555, 8);
    Insert_Queue(&a, 6, 8);
    Insert_Queue(&a, 55555, 10);

    Print_Queue(a);

    return 0;
}
