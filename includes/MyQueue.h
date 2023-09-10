#ifndef MYQUEUE_H
#define MYQUEUE_H

#include "MyNode.h"

template<class Q>
class MyQueue {
private:
    MyNode<Q>* front;
    MyNode<Q>* rear;
    MyNode<Q>* current;
    int count;

public:
    MyQueue();
    void Enqueue(Q value);
    Q Dequeue();
    bool IsEmpty();
    int size();
    Q Get_data();
    void print();
};

#include "../Templates/MyQueue.cpp" // Include the source file

#endif
