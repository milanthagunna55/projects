#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) 
{
    for(int i= 0;i<3;i++) 
    {
        for(int j=0;j<3;j++) 
        {
            printf("%c\t",board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for a win or draw
char checkWin(char board[3][3]) 
{
    for (int i=0;i<3;i++) 
    {
        // Check rows and columns
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
        return board[0][2];

    // Check for a draw
    for (int i=0;i<3; i++) 
    {
        for (int j=0;j<3;j++) 
        {
            if (board[i][j]!='X'&&board[i][j]!='O') 
                return ' '; // Game is still ongoing
        }
    }

    return 'D'; // Draw
}

// Function for the player's move
void playerMove(char board[3][3], char playerSymbol) 
{
    int move;
    printf("Player %c, enter your move (choose a number between 1 and 9): ", playerSymbol);
    while (1) 
    {
        scanf("%d", &move);
        if (move >= 1 && move <= 9)
        {
            int row = (move - 1) / 3;  // Mapping to row
            int col = (move - 1) % 3;  // Mapping to column
            if (board[row][col]!='X'&&board[row][col]!='O') 
            {
                board[row][col] = playerSymbol; // Place the player's symbol on the board
                break;
            }
            else
            {
                printf("That spot is already taken. Try again.\n");
            }
        }
        else 
        {
            printf("Invalid move. Please enter a number between 1 and 9.\n");
        }
    }
}

// Function for the AI's move (simple AI)
void aiMove(char board[3][3]) 
{
    // AI just places 'O' in the first empty spot
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O') 
            {
                board[i][j] = 'O';  // AI places 'O' in the first empty spot
                return;
            }
        }
    }
}

int main() 
{
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    char result;
    char player1Symbol, player2Symbol;
    char player1Name[50], player2Name[50];
    int gameMode;

    printf("Welcome to Tic-Tac-Toe!\n");

    // Choose the game mode: 1 for Player vs AI, 2 for Player vs Player
    printf("Choose game mode:\n");
    printf("1. Player vs AI\n");
    printf("2. Player vs Player\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &gameMode);

    if (gameMode == 1) 
    {
        // Player vs AI Mode
        printf("Enter your name: ");
        scanf("%s", player1Name);
        printf("Player %s, choose your symbol (X or O): ", player1Name);
        while (1) 
        {
            scanf(" %c", &player1Symbol);
            if (player1Symbol == 'X' || player1Symbol == 'O') 
            {
                break;
            } 
            else 
            {
                printf("Invalid symbol. Choose X or O: ");
            }
        }
        player2Symbol = (player1Symbol == 'X') ? 'O' : 'X';
        printf("AI will play as '%c'.\n", player2Symbol);
        player2Name[0] = '\0'; // No name for AI in Player vs AI mode
    }
    else if (gameMode == 2) 
    {
        // Player vs Player Mode
        printf("Enter Player 1's name: ");
        scanf("%s", player1Name);
        printf("Enter Player 2's name: ");
        scanf("%s", player2Name);

        printf("Player 1 (%s), choose your symbol (X or O): ", player1Name);
        while (1) 
        {
            scanf(" %c", &player1Symbol);
            if (player1Symbol == 'X' || player1Symbol == 'O') 
            {
                break;
            } 
            else 
            {
                printf("Invalid symbol. Choose X or O: ");
            }
        }
        player2Symbol = (player1Symbol == 'X') ? 'O' : 'X';
    }
    else 
    {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    // Print the initial empty board
    printBoard(board);

    // Start the game
    while ((result = checkWin(board)) == ' ') 
    {
        if (gameMode == 1) 
        {
            // Player vs AI
            // Player's move
            playerMove(board, player1Symbol);

            // Print board after Player's move
            printBoard(board);

            // Check for win or draw
            if ((result = checkWin(board)) != ' ') break;

            // AI's move
            aiMove(board);

            // Print board after AI's move
            printBoard(board);

            // Check for win or draw
            if ((result = checkWin(board)) != ' ') break;
        } 
        else if (gameMode == 2) 
        {
            // Player vs Player
            // Player 1's move
            playerMove(board, player1Symbol);

            // Print board after Player 1's move
            printBoard(board);

            // Check for win or draw
            if ((result = checkWin(board)) != ' ') break;

            // Player 2's move
            playerMove(board, player2Symbol);

            // Print board after Player 2's move
            printBoard(board);

            // Check for win or draw
            if ((result = checkWin(board)) != ' ') break;
        }
    }

    // Display the result
    if (result == 'X') 
    {
        printf("Congratulations %s! You won!\n", player1Name);
    } 
    else if (result == 'O') 
    {
        if (gameMode == 1)
            printf("AI wins! Better luck next time.\n");
        else
            printf("Congratulations %s! You won!\n", player2Name);
    } 
    else 
    {
        printf("It's a draw!\n");
    }

    return 0;
}

