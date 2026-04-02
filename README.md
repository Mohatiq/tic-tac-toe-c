
# 🎮 Tic-Tac-Toe Game in C

A classic Tic-Tac-Toe game implementation in C where you can play against a computer opponent with random AI.

## 📋 Features

- **Player vs Computer**: Challenge the computer with random move generation
- **Character Selection**: Choose to play as 'X' or 'O'
- **Input Validation**: Validates player input and prevents invalid moves
- **Win Detection**: Checks all winning conditions (rows, columns, and diagonals)
- **Tie Detection**: Detects when the game ends in a draw
- **User-Friendly Interface**: Clear board display and intuitive prompts


## 🛠️ Compilation

Before compilation you should clone the github repo first to your machine.Type the following command in your terminal:
```bash  Clone the repository:
   
   git clone https://github.com/Mohatiq/tic-tac-toe-c.git
```
Note: make sure you have git installed in your laptop.

### Prerequisites

- GCC compiler or any C compiler
- Standard C library

### Compile
```bash
gcc main.c -o tic-tac-toe
```

### Run
```bash
./tic-tac-toe
```

## 🎯 How to Play

1. **Start the Game**: Run the compiled executable
2. **Choose Your Character**: Enter 'X' or 'O'
   - If you choose 'X', you go first
   - If you choose 'O', the computer goes first
3. **Enter Your Moves**: When it's your turn, input:
   - **Line**: Enter a number between 1-3 (row)
   - **Column**: Enter a number between 1-3 (column)
   
   Example board positions:
   ```
   | 1,1 | 1,2 | 1,3 |
   | 2,1 | 2,2 | 2,3 |
   | 3,1 | 3,2 | 3,3 |
   ```

4. **Win or Lose**: 
   - Get 3 of your symbols in a row (horizontal, vertical, or diagonal) to win
   - If the board fills up without a winner, it's a tie
   - If the computer gets 3 in a row, you lose

## 📝 Game Rules

- Players alternate turns
- Each cell can only be filled once
- First player to get 3 marks in a line wins
- If all 9 cells are filled with no winner, it's a tie

## 🧬 Code Structure

- **`win()`**: Checks all winning conditions (rows, columns, diagonals)
- **`PlayerChoice()`**: Handles player input and validates moves
- **`ComputerChoice()`**: Generates random computer moves
- **`fill_table()`**: Displays the game board
- **`game()`**: Main game loop managing turn alternation
- **`main()`**: Initializes the game and handles player setup

## 📊 Example Game Session

```
Please choose your character 'X' or 'O' :
X
You are 'X', the computer is 'O'.
Let's start the game!!

Your turn!!
Please type the coordinates of your desired position.
1.line:1
2.column: 1

| X | . | . |
| . | . | . |
| . | . | . |

Now it's the computer's turn!!
| X | . | . |
| . | O | . |
| . | . | . |
```

## 🎲 AI Implementation

The computer uses a **random move generator** that:
- Randomly selects empty cells on the board
- Ensures no duplicate moves
- Provides a casual difficulty level


## 👨‍💻 Author

Created by [Mohatiq](https://github.com/Mohatiq)
