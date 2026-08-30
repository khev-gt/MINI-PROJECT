#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void UX(); 
int findTeamIndex(int id);
void ensureCapacity(int required);
void addTeam(int id, string name);      
void recordMission(int id, int points); 
void deleteTeam(int id);
void sortLeaderboard();
void displayTeams();
void loadTeams() {
    FILE* file = fopen("teams.txt", "r");
    if (file == NULL) return; 
    // fgets logic will go here
    fclose(file);
}
void saveTeams() {
    FILE* file = fopen("teams.txt", "w");
    if (file == NULL) return;
    // fprintf logic will go here
    fclose(file);
}
int main() {
    loadTeams();
    int choice = 0;

    while (choice != 6) {
        
        UX(); 
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter team ID: ";
            cin >> id;
            cout << "Enter team name: ";
            cin.ignore(); 
            getline(cin, name); 
            
            addTeam(id, name); 
            cout << "Team registered successfully.\n";
        }
        else if (choice == 2) {
            int id, points;
            cout << "Enter team ID: ";
            cin >> id;
            cout << "Enter mission points earned (1-100): ";
            cin >> points;
            
            recordMission(id, points); 
            cout << "Mission points recorded.\n";
        }
        else if (choice == 3) {
            int id;
            cout << "Enter team ID: ";
            cin >> id;
            findTeamIndex(id); 
        }
        else if (choice == 4) {
            int id;
            cout << "Enter team ID: ";
            cin >> id;
            deleteTeam(id); 
            cout << "Team removed.\n";
        }
        else if (choice == 5) {
            sortLeaderboard(); 
            displayTeams();    
        }
    }
    saveTeams();
    return 0;
}
