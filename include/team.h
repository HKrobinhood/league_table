#ifndef TEAM_H
#define TEAM_H

#include <iostream>
#include <iomanip>


class Team {
private:
    std::string name;
    int matchesPlayed;
    int wins;
    int draws;
    int losses;
    int goalsFor;
    int goalsAgainst;
    int points;

public:
    Team(std::string teamName);   //Declare constructor
    void updateMatchResult(int scored, int conceded);
    int getPoints() const;
    int getGoalDifference() const;
    std::string getName() const;
    void displayTeamStats() const;
};

#endif // TEAM_H
