#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
private:
    int height;
    T Name;
    int ID;
    int MoneySpent;
    T CountryName;
    T FavFood;
    T FavItem;
    T FavSong;
    T BadItem;
    T BadSong;
    T BadFood;
    Node<T>* Left;
    Node<T>* Right;

public:
    Node(int id, T nam, int money, T country, T favfood, T favItem, T favSong, T baditem, T badsong, T badfood);

    Node* GetLeft();
    Node* GetRight();
    int GetID();
    T GetName();
    int GetMoneySpent();
    T GetCountryName();
    T GetFavFood();
    T GetFavItem();
    T GetFavSong();
    T GetBadItem();
    T GetBadFood();
    T GetBadSong();
    void SetLeft(Node<T>* L);
    void SetRight(Node<T>* R);
    void SetValue(int id, T nam, int money, T country, T favfood, T favItem, T favSong, T baditem, T badsong, T badfood);
};

// #include "../srcs/CustomNode.cpp" // Include the source file

#endif
