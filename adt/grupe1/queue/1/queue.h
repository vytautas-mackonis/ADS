#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct node
{
    int data;
    struct node* next;
}node;

#define queue node*
#define KINTAMASIS int


int Delete_List(node** head);
int Dequeue(node **head);
int Enqueue(node **head,int new_element);
int Print_Queue(node *head);
int Queue_length(node *head);
int Get_First(node *head);
int Create_Empty(node *head);
int Is_Empty(node **head);

/* how to use:
Delete_List(&a);
Dequeue(&a);
Enqueue(&a,7);
Print_Queue(a);
Queue_length(a);
Get_First(a);
Create_Empty(&a);
Is_Empty(&a);
*/

#endif // TEST_H_INCLUDED
