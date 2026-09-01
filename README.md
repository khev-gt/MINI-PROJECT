# Campus Mission Tracker

A C++ console-based team management and mission tracking system.

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Project Objectives](#project-objectives)
3. [Main Features](#main-features)
4. [System Menu](#system-menu)
5. [Team Data Structure](#team-data-structure)
6. [Team Registration](#team-registration)
7. [Mission Point Recording](#mission-point-recording)
8. [Find a Team](#find-a-team)
9. [Remove a Team](#remove-a-team)
10. [Leaderboard](#leaderboard)
11. [Team Profile](#team-profile)
12. [Input Validation](#input-validation)
13. [Dynamic Memory Management](#dynamic-memory-management)
14. [File Handling](#file-handling)
15. [Data Format](#data-format)
16. [Program Flow](#program-flow)
17. [Project Structure](#project-structure)
18. [Example Usage](#example-usage)
19. [Example Leaderboard](#example-leaderboard)
20. [Example Team Profile](#example-team-profile)
21. [Testing](#testing)
22. [How to Compile and Run](#how-to-compile-and-run)
23. [Team Members and Roles](#team-members-and-roles)
24. [Programming Concepts Demonstrated](#programming-concepts-demonstrated)
25. [Current Project Status](#current-project-status)
26. [Future Improvements](#future-improvements)
27. [Conclusion](#conclusion)

---

## Project Overview

**Campus Mission Tracker** is a C++ console-based team management and mission tracking system.

The system is designed to manage teams participating in campus missions or activities. Users can register teams, record mission points, search for teams, remove teams, view a sorted leaderboard, and save the data to a file.

The project uses a menu-driven interface so users can easily select the operation they want to perform.

The system also includes input validation, dynamic memory management, file handling, sorting, searching, and structured data management.

---

## Project Objectives

The main objectives of the Campus Mission Tracker are:

- Manage multiple teams in one system.
- Register new teams with unique team IDs.
- Store team names, scores, and mission counts.
- Record mission points for registered teams.
- Search for a specific team using its ID.
- Remove teams from the system.
- Sort teams based on their total score.
- Display a formatted leaderboard.
- Display a detailed team profile.
- Save team data to a file.
- Load previously saved data when the program starts.
- Validate user input and reject invalid data.
- Demonstrate dynamic memory allocation and memory cleanup.
- Apply fundamental C++ programming concepts in a practical project.

---

## Main Features

### 1. Register a Team

Users can register a new team by entering:

- Team ID
- Team Name

The system checks that:

- The ID is positive.
- The ID does not exceed `99999`.
- The team name is not empty.
- The team name is no longer than 39 characters.
- The team name does not contain the `|` character.
- The team name contains only accepted characters.
- The team ID is not already used.

A newly registered team starts with:

- Score: `0`
- Missions: `0`

---

### 2. Record Mission Points

Users can add mission points to an existing team.

The system asks for:

- Team ID
- Mission points

Mission points must be between:

```text
1 - 100

When valid points are entered:

The team's total score increases.
The team's mission count increases by 1.

Example:

Current Score: 50
Mission Points: 30

New Score: 80
Missions: +1
3. Find a Team

Users can search for a team by entering its Team ID.

If the team exists, the system displays a formatted Team Profile containing:

Team ID
Team Name
Total Score
Missions
Status

Example:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================

If the team does not exist, the system displays:

Team not found.
4. Remove a Team

Users can remove an existing team by entering its Team ID.

If the team exists:

Team removed.

If the team does not exist:

Team not found.

When a team is removed, the remaining team records are shifted so that the data remains organized.

5. Show Leaderboard

The leaderboard displays all registered teams ranked by their total score.

The team with the highest score appears first.

The leaderboard displays:

Rank
Team ID
Team Name
Score
Missions
Total number of teams

Example:

==============================================================
                     LEADERBOARD
==============================================================
Rank     ID       Team Name              Score    Missions
--------------------------------------------------------------
1        101      team 1                 99       1
2        102      team 2                 80       1
3        103      team 3                 50       1
==============================================================
 Total Teams: 3
==============================================================

If there are no registered teams, the system displays:

No teams registered yet.
6. Save and Exit

The system saves the current team information into:

teams.txt

After successfully selecting option 6, the program displays:

Data saved. Goodbye!

Before the program terminates, allocated memory is also released.

System Menu

When the program starts, the main menu is displayed:

===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:
Menu Options
Option	Operation	Description
1	Register a team	Add a new team
2	Record mission points	Add mission points to a team
3	Find a team	Search and display team information
4	Remove a team	Delete a team
5	Show leaderboard	Display teams ranked by score
6	Save and exit	Save data and close the program
Team Data Structure

The program uses a Team structure to store team information.

typedef struct {
    int id;
    char name[40];
    int score;
    int missions;
} Team;

Each team contains four main pieces of information:

ID
int id;

Stores the unique team ID.

Name
char name[40];

Stores the team name.

The program reserves 40 characters for the name, including the terminating null character.

Score
int score;

Stores the team's total mission score.

Missions
int missions;

Stores the number of missions completed or recorded.

Team Registration

The registration process is handled by:

addTeam(int id, string name)

The function performs several validation checks before adding a team.

Registration process
Enter Team ID
       ↓
Validate ID
       ↓
Enter Team Name
       ↓
Validate Name
       ↓
Check Duplicate ID
       ↓
Ensure Memory Capacity
       ↓
Create Team
       ↓
Set Score = 0
       ↓
Set Missions = 0
       ↓
Register Successfully

A team cannot be registered if its ID already exists.

Mission Point Recording

Mission points are handled by:

recordMission(int id, int points)

The system first searches for the team.

If the team exists, the points are validated.

Valid points must satisfy:

1 <= points <= 100

After successful validation:

teams[index].score += points;
teams[index].missions++;

Therefore, both the score and mission count are updated.

Find a Team

The system searches for teams using:

findTeamIndex(int id)

The function checks each team until it finds a matching ID.

If a matching team is found, the function returns its array index.

If no team is found:

return -1;

The main program then displays:

Team not found.
Remove a Team

Team deletion is handled by:

deleteTeam(int id)

First, the system searches for the team.

After finding the team, the records after it are shifted one position to the left.

Conceptually:

Before:

[Team A] [Team B] [Team C] [Team D]

Remove Team B

After:

[Team A] [Team C] [Team D]

The variable teamSize is then reduced by one.

Leaderboard

The leaderboard is sorted using:

sortLeaderboard()

The system compares team scores and moves the team with the higher score toward the beginning.

The sorting process uses nested loops and swaps adjacent Team records.

The comparison is:

if (teams[j].score < teams[j + 1].score)

Therefore, the leaderboard is arranged in:

Highest Score
      ↓
Lower Score
      ↓
Lowest Score

The leaderboard is displayed through:

displayTeams()

The display includes a formatted header, ranking, team information, and total team count.

Team Profile

The Find Team feature provides a detailed profile for an individual team.

The current profile format is:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
Profile Information
Field	Meaning
Team ID	Unique identifier of the team
Team Name	Registered team name
Total Score	Total mission points earned
Missions	Number of recorded missions
Status	Current display status

The current system displays:

Status : ACTIVE

when a registered team is found.

Input Validation

Input validation is an important part of the system.

The program validates menu choices, team IDs, team names, mission points, and loaded file data.

Menu Validation

The menu accepts choices from:

1 - 6

Invalid input produces:

Invalid choice. Please enter 1-6.
Team ID Validation

The Team ID must:

Be a whole number.
Be greater than 0.
Be no greater than 99999.
Be unique.

Examples of invalid conditions:

ID <= 0
ID > 99999
Duplicate ID
Non-numeric ID
Team Name Validation

The team name:

Cannot be empty.
Must be shorter than 40 characters.
Cannot contain |.
Must contain accepted characters.

Accepted characters include:

Letters
Numbers
Spaces
Hyphens
Underscores
Periods
Commas
Semicolons
Colons
Parentheses
Mission Point Validation

Mission points must be:

1 - 100

Invalid input produces:

Invalid points. Enter 1-100.
Dynamic Memory Management

The project demonstrates dynamic memory management using:

Team *teams = NULL;

The system does not rely on a fixed-size team array.

Instead, memory is dynamically allocated and expanded when more space is required.

The main function responsible for this is:

ensureCapacity()
Capacity Management

The initial capacity is:

0

When the first team is added, the capacity becomes:

2

When the current capacity is not enough, it is doubled.

Example:

0
 ↓
2
 ↓
4
 ↓
8
 ↓
16
 ↓
32

This allows the system to support a changing number of teams without defining a fixed maximum team count in the program.

Reallocation

The program uses:

realloc()

to increase the memory area when necessary.

If memory allocation fails, the program displays:

Memory allocation failed.
Memory Cleanup

Before the program terminates, the allocated memory is released using:

cleanup(&teams, &teamSize, &capacity);

Inside the cleanup function:

free(*teams_ptr);

The pointer is then reset to:

NULL

and the size and capacity are reset to zero.

This prevents allocated memory from remaining unnecessarily after the program finishes.

File Handling

The system uses a text file named:

teams.txt

The file is used for persistent storage.

This means that team information can remain available after the program is closed and restarted.

Loading Data

When the program starts, it calls:

loadTeams();

The function attempts to open:

teams.txt

in read mode.

If the file exists, the saved team records are loaded into memory.

Each loaded record is validated before it is accepted.

Invalid records are rejected.

Saving Data

When the user selects:

6. Save and exit

the program calls:

saveTeams();

The team information is written to:

teams.txt

The saved information includes:

Team ID
Team Name
Score
Missions
Data Format

Each team is stored in teams.txt using the following format:

ID|TeamName|Score|Missions

Example:

101|team 1|99|1
102|team 2|80|1
103|team 3|50|1

The | character separates the four fields.

Therefore, team names are not allowed to contain:

|

This prevents the stored file format from becoming ambiguous.

Program Flow

The overall program works as follows:

START
  |
  v
Load teams.txt
  |
  v
Display Main Menu
  |
  +----> 1. Register Team
  |          |
  |          v
  |       Validate Input
  |          |
  |          v
  |       Add Team
  |
  +----> 2. Record Mission Points
  |          |
  |          v
  |       Find Team
  |          |
  |          v
  |       Validate Points
  |          |
  |          v
  |       Update Score/Missions
  |
  +----> 3. Find Team
  |          |
  |          v
  |       Display Team Profile
  |
  +----> 4. Remove Team
  |          |
  |          v
  |       Find and Delete Team
  |
  +----> 5. Show Leaderboard
  |          |
  |          v
  |       Sort by Score
  |          |
  |          v
  |       Display Leaderboard
  |
  +----> 6. Save and Exit
             |
             v
         Save teams.txt
             |
             v
         Free Memory
             |
             v
            END
Project Structure

The project contains the following important files:

MINI-PROJECT/
│
├── main.cpp
├── teams.txt
├── test-evidence.md
└── README.md
main.cpp

Contains the complete C++ implementation of the Campus Mission Tracker.

It includes:

Team structure
Dynamic memory management
Team registration
Mission recording
Team searching
Team deletion
Leaderboard sorting
Leaderboard display
File loading
File saving
Main menu
Input validation
Memory cleanup
teams.txt

Stores persistent team data.

Example:

101|team 1|99|1
102|team 2|80|1
103|team 3|50|1
test-evidence.md

Contains project testing evidence and records related to system verification.

README.md

Contains project documentation, system explanation, features, instructions, testing information, and project status.

Example Usage
Step 1 — Start the Program

The program displays:

===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:
Step 2 — Register a Team

Select:

1

Enter:

Enter team ID: 101
Enter team name: team 1

The system registers the team.

Initial information:

ID: 101
Name: team 1
Score: 0
Missions: 0
Step 3 — Record Mission Points

Select:

2

Enter:

Enter team ID: 101
Enter mission points earned (1-100): 99

The team becomes:

Score: 99
Missions: 1
Step 4 — Find the Team

Select:

3

Enter:

Enter team ID: 101

The system displays:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
Step 5 — View Leaderboard

Select:

5

The system sorts the teams by score and displays the leaderboard.

Step 6 — Save and Exit

Select:

6

The program saves the current data to:

teams.txt

and displays:

Data saved. Goodbye!
Example Leaderboard

For three teams, the leaderboard can look like:

==============================================================
                     LEADERBOARD
==============================================================
Rank     ID       Team Name              Score    Missions
--------------------------------------------------------------
1        101      team 1                 99       1
2        102      team 2                 80       1
3        103      team 3                 50       1
==============================================================
 Total Teams: 3
==============================================================

The ranking is based on total score.

Example Team Profile

When a valid team ID is found:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================

When an invalid or unknown ID is entered:

Team not found.
Testing

The system should be tested using both valid and invalid inputs.

Test Case 1 — Register Valid Team

Input:

ID: 101
Name: team 1

Expected result:

Team registered successfully.
Test Case 2 — Duplicate Team ID

Input:

ID: 101

when ID 101 already exists.

Expected result:

Team ID already exists.
Test Case 3 — Invalid Team ID

Input:

-1

Expected result:

Error: Team ID must be positive.
Test Case 4 — Team ID Too Large

Input:

100000

Expected result:

Error: Team ID too large (max 99999).
Test Case 5 — Invalid Mission Points

Input:

0

or:

101

Expected result:

Invalid points. Enter 1-100.
Test Case 6 — Find Existing Team

Input:

101

Expected result:

TEAM PROFILE

with the team's ID, name, score, missions, and status.

Test Case 7 — Find Non-existing Team

Input:

999

Expected result:

Team not found.
Test Case 8 — Remove Existing Team

Input:

101

Expected result:

Team removed.
Test Case 9 — Remove Non-existing Team

Input:

999

Expected result:

Team not found.
Test Case 10 — Leaderboard

Register multiple teams with different scores.

Expected result:

Highest score appears first.
Lower scores appear below.
Rank numbers are displayed.
Total team count is displayed.
Test Case 11 — Save Data

Select:

6

Expected result:

Data saved. Goodbye!

The information should be written to:

teams.txt
Test Case 12 — Load Saved Data

Run the program again after saving.

Expected result:

Previously saved teams are loaded.
Their scores remain available.
Their mission counts remain available.
How to Compile and Run
Requirements

You need:

A C++ compiler
Windows PowerShell or Command Prompt
The project files

A compiler such as g++ can be used.

Compile

Open PowerShell inside the project folder:

MINI-PROJECT

Run:

g++ main.cpp -o main

If there are no compilation errors, an executable named:

main.exe

will be created.

Run the Program

Run:

.\main.exe

The Campus Mission Tracker menu should appear.

Compile and Run Again After Changes

Whenever main.cpp is modified:

g++ main.cpp -o main

Then:

.\main.exe
Team Members and Roles

The project team consists of five members.

1. Long Thina

Role: Test Captain

Responsibilities include:

Testing system functionality.
Checking valid and invalid inputs.
Verifying expected outputs.
Recording testing evidence.
2. Kheng Khevin

Role: Integration Captain

Responsibilities include:

Integrating different parts of the project.
Coordinating project changes.
Helping maintain the project repository.
Ensuring different components work together.
3. Chheng Longheng

Role: Memory Guardian

Responsibilities include:

Managing dynamic memory.
Working with team storage.
Checking memory allocation.
Checking memory cleanup.
Maintaining ensureCapacity().
Maintaining cleanup().
4. Leng Sakda

Role: UX

Responsibilities include:

Designing the console interface.
Improving menu presentation.
Improving Team Profile presentation.
Improving Leaderboard presentation.
Making system output easier to understand.
5. Lim Chanmonyroth

Role: Record Architecture

Responsibilities include:

Working with team records.
Supporting data organization.
Working with data storage and retrieval.
Supporting the teams.txt structure.
Programming Concepts Demonstrated

This project demonstrates several important programming concepts.

1. Structures

The project uses:

typedef struct {
    int id;
    char name[40];
    int score;
    int missions;
} Team;

This groups related information into one data structure.

2. Functions

The project is divided into multiple functions, including:

UX()
ensureCapacity()
cleanup()
findTeamIndex()
addTeam()
recordMission()
deleteTeam()
sortLeaderboard()
displayTeams()
loadTeams()
saveTeams()

Using functions makes the program easier to organize and maintain.

3. Dynamic Memory

The project uses:

malloc/realloc/free

through the C standard library functions used in the program.

Dynamic memory allows the team storage capacity to grow when more teams are registered.

4. Searching

The function:

findTeamIndex()

searches for a team by its ID.

5. Sorting

The function:

sortLeaderboard()

sorts teams according to their score.

The implementation uses nested loops and record swapping.

6. File Handling

The project uses:

fopen()
fscanf()
fprintf()
fclose()

to read and write persistent team data.

7. Input Validation

The program validates user input before modifying system data.

This reduces the possibility of invalid team records or invalid scores being stored.

8. String Handling

The program uses string and C-string operations such as:

string
strlen()
strncpy()
strchr()

to process and validate team names.

9. Exception Handling for Numeric Input

The program uses:

stoi()

together with exception handling to safely process numeric input entered as strings.

This helps detect invalid numeric input such as letters or incomplete numeric values.

System Architecture

The program can be viewed as several logical components.

                 CAMPUS MISSION TRACKER
                          |
          +---------------+---------------+
          |               |               |
          v               v               v
      User Input      Team Management   File Storage
          |               |               |
          |          +----+----+          |
          |          |    |    |          |
          v          v    v    v          v
       Menu       Add  Find Delete     teams.txt
                    |
                    v
              Mission Records
                    |
                    v
              Score Updates
                    |
                    v
               Leaderboard
                    |
                    v
              Sorted Display
Data Lifecycle

The system follows this general data lifecycle:

teams.txt
    |
    v
loadTeams()
    |
    v
Dynamic Memory
    |
    +---- Register Team
    |
    +---- Record Mission
    |
    +---- Find Team
    |
    +---- Remove Team
    |
    +---- Sort Leaderboard
    |
    v
saveTeams()
    |
    v
teams.txt

This allows information to remain available between program executions.

Error Handling

The system provides messages when an operation cannot be completed.

Examples include:

Invalid choice. Please enter 1-6.
Error: Team ID must be a valid number.
Error: Team ID must be a whole number.
Error: Team ID must be positive.
Error: Team ID too large (max 99999).
Error: Team name cannot be empty.
Error: Team name too long (max 39 characters).
Error: Team name cannot contain '|' character.
Team ID already exists.
Team not found.
Invalid points. Enter 1-100.
Memory allocation failed.
Could not save teams.

These messages help users understand what went wrong and how the input should be corrected.

User Experience Improvements

The console interface was improved to make important information easier to read.

Team Profile

Instead of displaying plain lines such as:

Team found:
ID: 101
Name: team 1
Score: 99
Missions: 1

the current system uses a formatted profile:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
Leaderboard

The leaderboard uses borders and aligned columns:

==============================================================
                     LEADERBOARD
==============================================================
Rank     ID       Team Name              Score    Missions
--------------------------------------------------------------
1        101      team 1                 99       1
2        102      team 2                 80       1
3        103      team 3                 50       1
==============================================================
 Total Teams: 3
==============================================================

This makes the ranking information easier to read during a demonstration.

Current Project Status

The current project includes:

Team registration
Team ID validation
Team name validation
Duplicate ID checking
Mission point recording
Mission point validation
Team searching
Team Profile display
Team deletion
Leaderboard sorting
Formatted Leaderboard display
Dynamic team storage
Dynamic capacity expansion
Memory cleanup
File loading
File saving
Persistent team data
Menu input validation
Error handling
Testing documentation
Project documentation

The system has been tested using multiple normal and invalid input scenarios.

Project Demonstration Checklist

Before demonstrating the project, check the following:

Basic Functions
 Program starts successfully.
 Main menu is displayed.
 Team can be registered.
 Duplicate IDs are rejected.
 Mission points can be recorded.
 Team can be found.
 Team Profile is displayed correctly.
 Team can be removed.
 Leaderboard is displayed.
 Leaderboard ranks teams by score.
 Data can be saved.
 Data can be loaded again.
Validation
 Invalid menu input is handled.
 Invalid Team ID is handled.
 Duplicate Team ID is handled.
 Invalid Team Name is handled.
 Invalid mission points are handled.
 Non-existing team searches are handled.
 Non-existing team deletion is handled.
Documentation
 README is updated.
 Test evidence is available.
 Source code is committed.
 GitHub repository is synchronized.
Future Improvements

Possible future improvements include:

Add user login and authentication.
Add different user roles such as administrator and normal user.
Add confirmation before deleting a team.
Add sorting by both score and mission count.
Add search by team name.
Add more detailed team statistics.
Add mission history instead of only storing the total score.
Add date and time information for missions.
Add export functionality to CSV.
Improve the console interface with colors.
Add a graphical user interface.
Add automated unit testing.
Improve file recovery and backup handling.
Add stronger data validation.
Add more detailed reporting features.
Conclusion

The Campus Mission Tracker demonstrates how C++ programming concepts can be combined to build a practical team management system.

The project provides a complete workflow for:

Register Team
      ↓
Record Mission
      ↓
Update Score
      ↓
Find Team
      ↓
View Team Profile
      ↓
Rank Teams
      ↓
View Leaderboard
      ↓
Save Data

The project demonstrates the use of:

Structures
Functions
Dynamic memory
Searching
Sorting
File handling
String processing
Input validation
Exception handling
Memory cleanup

The formatted Team Profile and Leaderboard also provide a clearer user experience for demonstrations.

GitHub Repository

Project repository:

https://github.com/khev-gt/MINI-PROJECT
Final Project Status
==============================================================
                 CAMPUS MISSION TRACKER
==============================================================

System Status : COMPLETED
Language      : C++
Interface     : Console
Data Storage  : teams.txt
Team Storage  : Dynamic Memory
Leaderboard   : Implemented
Team Profile  : Implemented
Validation    : Implemented
File Handling : Implemented
Testing       : Completed
Documentation : Completed

==============================================================

Campus Mission Tracker — C++ Team Management and Mission Tracking System