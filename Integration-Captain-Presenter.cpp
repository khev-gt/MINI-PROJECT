#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct {
    int id;
    char name[40];
    int score;
    int missions;
} Team;

// Global tracking variables (matching your teammate's design expectations)
Team *teams = NULL;
int teamSize = 0;
int capacity = 0;

void UX(); 
int findTeamIndex(int id);

int ensureCapacity(Team **teams_ptr, int *cap_ptr, int required) {
    if (required <= *cap_ptr) {
        return 1;
    }

    int newCapacity;

    if (*cap_ptr == 0) {
        newCapacity = 2;
    } else {
        newCapacity = *cap_ptr * 2;
    }

    Team *temp = (Team *)realloc(*teams_ptr, newCapacity * sizeof(Team));

    if (temp == NULL) {
        return 0;
    }
    *teams_ptr = temp;
    *cap_ptr = newCapacity;

    return 1;
}

void cleanup(Team **teams_ptr, int *size_ptr, int *cap_ptr) {
    free(*teams_ptr);
    *teams_ptr = NULL;
    *size_ptr = 0;
    *cap_ptr = 0;
}

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
    cleanup(&teams, &teamSize, &capacity);
    return 0;
}