#include "../includes/MyNode.h"

template<class T>
MyNode<T>::MyNode() : next(nullptr), data() {}

template<class T>
MyNode<T>* MyNode<T>::GetNext() {
    return next;
}

template<class T>
T MyNode<T>::GetData() {
    return data;
}

template<class T>
void MyNode<T>::SetNext(MyNode<T>* a) {
    next = a;
}

template<class T>
void MyNode<T>::SetData(T a) {
    data = a;
}
