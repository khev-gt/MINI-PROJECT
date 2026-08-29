# UX Notes — Campus Mission Tracker

This file holds the exact wording and layout for everything the user sees.
Integration Captain can copy these strings directly into printf/menu code.

## Main Menu

    ===== Campus Mission Tracker =====
    1. Register a team
    2. Record mission points
    3. Find a team
    4. Remove a team
    5. Show leaderboard
    6. Save and exit
    Enter your choice:

## Input Prompts

- "Enter team ID: "
- "Enter team name: "
- "Enter mission points earned (1-100): "

## Success Messages

- "Team registered successfully."
- "Mission points recorded."
- "Team removed."

## Leaderboard Display (T8, F. Show leaderboard)

    Rank  ID    Name              Score  Missions
    ----  ----  ----------------  -----  --------
    1     101   Byte Bandits      120    2
    2     102   Pointer Pirates   90     1

- Columns are fixed-width so they line up regardless of name length.
- If no teams exist (T1 Empty), show:
    "No teams registered yet."

## Error / Rejection Messages (tied to specific tests)

- Duplicate ID (T4): "Error: Team ID 101 already exists. Registration rejected."
- Invalid points (T5): "Error: Points must be between 1 and 100. No changes made."
- Team not found (T6): "Error: No team found with ID 999."
- Malformed file line (T9): "Warning: Skipped malformed line in save file."

## Notes for Integration Captain

- Every rejection message should say WHAT was rejected and WHY.
- Success and error messages should be printed on their own line, no extra blank lines.
