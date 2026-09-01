<<<<<<< HEAD
=======
`# Campus Mission Tracker` to the very end.**

````markdown
>>>>>>> e4927b5 (Update README documentation)
# Campus Mission Tracker

## Project Overview

**Campus Mission Tracker** is a C++ console-based team management system designed to manage teams participating in campus missions.

The system allows users to register teams, record mission points, search for teams, remove teams, display a ranked leaderboard, and save team information for future use.

The project was developed as a practical C++ programming project to demonstrate how different programming concepts can be combined to create a functional management system.

The system uses a simple menu-driven interface so users can easily select the operation they want to perform.

---

# Project Objectives

The main objectives of the Campus Mission Tracker are:

1. Register and manage campus mission teams.
2. Store important information about each team.
3. Record points earned from completed missions.
4. Keep track of the total score of each team.
5. Keep track of the number of missions recorded for each team.
6. Search for a specific team using its Team ID.
7. Display individual team information using a clear Team Profile.
8. Remove teams when necessary.
9. Sort teams according to their total score.
10. Display teams using a ranked leaderboard.
11. Save team information into a file.
12. Load previously saved team information.
13. Validate user input.
14. Handle invalid input safely.
15. Demonstrate dynamic memory management.
16. Demonstrate file input/output.
17. Practice Git and GitHub version control.

---

# Main Features

The Campus Mission Tracker contains six main operations:

| Option | Feature | Description |
|---|---|---|
| 1 | Register a Team | Creates and stores a new team |
| 2 | Record Mission Points | Adds mission points to an existing team |
| 3 | Find a Team | Searches for a team and displays its Team Profile |
| 4 | Remove a Team | Removes an existing team |
| 5 | Show Leaderboard | Displays all teams ranked by score |
| 6 | Save and Exit | Saves the current data and exits the program |

Additional system features include:

- Input validation
- Error handling
- Team searching
- Team sorting
- Dynamic memory allocation
- File loading
- File saving
- Memory cleanup
- Formatted console output
- Git/GitHub version control

---

# System Requirements

To compile and run the project, the following are recommended:

- Windows, Linux, or another operating system supporting C++
- C++ compiler
- GCC / MinGW
- PowerShell, Command Prompt, or another terminal
- Git for version control
- Visual Studio Code or another C++ code editor

---

# Project Structure

```text
MINI-PROJECT/
│
├── main.cpp
├── teams.txt
├── README.md
└── .gitignore
````

## File Description

| File         | Purpose                                                        |
| ------------ | -------------------------------------------------------------- |
| `main.cpp`   | Main C++ source code for the complete system                   |
| `teams.txt`  | Stores saved team information                                  |
| `README.md`  | Project documentation                                          |
| `.gitignore` | Prevents unnecessary build and backup files from being tracked |

Compiled executable files and backup files are intentionally ignored by Git.

---

# Getting the Project

## Using Git

If Git is installed, open PowerShell or Command Prompt and run:

```text
git clone https://github.com/khev-gt/MINI-PROJECT.git
```

Then enter the project directory:

```text
cd MINI-PROJECT
```

---

# Downloading the Project from GitHub

The project can also be downloaded as a ZIP file.

### Steps

1. Open the GitHub repository.
2. Click the **Code** button.
3. Select **Download ZIP**.
4. Extract the ZIP file.
5. Open the extracted `MINI-PROJECT` folder.
6. Open PowerShell or Command Prompt in the project folder.

---

# How to Compile the Program

Open PowerShell inside the project directory.

Example:

```text
PS C:\Users\CTT\MINI-PROJECT>
```

Compile the program using:

```text
g++ main.cpp -o integration.exe
```

### Explanation

* `g++` is the C++ compiler.
* `main.cpp` is the source code.
* `-o` specifies the output executable.
* `integration.exe` is the executable file created by the compiler.

If there are no compiler errors, the executable will be created.

Example:

```text
PS C:\Users\CTT\MINI-PROJECT> g++ main.cpp -o integration.exe
```

---

# How to Run the Program

After compiling, run the program using:

```text
.\integration.exe
```

Example:

```text
PS C:\Users\CTT\MINI-PROJECT> .\integration.exe
```

The program will display the main menu.

---

# Main Menu

The Campus Mission Tracker displays:

```text
===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:
```

The user can select an operation by entering a number from `1` to `6`.

---

# Option 1 — Register a Team

## Purpose

Option `1` is used to register a new team.

The user provides:

1. Team ID
2. Team Name

After the information is entered successfully, the system stores the team.

---

## Example

```text
Enter your choice: 1
Enter team ID: 101
Enter team name: team 1
Team registered successfully.
```

The team is now stored in the system.

A newly registered team starts with its initial score and mission count.

Example:

```text
Team ID: 101
Team Name: team 1
Score: 0
Missions: 0
```

Mission points can later be added using Option `2`.

---

# Team ID

The Team ID is used to identify a team.

Example Team IDs:

```text
101
102
103
104
```

The Team ID must be entered as a valid whole number.

The Team ID is important because the system uses it when:

* Finding a team
* Recording mission points
* Removing a team

---

# Team Name

The user must provide a team name when registering a team.

Examples:

```text
team 1
team 2
Campus Warriors
Mission Squad
```

The team name is stored together with the Team ID.

---

# Option 2 — Record Mission Points

## Purpose

Option `2` is used to record points earned by a team after completing a mission.

The user enters:

1. Team ID
2. Mission points

The entered points are added to the team's existing total score.

The mission count is also increased by `1`.

---

## Example

Suppose Team `101` currently has:

```text
Score: 49
Missions: 0
```

The user enters:

```text
Enter your choice: 2
Enter team ID: 101
Enter mission points earned (1-100): 50
```

The system adds `50` points.

The team now has:

```text
Score: 99
Missions: 1
```

---

# Mission Point Validation

Mission points must be between:

```text
1-100
```

### Valid examples

```text
1
10
25
50
75
99
100
```

### Invalid examples

```text
0
101
-5
abc
```

If an invalid value is entered, the system displays:

```text
Invalid points. Enter 1-100.
```

The invalid value is not recorded.

---

# Recording Multiple Missions

A team can complete multiple missions.

For example:

```text
Mission 1 → 50 points
Mission 2 → 30 points
Mission 3 → 20 points
```

The team will have:

```text
Total Score: 100
Missions: 3
```

The score represents the accumulated points from all recorded missions.

---

# Team Not Found During Mission Recording

If the user enters a Team ID that does not exist:

```text
Enter team ID: 999
Team not found.
```

The system does not record the mission points.

This prevents points from being assigned to a team that is not registered.

---

# Option 3 — Find a Team

## Purpose

Option `3` is used to search for a specific team using its Team ID.

The current system uses a formatted **TEAM PROFILE** display instead of the previous simple text output.

This makes the information easier to read and gives the search function a more professional presentation.

---

# Steps to Find a Team

### Step 1

Select Option `3`:

```text
Enter your choice: 3
```

### Step 2

Enter the Team ID:

```text
Enter team ID: 101
```

### Step 3

If the team exists, the system displays the Team Profile.

---

# Team Profile

The current Team Profile overlay is:

```text
========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
```

---

# Team Profile Fields

The Team Profile contains:

| Field       | Meaning                                  |
| ----------- | ---------------------------------------- |
| Team ID     | Unique identification number of the team |
| Team Name   | Name of the team                         |
| Total Score | Total points earned by the team          |
| Missions    | Number of missions recorded              |
| Status      | Current display status of the team       |

The current profile displays:

```text
Status       : ACTIVE
```

when the team is successfully found.

---

# Team Not Found

If the user searches for a Team ID that does not exist:

```text
Enter your choice: 3
Enter team ID: 999
Team not found.
```

The system does not display an empty Team Profile.

This gives the user clear feedback that the requested team does not exist.

---

# Option 4 — Remove a Team

## Purpose

Option `4` allows the user to remove a registered team from the system.

The user only needs to provide the Team ID.

---

# Steps to Remove a Team

### Step 1

Select Option `4`:

```text
Enter your choice: 4
```

### Step 2

Enter the Team ID:

```text
Enter team ID: 104
```

### Step 3

If the team exists, it is removed.

The system displays:

```text
Team removed.
```

---

# Removing a Non-Existing Team

If the Team ID does not exist:

```text
Enter team ID: 999
Team not found.
```

No team is removed.

This prevents accidental removal of an unrelated team.

---

# Option 5 — Show Leaderboard

## Purpose

Option `5` displays all registered teams in ranked order.

Before displaying the leaderboard, the system sorts the teams according to their total score.

The team with the highest score receives Rank `1`.

---

# Leaderboard Design

The current system uses the following formatted leaderboard overlay:

```text
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
```

This design makes the leaderboard easier to read and gives the program a clearer console interface.

---

# Leaderboard Columns

The leaderboard contains five main columns.

| Column    | Description                           |
| --------- | ------------------------------------- |
| Rank      | Position of the team                  |
| ID        | Team ID                               |
| Team Name | Name of the team                      |
| Score     | Total mission score                   |
| Missions  | Number of completed/recorded missions |

At the bottom, the system also displays:

```text
Total Teams: 3
```

This shows the number of teams currently registered.

---

# Leaderboard Ranking

The leaderboard is sorted by score.

For example, suppose the system contains:

```text
Team A → 95
Team B → 80
Team C → 50
```

The leaderboard will display:

```text
Rank 1 → Team A → 95
Rank 2 → Team B → 80
Rank 3 → Team C → 50
```

The highest score appears first.

---

# Leaderboard Updates

The leaderboard changes automatically when team information changes.

For example, if Team `103` receives additional points and its score becomes higher than Team `101`, the next leaderboard display will reflect the new ranking.

Similarly, when a team is removed, it will no longer appear in the leaderboard.

This means the leaderboard represents the current state of the team data.

---

# Option 6 — Save and Exit

## Purpose

Option `6` saves the current team information and exits the program.

The user selects:

```text
Enter your choice: 6
```

The system saves the current data and displays:

```text
Data saved. Goodbye!
```

---

# Why Data Saving Is Important

Team information is stored in memory while the program is running.

If the program closes without saving, changes made during the current session could be lost.

The system therefore provides a save operation that writes the current information to:

```text
teams.txt
```

This allows information to be preserved between program sessions.

---

# File Loading

When the program starts, it attempts to load previously saved team information from:

```text
teams.txt
```

This allows previously registered teams to remain available after restarting the program.

---

# File Storage

The project uses:

```text
teams.txt
```

to store team information.

A team record contains information such as:

```text
Team ID
Team Name
Score
Missions
```

The data is stored so that it can be loaded again when the program starts.

---

# Example Team Data

A team record can be represented in the following format:

```text
101|team 1|99|1
```

The fields represent:

```text
101    → Team ID
team 1 → Team Name
99     → Total Score
1      → Missions
```

The `|` character separates the individual fields.

---

# Input Validation

Input validation is used throughout the system to prevent invalid data from being processed.

The system validates:

* Menu choices
* Team IDs
* Mission points
* Existing team IDs

---

# Menu Validation

The valid menu choices are:

```text
1
2
3
4
5
6
```

If the user enters:

```text
7
```

the system displays:

```text
Invalid choice. Please enter 1-6.
```

The user must then enter a valid option.

---

# Invalid Menu Input

If the user enters text instead of a number:

```text
Enter your choice: abc
```

the system handles the invalid input and displays an appropriate error message.

This prevents invalid menu input from causing the program to behave incorrectly.

---

# Team ID Validation

Team IDs must be valid whole numbers.

Valid examples:

```text
101
102
500
1000
```

Invalid examples:

```text
abc
10.5
hello
```

The program checks the input before using it.

Possible validation messages include:

```text
Error: Team ID must be a whole number.
```

and:

```text
Error: Team ID must be a valid number.
```

---

# Team Existence Validation

Before operations such as finding, recording points, or removing a team, the program checks whether the Team ID exists.

If the ID does not exist:

```text
Team not found.
```

This prevents the system from performing operations on an invalid team.

---

# Searching

The system uses the Team ID to search for teams.

Searching is required when:

* Recording mission points
* Finding a team
* Removing a team

The system checks the stored teams and finds the team whose ID matches the user's input.

If a match is found, the requested operation is performed.

If no match is found:

```text
Team not found.
```

is displayed.

---

# Sorting and Ranking

Sorting is used by the leaderboard.

When Option `5` is selected, the system sorts the teams according to their total score before displaying them.

The highest score is displayed first.

For example:

```text
Team 1 → 99
Team 2 → 80
Team 3 → 50
```

becomes:

```text
1 → Team 1 → 99
2 → Team 2 → 80
3 → Team 3 → 50
```

The displayed rank is based on the sorted order.

---

# Dynamic Memory Management

The project demonstrates dynamic memory management for storing team information.

The program maintains the current team storage capacity and can increase the capacity when more storage is required.

This allows the system to handle a growing number of teams.

Dynamic memory management is useful because the program does not need to depend only on a small fixed number of team records.

---

# Memory Capacity

When the existing storage becomes insufficient, the system increases its capacity.

The general process is:

```text
Current Capacity
       |
       v
New Team Required
       |
       v
Check Available Capacity
       |
       +----------------+
       |                |
   Enough Space      Not Enough
       |                |
       v                v
 Continue        Increase Capacity
                       |
                       v
                  Continue
```

This allows the application to support additional teams without manually defining a new fixed-size array.

---

# Memory Cleanup

Dynamically allocated memory must be released when it is no longer required.

The program performs memory cleanup before termination.

Proper memory cleanup helps prevent memory leaks and demonstrates responsible memory management in C++.

---

# Functions

The system is divided into functions so that different tasks can be handled separately.

Examples of functionality include:

* User interface / menu display
* Capacity management
* Team registration
* Team searching
* Mission recording
* Team removal
* Leaderboard sorting
* Team display
* File loading
* File saving

Using functions makes the program easier to read, test, debug, and maintain.

---

# Program Flow

The general program flow is:

```text
START
  |
  v
Load saved team data
  |
  v
Display Main Menu
  |
  +--------------------------+
  |                          |
  v                          v
Register Team          Record Mission
  |                          |
  +-------------+------------+
                |
                v
           Find Team
                |
                v
          Remove Team
                |
                v
          Leaderboard
                |
                v
          Save and Exit
                |
                v
               END
```

The user can repeatedly perform operations and return to the main menu.

The program continues until the user selects:

```text
6. Save and exit
```

---

# Typical User Workflow

A typical user can follow this workflow:

## Step 1 — Register Teams

Use Option `1` to register all participating teams.

Example:

```text
101 → team 1
102 → team 2
103 → team 3
```

---

## Step 2 — Record Missions

When a team completes a mission, use Option `2` to record its points.

Example:

```text
Team 101 → 99 points
Team 102 → 80 points
Team 103 → 50 points
```

---

## Step 3 — Check an Individual Team

Use Option `3` to search for a specific team.

The system displays its Team Profile.

---

## Step 4 — View the Rankings

Use Option `5` to display the leaderboard.

The system automatically sorts the teams according to score.

---

## Step 5 — Remove a Team if Necessary

Use Option `4` if a team needs to be removed.

---

## Step 6 — Save

Use Option `6` to save the current data before exiting.

---

# Complete Example Session

The following example demonstrates a complete system workflow.

## Starting the Program

```text
PS C:\Users\CTT\MINI-PROJECT> .\integration.exe
```

The menu appears:

```text
===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:
```

---

# Registering Teams

Select Option `1`:

```text
Enter your choice: 1
Enter team ID: 101
Enter team name: team 1
Team registered successfully.
```

Register additional teams:

```text
Enter your choice: 1
Enter team ID: 102
Enter team name: team 2
Team registered successfully.
```

```text
Enter your choice: 1
Enter team ID: 103
Enter team name: team 3
Team registered successfully.
```

---

# Recording Mission Points

For Team 101:

```text
Enter your choice: 2
Enter team ID: 101
Enter mission points earned (1-100): 99
```

For Team 102:

```text
Enter your choice: 2
Enter team ID: 102
Enter mission points earned (1-100): 80
```

For Team 103:

```text
Enter your choice: 2
Enter team ID: 103
Enter mission points earned (1-100): 50
```

The teams now have:

```text
Team 101 → Score 99 → Missions 1
Team 102 → Score 80 → Missions 1
Team 103 → Score 50 → Missions 1
```

---

# Find Team Example

Select Option `3`:

```text
Enter your choice: 3
Enter team ID: 101
```

The system displays:

```text
========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
```

---

# Find Non-Existing Team

If the user enters:

```text
Enter your choice: 3
Enter team ID: 999
```

the system displays:

```text
Team not found.
```

---

# Leaderboard Example

Select Option `5`:

```text
Enter your choice: 5
```

The system displays:

```text
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
```

---

# Remove Team Example

Select Option `4`:

```text
Enter your choice: 4
Enter team ID: 103
Team removed.
```

After removal, Team 103 will no longer appear in the leaderboard.

---

# Save and Exit Example

Select Option `6`:

```text
Enter your choice: 6
Data saved. Goodbye!
```

The current team information is saved to `teams.txt`.

---

# Error Handling Examples

## Invalid Menu Choice

Input:

```text
Enter your choice: 9
```

Output:

```text
Invalid choice. Please enter 1-6.
```

---

## Invalid Mission Points

Input:

```text
Enter mission points earned (1-100): 150
```

Output:

```text
Invalid points. Enter 1-100.
```

---

## Non-Existing Team

Input:

```text
Enter team ID: 999
```

Output:

```text
Team not found.
```

---

# Testing

The Campus Mission Tracker has been tested using normal and invalid input cases.

## Functional Tests

The following operations have been tested:

* Registering a team
* Recording mission points
* Finding an existing team
* Displaying the Team Profile
* Searching for a non-existing team
* Removing a team
* Displaying the leaderboard
* Sorting teams by score
* Displaying total team count
* Saving data
* Loading saved data
* Exiting the program

---

# Validation Tests

The following validation cases have been tested:

* Valid menu choices
* Invalid menu choices
* Invalid Team IDs
* Non-existing Team IDs
* Valid mission points
* Mission points below `1`
* Mission points above `100`
* Invalid mission point input

---

# Tested Team Profile Output

The updated Team Profile was tested successfully:

```text
========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
```

---

# Tested Leaderboard Output

The updated leaderboard was tested successfully:

```text
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
```

---

# Git and GitHub

The project is managed using Git for version control and GitHub for remote repository storage.

GitHub repository:

```text
https://github.com/khev-gt/MINI-PROJECT.git
```

---

# Checking Git Status

To check the current repository status:

```text
git status
```

A clean repository displays:

```text
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

This means the local branch has no uncommitted changes and is synchronized with the remote branch.

---

# Reviewing Changes

Before committing a modification, the changes can be reviewed using:

```text
git diff
```

For changes specifically in `main.cpp`:

```text
git diff -- main.cpp
```

For README changes:

```text
git diff -- README.md
```

This allows the developer to inspect exactly what changed.

---

# Git Commit Workflow

After modifying a file, use the following workflow.

## Step 1 — Check Status

```text
git status
```

## Step 2 — Review Changes

```text
git diff
```

## Step 3 — Stage the File

For example:

```text
git add README.md
```

or:

```text
git add main.cpp
```

## Step 4 — Check Staged Changes

```text
git status
```

The file should appear under:

```text
Changes to be committed:
```

## Step 5 — Commit

Example:

```text
git commit -m "Update README documentation"
```

## Step 6 — Push

```text
git push origin main
```

## Step 7 — Verify

```text
git status
```

The branch should be up to date with the remote repository.

---

# Git Pull and Rebase

If GitHub contains changes that are not available locally, a normal push may be rejected.

For example:

```text
! [rejected]        main -> main (fetch first)
```

The local repository can be updated using:

```text
git pull --rebase origin main
```

After a successful rebase, push again:

```text
git push origin main
```

This keeps the local changes integrated with the latest remote changes.

---

# .gitignore

The project includes a `.gitignore` file.

Current rules include:

```text
# Compiled C++ executables
*.exe

# Backup files
*.backup

# Test backup files
teams-test-backup.txt
```

These rules prevent generated executable files and backup files from being unnecessarily committed to GitHub.

---

# Why .gitignore Is Important

During development, the compiler may create executable files such as:

```text
main.exe
integration.exe
```

The project may also contain temporary backup files during development.

These files are not part of the source code and do not need to be stored in the GitHub repository.

The `.gitignore` file keeps the repository clean by ignoring them.

---

# Checking .gitignore

To check whether the `.gitignore` file exists:

```text
Test-Path .gitignore
```

Expected result:

```text
True
```

To view its contents:

```text
Get-Content .gitignore
```

The expected contents are:

```text
# Compiled C++ executables
*.exe

# Backup files
*.backup

# Test backup files
teams-test-backup.txt
```

---

# Building and Testing After Changes

Whenever `main.cpp` is modified, the recommended workflow is:

```text
Edit Code
   |
   v
Save Code
   |
   v
Compile
   |
   v
Run Program
   |
   v
Test Feature
   |
   v
Check Git
   |
   v
Commit
   |
   v
Push to GitHub
```

Compile:

```text
g++ main.cpp -o integration.exe
```

Run:

```text
.\integration.exe
```

Check Git:

```text
git status
```

---

# Troubleshooting

## Problem: `g++` Is Not Recognized

If PowerShell says that `g++` is not recognized, GCC / MinGW may not be installed or may not be configured in the system PATH.

Check the compiler using:

```text
g++ --version
```

If the command works, the compiler is available.

---

# Problem: Executable Does Not Exist

If PowerShell cannot find:

```text
integration.exe
```

compile the program first:

```text
g++ main.cpp -o integration.exe
```

Then run:

```text
.\integration.exe
```

---

# Problem: Team Data Is Not Loaded

Check that:

```text
teams.txt
```

exists in the expected project directory.

The program uses this file to store persistent team information.

---

# Problem: Invalid Mission Points

If the system displays:

```text
Invalid points. Enter 1-100.
```

enter a whole number between:

```text
1
```

and:

```text
100
```

---

# Problem: Team Not Found

If the system displays:

```text
Team not found.
```

check that the Team ID has been registered and that the entered ID is correct.

---

# Problem: Git Shows Modified Files

If:

```text
git status
```

shows:

```text
modified:   main.cpp
```

this means the file has changed since the last commit.

Review the changes:

```text
git diff -- main.cpp
```

If the changes are correct:

```text
git add main.cpp
```

Then commit:

```text
git commit -m "Describe the change"
```

Then push:

```text
git push origin main
```

---

# Problem: Git Says Working Tree Is Clean

If Git displays:

```text
nothing to commit, working tree clean
```

this is not an error.

It means there are no uncommitted changes.

If it also says:

```text
Your branch is up to date with 'origin/main'.
```

the local project and GitHub repository are synchronized.

---

# Programming Concepts Demonstrated

## Structures

Team information is grouped into a structure containing related fields such as:

* Team ID
* Team Name
* Score
* Missions

This allows each team to be represented as one data object.

---

# Functions

The program uses functions to separate different responsibilities.

This improves organization and makes the code easier to maintain.

---

# Searching

Searching is used to locate a team using its Team ID.

It is required for:

* Finding teams
* Recording mission points
* Removing teams

---

# Sorting

Sorting is used to arrange teams according to their total scores.

This produces the ranking displayed by the leaderboard.

---

# Dynamic Memory

Dynamic memory is used to manage team storage.

The system can increase its capacity when additional team storage is required.

---

# File Input/Output

The system reads and writes team information using:

```text
teams.txt
```

This provides persistent storage.

---

# Input Validation

The program validates user input before processing it.

Examples include:

* Menu choice validation
* Team ID validation
* Mission point validation

---

# Error Handling

The system provides clear feedback when invalid input or invalid operations occur.

Examples:

```text
Invalid choice. Please enter 1-6.
```

```text
Invalid points. Enter 1-100.
```

```text
Team not found.
```

---

# Memory Cleanup

The system releases dynamically allocated memory before the program terminates.

This helps prevent memory leaks and demonstrates proper resource management.

---

# System Design Summary

The Campus Mission Tracker follows a simple management cycle:

```text
REGISTER
   |
   v
RECORD MISSIONS
   |
   v
SEARCH / VIEW PROFILE
   |
   v
UPDATE TEAM DATA
   |
   v
VIEW LEADERBOARD
   |
   v
REMOVE IF NEEDED
   |
   v
SAVE DATA
```

This provides a complete workflow for managing campus mission teams.

---

# Data Management

The system manages team information throughout the program lifecycle.

The basic data flow is:

```text
INPUT
  |
  v
VALIDATE
  |
  v
STORE
  |
  v
UPDATE
  |
  v
DISPLAY
  |
  v
SAVE
```

This ensures that team information can be entered, checked, updated, displayed, and stored.

---

# Data Relationships

Each team contains the following important information:

```text
Team
 |
 +-- Team ID
 |
 +-- Team Name
 |
 +-- Total Score
 |
 +-- Missions
```

The Team ID identifies the team.

The Team Name identifies the team in human-readable form.

The Total Score stores accumulated mission points.

The Missions value records the number of mission point entries.

---

# Example of Score Calculation

Suppose Team 101 completes three missions:

```text
Mission 1 = 30 points
Mission 2 = 25 points
Mission 3 = 40 points
```

The total score becomes:

```text
30 + 25 + 40 = 95
```

The Team Profile would then show:

```text
Total Score  : 95
Missions     : 3
```

The leaderboard uses the total score when determining the team's rank.

---

# Relationship Between Missions and Score

Every time mission points are successfully recorded:

1. The entered points are added to the team's total score.
2. The mission count increases by one.

For example:

```text
Before:
Score = 50
Missions = 2

New mission:
Points = 30

After:
Score = 80
Missions = 3
```

This keeps the score and mission count synchronized.

---

# Relationship Between Score and Leaderboard

The leaderboard uses the team's total score to determine its position.

For example:

```text
Team A = 100
Team B = 75
Team C = 50
```

The ranking becomes:

```text
Rank 1 → Team A
Rank 2 → Team B
Rank 3 → Team C
```

If the scores change, the leaderboard can display the new ranking after sorting.

---

# Relationship Between Search and Team Profile

Option `3` connects the Team ID search function with the Team Profile display.

The process is:

```text
Enter Team ID
      |
      v
Search Team
      |
      v
Team Exists?
   /       \
 YES       NO
  |         |
  v         v
Display    Team
Profile    Not Found
```

This gives the user either detailed team information or a clear error message.

---

# Relationship Between Remove and Leaderboard

When a team is removed, the team is no longer part of the active team collection.

Therefore, when the leaderboard is displayed afterward, the removed team does not appear.

Example:

```text
Before removal:

101 → 99
102 → 80
103 → 50
```

After removing Team 103:

```text
101 → 99
102 → 80
```

The leaderboard updates based on the remaining teams.

---

# Save and Load Workflow

The program uses a persistent data workflow:

```text
PROGRAM START
      |
      v
LOAD teams.txt
      |
      v
WORK WITH TEAM DATA
      |
      v
USER MAKES CHANGES
      |
      v
SAVE teams.txt
      |
      v
PROGRAM EXIT
```

This allows the system to preserve team information between sessions.

---

# User Interface Improvements

The console interface has been improved to make important information easier to understand.

The Team Profile provides detailed information about one selected team.

The Leaderboard provides a complete overview of all registered teams.

These overlays improve readability without changing the core functionality of the system.

---

# Team Profile Update

The original simple team search output was improved into a formatted Team Profile.

Current output:

```text
========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
```

The Team Profile provides a clear summary of an individual team.

---

# Leaderboard Update

The original basic leaderboard output was improved into a more organized leaderboard overlay.

Current output:

```text
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
```

The new design provides:

* Clear title
* Rank column
* Team ID
* Team Name
* Score
* Mission count
* Total team count
* Clear visual separation

---

# Current System Status

The current system includes:

* [x] Team registration
* [x] Team ID input
* [x] Team name input
* [x] Mission point recording
* [x] Mission point validation from 1 to 100
* [x] Team searching
* [x] Team Profile overlay
* [x] Team not found handling
* [x] Team removal
* [x] Leaderboard sorting
* [x] Leaderboard overlay
* [x] Rank display
* [x] Score display
* [x] Mission count display
* [x] Total team count
* [x] Input validation
* [x] Error handling
* [x] File loading
* [x] File saving
* [x] Dynamic memory management
* [x] Memory cleanup
* [x] Git version control
* [x] GitHub repository
* [x] `.gitignore`
* [x] Detailed project documentation

---

# Project Development Updates

The project has been developed incrementally.

Important development stages include:

1. Initial project development.
2. Team management functionality.
3. Team registration.
4. Mission point recording.
5. Input validation.
6. Team searching.
7. Team removal.
8. Team Profile interface improvement.
9. Leaderboard interface improvement.
10. `.gitignore` configuration.
11. README documentation update.
12. GitHub synchronization.

Each major change can be stored as a Git commit.

---

# Git Commit History Highlights

The project has been updated through multiple commits.

Important recent updates include:

```text
Add gitignore for build and backup files
```

This added the `.gitignore` configuration.

```text
Improve team profile display
```

This improved Option `3` with the Team Profile overlay.

```text
Improve leaderboard display
```

This improved Option `5` with the formatted Leaderboard overlay.

```text
Update README documentation
```

This updated the project documentation to match the current system.

---

# Repository Synchronization

The project uses:

```text
main
```

as the primary branch.

The local branch is connected to:

```text
origin/main
```

After pushing changes, Git can confirm synchronization with:

```text
git status
```

Expected clean result:

```text
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

---

# Recommended Development Workflow

When making future changes, use the following process.

## Step 1 — Make the Code Change

Edit the required source file.

---

## Step 2 — Save the File

Save the file in Visual Studio Code using:

```text
Ctrl + S
```

---

## Step 3 — Compile

```text
g++ main.cpp -o integration.exe
```

---

## Step 4 — Test

```text
.\integration.exe
```

Test the changed functionality.

---

## Step 5 — Check Git

```text
git status
```

---

## Step 6 — Review the Difference

```text
git diff
```

---

## Step 7 — Stage the Changed File

For `main.cpp`:

```text
git add main.cpp
```

For `README.md`:

```text
git add README.md
```

---

## Step 8 — Check Staged Changes

```text
git status
```

Confirm that the correct file appears under:

```text
Changes to be committed:
```

---

## Step 9 — Commit

Example:

```text
git commit -m "Improve leaderboard display"
```

Use a clear message describing the change.

---

## Step 10 — Push

```text
git push origin main
```

---

## Step 11 — Final Verification

```text
git status
```

The expected result is:

```text
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

---

# Important Commands Reference

## Compile

```text
g++ main.cpp -o integration.exe
```

## Run

```text
.\integration.exe
```

## Check Compiler Version

```text
g++ --version
```

## Check Git Status

```text
git status
```

## Review All Changes

```text
git diff
```

## Review Main Source Changes

```text
git diff -- main.cpp
```

## Review README Changes

```text
git diff -- README.md
```

## Stage Main Source

```text
git add main.cpp
```

## Stage README

```text
git add README.md
```

## Commit

```text
git commit -m "Your commit message"
```

## Push

```text
git push origin main
```

## Pull with Rebase

```text
git pull --rebase origin main
```

---

# Quick User Guide

For a quick overview:

```text
1 → Register a team
2 → Record mission points
3 → Find a team / Team Profile
4 → Remove a team
5 → Show leaderboard
6 → Save and exit
```

---

# Quick Testing Guide

To test the main features:

### Test Option 1

Register a team:

```text
ID: 101
Name: team 1
```

### Test Option 2

Record points:

```text
Team ID: 101
Points: 99
```

### Test Option 3

Find the team:

```text
Team ID: 101
```

Expected:

```text
TEAM PROFILE
```

### Test Option 3 with Invalid ID

Use:

```text
999
```

Expected:

```text
Team not found.
```

### Test Option 5

View the leaderboard.

Expected:

```text
LEADERBOARD
```

### Test Option 6

Save and exit.

Expected:

```text
Data saved. Goodbye!
```

---

# Example Final Leaderboard

A successful leaderboard example:

```text
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
```

---

# Example Final Team Profile

A successful Team Profile example:

```text
========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
```

---

# Project Advantages

The Campus Mission Tracker provides several advantages:

1. Simple console interface.
2. Easy team registration.
3. Automatic score calculation.
4. Mission count tracking.
5. Team searching by ID.
6. Clear Team Profile display.
7. Automatic leaderboard ranking.
8. Team removal functionality.
9. Data persistence using a file.
10. Input validation.
11. Error handling.
12. Dynamic memory management.
13. Organized source code using functions.
14. Git version control.
15. GitHub remote repository.
16. Clean repository using `.gitignore`.

---

# Possible Future Improvements

The current system is functional, but it could be expanded in the future.

Possible improvements include:

* Add confirmation before deleting a team.
* Add more detailed team statistics.
* Add separate mission records.
* Add timestamps for missions.
* Add different mission categories.
* Add team status management.
* Add search by team name.
* Add multiple leaderboard sorting methods.
* Add export functionality.
* Improve menu navigation.
* Add colored console output if appropriate.
* Add administrator authentication.
* Add more advanced file storage.
* Add a graphical user interface in a future version.

These are possible future improvements and are not required for the current version.

---

# Project Learning Outcomes

Through this project, the developer practices:

* C++ syntax
* Variables
* Data types
* Structures
* Functions
* Arrays
* Pointers
* Dynamic memory
* Searching algorithms
* Sorting algorithms
* File handling
* Input validation
* Error handling
* Program design
* Console UI design
* Debugging
* Testing
* Git
* GitHub
* Documentation

---

# Conclusion

The **Campus Mission Tracker** is a functional C++ console application for managing campus mission teams and their performance.

The system provides a complete set of team-management operations:

* Register teams
* Record mission points
* Find teams
* Display Team Profiles
* Remove teams
* Rank teams
* Display the Leaderboard
* Save team information
* Load saved information

The project demonstrates important C++ programming concepts including:

* Structures
* Functions
* Searching
* Sorting
* Dynamic memory management
* File handling
* Input validation
* Error handling
* Memory cleanup

The updated **TEAM PROFILE** and **LEADERBOARD** overlays improve the clarity and usability of the console interface while keeping the system simple and easy to operate.

The project is maintained using Git and GitHub, with a `.gitignore` configuration to keep generated and temporary files out of the repository.

---

# Final Project Status

**Campus Mission Tracker — Completed, Tested, and Updated.**

Current major interface updates:

```text
Option 3 → TEAM PROFILE
Option 5 → LEADERBOARD
```

Current project files:

```text
main.cpp
teams.txt
README.md
.gitignore
```

Git branch:

```text
main
```

Remote branch:

```text
origin/main
```

GitHub repository:

```text
https://github.com/khev-gt/MINI-PROJECT.git
```

The latest project version has been committed and pushed to GitHub.

A clean Git status should show:

```text
On branch main
Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean
```

---

# End of README

**Campus Mission Tracker**

*A C++ Team Management and Mission Tracking System.*

