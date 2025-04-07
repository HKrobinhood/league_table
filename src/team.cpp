#include "team.h"

Team::Team(std::string teamName) : name(teamName), matchesPlayed(0), wins(0), draws(0), losses(0), goalsFor(0), goalsAgainst(0), points(0) {}//realize constructor

void Team::updateMatchResult(int scored, int conceded) {
    matchesPlayed++;
    goalsFor += scored;
    goalsAgainst += conceded;
    
    if (scored > conceded) {
        wins++;
        points += 3;
    } else if (scored == conceded) {
        draws++;
        points += 1;
    } else {
        losses++;
    }
}

int Team::getPoints() const { return points; }
int Team::getGoalDifference() const { return goalsFor - goalsAgainst; }
std::string Team::getName() const { return name; }

void Team::displayTeamStats() const {
    std::cout << std::left << std::setw(20) << name << std::setw(5) << matchesPlayed << std::setw(5) << wins << std::setw(5) << draws 
         << std::setw(5) << losses << std::setw(5) << goalsFor << std::setw(5) << goalsAgainst << std::setw(5) << getGoalDifference() << std::setw(5) << points << std::endl;
}
