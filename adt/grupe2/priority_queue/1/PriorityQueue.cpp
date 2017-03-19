#include <stdlib.h>
#include "PriorityQueue.h"

template <class T>
PriorityQueue<T>::PriorityQueue(){

    head = NULL;
    queueLength = 0;

}

template <class T>
int PriorityQueue<T>::InsertNode(int prior, T elVal){

Node<T> *newNode = new Node<T>;
    if(head == NULL){
        newNode -> next = NULL;
        newNode -> priority = prior;
        newNode -> element = elVal;
        head = newNode;
        queueLength++;
        return 0;
    }

    if(head -> priority < prior){
        newNode -> next = head;
        newNode -> priority = prior;
        newNode -> element = elVal;
        head = newNode;
        queueLength++;
        return 0;
    }

    Node<T> *currentNode = head;
    Node<T> *nextNode;


    while(true){

        if(currentNode -> next == NULL){
            currentNode -> next = newNode;
            newNode -> priority = prior;
            newNode -> element = elVal;
            newNode -> next = NULL;
            queueLength++;

            return 0;
        }

        nextNode = currentNode -> next;

        if(nextNode -> priority < prior){
            currentNode -> next = newNode;
            newNode -> next = nextNode;
            newNode -> priority = prior;
            newNode -> element = elVal;
            queueLength++;
            return 0;

        }

        else
            currentNode = currentNode -> next;

    }

return 0;
}

template <class T>
int PriorityQueue<T>::PrintQueue(){

    if(CheckIfEmpty() == 1) return -2;

    Node<T> *currentNode = head;

    while(currentNode){
        cout << currentNode -> element << " " << currentNode -> priority << endl;
        currentNode = currentNode -> next;
    }
return 0;
}

template <class T>
T PriorityQueue<T>::RemoveNode(){

    if(CheckIfEmpty() == 1) return NULL;

    T valueToReturn;
    Node<T> *temp = head;
    valueToReturn = temp -> element;
    head = head -> next;
    delete temp;
    queueLength--;


return valueToReturn;
}

template <class T>
int PriorityQueue<T>::CheckIfEmpty(){

return (queueLength == 0? 1: 0);

}

template <class T>
int PriorityQueue<T>::DeleteQueue(){

Node<T> *currentNode = head;
Node<T> *nextNode = head;
    while(nextNode){
        currentNode = nextNode;
        nextNode = currentNode -> next;
        if(nextNode) delete currentNode;
        queueLength--;
        }
    delete currentNode;

return 0;
}

template class PriorityQueue<int>;
template class PriorityQueue<char>;
template class PriorityQueue<string>;
template class PriorityQueue<double>;
template class PriorityQueue<long>;

