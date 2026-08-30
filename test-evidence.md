# Campus Quest Leaderboard — Test Evidence Sheet

## Required Test Gauntlet

| # | Input/State | Predicted Result | Actual Result | Pass/Fail | Defect Exposed |
|---|---|---|---|---|---|
| T1 | Empty leaderboard, `size = 0` | Shows "no teams"; no array read | Printed "No teams registered yet." Program did not crash or access the array. | Pass | Loop that assumes ≥1 record exists |
| T2 | Add first team (ID 101) | `size` becomes 1; full record visible | Team 101 added; leaderboard showed complete record (ID, name, score 0, missions 0). | Pass | Incomplete record copy on add |
| T3 | `capacity = 2`, add 3rd team | Capacity doubles; first two records unchanged; 3rd visible | Added 3 teams starting from capacity 0. All three displayed correctly after growth; no data lost. | Pass | Missing/failed `realloc` via temp pointer |
| T4 | Add duplicate ID 101 | Rejected; `size` and original record unchanged | Program printed "Team ID already exists." Leaderboard still showed only the original team 101 record. | Pass | Duplicate check rejects add but still increments `size` |
| T5 | Add 0 or 101 mission points | Rejected before update; score/missions unchanged | Data was correctly rejected (score/missions stayed 0) — BUT the menu still printed "Mission points recorded." even on rejection, which is misleading. | **Fail (UX)** | Success message not tied to actual validation result in `main()`'s menu branch |
| T6 | Search unused ID | Returns −1 / "not found"; no mutation | Printed "Team not found." on an ID never added; no team list changes. | Pass | Search reads unused capacity or mutates state |
| T7 | Delete first, then last | Records shift correctly; `size` −1 each time; no stale data | Deleted team 101 (first) from a 2-team list under AddressSanitizer — no memory errors, size decremented correctly. | Pass | Off-by-one in shift loop |
| T8 | Teams with equal/different scores | Correct descending sort, missions as tiebreaker; fields stay attached | 3 teams with equal score (50) but missions 5, 2, 8 came out in original insertion order, NOT sorted by missions. | **Fail** | `sortLeaderboard` compares only `.score`; missions tiebreaker not implemented at all |
| T9 | Malformed line in file | Bad line skipped; valid records still load | Loaded a file with: good line → malformed line (wrong field count) → good line. Only the FIRST team loaded. The team after the malformed line never loaded, with no error message printed. | **Fail (critical)** | `fscanf` while-loop condition (`== 4`) exits the entire load loop on first parse failure instead of skipping just that line |
| T10 | Save, exit, restart | Same records reload exactly | Confirmed for well-formed data — teams saved and reloaded matched exactly. | Pass | Save/load format mismatch |
| T11 | Normal exit | `free()` called once; owner set to `NULL` | Ran full add/delete/save/exit sequence under AddressSanitizer (leak + error detection). Exit code 0, no leaks, no double-free, no use-after-free detected. | Pass | Double-free or dangling pointer |
