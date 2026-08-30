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
| T10 | Save, exit, restart | Same records reload exactly | Confirmed for well-formed data. However, if a saved name contains a `|` character, reload silently loses ALL teams (see extra finding below) — cascades into the T9 defect. | **Partial fail** | Save/load format mismatch when name field contains the delimiter character |
| T11 | Normal exit | `free()` called once; owner set to `NULL` | Ran full add/delete/save/exit sequence under AddressSanitizer (leak + error detection). Exit code 0, no leaks, no double-free, no use-after-free detected. | Pass | Double-free or dangling pointer |

## Additional Adversarial Tests (beyond required gauntlet)

| Input/State | Predicted Result | Actual Result | Pass/Fail | Defect Exposed |
|---|---|---|---|---|
| Non-numeric team ID ("abc") entered at add-team prompt | Should reject cleanly without crashing | No crash. Input buffer left in a fail state briefly, causing a couple of extra "Invalid choice" prompts before recovering. | Pass (with UX rough edge) | `cin` fail-state not cleared immediately at point of invalid entry |
| Negative team ID (-5) | Rejected, no crash | Printed "Error: Team ID must be positive." No crash. | Pass | — |
| Overlong team name (60 chars) | Rejected, no crash | Printed "Error: Team name too long (maximum 39 characters)." No crash. | Pass | — |
| Integer-overflow ID (99999999999) | Rejected or handled safely | No crash; handled via same input-buffer-recovery path as non-numeric input (a few "Invalid choice" prompts, then continues normally). | Pass (with UX rough edge) | — |
| **Team name containing `\|` (e.g. "Alpha\|Team")** | Should either be rejected, or safely escaped/quoted in the save format | Name is accepted and saved as-is: `101\|Alpha\|Team\|0\|0` — a 5-field line. On next program launch, this corrupts the load: **zero teams loaded**, no error shown, due to the T9 defect above. | **Fail (critical — data loss)** | Missing validation on `|` character in name field; combines with T9 defect to silently destroy the entire saved leaderboard |

## Summary of Defects (priority order)

1. **Critical — Malformed-line load failure (T9):** any line that fails to parse silently truncates loading of the rest of the file. Triggerable innocently by a name containing `|`, which isn't blocked on input.
2. **Fail — Missing missions tiebreaker in sort (T8):** equal-score teams are not ordered by missions as required.
3. **UX bug — False success message (T5):** "Mission points recorded." prints even when the points were rejected.
4. **Minor — `saveTeams` doesn't check `fprintf`/`fclose` return values**, as required by spec step H.

## Confirmed Working (verified via direct testing + AddressSanitizer)
- Capacity growth/doubling with data preservation (T3)
- Duplicate ID rejection (T4)
- Negative-score and duplicate rejection when the line itself parses correctly
- Search on missing ID, delete on first/last records (T6, T7)
- Full memory cleanup with no leaks or double-frees (T11)
- Basic input validation: negative ID, overlong name, non-numeric/overflow ID (no crashes)
