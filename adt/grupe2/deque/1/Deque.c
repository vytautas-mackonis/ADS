#include <stdlib.h>
#include "DequeHeader.h"

void Create_Deque (struct DequeStruct *dq)
{
    dq->head=NULL;
    dq->tail=NULL;
}

int Check_If_Empty (struct DequeStruct *dq)
{
    if (dq==NULL) return 1;
    else if (dq->head==NULL) return 1;
    else return 0; /*return 1 - tuscias, return 0 - jeigu ne tuscias*/
}

int Check_If_Full (struct DequeStruct *dq)
{
    return 0;
}

int Push_Front (struct DequeStruct *dq, TYPE n)
{
       struct Node *elem;
       elem=(struct Node*) malloc (sizeof(struct Node));
       if(elem==NULL) return 0;
       elem->data=n;
       elem->prev=NULL;
       if(dq->head==NULL)
       {
           elem->next=NULL;
           dq->head=dq->tail=elem;
           return 1;
       }
       else
        {
            elem->next=dq->head;
            (dq->head)->prev=elem;
            dq->head=elem;
            return 1;

        }
    return 0;
}

int Pop_Front (struct DequeStruct *dq, TYPE *a)
{

    struct Node *elem = dq->head;
    if(dq->head!=NULL)
    {
        *a=elem->data;
        dq->head=elem->next;
        (dq->head)->prev=NULL;
        if((dq->head)->next==NULL) dq->tail=NULL;
        free(elem);
        return 1;
    }
    return 0;
}


int Push_End (struct DequeStruct *dq, TYPE n)
{
        struct Node *elem;
        elem = (struct Node*) malloc (sizeof(struct Node));
        if(elem==NULL) return 0;
        elem->data=n;
        elem->next=NULL;
        elem->prev=dq->tail;
        if(dq->tail==NULL)
        {
            dq->head=elem;
            dq->tail=elem;
            return 1;
        }
        else
        {
            (dq->tail)->next=elem;
            dq->tail=elem;
            return 1;
        }

    return 0;
}


int Pop_End (struct DequeStruct *dq, TYPE *a)
{
       struct Node *elem = dq->tail;
       if(dq->tail!=NULL)
       {
            *a=elem->data;
            dq->tail=elem->prev;
            (dq->tail)->next=NULL;
            if((dq->tail)->prev==NULL) dq->head=NULL;
            free(elem);
            return 1;
       }
       return 0;
}

int Check_Front (struct DequeStruct *dq, TYPE *a)
{
    if(dq->head!=NULL) {*a=(dq->head)->data; return 1;}
    else return 0;
}

int Check_End (struct DequeStruct *dq, TYPE *n)
{
    if(dq->tail!=NULL) {*n=(dq->tail)->data; return 1;}
    else return 0;
}

int Number_Of_Elements (struct DequeStruct *dq)
{
    int totEL=0;
    if(dq->head!=NULL)
    {
        struct Node *elem=dq->head;
        while(elem!=NULL)
        {
        totEL++;
        elem=elem->next;
        }
    }
    return totEL;
}

void Delete_Deque (struct DequeStruct *dq)
{
    if(dq->head==NULL) return ;
    struct Node *elem;
    while (dq->head!=NULL)
    {
        elem=dq->head;
        dq->head=(dq->head)->next;
        free(elem);
    }
}
