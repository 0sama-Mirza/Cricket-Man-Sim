#include "../includes/Globals.h"
#include "../includes/Stadium.h"
#include<random>
#include<string>
#include<iostream>
#include<fstream>
// Constructor

Stadium::Stadium()
    : ID(0),
      Capacity(0),
      MoneySpent(0),
      TicketPrice(0),
      MoneyCap(0),
      CountryName(""),
      FavFood(""),
      FavItem(""),
      FavSong(""),
      BadItem(""),
      BadSong(""),
      BadFood(""),
      FavDrink(""),
      BadDrink(""),
      Participants_List() {}

// Destructor
Stadium::~Stadium() {}
void Stadium::Calculate_Fav_Drink() {
    // srand(time(nullptr)+ID);
    // int RandomNumber=rand()%9;//[0]=value ;; [1]=Vote
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 8); // Range: 0 to 8
    int RandomNumber = dist(gen);
    int Current_Votes=stoi(Drinks[1][RandomNumber]);
    Current_Votes++;
    std::string String_Of_CurrentVotes = std::to_string(Current_Votes);
    Drinks[1][RandomNumber]=String_Of_CurrentVotes;
}

void Stadium::Calculate_MoneySpent() {
    // srand(time(nullptr)+ID);
    // MoneySpent=rand()%1000;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, MoneyCap); // Range: 0 to 1000
    MoneySpent = dist(gen);
}

void Stadium::Decide_Country() {
    // srand(time(nullptr)+ID);
    // int RandomNumber=rand()%196;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 195); // Range: 0 to 195
    int RandomNumber = dist(gen);
    CountryName=Country[0][RandomNumber];
    int Current_Votes=stoi(Country[1][RandomNumber]);
    Current_Votes++;
    std::string String_Of_CurrentVotes = std::to_string(Current_Votes);
    Country[1][RandomNumber]=String_Of_CurrentVotes;
}

void Stadium::Calculate_Fav_Item() {
    // srand(time(nullptr)+ID);
    // int RandomNumber=rand()%7;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 6); // Range: 0 to 6
    int RandomNumber = dist(gen);
    FavItem=Items[0][RandomNumber];
    int Current_Votes=stoi(Items[1][RandomNumber]);
    Current_Votes++;
    std::string String_Of_CurrentVotes = std::to_string(Current_Votes);
    Items[1][RandomNumber]=String_Of_CurrentVotes;
}

void Stadium::Calculate_Fav_Song() {
    // srand(time(nullptr)+ID);
    // int RandomNumber=rand()%7;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 6); // Range: 0 to 6
    int RandomNumber = dist(gen);
    FavSong=Songs[0][RandomNumber];
    int Current_Votes=stoi(Songs[1][RandomNumber]);
    Current_Votes++;
    std::string String_Of_CurrentVotes = std::to_string(Current_Votes);
    Songs[1][RandomNumber]=String_Of_CurrentVotes;
}

void Stadium::Calculate_Worst_Item() {
    // srand(time(nullptr)+ID+6);
    // int RandomNumber=rand()%7;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 6); // Range: 0 to 6
    int RandomNumber = dist(gen);
    BadItem=Items[0][RandomNumber];
}

void Stadium::Calculate_Worst_Song() {
    // srand(time(nullptr)+ID+6);
    // int RandomNumber=rand()%7;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 6); // Range: 0 to 6
    int RandomNumber = dist(gen);
    BadSong=Songs[0][RandomNumber];
}

void Stadium::Calculate_Worst_Food() {
    // srand(time(nullptr)+ID+9);
    // int RandomNumber=rand()%9;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 8); // Range: 0 to 8
    int RandomNumber = dist(gen);
    BadFood=Foods[0][RandomNumber];
}

void Stadium::Calculate_Fav_Food() {
    // srand(time(nullptr)+ID);
    // int RandomNumber=rand()%9;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 8); // Range: 0 to 8
    int RandomNumber = dist(gen);
    FavFood=Foods[0][RandomNumber];
    int Current_Votes=stoi(Foods[1][RandomNumber]);
    Current_Votes++;
    std::string String_Of_CurrentVotes = std::to_string(Current_Votes);
    Foods[1][RandomNumber]=String_Of_CurrentVotes;
}

void Stadium::Insert_Names_In_Tree() {
    std::string naam=Participants_List.gettop();
    std::string comeon="";
    for(size_t i=0;i<=naam.length()-2;i++)
        comeon=comeon+naam[i];
    GetDataStructure().insert(ID,comeon,MoneySpent,CountryName,FavFood,FavItem,FavSong,BadItem,BadSong,BadFood);
    ID--;
    Participants_List.del();
}

void Stadium::Store_Name_In_Queue() {
    std::fstream MyFile;
    MyFile.open("../Audiance-Data/"+GetFileName()+".txt",std::ios::in);//Read Mode
    if(MyFile.is_open()){
        std::string name;
        while(ID!=Capacity){
            std::getline(MyFile,name);
            Participants_List.insert(name);
            ID++;
        }
        MyFile.close();
    }
}

bool Stadium::Is_Participants_List_Empty() {
    if (Participants_List.IsEmpty())
        return true;
    else
        return false;
}

// Friend function
std::string Calculate_Worst_Drink() {
    std::string Min_Votes=Drinks[1][0];
    for(int i=1;i<=8;i++){
        if(Drinks[1][i]<Min_Votes)
            Min_Votes=Drinks[1][i];
    }
    return Min_Votes;
}
