#include "league.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

void League::addTeam(string name) {
    teams.push_back(Team(name));
}

void League::recordMatch(string team1, int score1, string team2, int score2) {
    auto findTeam = [&](string name) -> Team* {
        for (auto &team : teams) {
            if (team.getName() == name)
                return &team;
        }
        return nullptr;
    };

    Team *t1 = findTeam(team1);
    Team *t2 = findTeam(team2);

    if (t1 && t2) {
        t1->updateMatchResult(score1, score2);
        t2->updateMatchResult(score2, score1);
    } else {
        cout << "One or both teams not found!" << endl;
    }
}

void League::displayLeagueTable() {
    sort(teams.begin(), teams.end(), [](const Team &a, const Team &b) {
        if (a.getPoints() != b.getPoints())
            return a.getPoints() > b.getPoints();
        return a.getGoalDifference() > b.getGoalDifference();
    });
    
    cout << left << setw(20) << "Team" << setw(5) << "MP" << setw(5) << "W" << setw(5) << "D" << setw(5) << "L" 
         << setw(5) << "GF" << setw(5) << "GA" << setw(5) << "GD" << setw(5) << "Pts" << endl;
    for (const auto &team : teams) {
        team.displayTeamStats();
    }
}