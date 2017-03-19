#include <stdio.h>
#include <stdlib.h>
#include "DequeHeader.h"

void Fill (struct DequeStruct *);
void Display (struct DequeStruct *);

int main()
{
    struct DequeStruct dq;
    int r;
    TYPE n=10;
    TYPE a;

    Create_Deque (&dq);

    r=Check_If_Empty (&dq);
    if (r==1) printf("Dekas tuscias");
    if (r==0) printf("Dekas nera tuscias");

    r=Check_If_Full (&dq);
    if (r==1) printf("\nDekas pilnas");
    if (r==0) printf("\nDekas nera pilnas");

    Fill (&dq);
    Display (&dq);

    r=Push_Front (&dq, n);
    if(r==0) printf("\nDekas pilnas, Push_Front nepavyko");
    if(r==1) printf("\nPush_Front pavyko");

    Display (&dq);

    r=Pop_Front (&dq, &a);
    if(r==1) printf("\nPradzios elementas istrintas, data=%d", a);
    if(r==0) printf("\nDekas tuscias");

    Display (&dq);

    r=Push_End (&dq, n);
    if(r==1) printf("\nPush_End pavyko");
    if(r==0) printf("\nDekas pilnas");

    Display (&dq);

    r=Pop_End (&dq, &a);
    if(r==1) printf("\nPabaigos elementas istrintas, data=%d", a);
    if(r==0) printf("\nDekas tuscias");

    r=Check_Front (&dq, &a);
    if(r==1) printf("\nPirmas elementas lygus %d", a);
    if(r==0) printf("\nDekas tuscias");

    r=Check_End (&dq, &a);
    if(r==1) printf("\nPaskutinis elementas lygus %d", a);
    if(r==0) printf("\nDekas tuscias");

    r=Number_Of_Elements (&dq);
    printf("\nDeke yra %d elementai", r);

    Delete_Deque (&dq);
    return 0;
}

void Fill (struct DequeStruct *dq)
{
    int i;
    for(i=1; i<8; i++)
    {
        struct Node *elem = (struct Node*) malloc (sizeof(struct Node));
        elem->data=i;
        elem->next=NULL;
        if(dq->head==NULL)
        {
            elem->prev=NULL;
            dq->head=elem;
            dq->tail=elem;
        }
        else
        {
            struct Node *elem = (struct Node*) malloc (sizeof(struct Node));
            elem->data=i;
            elem->next=NULL;
            (dq->tail)->next=elem;
            dq->tail=elem;
        }
    }
}

void Display (struct DequeStruct *dq)
{
    if(dq->head!=NULL)
        {
            struct Node *elem=dq->head;
            printf("\n");
            while(elem!=NULL)
            {
                printf("%d ", elem->data);
                elem=elem->next;
            }
        }
}
