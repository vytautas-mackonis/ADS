#ifndef DEQUEHEADER_H_INCLUDED
#define DEQUEHEADER_H_INCLUDED

typedef int TYPE;

struct Node
{
    struct Node *prev;
    TYPE data;
    struct Node *next;
};

struct DequeStruct
{
    struct Node *head;
    struct Node *tail;
};

void Create_Deque (struct DequeStruct *);
int Check_If_Empty (struct DequeStruct *); /*return 1 - pavyko, return 0 - nepavyko*/
int Check_If_Full (struct DequeStruct *);
int Push_Front (struct DequeStruct *, TYPE n);
int Pop_Front (struct DequeStruct *, TYPE *a);
int Push_End (struct DequeStruct *, TYPE n);
int Pop_End (struct DequeStruct *, TYPE *a);
int Check_Front (struct DequeStruct *, TYPE *a);
int Check_End (struct DequeStruct *, TYPE *a);
int Number_Of_Elements (struct DequeStruct *);
void Delete_Deque (struct DequeStruct *);

#endif /* DEQUEHEADER_H_INCLUDED*/
