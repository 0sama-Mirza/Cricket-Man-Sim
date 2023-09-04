#include "../includes/Globals.h"
#include "../includes/General.h"
#include<iostream>
// Static member initialization
bst<std::string> General::General_Data;

General::General() {
    Capacity = Total_Stadium_Capacity * 0.6;
    ID = 0;
    MoneySpent = 0;
    MoneyCap = 1000;
}
General::~General(){}
bst<std::string>& General::GetDataStructure() {
    return General_Data;
}

std::string General::GetFileName() {
    return "Generalclass";
}

