#ifndef MYSTACK_H
#define MYSTACK_H

#include "MyNode.h"

template<typename A>
class MyStack {
private:
    MyNode<A>* top;
    MyNode<A>* current;
    int count;

public:
    MyStack();
    void insert(A value);
    void del();
    bool IsEmpty();
    void print();
    int size();
    A gettop();
};

// #include "../srcs/MyStack.cpp" // Include the source file

#endif
