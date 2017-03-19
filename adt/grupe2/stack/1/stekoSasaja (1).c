/* ADT Stekas           */
/* Benas Gudeliauskas   */
/* PS 2 gr.             */

#include <stdio.h>
#include <stdlib.h>
#define  MYTYPE " %d"
#include "stekas.h"

int Create(stackType* stack1);

int main(){
    stackType stack_new;
    myType value;
    int full, empty, inp, outp;
    int selection;
    int ui = 1;
    int isCreated = 0;


    while(ui != 0){
        printf("Create stack    - 1 \n");
        printf("Delete stack    - 2 \n");
        printf("Is stack full?  - 3 \n");
        printf("Is stack empty? - 4 \n");
        printf("Push            - 5 \n");
        printf("Pop             - 6 \n");

        printf("Input your selection: ");
        scanf("%d", &selection);
        switch (selection){

        case 1:
            isCreated = Create(&stack_new);
            if (isCreated == 1) printf("Stack was created \n");
            else                printf("You can't create stack \n");
            break;
        case 2:
            if (isCreated == 0) printf("No stack to be deleted \n");
            else {
                    Delete (&stack_new);
                    printf ("Stack was deleted \n");

            }
            break;
        case 3:
            if (isCreated == 0) printf("There is no stack created \n");
            else {
                full = isFull(&stack_new);
                if (full == 1) printf("Stack is full \n");
                else           printf("Stack is not full \n");
            }
            break;
        case 4:
            if (isCreated == 0) printf("There is no stack created \n");
            else {
                empty = isEmpty(&stack_new);
                if (empty == 1) printf("Stack is empty \n");
                else            printf("Stack is not empty \n");
            }
            break;
        case 5:
            if (isCreated == 0) printf("There is no stack created \n");
            else {
                printf("Input stack member: ");
                scanf(MYTYPE, &value);
                inp = Push (&value,&stack_new);
                if (inp == 0) printf("Memory was not alocated \n");
                if (inp == 1) printf("Element was pushed into stack \n");
            }
            break;
        case 6:
            if (isCreated == 0) printf("There is no stack created \n");
            if (empty != 1)     printf("Stack is empty \n");
            else{
                outp = Pop(&stack_new);
                if (outp == 0) printf("Value was poped out of stack \n");
                else           printf("Something is wrong \n");
            }
            break;
        }
    }
}
