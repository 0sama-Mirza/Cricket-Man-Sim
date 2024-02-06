#ifndef BST_H
#define BST_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"

#include "CustomNode.h" // Include the Node class header
#include<stack>
#include<iostream>
template <class U>
class bst {
private:
    Node<U>* Root;
    Node<U>* Current;
    std::stack<int> s;

    Node<U>* add(int id, U nam, int money, U country, U favfood, U favItem, U favSong, U baditem, U badsong, U badfood, Node<U>* SubRoot);
    Node<U>* RightRotation(Node<U>* SubRoot);
    Node<U>* LeftRotation(Node<U>* SubRoot);
    void inorderrr(Node<U>* t);
    void prr(Node<U>* t);
    void post(Node<U>* t);
    Node<U>* minn(Node<U>* t);
    Node<U>* maxx(Node<U>* t);
    Node<U>* Searchh(Node<U>* SubRoot, U value);
    int counter(Node<U>* SubRoot);
    int TotalDepth(Node<U>* SubRoot);
    int Get_Balance_Factor(Node<U>* SubRoot);
    Node<U>* Khatm(Node<U>* SubRoot, U v);
    void Write_Data_To_CSVFile(Node<U>* Data, std::string FileName);
    void Going_Inorder_For_CSV(Node<U>* t, std::string FileName);

public:
    bst();
    void insert(int id, U nam, int money, U country, U favfood, U favItem, U favSong, U baditem, U badsong, U badfood);
    void Search(int v);
    void Del(U v);
    U LastElement();
    void inorder();
    void PreOrder();
    void PostOrder();
    int count();
    void minvalue();
    void maxvalue();
    int Depth();
    void RootValue();
    void Write_Data_To_CSV(std::string Filename);
};

#include "../Templates/CustomBST.cpp" // Include the source file

#pragma GCC diagnostic pop
#endif
