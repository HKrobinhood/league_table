#ifndef LEAGUE_H
#define LEAGUE_H

#include <vector>
#include "Team.h"
using namespace std;

class League {
private:
    std::vector<Team> teams;
    

public:
    League() {}

    
    void addTeam(std::string name);
    void recordMatch(std::string team1, int score1, std::string team2, int score2);
    void displayLeagueTable();
};

#endif // LEAGUE_H
