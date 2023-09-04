#ifndef STADIUM_H
#define STADIUM_H
#include "CustomBST.h"
#include <string>
#include "MyStack.h" // Include the necessary header for MyStack

class Stadium {
protected:
    // Member variables
    int ID;
    int Capacity;
    int MoneySpent;
    int TicketPrice;
    int MoneyCap;
    std::string CountryName;
    std::string FavFood;
    std::string FavItem;
    std::string FavSong;
    std::string BadItem;
    std::string BadSong;
    std::string BadFood;
    std::string FavDrink;
    std::string BadDrink;
    MyStack<std::string> Participants_List;
public:
    // Constructors and destructor
    Stadium();
    virtual ~Stadium();
    // Virtual functions
    void Store_Name_In_Queue();
    void Insert_Names_In_Tree();
    void Calculate_MoneySpent();
    void Calculate_Fav_Item();
    void Decide_Country();
    void Calculate_Fav_Song();
    void Calculate_Fav_Drink();
    void Calculate_Worst_Item();
    void Calculate_Worst_Song();
    void Calculate_Worst_Food();
    void Calculate_Fav_Food();
    // Getters
    virtual bst<std::string>& GetDataStructure() = 0;
    virtual std::string GetFileName() = 0;
    bool Is_Participants_List_Empty();
    // Friend function declaration
    friend std::string Calculate_Worst_Drink();
};

#endif
