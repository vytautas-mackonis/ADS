/*Andrejus Kuznecovas, ADT eile, 2017*/
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef int type;
typedef struct Node{
    type val;        //saraso elemento reiksme
    struct Node *next;  //saraso elemento rodykle i kitas elementa
}node;
typedef struct Queue{
    node *begin, *end;      //eiles pradzios ir pabaigos rodykles
    int size;               //eiles dydzio elementas
}queue;
queue newQueue();                    //sukuriame eile
int push (queue *q, type data);     //idedame elementa (enqueque)
int pop (queue *q, type *);                //isimame elementa ir ji pasaliname is eiles (dequeue)
int peek (queue *q, type *ret);     //randame ailes virsune (pirmaji elementa)
int isEmpty (queue q);             //patikrinam ar eile tuscia
int queueSize (queue q);           //apskaiciuojame eiles dydi
void clear (queue *q);              //istriname eile
int isFull(queue q);                 //niekada nebus pilna, jeigu pavyks iskirti atminties
#endif // HEADER_H_INCLUDED
