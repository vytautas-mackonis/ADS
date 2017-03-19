#include <iostream>
#include <stdexcept>
using namespace std;

template <class A_Type> class Node
{
public:
    A_Type data;
    Node<A_Type>* next;
    Node<A_Type>* prev;
};

template <class A_Type> class Deque
{
private:
    Node<A_Type>* front;
    Node<A_Type>* rear;
    int count = 0;

public:
    void InsertFront(A_Type element);
    A_Type RemoveFront();
    void InsertBack(A_Type element);
    A_Type RemoveBack();
    A_Type Front();
    A_Type Back();
    int Size();
    bool isEmpty();
};

template <class A_Type>void Deque<A_Type>::InsertFront(A_Type element)
    {
        Node<A_Type>* tmp = new Node<A_Type>();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() )
        {
            front = rear = tmp;

        }
        else
        {
            tmp->next = front;
            front->prev = tmp;
            front = tmp;
        }

        count++;
    }

template <class A_Type>A_Type Deque<A_Type>::RemoveFront()
    {
        if ( isEmpty() ) {
            throw invalid_argument( "Deque is empty" );
        }

        int ret = front->data;

        Node<A_Type>* tmp = front;
        if ( front->next != NULL )
        {
            front = front->next;
            front->prev = NULL;
        }
        else
        {
            front = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }
template <class A_Type>void Deque<A_Type>::InsertBack(A_Type element)
        {
        Node<A_Type>* tmp = new Node<A_Type>();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() )
        {
            front = rear = tmp;
        }
        else
        {
            rear->next = tmp;
            tmp->prev = rear;
            rear = tmp;
        }

        count++;
    }
template <class A_Type>A_Type Deque<A_Type>::RemoveBack()
        {
        if ( isEmpty() ) {
            throw invalid_argument( "Deque is empty" );
        }

        int ret = rear->data;

        Node<A_Type>* tmp = rear;
        if ( rear->prev != NULL )
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        else
        {
            rear = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }
template <class A_Type>A_Type Deque<A_Type>::Front()
    {
        if ( isEmpty() )
        {
            throw invalid_argument( "Deque is empty" );
        }

        return front->data;
    }

template <class A_Type>A_Type Deque<A_Type>::Back()
    {
        if ( isEmpty() )
        {
            throw invalid_argument( "Deque is empty" );
            //throw exception("empty");
            //throw Error("Could not load config file '%s'");
            //throw runtime_error("empty");
            //throw string("a");
        }

        return rear->data;
    }

template <class A_Type>int Deque<A_Type>::Size()
    {
        return count;
    }

template <class A_Type>bool Deque<A_Type>::isEmpty()
    {
        return count == 0 ? true : false;
    }

