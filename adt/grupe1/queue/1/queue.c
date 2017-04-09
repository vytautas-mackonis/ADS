#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int Delete_List(node** head)
{
    node* current=*head;
    node* next;
    while (current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    *head=NULL;
    return 0;
}

KINTAMASIS Dequeue(node **head)
{
    KINTAMASIS n;
    node *current=*head;
    node *temp=current;
    n=current->data;
    current=current->next;
    *head=current;
    free (temp);
    return n;

}

int Enqueue(node **head,int new_element)
{

    //gut();

    node *temp=malloc(sizeof(node));
    if(temp==NULL)
    {
        return -1;
    }
    temp->data=new_element;

    if(*head==NULL)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    {
        node* current=*head;
        while (current->next!=NULL)
        {
            current=current->next;
            //printf("%d\n",new_element);
        }
        temp->next=current->next;
        current->next=temp;
    }
   // printf("%d\n",temp->data);
    return 0;
}

int Print_Queue(node *head)
{
    /*if(head==NULL)
    {
        printf("Queue is empty.\n");
        //return ;
    }
    else
    {*/
        node *temp=head;

        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
        return 0;
    //}
}
int Queue_length(node *head)
{
    node *temp=head;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }

    printf("\n%d\n",i);
    return i;
}

KINTAMASIS Get_First(node *head)
{
    if(head==NULL)
    {
        printf("Queue is empty.\n");
        //return ;
    }
    else
    {
        node *temp=head;
        printf("\n%d\n",temp->data);
        return temp->data;
    }
}

int Create_Empty(node **head)
{
    *head=NULL;
    return 0;
}

int Is_Empty(node **head)
{
    if(*head==NULL)
    {
        printf("The queue is empty.\n");
        printf("%d",*head);
        return 0;
    }
    else
    {
        printf("The queue is not empty.\n");
        printf("%d",*head);
        return 1;
    }
}

