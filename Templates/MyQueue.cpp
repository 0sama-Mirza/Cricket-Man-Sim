#include "../includes/MyQueue.h"
#include <iostream>

template<class Q>
MyQueue<Q>::MyQueue() : front(nullptr), rear(nullptr), current(nullptr), count(0) {}

template<class Q>
void MyQueue<Q>::Enqueue(Q value) {
    MyNode<Q>* temp = new MyNode<Q>;
    temp->SetData(value);
    if (front == nullptr) {
        temp->SetNext(nullptr);
        front = temp;
        rear = temp;
    } else {
        rear->SetNext(temp);
        rear = temp;
    }
    count++;
}

template<class Q>
Q MyQueue<Q>::Dequeue() {
    if (!IsEmpty()) {
        current = front->GetNext();
        delete front;
        front = current;
        count--;
    } else {
        std::cout << std::endl << "The Queue is empty." << std::endl;
    }
    return front->GetData();
}

template<class Q>
bool MyQueue<Q>::IsEmpty() {
    return (front == nullptr);
}

template<class Q>
int MyQueue<Q>::size() {
    return count;
}

template<class Q>
Q MyQueue<Q>::Get_data() {
    return front->GetData();
}

template<class Q>
void MyQueue<Q>::print() {
    std::cout << std::endl << "      [";
    current = front;
    while (current != rear) {
        std::cout << current->GetData() << ",";
        current = current->next;
    }
    std::cout << current->GetData() << "]" << std::endl << "       ^" << std::endl;
}
