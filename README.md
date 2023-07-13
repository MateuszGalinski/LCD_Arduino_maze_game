# LCD_Arduino_maze_game

This code is a simple Arduino sketch that implements a maze game using an LCD display and serial communication. Here's a breakdown of how the code works:

Library and Constants:

The code includes the LiquidCrystal library, which is used to control the LCD display.
The SCREEN_WIDTH and SCREEN_HEIGHT constants define the dimensions of the LCD display.
The maze array stores the coordinates of walls in the maze, and the objective array defines the position of the goal.
LCD Setup:

The setup() function is called once at the beginning of the program.
It initializes the LCD display using the begin() function.
The "P" character is printed on the LCD display as the initial position of the player.
Maze Drawing:

The drawMaze() function is responsible for drawing the maze on the LCD display.
It iterates through the maze array and uses the setCursor() and print() functions to display "X" characters at the wall positions.
The objective position is also displayed as an "O" character.
Player Movement:

The movement() function handles the player's movement based on the received character input.
If the input is 'w', 'a', 'd', or 's' (representing up, left, right, and down movements), the player's position is updated accordingly.
The LCD display is cleared, and the cursor position is adjusted.
Loss and Win Conditions:

The checkLoss() function checks if the player's position coincides with any wall position in the maze array.
If there is a collision, the game is over, and a "You've Lost!" message is displayed on the LCD.
The checkWin() function checks if the player's position matches the objective position.
If the player reaches the goal, the game is won, and a "You've Won!" message is displayed on the LCD.
Try Again Prompt:

The tryAgainScreen() function displays a prompt asking the player if they want to try again.
The options "Y-yes" and "N-no" are displayed on the LCD.
The tryAgainPrompt() function handles the player's response.
If 'Y' is received, the game is reset and the player's position is set back to the starting position.
If 'N' is received, a "Good Bye!" message is displayed, and the program exits.
Game Loop:

The loop() function runs continuously.
It checks if there is any serial input available (received from the Serial monitor or other input source).
If there is input, the player's movement is updated, and the LCD display is refreshed.
Loss and win conditions are checked.
Try Again:

If the game is over (either won or lost), the tryAgainScreen() function is called to prompt the player for another try.
It waits for the player's response and acts accordingly.
That's a brief overview of how the code functions. It combines LCD display control, player movement, collision detection, win/loss conditions, and a prompt for restarting the game.
