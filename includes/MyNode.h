#ifndef MYNODE_H
#define MYNODE_H

template<class T>
class MyNode {
    template<typename U>
    friend class MyStack;

private:
    MyNode* next;
    T data;

public:
    MyNode();
    MyNode<T>* GetNext();
    T GetData();
    void SetNext(MyNode<T>* a);
    void SetData(T a);
};

#include "../Templates/MyNode.cpp" // Include the source file

#endif
