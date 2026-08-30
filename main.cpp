#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// =========================
// Team Structure
// =========================
typedef struct {
    int id;
    char name[40];
    int score;
    int missions;
} Team;

// =========================
// Global Data
// =========================
Team *teams = NULL;
int teamSize = 0;
int capacity = 0;

// =========================
// Function Prototypes
// =========================
void UX();
int findTeamIndex(int id);

int ensureCapacity(Team **teams_ptr, int *cap_ptr, int required);
void cleanup(Team **teams_ptr, int *size_ptr, int *cap_ptr);

void addTeam(int id, string name);
void recordMission(int id, int points);
void deleteTeam(int id);
void sortLeaderboard();
void displayTeams();

void loadTeams();
void saveTeams();


// =========================
// UX / Main Menu
// =========================
void UX() {
    cout << "\n===== Campus Mission Tracker =====\n";
    cout << "1. Register a team\n";
    cout << "2. Record mission points\n";
    cout << "3. Find a team\n";
    cout << "4. Remove a team\n";
    cout << "5. Show leaderboard\n";
    cout << "6. Save and exit\n";
    cout << "Enter your choice: ";
}


// =========================
// Memory Guardian
// =========================
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

    while (newCapacity < required) {
        newCapacity *= 2;
    }

    Team *temp = (Team *)realloc(
        *teams_ptr,
        newCapacity * sizeof(Team)
    );

    if (temp == NULL) {
        cout << "Memory allocation failed.\n";
        return 0;
    }

    *teams_ptr = temp;
    *cap_ptr = newCapacity;

    return 1;
}


// =========================
// Cleanup
// =========================
void cleanup(Team **teams_ptr, int *size_ptr, int *cap_ptr) {

    free(*teams_ptr);

    *teams_ptr = NULL;
    *size_ptr = 0;
    *cap_ptr = 0;
}


// =========================
// Find Team
// =========================
int findTeamIndex(int id) {

    for (int i = 0; i < teamSize; i++) {

        if (teams[i].id == id) {
            return i;
        }
    }

    return -1;
}


// =========================
// Add Team
// =========================
void addTeam(int id, string name) {

    if (findTeamIndex(id) != -1) {
        cout << "Team ID already exists.\n";
        return;
    }

    if (!ensureCapacity(&teams, &capacity, teamSize + 1)) {
        return;
    }

    teams[teamSize].id = id;

    strncpy(
        teams[teamSize].name,
        name.c_str(),
        sizeof(teams[teamSize].name) - 1
    );

    teams[teamSize].name[
        sizeof(teams[teamSize].name) - 1
    ] = '\0';

    teams[teamSize].score = 0;
    teams[teamSize].missions = 0;

    teamSize++;
}


// =========================
// Record Mission
// =========================
void recordMission(int id, int points) {

    int index = findTeamIndex(id);

    if (index == -1) {
        cout << "Team not found.\n";
        return;
    }

    if (points < 1 || points > 100) {
        cout << "Invalid points. Enter 1-100.\n";
        return;
    }

    teams[index].score += points;
    teams[index].missions++;
}


// =========================
// Delete Team
// =========================
void deleteTeam(int id) {

    int index = findTeamIndex(id);

    if (index == -1) {
        cout << "Team not found.\n";
        return;
    }

    for (int i = index; i < teamSize - 1; i++) {
        teams[i] = teams[i + 1];
    }

    teamSize--;
}


// =========================
// Sort Leaderboard
// Highest Score First
// =========================
void sortLeaderboard() {

    for (int i = 0; i < teamSize - 1; i++) {

        for (int j = 0; j < teamSize - i - 1; j++) {

            if (teams[j].score < teams[j + 1].score) {

                Team temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }
}


// =========================
// Display Leaderboard
// =========================
void displayTeams() {

    if (teamSize == 0) {
        cout << "No teams registered yet.\n";
        return;
    }

    cout << "\nRank  ID    Name                         Score  Missions\n";
    cout << "----  ----  ---------------------------  -----  --------\n";

    for (int i = 0; i < teamSize; i++) {

        cout << i + 1 << "     ";
        cout << teams[i].id << "     ";

        cout.width(27);
        cout.setf(ios::left);
        cout << teams[i].name;

        cout.unsetf(ios::left);

        cout << "  ";
        cout.width(5);
        cout << teams[i].score;

        cout << "  ";
        cout << teams[i].missions;

        cout << "\n";
    }
}


// =========================
// Load Teams
// =========================
void loadTeams() {

    FILE *file = fopen("teams.txt", "r");

    if (file == NULL) {
        return;
    }

    int id;
    int score;
    int missions;
    char name[40];

    while (fscanf(
        file,
        "%d|%39[^|]|%d|%d\n",
        &id,
        name,
        &score,
        &missions
    ) == 4) {

        if (!ensureCapacity(&teams, &capacity, teamSize + 1)) {
            break;
        }

        teams[teamSize].id = id;

        strncpy(
            teams[teamSize].name,
            name,
            sizeof(teams[teamSize].name) - 1
        );

        teams[teamSize].name[
            sizeof(teams[teamSize].name) - 1
        ] = '\0';

        teams[teamSize].score = score;
        teams[teamSize].missions = missions;

        teamSize++;
    }

    fclose(file);
}


// =========================
// Save Teams
// =========================
void saveTeams() {

    FILE *file = fopen("teams.txt", "w");

    if (file == NULL) {
        cout << "Could not save teams.\n";
        return;
    }

    for (int i = 0; i < teamSize; i++) {

        fprintf(
            file,
            "%d|%s|%d|%d\n",
            teams[i].id,
            teams[i].name,
            teams[i].score,
            teams[i].missions
        );
    }

    fclose(file);
}


// =========================
// Main Program
// =========================
int main() {

    loadTeams();

    int choice = 0;

    while (choice != 6) {

        UX();

        cin >> choice;

        // Catch non-numeric inputs so the program doesn't infinitely loop
        if (cin.fail()) {
            cin.clear();             // Clear the error state
            cin.ignore(1000, '\n');  // Flush the bad input out of the buffer
            choice = 0;              // Force it to hit the "Invalid choice" else-block
        }

        if (choice == 1) {

            int id;
            string name;

            cout << "Enter team ID: ";
            cin >> id;

            cout << "Enter team name: ";
            cin.ignore();
            getline(cin, name);

            addTeam(id, name);

        }
        else if (choice == 2) {

            int id;
            int points;

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

            int index = findTeamIndex(id);

            if (index == -1) {
                cout << "Team not found.\n";
            }
            else {
                cout << "\nTeam found:\n";
                cout << "ID: " << teams[index].id << "\n";
                cout << "Name: " << teams[index].name << "\n";
                cout << "Score: " << teams[index].score << "\n";
                cout << "Missions: " << teams[index].missions << "\n";
            }

        }
        else if (choice == 4) {

            int id;

            cout << "Enter team ID: ";
            cin >> id;

            int before = teamSize;

            deleteTeam(id);

            if (teamSize < before) {
                cout << "Team removed.\n";
            }

        }
        else if (choice == 5) {

            sortLeaderboard();
            displayTeams();

        }
        else if (choice == 6) {

            saveTeams();
            cout << "Data saved. Goodbye!\n";

        }
        else {

            cout << "Invalid choice. Please enter 1-6.\n";
        }
    }

    cleanup(&teams, &teamSize, &capacity);

    return 0;
}
