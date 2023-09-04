#include "../includes/Globals.h"
#include "../includes/FirstClass.h"
#include<iostream>
// Static member initialization
bst<std::string> FirstClass::FirstClass_Data;

FirstClass::FirstClass() {
    Capacity = Total_Stadium_Capacity * 0.3;
    ID = 0;
    MoneySpent = 0;
    MoneyCap = 5000;
}
FirstClass::~FirstClass(){}
bst<std::string>& FirstClass::GetDataStructure() {
    return FirstClass_Data;
}
std::string FirstClass::GetFileName() {
    return "Firstclass";
}


