1. Execution:
•	Firstly, the program prompts for the value of N, the size of the Tic Tac Toe grid.
•	You can choose the grid of any size (3 or more).

2. Gameplay:
•The game starts with an empty grid (number printed in the grid). Enter your moves in the format of row and column numbers as shown in the empty grid.
•For example, for a 3x3 grid, you'd input coordinates like "2 3" (space- separated) for the second row, third column.
•The computer's moves are automatically generated based on predefined strategies to win or block your moves.
•Continue playing until someone wins or the game ends in a tie.

3. Visuals:
•The game displays the grid after each move, showing 'X' for your moves and 'O' for the computer's moves.
•The winner is displayed when someone wins, or it shows a tie if the game ends without a winner.

4. Additional Notes:
•The program uses numerical representations (0 for computer, 1 for the player, and 5 for an empty cell) on the grid.
•Ensure valid inputs within the grid size range provided at each turn.
•The computer employs certain logic to make its moves, aiming to win or prevent the player from winning

# The computer applies specific strategies to win or block the player's moves in the Tic Tac Toe game:

1. Winning Logic:
a. Row and Column Analysis:
   •It checks rows and columns to find its own markers (0s) and aims to complete a line to win.
b. Diagonal Check:
   •Examines both diagonals to identify its markers, attempting to complete a diagonal line for victory.

2. Blocking Player:
a. Row and Column Blocking:
   •Observes rows and columns to detect the player's markers (1s) and attempts to block any potential player wins.
b. Diagonal Block:
   •Analyses both diagonals for the player's markers to prevent the player from forming a winning diagonal line.

3. Decision Making:
a. Priority Based on Number of Markers:
   •Prioritizes moves based on the number of its own markers and the player's markers in rows, columns, and diagonals.
b. Strategic Placement:
   •Places its marker strategically to either win the game or prevent the player from winning, based on the current game state.

4. Fallback Strategy:
a. Random Moves:
   •If no immediate winning or blocking moves are available, it resorts to making random valid moves.

5. Optimization:
a. Efficient Move Selection:
   •Chooses moves that are not only aimed at winning but also focused on limiting the player's opportunities to win in subsequent turns


