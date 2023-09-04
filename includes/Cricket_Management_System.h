#ifndef CRICKET_MANAGEMENT_SYSTEM_H
#define CRICKET_MANAGEMENT_SYSTEM_H

#include <iostream>
#include <string>

class Cricket_Management_System {
private:
    int size;
    std::string bara;
    std::string BestFood, BestItem, BestDrink, BestSong;
    std::string BadFood, BadItem, BadDrink, BadSong;
    std::string VIP_Country, FirstClass_Country, General_Country;

public:
    Cricket_Management_System();
    ~Cricket_Management_System();

    void Store_Data_In_CSV();
    void Calculate_Total_Country_Count(std::string& a);
    void Calculate_Everything();
    void Show_Summary();
    void Show_Menu();
    void Menu_Input();
};

#endif
