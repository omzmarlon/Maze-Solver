//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  // TODO:  Initialize any member variables as needed in the constructor.
    head = NULL;
    tail = NULL;
    size = 0;
}

void LinkedListQueue::add(MazeState *elem)
{
  // TODO:  Implement this.
    if (size==0) {
        node * newnode = new node;
        newnode->next=NULL;
        newnode->data=elem;
        head=newnode;
        tail=newnode;
        size++;
    }else{
        //My implementation: head in tail out, next points to next to dequeue
        node * newnode = new node;
        newnode->data=elem;
        newnode->next=NULL;
        head->next=newnode;
        head=newnode;
        size++;
    }
}

MazeState *LinkedListQueue::remove()
{
  // TODO:  Implement this.
    assert(size!=0);
    MazeState * ret = tail->data;
    node * temp = tail;
    tail=tail->next;
    delete temp;
    size--;
    return ret;
    
}

bool LinkedListQueue::is_empty()
{
  // TODO:  Implement this.
    return size==0;
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO:  Implement the destructor.  Be sure to delete everything.
    while (size>0) {
        node * temp = tail;
        tail=tail->next;
        delete temp;
        size--;
    }
    head=NULL;
    tail=NULL;
}

#endif

