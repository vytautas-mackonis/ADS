/* ADT Stekas           */
/* Benas Gudeliauskas   */
/* PS 2 gr.             */

#include <stdio.h>
#include <stdlib.h>

#include "stekas.h"


struct LinkElem{
    myType var;
    stackPointer next;
};

int Create(stackType* stack1){
    stack1 -> end1 = NULL;
    if (stack1 -> end1 == NULL) return 1;
    else                        return 0;
}

int Delete(stackType* stack1){
    stackPointer elem;
    while(stack1 -> end1 != NULL){
        elem = (stack1 -> end1) -> next;
        free (stack1 -> end1);
        stack1 -> end1 = elem;
    }
    return 0;
}

int isFull(stackType* stack1){
    stackPointer elem = (struct LinkElem *) calloc (1, sizeof (struct LinkElem));
    if (!elem) return 1;
    else {
        free(elem);
        return 0;
    }
}

int isEmpty(stackType* stack1){
    if (stack1 -> end1 == NULL) return 1;
    else                        return 0;
}

int Push(myType value, stackType* stack1){
    stackPointer elem;
    elem = (struct LinkElem *) calloc (1, sizeof (struct LinkElem));
    if (elem == NULL) return 0;
    if (stack1 -> end1 == NULL){
        stack1 -> end1 = elem;
        elem -> next = NULL;
        elem -> var = value;
        return 1;
    }
    else{
        elem -> next = stack1 -> end1;
        elem -> var = value;
        stack1 -> end1 = elem;
        return 1;
    }

}

int Pop(stackType* stack1){
    stackPointer elem;
    myType numb = (stack1 -> end1) -> next;
    free(elem);

    (stack1 -> end1) -> next;

    return 0;
}
