# C Code Studying

A personal C programming learning workspace — step-by-step lessons and mini projects.

## Learning Path

| # | File | Topic | Key Concepts |
|---|---|---|---|
| 01 | `01_variables_and_types.c` | Data Types | int, float, double, char, sizeof, type casting, `L`/`LL`/`f` suffixes |
| 02 | `02_functions.c` | Functions | prototypes, return values, recursion, pass-by-pointer |
| 03 | `03_control_flow.c` | Control Flow | if/else, switch, while, for, do-while, break/continue, ternary |
| 04 | `04_pointers.c` | Pointers | addresses (`&`), dereferencing (`*`), pointer arithmetic, NULL, pointer-to-pointer |
| 05 | `05_strings.c` | Strings | char arrays, `string.h` functions, `ctype.h`, `fgets` for user input |
| 06 | `06_structs.c` | Structs | typedef, arrow operator (`->`), nested structs, passing structs to functions |
| 07 | `07_memory.c` | Dynamic Memory | malloc, calloc, realloc, free, memory rules |

## Mini Projects

| File | Project | Description |
|---|---|---|
| `project1_calculator.c` | Calculator | Two-number calculator with +, -, *, /, %, ^ operators and input validation |
| `project2_guessing_game.c` | Guessing Game | Random number 1-100, 7 attempts, hot/cold hints |
| `project3_grade_tracker.c` | Grade Tracker | Menu-driven app: add students, record grades, view stats |

## How to Compile & Run

```bash
gcc filename.c -o filename
./filename
```

For projects using `pow()` on Linux, add `-lm`:
```bash
gcc project1_calculator.c -o calculator -lm
```

## Notes & Discussions

### `long` vs `int32_t` / `uint32_t`
- On **Windows**: `long` = `int` = 32 bits (same size)
- On **Linux 64-bit**: `long` = 64 bits, `int` = 32 bits
- `int32_t` / `uint32_t` (from `<stdint.h>`) guarantee exact size on all platforms
- Mixing `unsigned long` and `uint32_t` can cause compiler warnings and portability bugs (printf format specifiers, struct packing, pointer casting)
- For portable code, prefer fixed-width types when exact size matters

### Integer literal suffixes
- `1000000` — treated as `int` by default
- `1000000L` — explicitly `long`
- `1000000LL` — explicitly `long long`
- Matters for **large values** and **arithmetic expressions** to avoid overflow before assignment
