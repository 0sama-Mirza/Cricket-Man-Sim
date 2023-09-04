#include "../includes/Globals.h"
#include "../includes/VIP.h"
#include<iostream>
// Static member initialization
bst<std::string> VIP::VIP_Data;

VIP::VIP() {
    Capacity = Total_Stadium_Capacity * 0.1;
    ID = 0;
    MoneySpent = 0;
    MoneyCap = 10000;
}
VIP::~VIP(){}
bst<std::string>& VIP::GetDataStructure() {
    return VIP_Data;
}

std::string VIP::GetFileName() {
    return "Vip";
}