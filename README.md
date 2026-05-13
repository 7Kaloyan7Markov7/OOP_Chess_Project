# Chess

A console-based chess game written in C++ for Windows. Full standard chess rules, including all special moves, with a colored board rendered via the Windows console API.

![Language](https://img.shields.io/badge/language-C%2B%2B-blue)
![Platform](https://img.shields.io/badge/platform-Windows-lightgrey)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-purple)

## Features

- Two-player game on the same machine
- Full move validation per piece type
- **All special moves implemented:**
  - Castling (king-side and queen-side)
  - En passant
  - Pawn promotion
- **Game state detection:**
  - Check
  - Checkmate
  - Stalemate
  - Draw by insufficient material (king vs. king)
- Unicode chess pieces (♔ ♕ ♖ ♗ ♘ ♙ / ♚ ♛ ♜ ♝ ♞) rendered with colored squares using the Windows Console API
- Algebraic-notation input (e.g. `e2` → `e4`)

## Architecture

The project follows an object-oriented design with clear separation of concerns:

| Component       | Responsibility                                              |
|-----------------|-------------------------------------------------------------|
| `Chess`         | Singleton entry point — runs the main game loop             |
| `Board`         | 8×8 grid of `Figure*`, handles moves, castling, en passant, promotion |
| `EventHandler`  | Input validation, turn management, check/checkmate/stalemate detection |
| `Drawer`        | Renders the board to the console with colors                |
| `Player`        | Stores player color, piece count, reads input               |
| `Parser`        | Converts between algebraic notation (`e4`) and array indices |
| `Figure` (abstract) | Base class for all pieces; subclasses generate their legal moves |
| `Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, `King` | Piece-specific move generation |
| `String`        | Custom string class (no `std::string`)                      |
| `MyVector<T>`   | Custom dynamic array template (no `std::vector`)            |

The `String` and `MyVector` classes are written from scratch and support copy/move semantics, dynamic resizing, and the standard set of operators.

Move legality is checked by simulating the move on a copy of the board and verifying the player's own king is not left in check — which is also how `isCheckmate` and `hasAnyLegalMove` are implemented.

## Build & Run

**Requirements:** Windows, Visual Studio 2022 (or any version supporting toolset v143), C++17.

1. Clone the repo:
   ```
   git clone https://github.com/<your-username>/Chess.git
   ```
2. Open `Chess.sln` in Visual Studio.
3. Build the solution (`Ctrl+Shift+B`).
4. Run (`F5` or `Ctrl+F5`).

> The renderer uses `<windows.h>`, `_setmode`, and `SetConsoleTextAttribute`, so the project is Windows-only as written. Porting to other platforms would require replacing `Drawer_implementation.cpp` and removing the `system("cls")` call.

## How to Play

1. The board is displayed; White moves first.
2. When prompted, enter the square of the piece you want to move (e.g. `e2`).
3. Then enter the destination square (e.g. `e4`).
4. Invalid moves are rejected with a message and you are asked again.
5. The game ends on checkmate, stalemate, or insufficient material.

## Project Structure

```
Chess/
├── Source.cpp                  # Entry point
├── Chess_*.{h,cpp}             # Main game loop (singleton)
├── Board_*.{h,cpp}             # Board state & move execution
├── EventHandler_*.{h,cpp}      # Input validation, check/mate detection
├── Drawer_*.{h,cpp}            # Console rendering
├── Player_*.{h,cpp}            # Player input & state
├── Parser_*.{h,cpp}            # Notation <-> index conversion
├── Figure_*.{h,cpp}            # Abstract base piece
├── Pawn / Rook / Knight / Bishop / Queen / King_*.{h,cpp}
├── String_*.{h,cpp}            # Custom string
├── Vector.h                    # Custom dynamic array template
├── Constnats_and_Enums.h       # Shared constants & enums
└── Chess.sln / Chess.vcxproj   # Visual Studio solution
```

## Possible Improvements

- Save/load games to file (scaffolding already exists in `Board`)
- Move history & PGN export
- AI opponent (minimax + alpha-beta)
- Cross-platform renderer (ncurses / SDL)
- Unit tests

## License

Add your preferred license here (e.g. MIT).
