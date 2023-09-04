#ifndef CRICKET_SIMULATION_H
#define CRICKET_SIMULATION_H

#include <string>
#include "MyQueue.h"  // Include the necessary headers

class Cricket_Simulation {
private:
    MyQueue<std::string> Australia, England, NewZealand, Pakistan, India, Afghanistan, Kenya, WestInDies, Zimbabwe, SriLanka, Bangladesh, SouthAfrica, NetherLands, IreLand, Nepal, ScotLand, HongKong, UAE;
    MyQueue<std::string> Country2;
    MyQueue<std::string> Country1;
    int Team1, Team2;
    int Overs;
    int Out;
    int Runs;
    int Score1;
    int Score2;
    int Balls;
    int Current_Overs;
    std::string Opening_Batsman;
    std::string Second_Batsman;
    int Limit_Of_Wide_And_NoBall;
    int Count_Of_Wide_And_NoBall;
    enum Cricket_Country_Names { Aus, Eng, New, Pak, Ind, Afg, Ken, West, Zim, Sri, Ban, South, Nether, Ire, Nep, Scot, Hong, UA };
public:
    Cricket_Simulation();
    MyQueue<std::string> Country1_Playing_Queue();
    MyQueue<std::string> Country2_Playing_Queue();
    void Random_Match_Selector();
    int Toss();
    int Bat_Ball();
    int Scores();
    bool All_Out();
    bool Over_End();
    bool Batting();
    void GamePlay();
};

#endif // CRICKET_SIMULATION_H
