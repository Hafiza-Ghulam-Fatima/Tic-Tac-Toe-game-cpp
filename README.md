# Tic-Tac-Toe Game (C++)
This is a colorful, console-based "Tic-Tac-Toe" game built in "C++" that allows you to play in "Two Modes" — against another player or against the computer.  
It uses "ANSI escape codes" to make the console display visually appealing, and includes input validation to ensure a smooth game experience.
## Features
### Game Modes
- "One Player Mode (vs Computer)" – Play against a computer opponent with random moves.
- "Two Player Mode" – Play with a friend on the same computer.
### Gameplay Features
- Colorful and clean board updates after every move.
- Input validation for:
  - Invalid numbers (outside 1–9).
  - Already occupied positions.
- Automatic "win detection" (rows, columns, diagonals).
- Automatic "draw detection" when no moves are left.
- Clear instructions displayed at the start of each game.
## Colors Used
- "Player 1 (X)" – Blue
- "Player 2 (O)" – Green
- "Errors" – Red
## How the Game Works
1. Choose game mode:
   - "1" → Play against the computer.
   - "2" → Play with a friend.
2. Enter a number (1–9) corresponding to the position on the board.
3. Players take turns placing their marks.
4. The first player to align three marks in a row, column, or diagonal wins.
5. If all positions are filled with no winner, the game ends in a draw.
## Project Structure
- "tic_tac_toe.cpp" – Main source code containing:
  - Game board display
  - Input handling
  - Turn switching logic
  - Win/Draw detection
  - Computer move generation
  - Game mode selection
## Requirements
- C++ compiler ("C++11" or later)
- Any IDE or terminal supporting "ANSI escape codes"
- Basic understanding of console I/O
## How to Run
1. Clone or download the project.
2. Open the ".cpp" file in your C++ IDE (e.g., Code::Blocks, Dev-C++, Visual Studio) or terminal than Compile the code.
## Author
Hafiza Ghulam Fatima
