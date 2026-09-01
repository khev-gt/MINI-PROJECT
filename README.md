# Campus Mission Tracker

A C++ console-based team management system designed to manage teams, record mission points, search for teams, remove teams, and display a ranked leaderboard.

The project demonstrates structured data handling, dynamic memory management, file input/output, searching, sorting, input validation, error handling, data persistence, and safe memory cleanup.

---

## Features

- Register a new team
- Record mission points
- Find a team by ID
- Remove a team
- Display a ranked leaderboard
- Sort teams by score from highest to lowest
- Save team data to `teams.txt`
- Load team data when the program starts
- Validate menu input
- Validate team IDs
- Validate team names
- Validate mission points
- Handle invalid numeric input
- Dynamically increase team storage capacity
- Free allocated memory before program exit

---

## Getting Started

There are two ways to get the Campus Mission Tracker onto your computer.

### Method 1: Clone the Repository Using Git

If Git is installed on your computer, open PowerShell or Command Prompt and run:

    git clone https://github.com/khev-gt/MINI-PROJECT.git

Then move into the project folder:

    cd MINI-PROJECT

The project files will now be available on your computer.

### Method 2: Download the Project as ZIP

If you do not have Git installed:

1. Open the Campus Mission Tracker GitHub repository.
2. Click the green `Code` button.
3. Select `Download ZIP`.
4. Extract the downloaded ZIP file.
5. Open the extracted `MINI-PROJECT` folder.
6. Open PowerShell or Command Prompt inside the project folder.

The project is now ready to compile and run.

---

## Requirements

Before running the program, make sure your computer has:

- A C++ compiler
- GCC / MinGW
- PowerShell, Command Prompt, or another terminal
- Git (only required if using the Git clone method)

---

## Compile the Program

After downloading or cloning the project, open a terminal inside the project folder.

For example:

    cd MINI-PROJECT

Compile the program using:

    g++ main.cpp -o integration.exe

If the compilation is successful, the executable file `integration.exe` will be created.

If your system uses a different C++ compiler, use the appropriate compiler command.

---

## Run the Program

After compiling, run the program from PowerShell using:

    .\integration.exe

The main menu will appear:

    ===== Campus Mission Tracker =====
    1. Register a team
    2. Record mission points
    3. Find a team
    4. Remove a team
    5. Show leaderboard
    6. Save and exit
    Enter your choice:

---

## Main Menu

The program provides six main operations:

| Option | Operation | Description |
|---|---|---|
| 1 | Register a team | Add a new team |
| 2 | Record mission points | Add points to a team |
| 3 | Find a team | Search for a team by ID |
| 4 | Remove a team | Delete a team |
| 5 | Show leaderboard | Display teams ranked by score |
| 6 | Save and exit | Save data and close the program |

---

## How to Use

### 1. Register a Team

Choose option `1` to register a new team.

Example:

    Enter your choice: 1
    Enter team ID: 101
    Enter team name: team 1

After successful registration, the team starts with:

    Score: 0
    Missions: 0

The Team ID must be a valid positive whole number and must not already exist.

The team name must satisfy the validation rules implemented by the system.

---

### 2. Record Mission Points

Choose option `2` to record points earned by a team.

Example:

    Enter your choice: 2
    Enter team ID: 101
    Enter mission points earned (1-100): 50

The system adds the mission points to the team's total score and increases the mission count by `1`.

Mission points must be a whole number between `1` and `100`.

If the entered Team ID does not exist, the system displays:

    Team not found.

---

### 3. Find a Team

Choose option `3` to search for a registered team using its Team ID.

Example:

    Enter your choice: 3
    Enter team ID: 101

If the team exists, the system displays:

    Team found:
    ID: 101
    Name: team 1
    Score: 50
    Missions: 1

If the team does not exist, the system displays:

    Team not found.

---

### 4. Remove a Team

Choose option `4` to remove a registered team.

Example:

    Enter your choice: 4
    Enter team ID: 101
    Team removed.

The system removes the team from the current team list.

If the Team ID does not exist, the system displays:

    Team not found.

---

### 5. Show Leaderboard

Choose option `5` to display the leaderboard.

The system sorts registered teams by score from highest to lowest and displays their rank, Team ID, team name, score, and number of missions.

Example:

    Rank  ID    Name                         Score  Missions
    ----  ----  ---------------------------  -----  --------
    1     101   team 1                       99     1
    2     102   team 2                       80     1
    3     103   team 3                       50     1

The leaderboard contains:

- Rank
- Team ID
- Team Name
- Score
- Missions completed

---

### 6. Save and Exit

Choose option `6` to save the current team data and exit the program.

Example:

    Enter your choice: 6
    Data saved. Goodbye!

The team information is saved to `teams.txt`.

When the program starts again, the saved team information is loaded automatically.

---

## Input Validation

The system validates user input to prevent invalid data from entering the system.

### Menu Choice Validation

Only options `1` through `6` are accepted.

Examples of invalid input:

    abc
    1.1
    7
    hello

The system displays:

    Invalid choice. Please enter 1-6.

The program then returns to the main menu.

---

### Team ID Validation

The Team ID must be a valid whole number.

Examples of invalid input:

    abc
    1.5
    hello

The system displays an appropriate error message and does not process the invalid Team ID.

For example:

    Error: Team ID must be a whole number.

or:

    Error: Team ID must be a valid number.

---

### Team Name Validation

Team names are validated before being stored.

The team name cannot be empty, cannot exceed the available storage size, and cannot contain the `|` separator used by the data file.

Invalid team names are rejected by the system.

---

### Mission Points Validation

Mission points must be a whole number from `1` to `100`.

Examples of invalid input:

    abc
    0
    101
    50.5

The system displays:

    Invalid points. Enter 1-100.

Invalid points are rejected and the team's score is not changed.

---

## Typical Usage Flow

A typical session can follow this process:

    1. Register teams
             |
             v
    2. Record mission points
             |
             v
    3. Find teams when needed
             |
             v
    4. Show the leaderboard
             |
             v
    5. Remove a team if necessary
             |
             v
    6. Save and exit

Team data is kept in memory while the program is running.

When the user selects `6. Save and exit`, the current data is saved to `teams.txt`.

---

## Leaderboard Example

For example, if the system contains:

    101|team 1|99|1
    102|team 2|80|1
    103|team 3|50|1

The leaderboard is displayed as:

    Rank  ID    Name                         Score  Missions
    ----  ----  ---------------------------  -----  --------
    1     101   team 1                       99     1
    2     102   team 2                       80     1
    3     103   team 3                       50     1

The team with the highest score is displayed at the top.

---

## Data Storage

Team data is stored in the `teams.txt` file.

Each team record uses the following format:

    ID|Team Name|Score|Missions

Example:

    101|team 1|99|1
    102|team 2|80|1
    103|team 3|50|1

The fields represent:

| Field | Description |
|---|---|
| ID | Unique Team ID |
| Team Name | Name of the team |
| Score | Total mission points |
| Missions | Number of missions completed |

The `|` character is used as the separator between fields.

---

## Loading and Saving Data

### Loading Data

When the program starts, it attempts to load team information from:

    teams.txt

Existing team records are loaded into memory.

### Saving Data

When the user selects option `6`, the program saves the current team information to:

    teams.txt

This allows team information to remain available after the program is closed.

---

## Searching

The system provides team searching using the Team ID.

The search operation checks the registered teams and identifies the team with the requested ID.

If the Team ID is not found, the system displays:

    Team not found.

---

## Sorting

The leaderboard sorts teams according to their scores.

Teams are displayed from the highest score to the lowest score.

For example:

    99 points
    80 points
    50 points

will appear in that order on the leaderboard.

---

## Dynamic Memory Management

The project uses dynamically allocated memory to store teams.

The system maintains:

- The team array
- The current number of teams
- The current storage capacity

When additional storage is required, the program increases the allocated capacity.

The program also performs memory cleanup before exiting to ensure allocated memory is properly released.

---

## Team Structure

Each team is represented by a `Team` structure containing information about:

- Team ID
- Team name
- Total score
- Number of missions

The structure is used to organize team information in memory.

---

## Error Handling

The program is designed to handle invalid user input safely.

For example, if the user enters text instead of a valid menu number:

    Enter your choice: abc

The system responds:

    Invalid choice. Please enter 1-6.

The user can then enter a valid menu option.

Similar validation is applied to Team IDs and mission points.

---

## Project Structure

    MINI-PROJECT/
    |
    +-- main.cpp
    +-- teams.txt
    +-- README.md
    +-- test-evidence.md
    |
    +-- output/

### File Description

| File / Folder | Description |
|---|---|
| `main.cpp` | Main C++ source code |
| `teams.txt` | Stores team information |
| `README.md` | Project documentation |
| `test-evidence.md` | Testing evidence and results |
| `output/` | Project output files |

---

## Testing

The system has been tested for the following operations:

- Registering a valid team
- Registering a team with an invalid ID
- Registering a team with a duplicate ID
- Validating team names
- Recording valid mission points
- Rejecting invalid mission points
- Finding an existing team
- Finding a non-existing team
- Removing an existing team
- Removing a non-existing team
- Handling invalid menu choices
- Handling non-numeric menu input
- Sorting the leaderboard
- Displaying the leaderboard with correct formatting
- Saving team data
- Loading team data
- Dynamic memory management
- Memory cleanup

---

## Example Session

A simple example session can look like this:

    ===== Campus Mission Tracker =====
    1. Register a team
    2. Record mission points
    3. Find a team
    4. Remove a team
    5. Show leaderboard
    6. Save and exit
    Enter your choice: 5

    Rank  ID    Name                         Score  Missions
    ----  ----  ---------------------------  -----  --------
    1     101   team 1                       99     1
    2     102   team 2                       80     1
    3     103   team 3                       50     1

---

## Troubleshooting

### `g++` is not recognized

If PowerShell displays an error that `g++` is not recognized, GCC / MinGW may not be installed or may not be added to the system PATH.

Install a C++ compiler and make sure `g++` is available from the terminal.

### `integration.exe` is not found

Compile the program first:

    g++ main.cpp -o integration.exe

Then run:

    .\integration.exe

### Team data is missing

Make sure `teams.txt` is located in the same project directory as the executable when the program is run.

---

## Project Purpose

The purpose of the Campus Mission Tracker is to demonstrate practical C++ programming concepts through a complete console-based application.

The project focuses on:

- Structures
- Dynamic arrays
- Dynamic memory management
- Searching
- Sorting
- File input/output
- Input validation
- Error handling
- Data persistence
- Memory cleanup

The project combines these concepts into a functional team management system.

---

## Project Status

**Completed and Tested**

The current version includes team management, mission point recording, searching, team removal, leaderboard sorting and display, file persistence, input validation, dynamic memory management, and memory cleanup.
