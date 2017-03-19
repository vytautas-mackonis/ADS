/* ADT Stekas           */
/* Benas Gudeliauskas   */
/* PS 2 gr.             */

#ifndef STEKAS_H_INCLUDED
#define STEKAS_H_INCLUDED

typedef struct LinkElem    stackValue;
typedef struct LinkElem*   stackPointer;
typedef struct StackStruct stackType;

typedef int myType;

struct StackStruct
{
    stackPointer end1;
};

int Create(stackType* stack1);
int Delete (stackType* stack1);
int isFull (stackType* stack1);
int isEmpty (stackType* stack1);
int Push (myType value, stackType* stack1);
int Pop(stackType* stack1);

#endif
