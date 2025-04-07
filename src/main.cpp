#include "League.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\nFootball League Management System" << endl;
    cout << "1. Create League" << endl;
    cout << "2. Add Team" << endl;
    cout << "3. Record Match" << endl;
    cout << "4. Display League Table" << endl;
    cout << "9. Reset League Data" << endl;
    cout << "Enter your choice: ";
}

int main() {
    League premierLeague;
    int choice;
    string team1, team2;
    int score1, score2;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                premierLeague = League(); // Reset league
                cout << "League created successfully!" << endl;
                break;
            case 2:
                cout << "Enter team name: ";
                getline(cin, team1);
                premierLeague.addTeam(team1);
                cout << "Team " << team1 << " added!" << endl;
                break;
            case 3:
                cout << "Enter first team name: ";
                getline(cin, team1);
                cout << "Enter first team score: ";
                cin >> score1;
                cin.ignore();
                cout << "Enter second team name: ";
                getline(cin, team2);
                cout << "Enter second team score: ";
                cin >> score2;
                cin.ignore();
                premierLeague.recordMatch(team1, score1, team2, score2);
                break;
            case 4:
                premierLeague.displayLeagueTable();
                break;
            case 9:
                premierLeague = League(); // Reset league
                cout << "League data cleared!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != -1);
    
    return 0;
}
