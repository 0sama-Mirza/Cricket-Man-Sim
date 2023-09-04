#include "../includes/CustomNode.h"

template <class T>
Node<T>::Node(int id, T nam, int money, T country, T favfood, T favItem, T favSong, T baditem, T badsong, T badfood)
    : height(0),
      Name(nam),
      ID(id),
      MoneySpent(money),
      CountryName(country),
      FavFood(favfood),
      FavItem(favItem),
      FavSong(favSong),
      BadItem(baditem),
      BadSong(badsong),
      BadFood(badfood),
      Left(nullptr),
      Right(nullptr) {}

template <class T>
Node<T>* Node<T>::GetLeft() {
    return Left;
}

template <class T>
Node<T>* Node<T>::GetRight() {
    return Right;
}

template <class T>
int Node<T>::GetID() {
    return ID;
}

template <class T>
T Node<T>::GetName() {
    return Name;
}

template <class T>
int Node<T>::GetMoneySpent() {
    return MoneySpent;
}

template <class T>
T Node<T>::GetCountryName() {
    return CountryName;
}

template <class T>
T Node<T>::GetFavFood() {
    return FavFood;
}

template <class T>
T Node<T>::GetFavItem() {
    return FavItem;
}

template <class T>
T Node<T>::GetFavSong() {
    return FavSong;
}

template <class T>
T Node<T>::GetBadItem() {
    return BadItem;
}

template <class T>
T Node<T>::GetBadFood() {
    return BadFood;
}

template <class T>
T Node<T>::GetBadSong() {
    return BadSong;
}

template <class T>
void Node<T>::SetLeft(Node* L) {
    Left = L;
}

template <class T>
void Node<T>::SetRight(Node* R) {
    Right = R;
}

template <class T>
void Node<T>::SetValue(int id, T nam, int money, T country, T favfood, T favItem, T favSong, T baditem, T badsong, T badfood) {
    Name = nam;
    MoneySpent = money;
    ID = id;
    CountryName = country;
    FavFood = favfood;
    FavItem = favItem;
    FavSong = favSong;
    BadItem = baditem;
    BadSong = badsong;
    BadFood = badfood;
}
