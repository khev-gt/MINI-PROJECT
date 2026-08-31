//Team members:
//1.Long Thina role Test Captain
//2.Kheng Khevin role Integration Captain
//3.Chheng Longheng role Memory Guardian
//4.Leng Sakda role UX
//5.Lim Chanmonyroth role Record Architecture

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std; 

// ====================================
// Helper: Check if name contains only valid characters
// ====================================
bool isValidName(const string& name) {
    // Only allow: letters, numbers, spaces, hyphens, apostrophes, periods, commas, underscores
    for (char c : name) {
        // Check if character is valid
        bool isValid = (c >= 'A' && c <= 'Z') ||
                       (c >= 'a' && c <= 'z') ||
                       (c >= '0' && c <= '9') ||
                       c == ' ' ||
                       c == '-' ||
                       c == '_' ||
                       c == '.' ||
                       c == ',' ||
                       c == ';' ||
                       c == ':' ||
                       c == '(' ||
                       c == ')';
        
        if (!isValid) {
            return false;  // Invalid character found
        }
    }
    return true;  // All characters are valid
}

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
    if (id <= 0) {
        cout << "Error: Team ID must be positive.\n";
        return;
    }
    if (id > 99999) {
        cout << "Error: Team ID too large (max 99999).\n";
        return;
    }
    if (name.empty()) {
        cout << "Error: Team name cannot be empty.\n";
        return;
    }
    if (name.length() >= 40) {
        cout << "Error: Team name too long (max 39 characters).\n";
        return;
    }
    if (name.find('|') != string::npos) {
        cout << "Error: Team name cannot contain '|' character.\n";
        return;
    }
    if (!isValidName(name)) {
        cout << "Error: Team name contains invalid characters. Use letters, numbers, spaces, or basic punctuation.\n";
        return;
    }
    // ===== END VALIDATION =====
    
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

    cout << "Mission points recorded.\n";
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

    // Sort before displaying
    sortLeaderboard();

    cout << "\n";  // Add blank line before leaderboard
    
    for (int i = 0; i < teamSize; i++) {
        cout << teams[i].id << "|" 
             << teams[i].name << "|" 
             << teams[i].score << "|" 
             << teams[i].missions << "\n";
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

    int id, score, missions;
    char name[40];
    int lineNum = 0;

    while (fscanf(file, "%d|%39[^|]|%d|%d\n", &id, name, &score, &missions) == 4) {
        lineNum++;
        bool valid = true;
        
        if (id <= 0) {
            cout << "Line " << lineNum << ": Rejected - ID must be positive\n";
            valid = false;
        }
        if (id > 99999) {
            cout << "Line " << lineNum << ": Rejected - ID too large (max 99999)\n";
            valid = false;
        }
        if (strlen(name) == 0) {
            cout << "Line " << lineNum << ": Rejected - Name cannot be empty\n";
            valid = false;
        }
        if (strlen(name) >= 40) {
            cout << "Line " << lineNum << ": Rejected - Name too long\n";
            valid = false;
        }
        if (strchr(name, '|') != NULL) {
            cout << "Line " << lineNum << ": Rejected - Name cannot contain '|'\n";
            valid = false;
        }
        
        // Check for invalid characters in name
        string nameStr(name);
        if (!isValidName(nameStr)) {
            cout << "Line " << lineNum << ": Rejected - Name contains invalid characters\n";
            valid = false;
        }
        
        if (score < 0) {
            cout << "Line " << lineNum << ": Rejected - Score cannot be negative\n";
            valid = false;
        }
        if (missions < 0) {
            cout << "Line " << lineNum << ": Rejected - Missions cannot be negative\n";
            valid = false;
        }
        if (valid && findTeamIndex(id) != -1) {
            cout << "Line " << lineNum << ": Rejected - Duplicate ID " << id << "\n";
            valid = false;
        }
        
        // Only commit if valid
        if (valid) {
            if (!ensureCapacity(&teams, &capacity, teamSize + 1)) {
                break;
            }
            teams[teamSize].id = id;
            strncpy(teams[teamSize].name, name, sizeof(teams[teamSize].name) - 1);
            teams[teamSize].name[sizeof(teams[teamSize].name) - 1] = '\0';
            teams[teamSize].score = score;
            teams[teamSize].missions = missions;
            teamSize++;
        }
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

        string choiceInput;
        getline(cin >> ws, choiceInput);

        try {
            size_t pos;
            choice = stoi(choiceInput, &pos);

            if (pos != choiceInput.length()) {
                cout << "Invalid choice. Please enter 1-6.\n";
                choice = 0;
                continue;
            }
        }
        catch (...) {
            cout << "Invalid choice. Please enter 1-6.\n";
            choice = 0;
            continue;
        }

        if (choice == 1) {

            int id;
            string name;

           cout << "Enter team ID: ";

            string idInput;
            getline(cin >> ws, idInput);

            try {
                size_t pos;
                id = stoi(idInput, &pos);

                if (pos != idInput.length()) {
                    cout << "Error: Team ID must be a whole number.\n";
                    continue;
                }
            }
            catch (...) {
                cout << "Error: Team ID must be a valid number.\n";
                continue;
            }

            cout << "Enter team name: ";
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
