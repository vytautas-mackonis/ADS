#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"PR_QUEUE.h"

/*Creates a priority queue*/
prqueue *Create()
{
    prqueue  *elem;
    elem        = (prqueue*)malloc(sizeof(prqueue));
    if( elem == NULL)
    {
        return NULL;
    }
    elem->last  = NULL;
    elem->next  = NULL;
    elem->FirstAdded = false;
    return elem;
}
//----------------------------------

/*Returns true if empty, false otherwise*/
bool IsEmpty(prqueue *startpt)
{
    if( startpt->next == NULL )
    return true;
    else
    return false;
}
//-----------------------------------

/*Inserts an element into the queue*/
int Insert(prqueue **startpt, our_type data, int priority)
{

    /* Bad starting queue pointer input handling*/
    if( (*startpt) == NULL )
    {
        return -1;
    }
    //--------------------------------------------

    bool Inserted = false;
    prqueue *elem;
    prqueue *elem2;
    elem2 = (prqueue *)malloc(sizeof(prqueue));

    /*Handling malloc failure*/
    if(elem2  == NULL)
    {
        return -2;
    }
    //-------------------------

    elem2->data  = data;
    elem2->prior = priority;
    elem = (*startpt);

    while( elem->next != NULL)
    {

        if( elem->prior == priority || elem->prior < priority )
        {
            elem = elem->next;
        }
        else
        {
            prqueue *temp;
            temp = elem->last;

            //Connect new element to the last element of lower priority

            elem->last = elem2;
            elem2->next = elem;
            //-----------------

            // Connect new element to the previously last element of its priority
            temp->next = elem2;
            elem2->last = temp;
            //-----------------

            Inserted = true;
            break;
        }
    }

    if (elem->next == NULL && Inserted == false)
    {
        // In case of inserting first element
        if ( (*startpt)->FirstAdded == false)
        {
            elem->data  = data;
            elem->prior = priority;
            elem->next = NULL;
            elem->last = NULL;
            (*startpt)->FirstAdded = true;

            return 0;
        }
        //-----------------------------------
        if(elem->prior == priority || elem->prior < priority)
        {
            elem->next = elem2;
            elem2->last = elem;
            elem2->next = NULL;
        }
        else
        {
            prqueue *temp2;
            temp2 = elem->last;
            temp2->next = elem2;
            elem2->next = elem;
            elem->last = elem2;
            elem2->last = temp2;
        }
    }
    return 0;

}
//-----------------------------------

/*Removes an element with the highest priority*/
prqueue *Remove(prqueue *startpt)
{
    /* Bad starting queue pointer input handling*/
    if( startpt == NULL)
    {
        return NULL;
    }
    //--------------------------------------------
    prqueue *randomptr;
    randomptr = startpt;
    free (startpt);
    return randomptr->next;
}
//---------------------------------------------

/*Merges two priority queues*/
int Join(prqueue **startpt, prqueue **startpt2)
{
    /* Bad starting queue pointer input handling*/
    if( (*startpt) == NULL || (*startpt2) == NULL)
    {
        return (-2);
    }
    //--------------------------------------------
    prqueue *elem;
    elem = (*startpt2);
    Insert(startpt, elem->data, elem->prior);
    while(elem->next != NULL)
    {
        elem = Remove(elem);
        Insert(startpt, elem->data, elem->prior);
    }
    return 0;
}
//----------------
