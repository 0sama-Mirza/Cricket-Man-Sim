#include "../includes/Globals.h"
#include "../includes/Cricket_Management_System.h"
#include "../includes/VIP.h"
#include "../includes/FirstClass.h"
#include "../includes/General.h"


Cricket_Management_System::Cricket_Management_System()
    : size(0),
    bara("Big Country"),
    BestFood("BestFood"),
    BestItem("BestItem"),
    BestDrink("BestDrink"),
    BestSong("BestSong"),
    BadFood("BadFood"),
    BadItem("BadItem"),
    BadDrink("BadDrink"),
    BadSong("BadSong"),
    VIP_Country("VIP_Country"),
    FirstClass_Country("FirstClass_Country"),
    General_Country("General_Country") {
    for (int i = 0; i <= 195; i++) {
        Country[1][i] = "0";
    }
    Calculate_Everything();
}

Cricket_Management_System::~Cricket_Management_System() {}

void Cricket_Management_System::Store_Data_In_CSV() {
    VIP v;
    FirstClass f;
    General g;
    v.Store_Name_In_Queue();
    f.Store_Name_In_Queue();
    g.Store_Name_In_Queue();
    while (!v.Is_Participants_List_Empty()) {
        //VIP
        v.Calculate_Fav_Drink();
        v.Calculate_Fav_Food();
        v.Calculate_Fav_Item();
        v.Calculate_Fav_Song();
        v.Calculate_MoneySpent();
        v.Calculate_Worst_Food();
        v.Calculate_Worst_Item();
        v.Calculate_Worst_Song();
        v.Decide_Country();
        v.Insert_Names_In_Tree();
        Calculate_Total_Country_Count(VIP_Country);
    }
    while (!f.Is_Participants_List_Empty()) {
        //First Class
        f.Calculate_Fav_Drink();
        f.Calculate_Fav_Food();
        f.Calculate_Fav_Item();
        f.Calculate_Fav_Song();
        f.Calculate_MoneySpent();
        f.Calculate_Worst_Food();
        f.Calculate_Worst_Item();
        f.Calculate_Worst_Song();
        f.Decide_Country();
        f.Insert_Names_In_Tree();
        Calculate_Total_Country_Count(FirstClass_Country);
    }
    while (!g.Is_Participants_List_Empty()) {
        //General
        g.Calculate_Fav_Drink();
        g.Calculate_Fav_Food();
        g.Calculate_Fav_Item();
        g.Calculate_Fav_Song();
        g.Calculate_MoneySpent();
        g.Calculate_Worst_Food();
        g.Calculate_Worst_Item();
        g.Calculate_Worst_Song();
        g.Decide_Country();
        g.Insert_Names_In_Tree();
        Calculate_Total_Country_Count(General_Country);
    }
    std::cout << std::endl;
    v.GetDataStructure().Write_Data_To_CSV("VIP_Data_To_File");
    f.GetDataStructure().Write_Data_To_CSV("FirstClass_Data_To_File");
    g.GetDataStructure().Write_Data_To_CSV("General_Data_To_File");
}

void Cricket_Management_System::Calculate_Total_Country_Count(std::string& a) {
    bara = Country[1][0];
    a = Country[0][1];
    size = (sizeof(Country) / sizeof(Country[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara < Country[1][i]) {
            bara = Country[1][i];    //vote
            a = Country[0][i]; //Name
        }
    }
}

void Cricket_Management_System::Calculate_Everything() {
    Store_Data_In_CSV();
    bara = Foods[1][0];
    BestFood = Foods[0][1];
    size = (sizeof(Foods) / sizeof(Foods[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara < Foods[1][i]) {
            bara = Foods[1][i];    //vote
            BestFood = Foods[0][i]; //Name
        }
    }
    bara = Items[1][0];
    BestItem = Items[0][1];
    size = (sizeof(Items) / sizeof(Items[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara < Items[1][i]) {
            bara = Items[1][i];    //vote
            BestItem = Items[0][i]; //Name
        }
    }
    bara = Drinks[1][0];
    BestDrink = Drinks[0][1];
    size = (sizeof(Drinks) / sizeof(Drinks[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara < Drinks[1][i]) {
            bara = Drinks[1][i];    //vote
            BestDrink = Drinks[0][i]; //Name
        }
    }
    bara = Songs[1][0];
    BestSong = Songs[0][1];
    size = (sizeof(Songs) / sizeof(Songs[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara < Songs[1][i]) {
            bara = Songs[1][i];    //vote
            BestSong = Songs[0][i]; //Name
        }
    }

    // Bad
    bara = Foods[1][0];
    BadFood = Foods[0][1];
    size = (sizeof(Foods) / sizeof(Foods[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara > Foods[1][i]) {
            bara = Foods[1][i];    //vote
            BadFood = Foods[0][i]; //Name
        }
    }
    bara = Items[1][0];
    BadItem = Items[0][1];
    size = (sizeof(Items) / sizeof(Items[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara > Items[1][i]) {
            bara = Items[1][i];    //vote
            BadItem = Items[0][i]; //Name
        }
    }
    bara = Drinks[1][0];
    BadDrink = Drinks[0][1];
    size = (sizeof(Drinks) / sizeof(Drinks[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara > Drinks[1][i]) {
            bara = Drinks[1][i];    //vote
            BadDrink = Drinks[0][i]; //Name
        }
    }
    bara = Songs[1][0];
    BadSong = Songs[0][1];
    size = (sizeof(Songs) / sizeof(Songs[0][0])) / 2;
    for (int i = 0; i < size; i++) {
        if (bara > Songs[1][i]) {
            bara = Songs[1][i];    //vote
            BadSong = Songs[0][i]; //Name
        }
    }
}

void Cricket_Management_System::Show_Summary() {
    std::cout << "The Best Performing Item was  : " << BestItem << std::endl;
    std::cout << "The Best Performing Food was  : " << BestFood << std::endl;
    std::cout << "The Best Performing Song was  : " << BestSong << std::endl;
    std::cout << "The Best Performing Drink was : " << BestDrink << std::endl;
    std::cout << "The Worst Performing Item was : " << BadItem << std::endl;
    std::cout << "The Worst Performing Food was : " << BadFood << std::endl;
    std::cout << "The Worst Performing Song was : " << BadSong << std::endl;
    std::cout << "The Worst Performing Drink was: " << BadDrink << std::endl;
}

void Cricket_Management_System::Show_Menu() {
    std::cout << "\n=================================================================================================================\n";
    std::cout << "\n\t\t\t\t\tCricket Stadium Management System";
    std::cout << "\n=================================================================================================================\n";
    std::cout << "1) Show Summary" << std::endl;
    std::cout << "2) Show VIP Data" << std::endl;
    std::cout << "3) Show First Class Data" << std::endl;
    std::cout << "4) Show General Class Data" << std::endl;
    std::cout << "5) Exit" << std::endl;
}

void Cricket_Management_System::Menu_Input() {
    VIP v;
    FirstClass f;
    General g;
    bst<std::string>tempV = v.GetDataStructure();
    bst<std::string>tempF = f.GetDataStructure();
    bst<std::string>tempG = g.GetDataStructure();
    v.~VIP();
    f.~FirstClass();
    g.~General();
    int Options = 0;
    while (Options != 5) {
        Show_Menu();
        std::cin >> Options;
        if (Options == 1)
            Show_Summary();
        else if (Options == 2) {
            do {
                std::cout << "1) Most Money Spent By An Individual" << std::endl;
                std::cout << "2) Least Money Spent By An Individual" << std::endl;
                std::cout << "3) Most People From A Country" << std::endl;
                std::cin >> Options;
                if (Options == 1)
                    tempV.maxvalue();
                else if (Options == 2)
                    tempV.minvalue();
                else if (Options == 3)
                    std::cout << VIP_Country << std::endl;
                else
                    std::cout << "\nInvalid Input. Enter Again\n";
            } while (Options > 3 || Options < 1);
        }
        else if (Options == 3) {
            do {
                std::cout << "1) Most Money Spent By An Individual" << std::endl;
                std::cout << "2) Least Money Spent By An Individual" << std::endl;
                std::cout << "3) Most People From A Country" << std::endl;
                std::cin >> Options;
                if (Options == 1)
                    tempF.maxvalue();
                else if (Options == 2)
                    tempF.minvalue();
                else if (Options == 3)
                    std::cout << FirstClass_Country << std::endl;
                else
                    std::cout << "\nInvalid Input. Enter Again\n";
            } while (Options > 3 || Options < 1);
        }
        else if (Options == 4) {
            do {
                std::cout << "1) Most Money Spent By An Individual" << std::endl;
                std::cout << "2) Least Money Spent By An Individual" << std::endl;
                std::cout << "3) Most People From A Country" << std::endl;
                std::cin >> Options;
                if (Options == 1)
                    tempG.maxvalue();
                else if (Options == 2)
                    tempG.minvalue();
                else if (Options == 3)
                    std::cout << General_Country << std::endl;
                else
                    std::cout << "\nInvalid Input. Enter Again\n";
            } while (Options > 3 || Options < 1);
        }
        else if (Options != 5) {
            std::cout << "Invalid Input. Enter Again: " << std::endl;
        }
    }
}