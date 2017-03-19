#ifndef PriorityQueue_h
#define PriorityQueue_h


#include <iostream>

using namespace std;

template <class T>
struct Node{

    int priority;
    T element;
    Node<T> *next;

};

template <class T>
class PriorityQueue{

private:
    Node<T> *head;
    int queueLength;

public:
    int InsertNode(int prior, T elVal);
    T RemoveNode();
    int CheckIfEmpty();
    int PrintQueue();
    int DeleteQueue();
    PriorityQueue();



};

#endif // PriorityQueue_h
