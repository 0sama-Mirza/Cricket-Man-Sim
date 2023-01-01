#include<iostream>
// #include<vector>
#include<unistd.h>//Sleep Function
#include"MyQueue.cpp"
#include"MyStack.cpp"
int Total_Attendees=0;
#include"CustomBST.cpp"
#include<string>
#include<fstream>

using namespace std;
const int Total_Stadium_Capacity=2500;
string Hits[12]={"Makes a Single","Makes a Double","Makes a Triple","Hits a Four","is Bowled! The Umpire Lifts The Finger.","Hits A Six!","No Ball!","Wide Ball","got LBW And Thats Out!","Hits. The Ball Is In The Air And He Catches It! Hes Out!","Dot Ball","Got Run Out!"};
enum Cricket_Country_Names{Aus,Eng,New,Pak,Ind,Afg,Ken,West,Zim,Sri,Ban,South,Nether,Ire,Nep,Scot,Hong,UA};
string Cricket_Teams[]={"Australia","England","NewZealand","Pakistan","India","Afghanistan","Kenya","WestInDies","Zimbabwe","SriLanka","Banladesh","SouthAfrica","NetherLands","IreLand","Nepal","ScotLand","HongKong","UAE"};
string Country[2][196]={"Afghanistan", "Albania", "Algeria", "Andorra", "Angola", "Antigua & Deps", "Argentina", "Armenia", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bhutan", "Bolivia", "Bosnia Herzegovina", "Botswana", "Brazil", "Brunei", "Bulgaria", "Burkina", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape Verde", "Central African Rep", "Chad", "Chile", "China", "Colombia", "Comoros", "Congo", "Congo {Democratic Rep}", "Costa Rica", "Croatia", "Cuba", "Cyprus", "Czech Republic", "Denmark", "Djibouti", "Dominica", "Dominican Republic", "East Timor", "Ecuador", "Egypt", "El Salvador", "Equatorial Guinea", "Eritrea", "Estonia", "Ethiopia", "Fiji", "Finland", "France", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Greece", "Grenada", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Honduras", "Hungary", "Iceland", "India", "Indonesia", "Iran", "Iraq", "Ireland {Republic}", "Italy", "Ivory Coast", "Jamaica", "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati", "Korea North", "Korea South", "Kosovo", "Kuwait", "Kyrgyzstan", "Laos", "Latvia", "Lebanon", "Lesotho", "Liberia", "Libya", "Liechtenstein", "Lithuania", "Luxembourg", "Macedonia", "Madagascar", "Malawi", "Malaysia", "Maldives", "Mali", "Malta", "Marshall Islands", "Mauritania", "Mauritius", "Mexico", "Micronesia", "Moldova", "Monaco", "Mongolia", "Montenegro", "Morocco", "Mozambique", "Myanmar", "Namibia", "Nauru", "Nepal", "Netherlands", "New Zealand", "Nicaragua", "Niger", "Nigeria", "Norway", "Oman", "Pakistan","Palestine", "Palau", "Panama", "Papua New Guinea", "Paraguay", "Peru", "Philippines", "Poland", "Portugal", "Qatar", "Romania", "Russian Federation", "Rwanda", "St Kitts & Nevis", "St Lucia", "Saint Vincent & the Grenadines", "Samoa", "San Marino", "Sao Tome & Principe", "Saudi Arabia", "Senegal", "Serbia", "Seychelles", "Sierra Leone", "Singapore", "Slovakia", "Slovenia", "Solomon Islands", "Somalia", "South Africa", "South Sudan", "Spain", "Sri Lanka", "Sudan", "Suriname", "Swaziland", "Sweden", "Switzerland", "Syria", "Taiwan", "Tajikistan", "Tanzania", "Thailand", "Togo", "Tonga", "Trinidad & Tobago", "Tunisia", "Turkey", "Turkmenistan", "Tuvalu", "Uganda", "Ukraine", "United Arab Emirates", "United Kingdom", "United States", "Uruguay", "Uzbekistan", "Vanuatu", "Vatican City", "Venezuela", "Vietnam", "Yemen", "Zambia", "Zimbabwe"};
string Songs[2][7]={"Boisterous Throwback","Time For Endless Adventures","All In World","The Time Has Come Again For Disco","Tum Jeeto Ya Haro","Stay","Kala Jora","0","0","0","0","0","0","0"};
string Foods[2][9]={"Biryani","Kofta-Kabab","Murgh-Pulao","Fish","Fried-Silk-Worm","Shirako","Dragon-Fruit","Passion-Fruit","HotDog","0","0","0","0","0","0","0","0","0"};
string Items[2][7]={"Foam-Hand","Shirts","Flag","Face Painting","Seats","Baja","View","0","0","0","0","0","0","0"};
string Drinks[2][9]={"Miranda","Coke","Pepsi","Orange-Juice","Apple-Juice","Lassi","Mango-Lassi","Chai","Coffee","0","0","0","0","0","0","0","0","0"};
//Name[0][X]= 0=value ;;;;;  Name[1][X]=Vote 


class Cricket_Managment_System;

string Calculate_Worst_Drink(){
    string Min_Votes=Drinks[1][0];
    for(int i=1;i<=8;i++){
        if(Drinks[1][i]<Min_Votes)
            Min_Votes=Drinks[1][i];
    }
    return Min_Votes;
}

class Stadium{
    protected:
        friend class Cricket_Managment_System;
        int ID;
        int Capacity;
        int MoneySpent;
        int TicketPrice;
        string CountryName;
        string FavFood;
        string FavItem;
        string FavSong;
        string BadItem;
        string BadSong;
        string BadFood;
        string FavDrink;
        string BadDrink;
        MyStack<string> Participants_List;
    public:
        virtual void Store_Name_In_Queue()=0;
        virtual void Insert_Names_In_Tree()=0;
        virtual void Calculate_MoneySpent()=0;
        virtual void Calculate_Fav_Item()=0;
        virtual void Decide_Country()=0;
        virtual void Calculate_Fav_Song()=0;
        virtual void Calculate_Fav_Drink()=0;
        friend string Calculate_Worst_Drink();
        virtual void Calculate_Worst_Item()=0;
        virtual void Calculate_Worst_Song()=0;
        virtual void Calculate_Worst_Food()=0;
        virtual void Calculate_Fav_Food()=0;
        // virtual void Noor_CSV_Kr_LO()=0;
};

class VIP:public Stadium{
    protected:
        friend class Cricket_Managment_System;
        static bst<string>VIP_Data;
    public:
        VIP(){
            Capacity=Total_Stadium_Capacity*0.1;
            ID=0;
            MoneySpent=0;
        }

        void Insert_Names_In_Tree(){
            string naam=Participants_List.gettop();
            string comeon="";
            for(int i=0;i<=naam.length()-2;i++)
                comeon=comeon+naam[i];
            VIP_Data.insert(ID,comeon,MoneySpent,CountryName,FavFood,FavItem,FavSong,BadItem,BadSong,BadFood);
            ID--;
            Participants_List.del();
        }

        void Store_Name_In_Queue(){//This will store all the names at once so no need to run it again.
            fstream VipFile;
            VipFile.open("Vip.txt",ios::in);//Read Mode
            if(VipFile.is_open()){
                string name;
                while(ID!=Capacity){
                    getline(VipFile,name);
                    Participants_List.insert(name);
                    ID++;
                }
                VipFile.close();
            }
        }

        void Calculate_Fav_Drink(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%9;//0=value ;;;;;; 1=Vote
            int Current_Votes=stoi(Drinks[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Drinks[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_MoneySpent(){
            srand(time(nullptr)+ID);
            MoneySpent=rand()%10000;
        }

        void Decide_Country(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%196;
            CountryName=Country[0][RandomNumber];
            int Current_Votes=stoi(Country[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Country[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Fav_Item(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%7;
            FavItem=Items[0][RandomNumber];
            int Current_Votes=stoi(Items[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Items[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Fav_Song(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%7;
            FavSong=Songs[0][RandomNumber];
            int Current_Votes=stoi(Songs[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Songs[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Worst_Item(){
            srand(time(nullptr)+ID+6);
            int RandomNumber=rand()%7;
            BadItem=Items[0][RandomNumber];
        }

        void Calculate_Worst_Song(){
            srand(time(nullptr)+ID+6);
            int RandomNumber=rand()%7;
            BadSong=Songs[0][RandomNumber];
        }

        void Calculate_Worst_Food(){
            srand(time(nullptr)+ID+9);
            int RandomNumber=rand()%9;
            BadFood=Foods[0][RandomNumber];
        }

        void Calculate_Fav_Food(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%9;
            FavFood=Foods[0][RandomNumber];
            int Current_Votes=stoi(Foods[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Foods[1][RandomNumber]=String_Of_CurrentVotes;
		}

        // virtual void Noor_CSV_Kr_LO(){

        //}
};
bst<string>VIP:: VIP_Data;



class FirstClass:public Stadium{
    protected:
        friend class Cricket_Managment_System;
        static bst<string>FirstClass_Data;
    public:
        FirstClass(){
            ID=0;
            MoneySpent=0;
            Capacity=Total_Stadium_Capacity*0.3;
        }

        void Store_Name_In_Queue(){
            fstream FirstClassFile;
            FirstClassFile.open("Firstclass.txt",ios::in);//Read Mode
            if(FirstClassFile.is_open()){
                string name;
                while(ID!=Capacity){
                    getline(FirstClassFile,name);
                    Participants_List.insert(name);
                    ID++;
                }
                FirstClassFile.close();
            }
        }

        void Insert_Names_In_Tree(){
            string naam=Participants_List.gettop();
            string comeon="";
            for(int i=0;i<=naam.length()-2;i++)
                comeon=comeon+naam[i];
            FirstClass_Data.insert(ID,comeon,MoneySpent,CountryName,FavFood,FavItem,FavSong,BadItem,BadSong,BadFood);
            ID--;
            Participants_List.del();
        }

        void Calculate_MoneySpent(){
            srand(time(nullptr)+ID);
            MoneySpent=rand()%5000;
        }

        void Calculate_Fav_Item(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%7;
            FavItem=Items[0][RandomNumber];
            int Current_Votes=stoi(Items[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Items[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Decide_Country(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%196;
            CountryName=Country[0][RandomNumber];
            int Current_Votes=stoi(Country[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Country[1][RandomNumber]=String_Of_CurrentVotes;
        }

       void Calculate_Fav_Song(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%7;
            FavSong=Songs[0][RandomNumber];
            int Current_Votes=stoi(Songs[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Songs[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Fav_Drink(){
            srand(time(nullptr));
            int RandomNumber=rand()%9;//0=value ;;;;;; 1=Vote
            int Current_Votes=stoi(Drinks[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Drinks[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Worst_Item(){
            srand(time(nullptr)+ID+6);
            int RandomNumber=rand()%7;
            BadItem=Items[0][RandomNumber];

        }

        void Calculate_Worst_Song(){
            srand(time(nullptr)+ID+6);
            int RandomNumber=rand()%7;
            BadSong=Songs[0][RandomNumber];
        }

        void Calculate_Worst_Food(){
            srand(time(nullptr)+ID+9);
            int RandomNumber=rand()%9;
            BadFood=Foods[0][RandomNumber];
        }

        void Calculate_Fav_Food(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%9;
            FavFood=Foods[0][RandomNumber];
            int Current_Votes=stoi(Foods[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Foods[1][RandomNumber]=String_Of_CurrentVotes;
		}

        // virtual void Noor_CSV_Kr_LO(){

        //}
};
bst<string> FirstClass:: FirstClass_Data;



class General:public Stadium{
    protected:
        friend class Cricket_Managment_System;
        static bst<string>General_Data;
    public:
        General(){
            ID=0;
            MoneySpent=0;
            Capacity=Total_Stadium_Capacity*0.6;
        }

        void Store_Name_In_Queue(){
            fstream GeneralFile;
            GeneralFile.open("Generalclass.txt",ios::in);//Read Mode
            if(GeneralFile.is_open()){
                string name;
                while(ID!=Capacity){
                    getline(GeneralFile,name);
                    Participants_List.insert(name);
                    ID++;
                }
                GeneralFile.close();
            }
        }

        void Insert_Names_In_Tree(){
            string naam=Participants_List.gettop();
            string comeon="";
            for(int i=0;i<=naam.length()-2;i++)
                comeon=comeon+naam[i];
            General_Data.insert(ID,comeon,MoneySpent,CountryName,FavFood,FavItem,FavSong,BadItem,BadSong,BadFood);
            ID--;
            Participants_List.del();
            Total_Attendees++;
        }

        void Calculate_MoneySpent(){
            srand(time(nullptr)+ID);
            MoneySpent=rand()%1000;
        }

        void Calculate_Fav_Item(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%7;
            FavItem=Items[0][RandomNumber];
            int Current_Votes=stoi(Items[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Items[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Decide_Country(){
            srand(time(nullptr));
             srand(time(nullptr)+ID);
            int RandomNumber=rand()%196;
            CountryName=Country[0][RandomNumber];
            int Current_Votes=stoi(Country[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Country[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Fav_Song(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%7;
            FavSong=Songs[0][RandomNumber];
            int Current_Votes=stoi(Songs[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Songs[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Fav_Drink(){
            srand(time(nullptr));
            int RandomNumber=rand()%9;//0=value ;;;;;; 1=Vote
            int Current_Votes=stoi(Drinks[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Drinks[1][RandomNumber]=String_Of_CurrentVotes;
        }

        void Calculate_Worst_Item(){
            srand(time(nullptr)+ID+6);
            int RandomNumber=rand()%7;
            BadItem=Items[0][RandomNumber];
        }

        void Calculate_Worst_Song(){
            srand(time(nullptr)+ID+6);
            int RandomNumber=rand()%7;
            BadSong=Songs[0][RandomNumber];
        }

        void Calculate_Worst_Food(){
            srand(time(nullptr)+ID+9);
            int RandomNumber=rand()%9;
            BadFood=Foods[0][RandomNumber];
        }

        void Calculate_Fav_Food(){
            srand(time(nullptr)+ID);
            int RandomNumber=rand()%9;
            FavFood=Foods[0][RandomNumber];
            int Current_Votes=stoi(Foods[1][RandomNumber]);
            Current_Votes++;
            string String_Of_CurrentVotes = to_string(Current_Votes);
            Foods[1][RandomNumber]=String_Of_CurrentVotes;
		}

        // virtual void Noor_CSV_Kr_LO(){

        //}
};
bst<string> General:: General_Data;



class Cricket_Managment_System{
    private:    
        int size;
        string bara;
        string BestFood,BestItem,BestDrink,BestSong;
        string BadFood,BadItem,BadDrink,BadSong;
        string VIP_Country,FirstClass_Country,General_Country;
    public:
        Cricket_Managment_System(){
            for(int i=0;i<=195;i++){
                Country[1][i]="0";
            }
            Calculate_Everything();
        }

        void Store_Data_In_CSV(){
            VIP v;
            FirstClass f;
            General g;
            v.Store_Name_In_Queue();
            f.Store_Name_In_Queue();
            g.Store_Name_In_Queue();
            while(!v.Participants_List.IsEmpty()){
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
            while(!f.Participants_List.IsEmpty()){
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
            while(!g.Participants_List.IsEmpty()){
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
            cout<<endl;
            VIP::VIP_Data.Write_Data_To_CSV("VIP_Data_To_File");
            FirstClass::FirstClass_Data.Write_Data_To_CSV("FirstClass_Data_To_File");
            General::General_Data.Write_Data_To_CSV("General_Data_To_File");
            // cout<<"Data Stored Successfully";
        }
        
        void Calculate_Total_Country_Count(string &a){
            bara=Country[1][0];
            a=Country[0][1];
            size=(sizeof(Country)/sizeof(Country[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara<Country[1][i]){
                    bara=Country[1][i];    //vote
                    a=Country[0][i]; //Name
                }
            }
        }
        
        void Calculate_Everything(){
            Store_Data_In_CSV();
            bara=Foods[1][0];
            BestFood=Foods[0][1];
            size=(sizeof(Foods)/sizeof(Foods[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara<Foods[1][i]){
                    bara=Foods[1][i];    //vote
                    BestFood=Foods[0][i]; //Name
                }
            }
            bara=Items[1][0];
            BestItem=Items[1][1];
            size=(sizeof(Items)/sizeof(Items[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara<Items[1][i]){
                    bara=Items[1][i];    //vote
                    BestItem=Items[0][i]; //Name
                }
            }
            bara=Drinks[1][0];
            BestDrink=Drinks[0][1];
            size=(sizeof(Drinks)/sizeof(Drinks[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara<Drinks[1][i]){
                    bara=Drinks[1][i];    //vote
                    BestDrink=Drinks[0][i]; //Name
                }
            }
            bara=Songs[1][0];
            BestSong=Songs[0][1];
            size=(sizeof(Songs)/sizeof(Songs[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara<Songs[1][i]){
                    bara=Songs[1][i];    //vote
                    BestSong=Songs[0][i]; //Name
                }
            }

            //Bad
            bara=Foods[1][0];
            BadFood=Foods[0][1];
            size=(sizeof(Foods)/sizeof(Foods[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara>Foods[1][i]){
                    bara=Foods[1][i];    //vote
                    BadFood=Foods[0][i]; //Name
                }
            }
            bara=Items[1][0];
            BadItem=Items[0][1];
            size=(sizeof(Items)/sizeof(Items[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara>Items[1][i]){
                    bara=Items[1][i];    //vote
                    BadItem=Items[0][i]; //Name
                }
            }
            bara=Drinks[1][0];
            BadDrink=Drinks[0][1];
            size=(sizeof(Drinks)/sizeof(Drinks[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara>Drinks[1][i]){
                    bara=Drinks[1][i];    //vote
                    BadDrink=Drinks[0][i]; //Name
                }
            }
            bara=Songs[1][0];
            BadSong=Songs[0][1];
            size=(sizeof(Songs)/sizeof(Songs[0][0]))/2;
            for(int i=0;i<size;i++){
                if(bara>Songs[1][i]){
                    bara=Songs[1][i];    //vote
                    BadSong=Songs[0][i]; //Name
                }
            }
        }

        void Show_Summary(){
            cout<<"The Best Performing Item was  : "<<BestItem<<endl;
            cout<<"The Best Performing Food was  : "<<BestFood<<endl;
            cout<<"The Best Performing Song was  : "<<BestSong<<endl;
            cout<<"The Best Performing Drink was : "<<BestDrink<<endl;
            cout<<"The Worst Performing Item was : "<<BadItem<<endl;
            cout<<"The Worst Performing Food was : "<<BadFood<<endl;
            cout<<"The Worst Performing Song was : "<<BadSong<<endl;
            cout<<"The Worst Performing Drink was: "<<BadDrink<<endl;
        }

        void Show_Menu(){
            cout<<"\n=================================================================================================================\n";
            cout<<"\n\t\t\t\t\tCricket Stadium Managment System";
            cout<<"\n=================================================================================================================\n";
            cout<<"1) Show Summary"<<endl;
            cout<<"2) Show VIP Data"<<endl;
            cout<<"3) Show First Class Data"<<endl;
            cout<<"4) Show General Class Data"<<endl;
            cout<<"5) Exit"<<endl;
        }
        
        void Menu_Input(){
            int Options=0;
            while(Options!=5){
                Show_Menu();
                cin>>Options;
                if(Options==1)
                    Show_Summary();
                else if(Options==2){
                    do{
                        cout<<"1) Most Money Spent By An Individual"<<endl;
                        cout<<"2) Least Money Spent By An Individual"<<endl;
                        cout<<"3) Most People From A Country"<<endl;
                        cin>>Options;
                        if(Options==1)
                            VIP::VIP_Data.maxvalue();
                        else if(Options==2)
                            VIP::VIP_Data.minvalue();
                        else if(Options==3)
                            cout<<VIP_Country<<endl;
                        else
                            cout<<"\nInvalid Input. Enter Again\n";
                    }while(Options>3||Options<1);
                }

                else if(Options==3){
                    do{
                        cout<<"1) Most Money Spent By An Individual"<<endl;
                        cout<<"2) Least Money Spent By An Individual"<<endl;
                        cout<<"3) Most People From A Country"<<endl;
                        cin>>Options;
                        if(Options==1)
                            FirstClass::FirstClass_Data.maxvalue();
                        else if(Options==2)
                            FirstClass::FirstClass_Data.minvalue();
                        else if(Options==3)
                            cout<<FirstClass_Country<<endl;
                        else
                            cout<<"\nInvalid Input. Enter Again\n";
                    }while(Options>3||Options<1);
                }

                else if(Options==4){
                    do{
                        cout<<"1) Most Money Spent By An Individual"<<endl;
                        cout<<"2) Least Money Spent By An Individual"<<endl;
                        cout<<"3) Most People From A Country"<<endl;
                        cin>>Options;
                        if(Options==1)
                            General::General_Data.maxvalue();
                        else if(Options==2)
                            General::General_Data.minvalue();
                        else if(Options==3)
                            cout<<General_Country<<endl;
                        else
                            cout<<"\nInvalid Input. Enter Again\n";
                    }while(Options>3||Options<1);
                }
                else if(Options!=5){
                    cout<<"Invalid Input. Enter Again: "<<endl;
                }
            }
        }

};


class Cricket_Simulation{
    private:
        queue<string>Australia,England,NewZealand,Pakistan,India,Afghanistan,Kenya,WestInDies,Zimbabwe,SriLanka,Bangladesh,SouthAfrica,NetherLands,IreLand,Nepal,ScotLand,HongKong,UAE;
        queue<string>Country2;
        queue<string>Country1;
        int Team1,Team2;//Address 
        int Overs;
        int BatOrBall;
        int Out;
        int Runs;
        int Score1;
        int Score2;
        int Balls;
        int Current_Overs;
        string Opening_Batsman;
        string Second_Batsman;
        int Limit_Of_Wide_And_NoBall;
        int Count_Of_Wide_And_NoBall;
        int More_Random_Count;
    public:
        Cricket_Simulation(){
            More_Random_Count=0;
            Limit_Of_Wide_And_NoBall=20;
            Count_Of_Wide_And_NoBall=0;
            Current_Overs=0;
            Runs=0;
            Score1=0;
            Score2=0;
            Out=0;
            Overs=5;
            Balls=0;
            Australia.Enqueue("David Warner");
            Australia.Enqueue("Usman Khawaja");
            Australia.Enqueue("Aaroan Finch(C)");
            Australia.Enqueue("Steve Smith");
            Australia.Enqueue("Glenn Maxwell(WC)");
            Australia.Enqueue("Michale Charke");
            Australia.Enqueue("Mitchell Starc");
            Australia.Enqueue("Gosh Hazlewood");
            Australia.Enqueue("Travis Head");
            Australia.Enqueue("James Fawlkner");
            Australia.Enqueue("Ashton Agar");
            Australia.Enqueue("Brett Lee");
            England.Enqueue("Dawid Malan(C)");
            England.Enqueue("Liam Living-Stone");
            England.Enqueue("Alex Hales");
            England.Enqueue("Adil Rashid");
            England.Enqueue("Sam Curran");
            England.Enqueue("Moeen Ali");
            England.Enqueue("Harry Brook(WC)");
            England.Enqueue("James Anderson");
            England.Enqueue("Mark Wood");
            England.Enqueue("Chris Jordan");
            England.Enqueue("Jack Leach");
            NewZealand.Enqueue("James Neesham");
            NewZealand.Enqueue("Mitchell Santner");
            NewZealand.Enqueue("Michael Bracewell");
            NewZealand.Enqueue("Finn Allen");
            NewZealand.Enqueue("Glenn Phillips");
            NewZealand.Enqueue("Devon Conway");
            NewZealand.Enqueue("Martin Guptill");
            NewZealand.Enqueue("Tim Southee");
            NewZealand.Enqueue("Ish Sodhi");
            NewZealand.Enqueue("Lockie Ferguson");
            NewZealand.Enqueue("Trend Boult");
            Pakistan.Enqueue("Shoib Malik");
            Pakistan.Enqueue("Muhammad Hafeez");
            Pakistan.Enqueue("Shahid Afridi");
            Pakistan.Enqueue("Kamran Akmal(WC)");
            Pakistan.Enqueue("Asif Ali");
            Pakistan.Enqueue("Munammad Rizwan");
            Pakistan.Enqueue("Baber Azam(C)");
            Pakistan.Enqueue("Muhammad Abrar Ahmed");
            Pakistan.Enqueue("Naseem Shah");
            Pakistan.Enqueue("Shaheen Shah Afridi");
            Pakistan.Enqueue("Haris Rauf");
            India.Enqueue("Rohit Sharma");
            India.Enqueue("KL Rahul");
            India.Enqueue("Virat Kohli(C)");
            India.Enqueue("Surya Kumar Yadav(VC)");
            India.Enqueue("Ravinder Jadeja");
            India.Enqueue("Jaspreet Bumrah");
            India.Enqueue("MS Dhoni(WC)");
            India.Enqueue("Rishabh Pant");
            India.Enqueue("Hardik Pandya");
            India.Enqueue("Muhammad Shami");
            India.Enqueue("Bhuveneshwar Kumar");
            Afghanistan.Enqueue("Munammad Nabi");
            Afghanistan.Enqueue("Gulbadin Naib");
            Afghanistan.Enqueue("Usman Ghani");
            Afghanistan.Enqueue("Najibullah Zadran");
            Afghanistan.Enqueue("Rashid Khan(C)");
            Afghanistan.Enqueue("Hazratullah Zazai(WC)");
            Afghanistan.Enqueue("Qais Ahmad");
            Afghanistan.Enqueue("Naveen-ul-Haq");
            Afghanistan.Enqueue("Qais Ahmad");
            Afghanistan.Enqueue("Mujeeb ur Rehman");
            Afghanistan.Enqueue("Fazal Haq Farooqi");
            Kenya.Enqueue("Alex Obanda");
            Kenya.Enqueue("Rakep Patel");
            Kenya.Enqueue("Aman Gandhi");
            Kenya.Enqueue("Dhiren Gondaria");
            Kenya.Enqueue("Irfan Karim");
            Kenya.Enqueue("Elijah Otieno");
            Kenya.Enqueue("Jasraj Kundi");
            Kenya.Enqueue("Nelson Odhiambo");
            Kenya.Enqueue("Shem Ngoche");
            Kenya.Enqueue("Pushpak Kerai");
            Kenya.Enqueue("Collins Obuya");
            WestInDies.Enqueue("Brian Lara(C)");
            WestInDies.Enqueue("Chris Gayle");
            WestInDies.Enqueue("Andre Russell");
            WestInDies.Enqueue("Dwayne Bravo");
            WestInDies.Enqueue("Daren Sammy");
            WestInDies.Enqueue("Obed McCoy(WC)");
            WestInDies.Enqueue("Jason Holder");
            WestInDies.Enqueue("Yannic Cariah");
            WestInDies.Enqueue("Sheldon Cottrell");
            WestInDies.Enqueue("Akeal Hosein");
            WestInDies.Enqueue("Raymon Reifer");
            Zimbabwe.Enqueue("Milton Shumba");
            Zimbabwe.Enqueue("Craig Ervine");
            Zimbabwe.Enqueue("Ryan Burl");
            Zimbabwe.Enqueue("Clive Madande");
            Zimbabwe.Enqueue("Sean Williams");
            Zimbabwe.Enqueue("Sikandar Raza");
            Zimbabwe.Enqueue("Wellington Masakadza");
            Zimbabwe.Enqueue("Blessing Muzarabani");
            Zimbabwe.Enqueue("Tony Munyonga");
            Zimbabwe.Enqueue("Richard Ngarava");
            Zimbabwe.Enqueue("Wessly Madhevere");
            SriLanka.Enqueue("Kumar Sangakkara");
            SriLanka.Enqueue("Lasith Malinga");
            SriLanka.Enqueue("TM Dilshan");
            SriLanka.Enqueue("Nuwanidu Fernando");
            SriLanka.Enqueue("Pathum Nissanka");
            SriLanka.Enqueue("Matheesha Pathirana");
            SriLanka.Enqueue("Maheesh Theekshana");
            SriLanka.Enqueue("Praveen Jayawickrama");
            SriLanka.Enqueue("Nuwan Thushara");
            SriLanka.Enqueue("Pramod Madushan");
            SriLanka.Enqueue("Muttiah Muralitharan");
            Bangladesh.Enqueue("Shakib Al Hasan");
            Bangladesh.Enqueue("Najmul Hossain Shanto");
            Bangladesh.Enqueue("Nurul Hasan");
            Bangladesh.Enqueue("Soumya Sarkar");
            Bangladesh.Enqueue("Mosaddek Hossain");
            Bangladesh.Enqueue("Yasir Ali");
            Bangladesh.Enqueue("Ebadot Hossain");
            Bangladesh.Enqueue("Afif Hossain");
            Bangladesh.Enqueue("Hasan Mahmud");
            Bangladesh.Enqueue("Mehidy Hasan Miraz");
            Bangladesh.Enqueue("Mustafizur Rahman");
            SouthAfrica.Enqueue("AB de Villiers");
            SouthAfrica.Enqueue("Hashim Amla(C)");
            SouthAfrica.Enqueue("Temba Bavuma");
            SouthAfrica.Enqueue("Quinton de Kock(WC)");
            SouthAfrica.Enqueue("Shaun Pollock");
            SouthAfrica.Enqueue("David Miller");
            SouthAfrica.Enqueue("Rassie van der Dussen");
            SouthAfrica.Enqueue("Heinrich Klaasen");
            SouthAfrica.Enqueue("Keshav Maharaj");
            SouthAfrica.Enqueue("Anrich Nortje");
            SouthAfrica.Enqueue("Wayne Parnell");
            NetherLands.Enqueue("Max O'Dowd");
            NetherLands.Enqueue("Stephan Myburgh");
            NetherLands.Enqueue("Scott Edwards");
            NetherLands.Enqueue("Tom Cooper");
            NetherLands.Enqueue("Colin Ackermann");
            NetherLands.Enqueue("Bas de Leede");
            NetherLands.Enqueue("Brandon Glover");
            NetherLands.Enqueue("Timm van der Gugten");
            NetherLands.Enqueue("Paul van Meekeren");
            NetherLands.Enqueue("Logan van Beek");
            NetherLands.Enqueue("Roelof van der Merwe");
            IreLand.Enqueue("Stephen Doheny");
            IreLand.Enqueue("Andy Balbirnie");
            IreLand.Enqueue("Paul Stirling");
            IreLand.Enqueue("Harry Tector");
            IreLand.Enqueue("Lorcan Tucker");
            IreLand.Enqueue("Fionn Hand");
            IreLand.Enqueue("Gareth Delany");
            IreLand.Enqueue("Graham Hume");
            IreLand.Enqueue("Barry McCarthy");
            IreLand.Enqueue("Josh Little");
            IreLand.Enqueue("Conor Olphert");
            Nepal.Enqueue("Kushal Bhurtel");
            Nepal.Enqueue("Aarif Sheikh");
            Nepal.Enqueue("Kamal Airee");
            Nepal.Enqueue("Gyanendra Malla");
            Nepal.Enqueue("Rohit Paudel");
            Nepal.Enqueue("Karan KC");
            Nepal.Enqueue("Sompal Kami");
            Nepal.Enqueue("Lalit Rajbanshi");
            Nepal.Enqueue("Mohammad Aadil Alam");
            Nepal.Enqueue("Gulsan Jha");
            Nepal.Enqueue("Dipendra Singh Airee");
            ScotLand.Enqueue("George Munsey");
            ScotLand.Enqueue("Richie Berrington(C)");
            ScotLand.Enqueue("Michael Jones");
            ScotLand.Enqueue("Calum MacLeod");
            ScotLand.Enqueue("Matthew Cross(WC)");
            ScotLand.Enqueue("Craig Wallace");
            ScotLand.Enqueue("Michael Leask");
            ScotLand.Enqueue("Brandon McMullen");
            ScotLand.Enqueue("Safyaan Sharif");
            ScotLand.Enqueue("Chris Sole");
            ScotLand.Enqueue("Mark Watt");
            HongKong.Enqueue("Kinchit Shah(VC)");
            HongKong.Enqueue("Babar Hayat");
            HongKong.Enqueue("Scott McKechnie(WC)");
            HongKong.Enqueue("Zeeshan Ali");
            HongKong.Enqueue("Nizakat Khan");
            HongKong.Enqueue("Aizaz Khan");
            HongKong.Enqueue("Ateeq Iqbal");
            HongKong.Enqueue("Dhananjay Rao");
            HongKong.Enqueue("Ehsan Khan");
            HongKong.Enqueue("Mohammad Waheed");
            HongKong.Enqueue("Mohammad Ghazanfar");
            UAE.Enqueue("Muhammad Waseem");
            UAE.Enqueue("Alishan Sharafu");
            UAE.Enqueue("Rohan Mustafa");
            UAE.Enqueue("Chundangapoyil Rizwan(C)");
            UAE.Enqueue("Basil Hameed");
            UAE.Enqueue("Aayan Afzal Khan");
            UAE.Enqueue("Ahmed Raza");
            UAE.Enqueue("Junaid Siddique");
            UAE.Enqueue("Adhitya Shetty");
            UAE.Enqueue("Sabir Ali");
            UAE.Enqueue("Zahoor Khan");

        }

        queue<string> Country1_Playing_Queue(){
            if(Team1==Aus)
                return Australia;
            else if(Team1==Eng)
                return England;
            else if(Team1==New)
                return NewZealand;
            else if(Team1==Pak)
                return Pakistan;
            else if(Team1==Ind)
                return India;
            else if(Team1==Afg)
                return Afghanistan;
            else if(Team1==Ken)
                return Kenya;
            else if(Team1==West)
                return WestInDies;
            else if(Team1==Zim)
                return Zimbabwe;
            else if(Team1==Sri)
                return SriLanka;
            else if(Team1==Ban)
                return Bangladesh;
            else if(Team1==South)
                return SouthAfrica;
            else if(Team1==Nether)
                return NetherLands;
            else if(Team1==Ire)
                return IreLand;
            else if(Team1==Nep)
                return Nepal;
            else if(Team1==Scot)
                return ScotLand;
            else if(Team1==Hong)
                return HongKong;
            else if(Team1==UA)
                return UAE;
            return Pakistan;   
        }

        queue<string> Country2_Playing_Queue(){
            if(Team2==Aus)
                return Australia;
            else if(Team2==Eng)
                return England;
            else if(Team2==New)
                return NewZealand;
            else if(Team2==Pak)
                return Pakistan;
            else if(Team2==Ind)
                return India;
            else if(Team2==Afg)
                return Afghanistan;
            else if(Team2==Ken)
                return Kenya;
            else if(Team2==West)
                return WestInDies;
            else if(Team2==Zim)
                return Zimbabwe;
            else if(Team2==Sri)
                return SriLanka;
            else if(Team2==Ban)
                return Bangladesh;
            else if(Team2==South)
                return SouthAfrica;
            else if(Team2==Nether)
                return NetherLands;
            else if(Team2==Ire)
                return IreLand;
            else if(Team2==Nep)
                return Nepal;
            else if(Team2==Scot)
                return ScotLand;
            else if(Team2==Hong)
                return HongKong;
            else if(Team2==UA)
                return UAE;
            return India;   
        }

        void Random_Match_Selector(){   //
            int a=0;
            abc:
            srand(time(nullptr));
            Team1=rand()%18;//Address

            srand((time(nullptr))+a);
            Team2=rand()%18;//Address
            if(Team1==Team2){
                a++;
                goto abc;
            }

        }
        
        int Toss(){
            srand(time(nullptr));
            int HT=rand()%1;
            if(HT==0)
                return HT=Team1;
            else
                return HT=Team2;
        }
        
        int Bat_Ball(){
            srand(time(nullptr));
            int BatOrBall=rand()%2;//0=Ball     1=Bat
            return BatOrBall;
        }
        
        int Scores(){//Determines What Score/Hits will the player play
            srand(time(nullptr)+More_Random_Count);
            int Hit=rand()%12;
            More_Random_Count++;
            return Hit;
        }
        
        bool All_Out(){
            if(Out==9){
                return true;
            }
            else{
                return false;
            }
        }
        
        bool Over_End(){
            if(Current_Overs==Overs){
                return true;
            }
            else
                return false;
        }

        bool Batting(){
            string Batsman;
            int Mara=Scores();
            if(Count_Of_Wide_And_NoBall>=Limit_Of_Wide_And_NoBall&&Mara==6||Mara==7){
                return false;
            }
            if(Balls==6){
                Batsman=Opening_Batsman;
                Opening_Batsman=Second_Batsman;
                Second_Batsman=Batsman;
                Current_Overs++;
                Balls=0;
            }
            cout<<"\n---------------------------------------------------------------------------------------------------------";
            cout<<"\nTotal Overs: "<<Current_Overs<<endl;
            cout<<"Balls: "<<Balls<<"\nTotal Score: "<<Runs<<"\n---------------------------------------------------------------------------------------------------------"<<endl;
            if(Mara==4||Mara==8||Mara==9||Mara==11){//Out
                Out++;
                cout<<"Out: "<<Out<<endl;
                cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<endl;
                Balls++;
                return true;
            }
            else if(Mara==0){//Single
                cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<endl;
                Runs++;
                Balls++;
                Batsman=Opening_Batsman;
                Opening_Batsman=Second_Batsman;
                Second_Batsman=Batsman;
                return false;
            }
            else if(Mara==2){//Triple
                cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<endl;
                Runs=Runs+3;
                Batsman=Opening_Batsman;
                Opening_Batsman=Second_Batsman;
                Second_Batsman=Batsman;
                Balls++;
                return false;
            }
//string Hits[12]={"Makes a Single","Makes a Double","Makes a Triple","Hits a Four","is Bowled! The Umpire Lifts The Finger.","Hits A Six!","No Ball!","Wide Ball","got LBW And Thats Out!","Hits. The Ball Is In The Air And He Catches It! Hes Out!","Dot Ball","Got Run Out!"};
            else if(Mara==1){//Double
                cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<endl;
                Runs=Runs+2;
                Balls++;
                return false;
            }
            else if(Mara==3){//Four
                cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<endl;
                Runs=Runs+4;
                Balls++;
                return false;
            }
            else if(Mara==5){//SIX!!
                cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<endl;
                Runs=Runs+6;
                Balls++;
                return false;
            }
            else if(Mara==6||Mara==7){//Wide or No Ball
                cout<<"\t\t\tThat was a "<<Hits[Mara]<<endl;
                Runs++;
                Count_Of_Wide_And_NoBall++;
                return false;
            }
            else if(Mara==10){//Dot ball
                cout<<"\t\t\tThat Was A Dot Ball. You Just Cannot Afford A Dot Ball In This Limited Over Match"<<endl;
                Balls++;
            }
            return false;
        }

        void GamePlay(){
            cout<<"\t\t\t\tWelcome To BNO Cricket Stadium\n\t\tWe have Got Osama Bilal And Noor With Us In The Commentary Box\n\t\t\t\tThe Weather Is Nice And Lovely."<<endl;
            sleep(1);
            cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t\t\tPITCH ANALYSIS"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
            sleep(1);
            cout<<"\tThe Pitch Is Quite Damp So The Ballers Will Have A Masive Advantage."<<endl;
            Random_Match_Selector();
            sleep(3);
            cout<<"\n\t\tToday The Match Is Between "<<Cricket_Teams[Team1]<<" and "<<Cricket_Teams[Team2]<<endl;
            sleep(1);
            cout<<"\t\tIt Looks To Be A Very Exciting Match. The Stadium Is Jammed Pack At "<<Total_Attendees<<" People.\n\t\tLets See Who Wins And Good Luck To Both Of Them."<<endl;
            int TossWin=Toss();
            sleep(1);
            cout<<"\n=================================================================================================================\n";
            cout<<"\t\t\t\t\t"<<Cricket_Teams[Team1]<<" VS "<<Cricket_Teams[Team2]<<"\n=================================================================================================================\n";
            sleep(3);
            cout<<"\n\t"<<Cricket_Teams[TossWin]<<" Won The Toss And Decided To";
            if(TossWin==Team1){
                Country1=Country1_Playing_Queue();
                Country2=Country2_Playing_Queue();
            }
            else{
                Country2=Country1_Playing_Queue();
                Country1=Country2_Playing_Queue();
            }
            if(Bat_Ball()==0){
                cout<<" Ball First."<<endl;
                Opening_Batsman=Country2.Dequeue();
                Second_Batsman=Country2.Dequeue();
                sleep(1);
                cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"\t"<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman.";
                while(!All_Out()&&!Over_End()){
                    sleep(2);
                    if(Batting()&&!All_Out()){
                        Opening_Batsman=Country2.Dequeue();
                        cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<endl;
                    }
                }
                Score2=Runs;
                cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[Team2]<<" Comes Out To Be: "<<Score2<<endl;
                Current_Overs=0;
                Balls=0;
                Out=0;
                Runs=0;
                sleep(1);
                cout<<"\n=================================================================================================================\n";
                cout<<"\t\t\t\t\t"<<Cricket_Teams[Team1]<<" Will Now Bat "<<"\n=================================================================================================================\n";
                //2nd Country's Batting:
                //Casing Runs
                Opening_Batsman=Country1.Dequeue();
                Second_Batsman=Country1.Dequeue();
                cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"\t"<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman.";
                do{
                    sleep(2);
                    if(Batting()&&!All_Out()){
                        Opening_Batsman=Country1.Dequeue();
                        cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<endl;
                    }
                }while(!All_Out()&&!Over_End()&&Runs<=Score2);
                Score1=Runs;
                cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[Team1]<<" Comes Out To Be: "<<Score1<<endl;
                Current_Overs=0;
                Balls=0;
                Out=0;
                Runs=0;
            }
            else{
                cout<<" Bat First."<<endl;
                Opening_Batsman=Country1.Get_data();
                Second_Batsman=Country1.Dequeue();
                cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                cout<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman."<<endl;
                while(!All_Out()&&!Over_End()){
                    sleep(2);
                    if(Batting()&&!All_Out()){
                        Opening_Batsman=Country1.Dequeue();
                        cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<endl;
                    }
                }
                Score1=Runs;
                cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[TossWin]<<" Comes Out To Be: "<<Score1<<endl;
                Current_Overs=0;
                Balls=0;
                Out=0;
                Runs=0;
                cout<<"\n=================================================================================================================\n";
                cout<<"\t\t\t\t\t"<<Cricket_Teams[Team2]<<" Will Now Bat "<<"\n=================================================================================================================\n";
                //2nd Country's Batting:
                //Casing Runs
                Opening_Batsman=Country2.Dequeue();
                Second_Batsman=Country2.Dequeue();
                cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"\t"<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman.";
                do{
                    sleep(2);
                    if(Batting()&&!All_Out()){
                        Opening_Batsman=Country2.Dequeue();
                        cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<endl;
                    }
                }while(!All_Out()&&!Over_End()&&Runs<=Score1);
                Score2=Runs;
                cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[Team2]<<" Comes Out To Be: "<<Score2<<endl;
                Current_Overs=0;
                Balls=0;
                Out=0;
                Runs=0;
            }
            sleep(1);
            cout<<"=================================================================================================================";
            cout<<"\n\t\t\t\tMatch Results\n";
            cout<<"================================================================================================================="<<endl;
            cout<<"\t\t________________________________________________"<<endl;
            cout<<"\t\t||"<<Cricket_Teams[Team1]<<"'s Score: "<<Score1<<"||"<<Cricket_Teams[Team2]<<"'s Score: "<<Score2<<"||"<<endl;
            cout<<"\t\t------------------------------------------------"<<endl;
            cout<<endl<<endl<<"\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
            if(Score1>Score2)
                cout<<"\t\t\t"<<Cricket_Teams[Team1]<<" Wins The Match!";
            else if(Score2>Score1)
                cout<<"\t\t\t"<<Cricket_Teams[Team2]<<" Wins The Match!";
            else
                cout<<"\t\t\tMatch Draw!"<<endl;
            cout<<"\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
            cout<<"\n\tIt Was A Thrilling Match. I Loved It, The Audiance Enjoyed It And I Hope You Enjoyed It As Well."<<endl;
            cout<<"\t\t\t\t\tBye Bye!"<<endl<<endl;
        }

};


int main(){
    Cricket_Managment_System Manage;
    Cricket_Simulation a;
    a.GamePlay();
    Manage.Menu_Input();
    return 0;
}