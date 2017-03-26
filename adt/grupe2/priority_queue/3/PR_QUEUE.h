#ifndef PR_QUEUE_H_
#define PR_QUEUE_H_
#include<stdbool.h>
typedef int our_type;
typedef struct prqueue
{
    struct prqueue *last;
    our_type data;
    int prior; // priority
    struct prqueue *next;
    bool FirstAdded;
} prqueue;


prqueue *Create();
bool IsEmpty(prqueue *startpt);
int Insert(prqueue **startpt, our_type data, int priority);
prqueue *Remove(prqueue *startpt);
int Join(prqueue **startpt, prqueue **startpt2);

#endif
