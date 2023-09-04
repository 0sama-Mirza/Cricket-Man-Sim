#include "../includes/Globals.h"
#include "../includes/Cricket_Simulation.h"
#include <iostream>
#include <random>
#include <unistd.h> // For sleep function

// Constructor definition
Cricket_Simulation::Cricket_Simulation()
    : Australia(),
      England(),
      NewZealand(),
      Pakistan(),
      India(),
      Afghanistan(),
      Kenya(),
      WestInDies(),
      Zimbabwe(),
      SriLanka(),
      Bangladesh(),
      SouthAfrica(),
      NetherLands(),
      IreLand(),
      Nepal(),
      ScotLand(),
      HongKong(),
      UAE(),
      Country2(),
      Country1(),
      Team1(0),
      Team2(0),
      Overs(5),
      Out(0),
      Runs(0),
      Score1(0),
      Score2(0),
      Balls(0),
      Current_Overs(0),
      Opening_Batsman(""),
      Second_Batsman(""),
      Limit_Of_Wide_And_NoBall(20),
      Count_Of_Wide_And_NoBall(0)
{
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

MyQueue<std::string> Cricket_Simulation::Country1_Playing_Queue(){
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

MyQueue<std::string> Cricket_Simulation::Country2_Playing_Queue(){
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

void Cricket_Simulation::Random_Match_Selector(){
    int a=0;
    abc:
    // srand(time(nullptr));
    // Team1=rand()%18;//Address
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 17); // Range: 0 to 17
    Team1 = dist(gen);
    // srand((time(nullptr))+a);
    // Team2=rand()%18;//Address
    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_int_distribution<int> dist2(0, 17); // Range: 0 to 17
    Team2 = dist2(gen2);
    if(Team1==Team2){
        a++;
        goto abc;
    }
}
   
int Cricket_Simulation::Toss(){
    // srand(time(nullptr));
    // int HT=rand()%1;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1); // Range: 0 to 1
    int HT = dist(gen);
    if(HT==0)
        return HT=Team1;
    else
        return HT=Team2;
}

int Cricket_Simulation::Bat_Ball(){
    // srand(time(nullptr));
    // int BatOrBall=rand()%2;//0=Ball     1=Bat
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1); // Range: 0 to 1
    return dist(gen);
}

int Cricket_Simulation::Scores(){//Determines What Score/Hits will the player play
    // srand(time(nullptr));
    // int Hit=rand()%12;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 11); // Range: 0 to 11
    int Hit = dist(gen);
    return Hit;
}

bool Cricket_Simulation::All_Out(){
    if(Out==9){
        return true;
    }
    else{
        return false;
    }
}

bool Cricket_Simulation::Over_End(){
    if(Current_Overs==Overs){
        return true;
    }
    else
        return false;
}

bool Cricket_Simulation::Batting(){
    std::string Batsman;
    int Mara=Scores();
    if((Count_Of_Wide_And_NoBall>=Limit_Of_Wide_And_NoBall)&&(Mara==6||Mara==7)){
        return false;
    }
    if(Balls==6){
        Batsman=Opening_Batsman;
        Opening_Batsman=Second_Batsman;
        Second_Batsman=Batsman;
        Current_Overs++;
        Balls=0;
    }
    std::cout<<"\n---------------------------------------------------------------------------------------------------------";
    std::cout<<"\nTotal Overs: "<<Current_Overs<<std::endl;
    std::cout<<"Balls: "<<Balls<<"\nTotal Score: "<<Runs<<"\n---------------------------------------------------------------------------------------------------------"<<std::endl;
    if(Mara==4||Mara==8||Mara==9||Mara==11){//Out
        Out++;
        std::cout<<"Out: "<<Out<<std::endl;
        std::cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<std::endl;
        Balls++;
        return true;
    }
    else if(Mara==0){//Single
        std::cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<std::endl;
        Runs++;
        Balls++;
        Batsman=Opening_Batsman;
        Opening_Batsman=Second_Batsman;
        Second_Batsman=Batsman;
        return false;
    }
    else if(Mara==2){//Triple
        std::cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<std::endl;
        Runs=Runs+3;
        Batsman=Opening_Batsman;
        Opening_Batsman=Second_Batsman;
        Second_Batsman=Batsman;
        Balls++;
        return false;
    }
//string Hits[12]={"Makes a Single","Makes a Double","Makes a Triple","Hits a Four","is Bowled! The Umpire Lifts The Finger.","Hits A Six!","No Ball!","Wide Ball","got LBW And Thats Out!","Hits. The Ball Is In The Air And He Catches It! Hes Out!","Dot Ball","Got Run Out!"};
    else if(Mara==1){//Double
        std::cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<std::endl;
        Runs=Runs+2;
        Balls++;
        return false;
    }
    else if(Mara==3){//Four
        std::cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<std::endl;
        Runs=Runs+4;
        Balls++;
        return false;
    }
    else if(Mara==5){//SIX!!
        std::cout<<"\t\t\t"<<Opening_Batsman<<" "<<Hits[Mara]<<std::endl;
        Runs=Runs+6;
        Balls++;
        return false;
    }
    else if(Mara==6||Mara==7){//Wide or No Ball
        std::cout<<"\t\t\tThat was a "<<Hits[Mara]<<std::endl;
        Runs++;
        Count_Of_Wide_And_NoBall++;
        return false;
    }
    else if(Mara==10){//Dot ball
        std::cout<<"\t\t\tThat Was A Dot Ball. You Just Cannot Afford A Dot Ball In This Limited Over Match"<<std::endl;
        Balls++;
    }
    return false;
}

void Cricket_Simulation::GamePlay(){
    std::cout<<"\t\t\t\tWelcome To BNO Cricket Stadium\n\t\tWe have Got Osama Bilal And Noor With Us In The Commentary Box\n\t\t\t\tThe Weather Is Nice And Lovely."<<std::endl;
    sleep(1);
    std::cout<<"--------------------------------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"\t\t\t\t\tPITCH ANALYSIS"<<std::endl;
    std::cout<<"--------------------------------------------------------------------------------------------------------------"<<std::endl;
    sleep(1);
    std::cout<<"\tThe Pitch Is Quite Damp So The Ballers Will Have A Masive Advantage."<<std::endl;
    Random_Match_Selector();
    sleep(3);
    std::cout<<"\n\t\tToday The Match Is Between "<<Cricket_Teams[Team1]<<" and "<<Cricket_Teams[Team2]<<std::endl;
    sleep(1);
    std::cout<<"\t\tIt Looks To Be A Very Exciting Match. The Stadium Is Jammed Pack At "<<Total_Attendees<<" People.\n\t\tLets See Who Wins And Good Luck To Both Of Them."<<std::endl;
    int TossWin=Toss();
    sleep(1);
    std::cout<<"\n=================================================================================================================\n";
    std::cout<<"\t\t\t\t\t"<<Cricket_Teams[Team1]<<" VS "<<Cricket_Teams[Team2]<<"\n=================================================================================================================\n";
    sleep(3);
    std::cout<<"\n\t"<<Cricket_Teams[TossWin]<<" Won The Toss And Decided To";
    if(TossWin==Team1){
        Country1=Country1_Playing_Queue();
        Country2=Country2_Playing_Queue();
    }
    else{
        Country2=Country1_Playing_Queue();
        Country1=Country2_Playing_Queue();
    }
    if(Bat_Ball()==0){
        std::cout<<" Ball First."<<std::endl;
        Opening_Batsman=Country2.Dequeue();
        Second_Batsman=Country2.Dequeue();
        sleep(1);
        std::cout<<"---------------------------------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\t"<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman.";
        while(!All_Out()&&!Over_End()){
            sleep(2);
            if(Batting()&&!All_Out()){
                Opening_Batsman=Country2.Dequeue();
                std::cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<std::endl;
            }
        }
        Score2=Runs;
        std::cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[Team2]<<" Comes Out To Be: "<<Score2<<std::endl;
        Current_Overs=0;
        Balls=0;
        Out=0;
        Runs=0;
        sleep(1);
        std::cout<<"\n=================================================================================================================\n";
        std::cout<<"\t\t\t\t\t"<<Cricket_Teams[Team1]<<" Will Now Bat "<<"\n=================================================================================================================\n";
        //2nd Country's Batting:
        //Casing Runs
        Opening_Batsman=Country1.Dequeue();
        Second_Batsman=Country1.Dequeue();
        std::cout<<"---------------------------------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\t"<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman.";
        do{
            sleep(2);
            if(Batting()&&!All_Out()){
                Opening_Batsman=Country1.Dequeue();
                std::cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<std::endl;
            }
        }while(!All_Out()&&!Over_End()&&Runs<=Score2);
        Score1=Runs;
        std::cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[Team1]<<" Comes Out To Be: "<<Score1<<std::endl;
        Current_Overs=0;
        Balls=0;
        Out=0;
        Runs=0;
    }
    else{
        std::cout<<" Bat First."<<std::endl;
        Opening_Batsman=Country1.Get_data();
        Second_Batsman=Country1.Dequeue();
        std::cout<<"---------------------------------------------------------------------------------------------------------"<<std::endl;
        std::cout<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman."<<std::endl;
        while(!All_Out()&&!Over_End()){
            sleep(2);
            if(Batting()&&!All_Out()){
                Opening_Batsman=Country1.Dequeue();
                std::cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<std::endl;
            }
        }
        Score1=Runs;
        std::cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[TossWin]<<" Comes Out To Be: "<<Score1<<std::endl;
        Current_Overs=0;
        Balls=0;
        Out=0;
        Runs=0;
        std::cout<<"\n=================================================================================================================\n";
        std::cout<<"\t\t\t\t\t"<<Cricket_Teams[Team2]<<" Will Now Bat "<<"\n=================================================================================================================\n";
        //2nd Country's Batting:
        //Casing Runs
        Opening_Batsman=Country2.Dequeue();
        Second_Batsman=Country2.Dequeue();
        std::cout<<"---------------------------------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"\t"<<Opening_Batsman<<" And "<<Second_Batsman<<" Are The Opening Batsman.";
        do{
            sleep(2);
            if(Batting()&&!All_Out()){
                Opening_Batsman=Country2.Dequeue();
                std::cout<<"\n\t\t\t"<<Opening_Batsman<<" Now Comes To The Pitch"<<std::endl;
            }
        }while(!All_Out()&&!Over_End()&&Runs<=Score1);
        Score2=Runs;
        std::cout<<"\n\tSo The Total Score Of "<<Cricket_Teams[Team2]<<" Comes Out To Be: "<<Score2<<std::endl;
        Current_Overs=0;
        Balls=0;
        Out=0;
        Runs=0;
    }
    sleep(1);
    std::cout<<"=================================================================================================================";
    std::cout<<"\n\t\t\t\tMatch Results\n";
    std::cout<<"================================================================================================================="<<std::endl;
    std::cout<<"\t\t________________________________________________"<<std::endl;
    std::cout<<"\t\t||"<<Cricket_Teams[Team1]<<"'s Score: "<<Score1<<"||"<<Cricket_Teams[Team2]<<"'s Score: "<<Score2<<"||"<<std::endl;
    std::cout<<"\t\t------------------------------------------------"<<std::endl;
    std::cout<<std::endl<<std::endl<<"\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
    if(Score1>Score2)
        std::cout<<"\t\t\t"<<Cricket_Teams[Team1]<<" Wins The Match!";
    else if(Score2>Score1)
        std::cout<<"\t\t\t"<<Cricket_Teams[Team2]<<" Wins The Match!";
    else
        std::cout<<"\t\t\tMatch Draw!"<<std::endl;
    std::cout<<"\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<std::endl;
    std::cout<<"\n\tIt Was A Thrilling Match. I Loved It, The Audiance Enjoyed It And I Hope You Enjoyed It As Well."<<std::endl;
    std::cout<<"\t\t\t\t\tBye Bye!"<<std::endl<<std::endl;
}




