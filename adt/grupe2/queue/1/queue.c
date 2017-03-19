/*Andrejus Kuznecovas, ADT eile, 2017*/
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
node *newNode (type data);           //sukuriama eiles kopija, joje idedamas elementas
queue newQueue()
{
    queue ret;
    ret.begin = NULL;       //kad eiles pradzios ir pabaigos rodykles rodytu i NULL, dydis 0
    ret.end = NULL;
    ret.size = 0;
    return ret;     //grazinam nauja eile.
}
int push (queue *q, type data)
{
    node *newEl = newNode(data);
    if (newEl!=NULL)
    {
       q->size++;
       if (isEmpty(*q))
    {     //jei eile tuscia
        q->begin = newEl;
        q->end = newEl;
        return 0;
    }
    else
    {
    q->end->next = newEl;
    q->end = newEl;
    }
    }
    else
    {
    return -1;
    }
}

int pop (queue *q, type *top)
{
    if (isEmpty(*q)) return -1;
    *top= q->begin->val;
    q->size--;
    if (q->end == q->begin){
        free (q->begin);
        q->end = NULL;
        q->begin = NULL;
        return 0;
    }

    node *first = q->begin;
    q->begin = q->begin->next;
    free(first);
    return 0;
}
int peek (queue *q, type *ret)
{
    if (isEmpty(*q)) return 0;
    *ret = q->begin->val;
    return 1;
}
int isEmpty (queue q)
{
    if (q.end == NULL && q.begin == NULL) return 1;
    return 0;
}
int isFull(queue q) //nebus pilna, kol galima pushint
{
    return 0;
}
int queueSize (queue q){
    return q.size;
}
void clear (queue *q){
    if (isEmpty(*q)) return;
    while (!isEmpty(*q)){
            q->size--;
    if (q->end == q->begin){
        free (q->begin);
        q->end = NULL;
        q->begin = NULL;
        return;
    }
    node *first = q->begin;
    q->begin = q->begin->next;
    free(first);
    }
}
node *newNode (type data){
    node *ret;
    ret = (node*)malloc (sizeof(node));
    if(ret==NULL)                        //jeigu nepavyko isskirti atminties
    {
      return 0;
    }
    ret->val = data;
    ret->next = NULL;
    return ret;  //grazina rodykle i eiles elementa
}

