#include "../includes/MyStack.h"
#include<iostream>
template<typename A>
MyStack<A>::MyStack() : top(nullptr), current(nullptr), count(0) {}

template<typename A>
void MyStack<A>::insert(A value) {
    MyNode<A>* temp = new MyNode<A>;
    temp->SetData(value);
    if (top == nullptr) {
        temp->SetNext(nullptr);
        top = temp;
    } else {
        temp->SetNext(top);
        top = temp;
    }
    count++;
}

template<typename A>
void MyStack<A>::del() {
    if (!IsEmpty()) {
        current = top->next;
        delete top;
        top = current;
        count--;
    } else
        std::cout << "There Are No Participants!" << std::endl;
}

template<typename A>
bool MyStack<A>::IsEmpty() {
    return (top == nullptr);
}

template<typename A>
void MyStack<A>::print() {
    if (IsEmpty())
        std::cout << "";
    else {
        current = top;
        std::cout << "|";
        while (current->next != nullptr) {
            std::cout << current->data << "|" << std::endl << "|";
            current = current->next;
        }
        std::cout << current->data << "|" << std::endl;
    }
}

template<typename A>
int MyStack<A>::size() {
    return count;
}

template<typename A>
A MyStack<A>::gettop() {
    return top->GetData();
}
