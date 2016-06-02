//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::add(MazeState *elem) {
  // TODO:  Implement this!
    
    heap.push_back(elem);
    swapUp(heap.size()-1);
    
    //Perform swap up


}

MazeState * HeapPriorityQueue::remove() {
  assert(!is_empty());
  // TODO:  Implement this!
    MazeState* ret = heap[0];
    MazeState* last = heap[heap.size()-1];
    heap[0] = last;
    heap.erase(heap.begin()+heap.size()-1);
    swapDown(0);
    return ret;
}


bool HeapPriorityQueue::is_empty() {
  // TODO:  Implement this!
    return heap.size() == 0;
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

void HeapPriorityQueue::swapUp(int index){
    int p = parent(index);
    if (heap[p]->getBadness()<=heap[index]->getBadness()) {
        return;
    }
    MazeState* temp = heap[index];
    heap[index] = heap[p];
    heap[p]=temp;
    swapUp(p);
}

void HeapPriorityQueue::swapDown(int index){
    int size = heap.size();
    int left = 2*index+1;
    int right = left+1;
    //If went over size, stop
    if (left>=size || right>=size) { return; }
    
    int indexBad = heap[index]->getBadness();
    int leftBad = heap[left]->getBadness();
    int rightBad = heap[right]->getBadness();
    
    //If getBadness is definitely smaller, return
    if (indexBad<=leftBad && indexBad<=rightBad) { return; }
    else{
        if (leftBad>=rightBad) {
            MazeState* temp=heap[index];
            heap[index]=heap[right];
            heap[right]=temp;
            index=right;
            swapDown(right);
        }else{
            MazeState* temp=heap[index];
            heap[index]=heap[left];
            heap[left]=temp;
            index=left;
            swapDown(left);
        }
    }
    
    
}



#endif
