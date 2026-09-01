Pasted text(3).txt
Document
here 
Pasted markdown.md
File
Bro still doing the same again and again can you look at the last one again ?

can you ? i just copy and past from you broooooooo0oo




YES bro 😭. Here is the whole README, rebuilt in the same detailed style as your previous one, but with the current updated Option 3 and Option 5 system.

Copy everything below and replace the entire contents of README.md.

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
5. Keep track of the number of missions completed by each team.
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

The system also provides:

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
- Git (optional, for GitHub operations)

---

# Project Structure

The project contains the following main files:

```text
MINI-PROJECT/
│
├── main.cpp
├── teams.txt
├── README.md
└── .gitignore
File Description
File	Purpose
main.cpp	Main C++ source code for the complete system
teams.txt	Stores saved team information
README.md	Project documentation
.gitignore	Prevents unnecessary build and backup files from being tracked

Compiled .exe files and backup files are intentionally ignored by Git.

How to Get the Project
Using Git

If Git is installed, open PowerShell or Command Prompt and run:

git clone https://github.com/khev-gt/MINI-PROJECT.git

Then enter the project directory:

cd MINI-PROJECT
Downloading the Project

The project can also be downloaded from GitHub as a ZIP file.

Steps
Open the GitHub repository.
Click the Code button.
Select Download ZIP.
Extract the ZIP file.
Open the extracted MINI-PROJECT folder.
Open PowerShell or Command Prompt in the project folder.
How to Compile the Program

Open PowerShell inside the project directory.

For example:

PS C:\Users\CTT\MINI-PROJECT>

Compile the program using:

g++ main.cpp -o integration.exe
Explanation
g++ → C++ compiler
main.cpp → source code
-o → specifies the output file
integration.exe → executable program

If there are no compiler errors, the executable will be created.

Example:

PS C:\Users\CTT\MINI-PROJECT> g++ main.cpp -o integration.exe

If PowerShell returns to the command prompt without showing an error, compilation was successful.

How to Run the Program

After compiling, run the program using:

.\integration.exe

Example:

PS C:\Users\CTT\MINI-PROJECT> .\integration.exe

The program will display the main menu.

Main Menu

The Campus Mission Tracker displays:

===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:

The user can select an operation by entering a number from 1 to 6.

Option 1 — Register a Team
Purpose

Option 1 is used to register a new team.

The user provides:

Team ID
Team Name

After the information is entered successfully, the system stores the team.

Example
Enter your choice: 1
Enter team ID: 101
Enter team name: team 1
Team registered successfully.

The team is now stored in the system.

A newly registered team starts with its initial score and mission count.

For example:

Team ID: 101
Team Name: team 1
Score: 0
Missions: 0

Mission points can later be added using Option 2.

Team ID

The Team ID is used to identify a team.

Example Team IDs:

101
102
103
104

The Team ID must be entered as a valid whole number.

The Team ID is important because the system uses it when:

Finding a team
Recording mission points
Removing a team
Team Name

The user must provide a team name when registering a team.

Example:

team 1
team 2
Campus Warriors
Mission Squad

The team name is stored together with the Team ID.

Option 2 — Record Mission Points
Purpose

Option 2 is used to record points earned by a team after completing a mission.

The user enters:

Team ID
Mission points

The entered points are added to the team's existing total score.

The mission count is also increased by 1.

Example

Suppose Team 101 currently has:

Score: 49
Missions: 0

The user enters:

Enter your choice: 2
Enter team ID: 101
Enter mission points earned (1-100): 50

The system adds 50 points.

The team now has:

Score: 99
Missions: 1
Mission Point Validation

Mission points must be between:

1-100
Valid examples
1
10
25
50
75
99
100
Invalid examples
0
101
-5
abc

If an invalid value is entered, the system displays:

Invalid points. Enter 1-100.

The invalid value is not recorded.

Recording Multiple Missions

A team can complete multiple missions.

For example:

First mission:

50 points

Second mission:

30 points

Third mission:

20 points

The team will have:

Total Score: 100
Missions: 3

The score represents the accumulated points from all recorded missions.

Team Not Found During Mission Recording

If the user enters a Team ID that does not exist:

Enter team ID: 999
Team not found.

The system does not record the mission points.

This prevents points from being assigned to a team that is not registered.

Option 3 — Find a Team
Purpose

Option 3 is used to search for a specific team using its Team ID.

The current system uses a formatted TEAM PROFILE display instead of the previous simple text output.

This makes the information easier to read and gives the user a clear summary of the selected team.

Steps
Step 1

Select Option 3:

Enter your choice: 3
Step 2

Enter the Team ID:

Enter team ID: 101
Step 3

If the team exists, the system displays the Team Profile.

Team Profile

The current Team Profile overlay is:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
Team Profile Fields

The Team Profile contains:

Field	Meaning
Team ID	Unique identification number of the team
Team Name	Name of the team
Total Score	Total points earned by the team
Missions	Number of missions recorded
Status	Current display status of the team

The current profile displays:

Status : ACTIVE

when the team is successfully found.

Team Not Found

If the user searches for a Team ID that does not exist:

Enter your choice: 3
Enter team ID: 999
Team not found.

The system does not display an empty Team Profile.

This gives the user clear feedback that the requested team does not exist.

Option 4 — Remove a Team
Purpose

Option 4 allows the user to remove a registered team from the system.

The user only needs to provide the Team ID.

Steps
Step 1

Select Option 4:

Enter your choice: 4
Step 2

Enter the Team ID:

Enter team ID: 104
Step 3

If the team exists, it is removed.

The system displays:

Team removed.
Removing a Non-Existing Team

If the Team ID does not exist:

Enter team ID: 999
Team not found.

No team is removed.

This prevents accidental removal of an unrelated team.

Option 5 — Show Leaderboard
Purpose

Option 5 displays all registered teams in ranked order.

Before displaying the leaderboard, the system sorts the teams according to their total score.

The team with the highest score receives Rank 1.

Leaderboard Design

The current system uses a formatted leaderboard overlay:

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

This design makes the leaderboard easier to read and gives the program a clearer console interface.

Leaderboard Columns

The leaderboard contains five main columns.

Column	Description
Rank	Position of the team
ID	Team ID
Team Name	Name of the team
Score	Total mission score
Missions	Number of completed/recorded missions

At the bottom, the system also displays:

Total Teams: 3

This shows the number of teams currently registered.

Leaderboard Ranking

The leaderboard is sorted by score.

For example, suppose the system contains:

Team A → 95
Team B → 80
Team C → 50

The leaderboard will display:

Rank 1 → Team A → 95
Rank 2 → Team B → 80
Rank 3 → Team C → 50

The highest score appears first.

Leaderboard Updates

The leaderboard changes automatically when team information changes.

For example, if Team 103 receives additional points and its score becomes higher than Team 101, the next leaderboard display will reflect the new ranking.

Similarly, when a team is removed, it will no longer appear in the leaderboard.

This means the leaderboard represents the current state of the team data.

Option 6 — Save and Exit
Purpose

Option 6 saves the current team information and exits the program.

The user selects:

Enter your choice: 6

The system saves the current data and displays:

Data saved. Goodbye!
Why Data Saving Is Important

The teams and scores are stored in memory while the program is running.

If the program closes without saving, changes made during the current session could be lost.

The system therefore provides a save operation that writes the current information to:

teams.txt

This allows information to be preserved between program sessions.

File Loading

When the program starts, it attempts to load previously saved team information from:

teams.txt

This allows previously registered teams to remain available after restarting the program.

File Storage

The project uses:

teams.txt

to store team information.

A team record contains information such as:

Team ID
Team Name
Score
Missions

The data is stored so that it can be loaded again when the program starts.

Example Team Data

A record can be represented in the following format:

101|team 1|99|1

The fields represent:

101    → Team ID
team 1 → Team Name
99     → Total Score
1      → Missions

The | character separates the individual fields.

Input Validation

Input validation is used throughout the system to prevent invalid data from being processed.

The system validates:

Menu choices
Team IDs
Mission points
Existing team IDs
Menu Validation

The valid menu choices are:

1
2
3
4
5
6

If the user enters:

7

the system displays:

Invalid choice. Please enter 1-6.

The user must then enter a valid option.

Invalid Menu Input

If the user enters text instead of a number:

Enter your choice: abc

the system handles the invalid input and displays an appropriate error message.

This prevents invalid menu input from causing the program to behave incorrectly.

Team ID Validation

Team IDs must be valid whole numbers.

Valid examples:

101
102
500
1000

Invalid examples:

abc
10.5
hello

The program checks the input before using it.

Possible validation messages include:

Error: Team ID must be a whole number.

and:

Error: Team ID must be a valid number.
Team Existence Validation

Before operations such as finding, recording points, or removing a team, the program checks whether the Team ID exists.

If the ID does not exist:

Team not found.

This prevents the system from performing operations on an invalid team.

Mission Point Validation

Mission points have a strict range:

1-100

Values below 1 or above 100 are rejected.

For example:

0
101

are invalid.

The system displays:

Invalid points. Enter 1-100.
Searching

The system uses the Team ID to search for teams.

Searching is required when:

Recording mission points
Finding a team
Removing a team

The system checks the stored teams and finds the team whose ID matches the user's input.

If a match is found, the requested operation is performed.

If no match is found:

Team not found.

is displayed.

Sorting and Ranking

Sorting is used by the leaderboard.

When Option 5 is selected, the system sorts the teams according to their total score before displaying them.

The highest score is displayed first.

For example:

Team 1 → 99
Team 2 → 80
Team 3 → 50

becomes:

1 → Team 1 → 99
2 → Team 2 → 80
3 → Team 3 → 50

The displayed rank is based on the sorted order.

Dynamic Memory Management

The project demonstrates dynamic memory management for storing team information.

The program maintains the current team storage capacity and can increase the capacity when more storage is required.

This allows the system to handle a growing number of teams.

Dynamic memory management is useful because the program does not need to depend only on a small fixed number of team records.

Memory Cleanup

Dynamically allocated memory must be released when it is no longer required.

The program performs memory cleanup before termination.

Proper memory cleanup helps prevent memory leaks and demonstrates responsible memory management in C++.

Functions

The system is divided into functions so that different tasks can be handled separately.

Examples of functionality include:

User interface / menu display
Capacity management
Team registration
Team searching
Mission recording
Team removal
Leaderboard sorting
Team display
File loading
File saving

Using functions makes the program easier to read, test, debug, and maintain.

Program Flow

The general program flow is:

START
  |
  v
Load saved team data
  |
  v
Display Main Menu
  |
  +----------------------+
  |                      |
  v                      v
Register Team       Record Mission
  |                      |
  +----------+-----------+
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

The user can repeatedly perform operations and return to the main menu.

The program continues until the user selects:

6. Save and exit
Typical User Workflow

A typical user can follow this workflow:

Step 1 — Register Teams

Use Option 1 to register all participating teams.

Example:

101 → team 1
102 → team 2
103 → team 3
Step 2 — Record Missions

When a team completes a mission, use Option 2 to record its points.

Example:

Team 101 → 99 points
Team 102 → 80 points
Team 103 → 50 points
Step 3 — Check an Individual Team

Use Option 3 to search for a specific team.

The system displays its Team Profile.

Step 4 — View the Rankings

Use Option 5 to display the leaderboard.

The system automatically sorts the teams according to score.

Step 5 — Remove a Team if Necessary

Use Option 4 if a team needs to be removed.

Step 6 — Save

Use Option 6 to save the current data before exiting.

Complete Example Session

The following example demonstrates a complete system workflow.

Starting the Program
PS C:\Users\CTT\MINI-PROJECT> .\integration.exe

The menu appears:

===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:
Registering Teams

Select Option 1:

Enter your choice: 1
Enter team ID: 101
Enter team name: team 1
Team registered successfully.

Register additional teams:

Enter your choice: 1
Enter team ID: 102
Enter team name: team 2
Team registered successfully.
still let me copy the short one whyyyyyyy?

😂 Bro, I understand why you're frustrated now.

The problem is not the README content itself. The problem is that when I put the README inside a normal Markdown code block, the ChatGPT interface can make the Copy button copy only part of the response or treat the huge block strangely.

So let's fix the method.

Do this instead

I should create the complete README.md as an actual file for you, rather than making you copy a massive text block manually.

Then you'll simply get:

Download the complete README.md

You put that file into:

C:\Users\CTT\MINI-PROJECT\README.md

and replace the old one.

That way:

✅ The entire README is included
✅ No copy/paste cutoff
✅ No accidentally missing sections
✅ Keeps the detailed style
✅ Matches your updated Option 3
✅ Matches your updated Option 5
✅ Includes the detailed guidance
✅ Easy to put directly into your project

But I need to base it on the actual previous README, not the shortened versions I generated. I already found the previous README in your files, so I can use that as the base and update it properly.

I'll make the full actual file, not another giant text response for you to copy.

README.md
Document
can not downl;oad 

Bro, fixed. I created the complete README.md as an actual file — about 30 KB / 1,800+ lines, so it won't get cut off like the copy/paste versions.

Download the complete README.md

Replace your current:

C:\Users\CTT\MINI-PROJECT\README.md

with this file.

Then open it in VS Code and check it. Don't commit/push yet. Once you confirm it looks right, we'll do the Git steps one by one. 

README.md
Document

Library
/
README.md
Campus Mission Tracker
Project Overview

Campus Mission Tracker is a C++ console-based team management system designed to manage teams participating in campus missions.

The system allows users to register teams, record mission points, search for teams, remove teams, display a ranked leaderboard, and save team information for future use.

The project demonstrates practical C++ programming concepts including:

Structures
Functions
Arrays and dynamic memory
Searching
Sorting
File input/output
Input validation
Error handling
Data persistence
Memory cleanup
Console user interface design
Git and GitHub version control
Project Objectives

The main objectives of the Campus Mission Tracker are:

Register and manage campus mission teams.
Store important information about each team.
Record points earned from completed missions.
Keep track of each team's total score.
Keep track of the number of missions recorded for each team.
Search for a team using its Team ID.
Display individual team information using a clear Team Profile.
Remove teams when necessary.
Sort teams according to their total score.
Display teams in a ranked leaderboard.
Save team information into a file.
Load previously saved team information.
Validate user input.
Handle invalid input safely.
Demonstrate dynamic memory management.
Demonstrate file input/output.
Practice Git and GitHub version control.
Main Features

The system provides six main operations:

Option	Feature	Description
1	Register a team	Adds a new team to the system
2	Record mission points	Adds mission points to an existing team
3	Find a team	Searches for a team and displays its Team Profile
4	Remove a team	Removes an existing team
5	Show leaderboard	Displays all teams ranked by score
6	Save and exit	Saves the current data and exits

Additional features include:

Team ID validation
Mission point validation from 1 to 100
Team existence checking
Error messages for invalid input
Leaderboard sorting
Formatted Team Profile display
Formatted Leaderboard display
File loading and saving
Dynamic memory management
Memory cleanup
Git version control
.gitignore for generated files
System Requirements

Recommended requirements:

Windows, Linux, or another operating system supporting C++
GCC / MinGW C++ compiler
PowerShell, Command Prompt, or another terminal
Git (optional for GitHub operations)
A text/code editor such as Visual Studio Code
Project Structure
MINI-PROJECT/
│
├── main.cpp
├── teams.txt
├── README.md
└── .gitignore
File Description
File	Purpose
main.cpp	Main C++ source code containing the system
teams.txt	Stores saved team information
README.md	Project documentation
.gitignore	Prevents unnecessary compiled and backup files from being tracked

Compiled .exe files and backup files are ignored by Git.

How to Get the Project
Using Git

Clone the repository with:

git clone https://github.com/khev-gt/MINI-PROJECT.git

Then enter the project folder:

cd MINI-PROJECT
How to Compile

Open PowerShell inside the project directory.

Example:

PS C:\Users\CTT\MINI-PROJECT>

Compile the program:

g++ main.cpp -o integration.exe
Command Explanation
g++ = C++ compiler
main.cpp = source file
-o = specifies the output file
integration.exe = executable program

If there are no compiler errors, the executable has been created successfully.

How to Run

After compilation, run:

.\integration.exe

The main menu will appear.

Main Menu

The current system displays:

===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:

The user can select an operation by entering a number from 1 to 6.

Option 1 — Register a Team
Purpose

Option 1 allows the user to register a new team.

The user enters:

Team ID
Team Name

After successful registration, the system displays a confirmation message.

Example
Enter your choice: 1
Enter team ID: 101
Enter team name: team 1
Team registered successfully.

A newly registered team begins with its initial score and mission count.

For example:

Team ID: 101
Team Name: team 1
Score: 0
Missions: 0

Mission points can later be added using Option 2.

Team ID

The Team ID is used to identify a team.

Examples:

101
102
103
104

The ID is important because the system uses it when:

Finding a team
Recording mission points
Removing a team

The program validates the Team ID before using it.

Option 2 — Record Mission Points
Purpose

Option 2 records points earned by a team after completing a mission.

The user enters:

Team ID
Mission points

The entered points are added to the team's existing total score.

The mission count is increased by 1.

Example
Enter your choice: 2
Enter team ID: 101
Enter mission points earned (1-100): 50

If the team previously had:

Score: 49
Missions: 0

after recording 50 points:

Score: 99
Missions: 1
Mission Point Validation

Mission points must be between:

1-100
Valid examples
1
25
50
75
99
100
Invalid examples
0
101
-5
abc

If an invalid value is entered, the system displays:

Invalid points. Enter 1-100.

The invalid value is not recorded.

Recording Multiple Missions

A team can record multiple missions.

For example:

Mission 1 → 50 points
Mission 2 → 30 points
Mission 3 → 20 points

The team will have:

Total Score: 100
Missions: 3

The score represents the accumulated points from recorded missions.

Team Not Found During Mission Recording

If the user enters a Team ID that does not exist:

Enter team ID: 999
Team not found.

No points are recorded.

Option 3 — Find a Team
Purpose

Option 3 searches for a specific team using its Team ID.

The updated system uses a formatted TEAM PROFILE overlay to present the team's information clearly.

Steps
Step 1

Select Option 3:

Enter your choice: 3
Step 2

Enter the Team ID:

Enter team ID: 101
Step 3

If the team exists, the Team Profile is displayed.

Team Profile

The current Team Profile is:

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
Field	Description
Team ID	Unique ID of the team
Team Name	Name of the team
Total Score	Total mission points earned
Missions	Number of recorded missions
Status	Current display status

The current system displays:

Status       : ACTIVE

when the team is successfully found.

Team Not Found

If the user searches for a Team ID that does not exist:

Enter your choice: 3
Enter team ID: 999
Team not found.

The system does not display an empty profile.

Option 4 — Remove a Team
Purpose

Option 4 removes an existing team from the system.

The user provides the Team ID.

Steps
Step 1

Select:

Enter your choice: 4
Step 2

Enter the Team ID:

Enter team ID: 104
Step 3

If the team exists, the system removes it and displays:

Team removed.

After removal, the team will no longer appear in the current team data or leaderboard.

Removing a Non-Existing Team

If the Team ID does not exist:

Enter team ID: 999
Team not found.

No team is removed.

Option 5 — Show Leaderboard
Purpose

Option 5 displays all currently registered teams in ranked order.

Before displaying the leaderboard, the system sorts the teams according to their total score.

The highest-scoring team is displayed at Rank 1.

Leaderboard Overlay

The current leaderboard uses the following formatted design:

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

The formatted border and headings make the ranking easier to read.

Leaderboard Columns
Column	Meaning
Rank	Position of the team
ID	Team ID
Team Name	Name of the team
Score	Total mission points
Missions	Number of recorded missions

At the bottom, the system displays:

Total Teams: 3

This represents the current number of registered teams.

Leaderboard Ranking

The leaderboard is sorted according to total score.

For example:

Team 1 → 99
Team 2 → 80
Team 3 → 50

will be displayed as:

1 → Team 1 → 99
2 → Team 2 → 80
3 → Team 3 → 50

Therefore, the highest score appears first.

Leaderboard Updates

The leaderboard is based on the current team data.

If a team receives additional mission points, its score changes and its position may change the next time the leaderboard is displayed.

If a team is removed, it will no longer appear in the leaderboard.

This keeps the leaderboard synchronized with the current system data.

Option 6 — Save and Exit
Purpose

Option 6 saves the current team information and exits the program.

The user selects:

Enter your choice: 6

The system saves the data and displays:

Data saved. Goodbye!
Why Saving Is Important

Team information is stored in memory while the program is running.

The information needs to be saved so that changes are not lost when the program closes.

The system saves the data to:

teams.txt

The saved information can then be loaded during a future program session.

Data Persistence

Data persistence means that important information remains available after the program has been closed.

The Campus Mission Tracker achieves this by:

Loading existing data when the program starts.
Managing the data while the program is running.
Saving the current data when the user selects Option 6.

This allows team information to continue across program sessions.

File Storage

The main data file is:

teams.txt

Team information includes:

Team ID
Team Name
Score
Missions

A record can be represented as:

101|team 1|99|1

The fields represent:

101    → Team ID
team 1 → Team Name
99     → Total Score
1      → Missions

The | character separates the fields.

Loading Data

When the program starts, it attempts to load existing team information from:

teams.txt

If saved information exists, it can be loaded into the program.

This means users do not need to register the same teams again after restarting the application.

Saving Data

When the user chooses:

6. Save and exit

the system writes the current team information to:

teams.txt

The program then displays:

Data saved. Goodbye!
Input Validation

Input validation prevents invalid information from being processed.

The system validates:

Menu choices
Team IDs
Mission points
Team existence
Menu Choice Validation

Valid menu choices are:

1
2
3
4
5
6

For example, if the user enters:

7

the system displays:

Invalid choice. Please enter 1-6.

The user must enter a valid option.

Invalid Menu Input

If the user enters text instead of a valid menu number, the system handles the invalid input and displays an appropriate error message.

This prevents invalid input from breaking the main program flow.

Team ID Validation

Team IDs must be valid whole numbers.

Valid examples
101
102
500
1000
Invalid examples
abc
10.5
hello

The system validates the Team ID before using it.

Possible error messages include:

Error: Team ID must be a whole number.

and:

Error: Team ID must be a valid number.
Team Existence Checking

Before operations such as recording points, finding a team, or removing a team, the program checks whether the Team ID exists.

If the team does not exist:

Team not found.

The requested operation is not performed.

Searching

The system searches for teams using their Team ID.

Searching is required for:

Recording mission points
Finding a team
Removing a team

The program checks the stored teams and compares their IDs with the user's input.

If a matching team is found, the requested operation is performed.

If no matching team is found:

Team not found.
Sorting

Sorting is used for the leaderboard.

Before the leaderboard is displayed, the system sorts the teams according to their total scores.

Example:

Team A → 95
Team B → 70
Team C → 40

After sorting:

Rank 1 → Team A → 95
Rank 2 → Team B → 70
Rank 3 → Team C → 40

This allows the leaderboard to show the highest-scoring teams first.

Dynamic Memory Management

The project demonstrates dynamic memory management for storing team information.

The system maintains information about:

Current number of teams
Available storage capacity
Team data

When more storage is required, the program can increase the available capacity.

This allows the application to support a growing number of teams.

Memory Cleanup

Dynamically allocated memory should be released when it is no longer needed.

The program performs memory cleanup before termination.

Proper memory cleanup helps prevent memory leaks and demonstrates responsible memory management.

Functions

The program separates different responsibilities into functions.

The system contains functionality for tasks such as:

Displaying the user interface
Managing storage capacity
Registering teams
Searching for teams
Recording mission points
Removing teams
Sorting the leaderboard
Displaying teams
Loading saved data
Saving data

Using separate functions makes the program easier to:

Read
Understand
Test
Debug
Maintain
Program Flow

The general system flow is:

START
  |
  v
Load saved team data
  |
  v
Display Main Menu
  |
  +-----------------------------+
  |                             |
  v                             v
Register Team             Record Mission Points
  |                             |
  +--------------+--------------+
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

The user can repeatedly perform operations until Option 6 is selected.

Typical User Workflow

A typical session can follow these steps.

Step 1 — Register Teams

Use Option 1 to register participating teams.

Example:

101 → team 1
102 → team 2
103 → team 3
Step 2 — Record Mission Points

Use Option 2 whenever a team completes a mission.

Example:

Team 101 → 99 points
Team 102 → 80 points
Team 103 → 50 points
Step 3 — Check a Team

Use Option 3 to view one team's Team Profile.

Step 4 — View Rankings

Use Option 5 to see the current leaderboard.

The system sorts the teams according to their scores.

Step 5 — Remove a Team

Use Option 4 if a team needs to be removed.

Step 6 — Save and Exit

Use Option 6 to save the current data before closing the program.

Complete Example Session
Starting the Program
PS C:\Users\CTT\MINI-PROJECT> .\integration.exe

The main menu appears:

===== Campus Mission Tracker =====
1. Register a team
2. Record mission points
3. Find a team
4. Remove a team
5. Show leaderboard
6. Save and exit
Enter your choice:
Register Team 1
Enter your choice: 1
Enter team ID: 101
Enter team name: team 1
Team registered successfully.
Register Team 2
Enter your choice: 1
Enter team ID: 102
Enter team name: team 2
Team registered successfully.
Register Team 3
Enter your choice: 1
Enter team ID: 103
Enter team name: team 3
Team registered successfully.
Record Mission Points

For Team 101:

Enter your choice: 2
Enter team ID: 101
Enter mission points earned (1-100): 99

For Team 102:

Enter your choice: 2
Enter team ID: 102
Enter mission points earned (1-100): 80

For Team 103:

Enter your choice: 2
Enter team ID: 103
Enter mission points earned (1-100): 50

The teams now have:

Team 101 → Score 99 → Missions 1
Team 102 → Score 80 → Missions 1
Team 103 → Score 50 → Missions 1
Find Team Example

Select Option 3:

Enter your choice: 3
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
Find Non-Existing Team

If the user enters:

Enter your choice: 3
Enter team ID: 999

the system displays:

Team not found.
Leaderboard Example

Select Option 5:

Enter your choice: 5

The system displays:

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
Remove Team Example

Select Option 4:

Enter your choice: 4
Enter team ID: 103
Team removed.

After removal, Team 103 will no longer appear in the leaderboard.

Save and Exit Example

Select Option 6:

Enter your choice: 6
Data saved. Goodbye!

The current team information is saved to teams.txt.

Error Handling Examples
Invalid Menu Choice

Input:

Enter your choice: 9

Output:

Invalid choice. Please enter 1-6.
Invalid Mission Points

Input:

Enter mission points earned (1-100): 150

Output:

Invalid points. Enter 1-100.
Non-Existing Team

Input:

Enter team ID: 999

Output:

Team not found.
Testing

The Campus Mission Tracker has been tested using normal and invalid input cases.

Functional Tests

The following operations have been tested:

Registering a team
Recording mission points
Finding an existing team
Displaying the Team Profile
Searching for a non-existing team
Removing a team
Displaying the leaderboard
Sorting teams by score
Displaying total team count
Saving data
Loading saved data
Exiting the program
Validation Tests

The following validation cases have been tested:

Valid menu choices
Invalid menu choices
Invalid Team IDs
Non-existing Team IDs
Valid mission points
Mission points below 1
Mission points above 100
Invalid mission point input
Tested Team Profile Output

The updated Team Profile was tested successfully:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================
Tested Leaderboard Output

The updated leaderboard was tested successfully:

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
Git and GitHub

The project is managed using Git for version control and GitHub for remote repository storage.

GitHub repository:

https://github.com/khev-gt/MINI-PROJECT.git
Checking Git Status

To check the current repository status:

git status

A clean repository displays:

Your branch is up to date with 'origin/main'.

nothing to commit, working tree clean

This means the local branch has no uncommitted changes and is synchronized with the remote branch.

Reviewing Changes

Before committing a modification, the changes can be reviewed using:

git diff -- main.cpp

For README changes:

git diff -- README.md

This allows the developer to inspect exactly what changed.

Git Commit Workflow

After modifying a file:

Step 1 — Check Status
git status
Step 2 — Review Changes
git diff
Step 3 — Stage the File

For example:

git add README.md
Step 4 — Commit
git commit -m "Update README documentation"
Step 5 — Push
git push origin main
Step 6 — Verify
git status

The branch should be up to date with the remote repository.

Git Pull and Rebase

If GitHub contains changes that are not available locally, a normal push may be rejected.

For example:

! [rejected]        main -> main (fetch first)

The local repository can be updated using:

git pull --rebase origin main

After a successful rebase, push again:

git push origin main

This keeps the local changes integrated with the latest remote changes.

.gitignore

The project includes a .gitignore file.

Current rules include:

# Compiled C++ executables
*.exe

# Backup files
*.backup

# Test backup files
teams-test-backup.txt

These rules prevent generated executable files and backup files from being unnecessarily committed to GitHub.

Why .gitignore Is Important

During development, the compiler may create executable files such as:

main.exe
integration.exe

The project also contains temporary backup files during development.

These files are not part of the source code and do not need to be stored in the GitHub repository.

The .gitignore file keeps the repository clean by ignoring them.

Troubleshooting
Problem: g++ Is Not Recognized

If PowerShell says that g++ is not recognized, GCC / MinGW may not be installed or may not be configured in the system PATH.

Check the compiler using:

g++ --version

If the command works, the compiler is available.

Problem: Executable Does Not Exist

If PowerShell cannot find:

integration.exe

compile the program first:

g++ main.cpp -o integration.exe

Then run:

.\integration.exe
Problem: Team Data Is Not Loaded

Check that:

teams.txt

exists in the expected project directory.

The program uses this file to store persistent team information.

Problem: Invalid Mission Points

If the system displays:

Invalid points. Enter 1-100.

enter a whole number between:

1

and:

100
Problem: Team Not Found

If the system displays:

Team not found.

check that the Team ID has been registered and that the entered ID is correct.

Programming Concepts Demonstrated
Structures

Team information is grouped into a structure containing related fields such as:

Team ID
Team Name
Score
Missions

This allows each team to be represented as one data object.

Functions

The program uses functions to separate different responsibilities.

This improves organization and makes the code easier to maintain.

Searching

Searching is used to locate a team using its Team ID.

It is required for:

Finding teams
Recording mission points
Removing teams
Sorting

Sorting is used to arrange teams according to their total scores.

This produces the ranking displayed by the leaderboard.

Dynamic Memory

Dynamic memory is used to manage team storage.

The system can increase its capacity when additional team storage is required.

File Input/Output

The system reads and writes team information using:

teams.txt

This provides persistent storage.

Input Validation

The program validates user input before processing it.

Examples include:

Menu choice validation
Team ID validation
Mission point validation
Error Handling

The system provides clear feedback when invalid input or invalid operations occur.

Examples:

Invalid choice. Please enter 1-6.
Invalid points. Enter 1-100.
Team not found.
Memory Cleanup

The system releases dynamically allocated memory before the program terminates.

This helps prevent memory leaks and demonstrates proper resource management.

System Design Summary

The Campus Mission Tracker follows a simple management cycle:

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

This provides a complete workflow for managing campus mission teams.

Current System Status

The current system includes:

Team registration

Team ID input

Team name input

Mission point recording

Mission point validation from 1 to 100

Team searching

Team Profile overlay

Team not found handling

Team removal

Leaderboard sorting

Leaderboard overlay

Rank display

Score display

Mission count display

Total team count

Input validation

Error handling

File loading

File saving

Dynamic memory management

Memory cleanup

Git version control

GitHub repository

.gitignore

Project Development Updates

The user interface has been improved during development.

Team Profile Update

The original simple team search output was improved into a formatted Team Profile:

========================================
             TEAM PROFILE
========================================
Team ID      : 101
Team Name    : team 1
Total Score  : 99
Missions     : 1
Status       : ACTIVE
========================================

This makes individual team information easier to read.

Leaderboard Update

The original basic leaderboard output was improved into a more organized leaderboard overlay:

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

The new design provides:

Clear title
Rank column
Team ID
Team Name
Score
Mission count
Total team count
Clear visual separation
Conclusion

The Campus Mission Tracker is a functional C++ console application for managing campus mission teams and their performance.

The system provides a complete set of basic team-management operations:

Register teams
Record mission points
Find teams
Display Team Profiles
Remove teams
Rank teams
Display the Leaderboard
Save team information
Load saved information

The project also demonstrates important C++ programming concepts including structures, functions, searching, sorting, dynamic memory management, file handling, input validation, error handling, and memory cleanup.

The updated TEAM PROFILE and LEADERBOARD overlays improve the clarity and usability of the console interface while keeping the system simple and easy to operate.

The project is maintained using Git and GitHub, with a .gitignore configuration to keep generated and temporary files out of the repository.

Repository

GitHub Repository:

https://github.com/khev-gt/MINI-PROJECT.git

The latest project updates are maintained in the main branch.

Final Project Status

Campus Mission Tracker — Completed, Tested, and Updated.