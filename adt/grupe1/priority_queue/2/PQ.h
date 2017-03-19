#ifndef PQ_H_INCLUDED
#define PQ_H_INCLUDED

typedef struct Node{
    int data;
    int priority;
    struct Node* next;
}Node;

int Print_Queue(struct Node*);
int Insert_Queue(struct Node**, int, int);
int Delete_Pos(struct Node**, int);
int Nuke_Queue(struct Node**);
int Is_Empty(struct Node**);
int Create_Empty(struct Node**);

#endif // PQ_H_INCLUDED
