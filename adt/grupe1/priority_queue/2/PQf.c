#include<stdio.h>
#include<stdlib.h>

#include "PQ.h"

int Sorted_Queue(struct Node** head_ref, struct Node* new_node)   ///Funkcija gali keisti inicijuoto saraso "head", todel reikalauja pointer i "head_ref"
{
    struct Node* current;
    if ((*head_ref == NULL) || ((*head_ref)->priority < new_node->priority)){   ///Kai "head_ref" pasibaigia
        new_node->next= *head_ref;
        *head_ref= new_node;
    }

    else{    ///Susirandam pries ka iterpti node bloka
        current= *head_ref;

        while ((current->next != NULL) && (current->next->priority >= new_node->priority)){
            current= current->next;
        }

        new_node->next= current->next;
        current->next= new_node;
    }
}

int Print_Queue(struct Node *head)
{
    struct Node *temp= head;

    while(temp != NULL){
        printf("%d (%d) \n",temp->data, temp->priority);    ///Tarp skliaustuku prioritetas
        temp= temp->next;
    }
}

int Insert_Queue(struct Node** head_ref, int new_data, int new_priority)
{
    struct Node* new_node= (struct Node*)malloc(sizeof (struct Node));  ///Allocate node

    if(new_node == NULL){
        return 404;
    }

    new_node->data= new_data;   ///Priskiriame ivestus duomenis
    new_node->priority= new_priority;
    new_node->next= NULL;

    Sorted_Queue(head_ref, new_node);

    return 0;
}

int Create_Empty(struct Node** head_ref)
{
    *head_ref = NULL;
    //struct Node* new_node= (struct Node*)malloc(sizeof (struct Node*));
}

int Delete_Pos(struct Node** head_ref, int pos)
{
    int i, counter = 0;
    struct Node *temp;

    if (*head_ref == NULL){
        //printf("Priority queue is empty\n");
        return 0;
    }

    struct Node *s, *ptr;
    s= *head_ref;

    if (pos == 1){
        *head_ref= s->next;
    }

    else{
        while (s != NULL){
            s= s->next;
            counter++;
        }

        if (pos > 0 && pos <= counter){
            s= *head_ref;

            for (i= 1; i < pos; i++){
                ptr= s;
                s= s->next;
            }

            ptr->next= s->next;
        }

        else{
            //printf("Position out of range\n");
            return -1;
        }

        free(s);
    }
}

int Nuke_Queue(struct Node** head_ref)
{
    int counter=0, i;
    struct Node *s, *ptr;
    s= *head_ref;

    while (s != NULL){
            s= s->next;
            counter++;
    }

    while(counter > 0){
        Delete_Pos(head_ref, 1);
        counter--;
    }
}

int Is_Empty(struct Node** head_ref)
{
    if (*head_ref == NULL){
        //printf("The priority queue is empty\n");
        return 0;
    }

    else //printf("The priority queue is not empty\n");
        return 1;
}
