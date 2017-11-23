/*
 This program runs a game similar to the game 'Connect Four'.
 This program begins by taking the input of the 
 number of rows, number of columns, and the consecutive number of pieces required to win the game!
 Command Line Arguement clone:  ./connectn.out 3 3 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void playerPiece(char *playerCounter, int *counter, int *rows, int *cols, int *playmove, char **board);
void board_create(int *rowsMinusOne, int *rows, int *cols, char **board);
void starboard(char **board, int rows, int cols);
void tieGame(int *wins, int *playmove, int *cols, int *rows, char **board);
void horizontalwin(int *wins, int *playmove, int *cols, int *rows, char **board);
void Leftdiagonalwin(int *wins, int *playmove, int *cols, int *rows, char **board);
void verticalwin(int *wins, int *playmove, int *cols, int *rows, char **board);
void Rightdiagonalwin(int *wins, int *playmove, int *cols, int *rows, char **board);

// Input validation for the command line arguements.
void CLAvalidation(int val) {
    if (val < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    if (val > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
}

// Input validation for the column in which the piece is played.
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    
    do {
        scanf("%c", &character);
        if (!isspace(character)) {
            formatIsGood = false;
        }
        // formatIsGood = formatIsGood && isspace(character);
        // formatIsGood = isspace(character) ? formatIsGood : false;
    } while (character != '\n');
    
    return formatIsGood;
}

// Asking the user for the column the piece is to be played in.
int getPosInt(int *rows, int *cols, char **board ) {
    int posInt;
    int rowsMinusOne = *rows - 1;
    int colMinusOne = *cols - 1;
    
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("Enter a column between 0 and %d to play in: ", colMinusOne);
        numArgsRead = scanf(" %d", &posInt);
    } while (!(isValidFormat(numArgsRead, numArgsNeeded) &&
               posInt >= 0 && posInt <= colMinusOne && board[rowsMinusOne][posInt] == '*'));
    
    return posInt;
}

// Initially assigning every place of the board to '*'
void starboard(char **board, int rows, int cols) {
    // Star Board
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'O' || board[i][j] == 'X') {
                continue;
            } else {
                board[i][j] = '*';
            }
        }
    }
}

// Creating the entire board
void board_create(int *rowsMinusOne, int *rows, int *cols, char **board) {
    int i, j;
    *rowsMinusOne = *rows - 1;
    
    // Star Board
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            if (board[i][j] == 'O' || board[i][j] == 'X') {
                continue;
            } else {
                board[i][j] = '*';
            }
        }
    }
    
    // Num Board
    for (i = *rowsMinusOne; i >= 0; i--) {
        // printing the row number
        printf("%d ", i);
        for (j = 0; j < *cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
        // printing the column number
    for (j = 0; j < *cols; j++) {
        if (j == 0) {
            printf("  0 ");
        } else {
            printf("%d ", j);
        }
    }
    printf("\n");
    
    return;
}

// Alternating between piece X and O.
void playerPiece(char *playerCounter, int *counter, int *rows, int *cols, int *playmove, char **board) {
    int i;
    
    *playmove = getPosInt(rows, cols, board);
    // First person to play the game recieves the X-piece
    if (*counter % 2 == 0) {
        *playerCounter = 'X';
        *counter = *counter + 1;
    } else {
        *playerCounter = 'O';
        *counter = *counter + 1;
    }
    // Starting from the bottom of a column, replace the first '*' with the player's piece
    for (i = 0; i <= *rows; i++) {
        if (board[i][*playmove] == '*') {
            board[i][*playmove] = *playerCounter;
            break;
        }
    }
    return;
}

// Checking the board for a horizontal win
void horizontalwin(int *wins, int *playmove, int *cols, int *rows, char **board) {
    int i, j;
    // Xcounter counts the number of X's in the row
    int xcounter = 0;
    int ocounter = 0;
    
    // The entire board is checked for a horizontal play after every move
    for (i = 0; i < *rows; i++) {
        xcounter = 0;
        ocounter = 0;
        for (j = 0; j < *cols; j++) {
            // Checking the board for 'X', 'O', '*' and altering the counter accordingly
            if (board[i][j] == 'X') {
                xcounter = xcounter + 1;
                ocounter = 0;
                if (xcounter == *wins) {
                    printf("Player 1 Won!\n");
                    exit(0);
                }
            } else if (board[i][j] == '*') {
                xcounter = 0;
                ocounter = 0;
            } else if (board[i][j] == 'O') {
                xcounter = 0;
                ocounter = ocounter + 1;
                if (ocounter == *wins) {
                    printf("Player 2 Won!\n");
                    exit(0);
                }
            }
        }
    }
    return;
}

// Checking the board for a vertical win
void verticalwin(int *wins, int *playmove, int *cols, int *rows, char **board) {
    int i, j;
    // Xcounter counts the number of X's in the row
    int xcounter = 0;
    int ocounter = 0;
    
    // The entire board is checked for a vertical play after every move
    for (j = 0; j < *cols; j++) {
        xcounter = 0;
        ocounter = 0;
        for (i = 0; i < *rows; i++) {
            // Checking the board for 'X', 'O', '*' and altering the counter accordingly
            if (board[i][j] == 'X') {
                xcounter = xcounter + 1;
                ocounter = 0;
                if (xcounter == *wins) {
                    printf("Player 1 Won!\n");
                    exit(0);
                }
            } else if (board[i][j] == '*') {
                xcounter = 0;
                ocounter = 0;
            } else if (board[i][j] == 'O') {
                xcounter = 0;
                ocounter = ocounter + 1;
                if (ocounter == *wins) {
                    printf("Player 2 Won!\n");
                    exit(0);
                }
            }
        }
    }
    return;
}

// Checking the board diagonally from the left to the right
void Leftdiagonalwin(int *wins, int *playmove, int *cols, int *rows, char **board) {
    int i = 0, j;
    int xcounter = 0, ocounter = 0;
    int Trows = *rows - 1;
    int newcols = *cols - 1;
    int Tcols = newcols;
    j = newcols;
    
    for (i = 0; i < *rows; i++) {
        // Checking the board for 'X', 'O', '*' and altering the counter accordingly
        if (board[i][j] == 'X') {
            xcounter = xcounter + 1;
            ocounter = 0;
            if (xcounter == *wins) {
                printf("Player 1 Won!\n");
                exit(0);
            }
        } else if (board[i][j] == '*') {
            xcounter = 0;
            ocounter = 0;
        } else if (board[i][j] == 'O') {
            xcounter = 0;
            ocounter = ocounter + 1;
            if (ocounter == *wins) {
                printf("Player 2 Won!\n");
                exit(0);
            }
        }
        // When one diagonal line ends, the i-counter is set to 0 and
        // the j-counter is set to 1 less than the columns (j = number of columns - 1) to begin the next diagonal line
        // Setting the xcounter and ocounter both to 0 as the line is changing.
        if (i == Trows) {
            i = -1;
            Trows--;
            Tcols--;
            j = Tcols;
            j++;
            xcounter = 0;
            ocounter = 0;
        }
        j--;
    }
    
    // offset by 1 and this offset increments with the change in every line
    int startrow = 1;
    int Scols = *cols - 1;
    int k = Scols;
    int Srows = *rows - 1;
    for (i = startrow; i < *rows; i++) {
        if (board[i][k] == 'X') {
            xcounter = xcounter + 1;
            ocounter = 0;
            // Checking the board for 'X', 'O', '*' and altering the counter accordingly
            if (xcounter == *wins) {
                printf("Player 1 Won by x left!\n");
                exit(0);
            }
        } else if (board[i][k] == '*') {
            xcounter = 0;
            ocounter = 0;
        } else if (board[i][k] == 'O') {
            xcounter = 0;
            ocounter = ocounter + 1;
            if (ocounter == *wins) {
                printf("Player 2 Won by x left!\n");
                exit(0);
            }
        }
        if (i == Srows) {
            i = startrow;
            startrow++;
            k  = Scols + 1;
            xcounter = 0;
            ocounter = 0;
        }
        k--;
    }
    
    return;
}

// Checking the board diagonally from the right to left
void Rightdiagonalwin(int *wins, int *playmove, int *cols, int *rows, char **board) {
    int start = 0;
    int j = 0;
    int i, xcounter = 0, ocounter = 0;
    int finalrows = *rows -1;
    for (i = 0; i < *rows; i++) {
        // Checking the board for 'X', 'O', '*' and altering the counter accordingly
        if (board[i][j] == 'X') {
            xcounter = xcounter + 1;
            ocounter = 0;
            if (xcounter == *wins) {
                printf("Player 1 Won!\n");
                exit(0);
            }
        } else if (board[i][j] == '*') {
            xcounter = 0;
            ocounter = 0;
        } else if (board[i][j] == 'O') {
            xcounter = 0;
            ocounter = ocounter + 1;
            if (ocounter == *wins) {
                printf("Player 2 Won!\n");
                exit(0);
            }
        }
        // When one diagonal line ends, the i-counter is set to 0 and
        // the j-counter is set to one more than the column it begun with.
        // Setting the xcounter and ocounter both to 0 as the line is changing.
        if (i == finalrows) {
            i = -1;
            j = start;
            start++;
            xcounter = 0;
            ocounter = 0;
        }
        if (j > *cols) {
            break;
        }
        j++;
    }
    
    // offset by 1 and this offset increments with the change in every line
    int col_2 = *cols - 2;
    int rowstart = 1;
    int k = 0;
    for (i = rowstart; i < *rows; i++) {
        // Checking the board for 'X', 'O', '*' and altering the counter accordingly
        if (board[i][k] == 'X') {
            xcounter = xcounter + 1;
            ocounter = 0;
            if (xcounter == *wins) {
                printf("Player 1 Won by x right!\n");
                exit(0);
            }
        } else if (board[i][k] == '*') {
            xcounter = 0;
            ocounter = 0;
        } else if (board[i][k] == 'O') {
            xcounter = 0;
            ocounter = ocounter + 1;
            if (ocounter == *wins) {
                printf("Player 2 Won by x right!\n");
                exit(0);
            }
        }
        // When one diagonal line ends, the k-counter is set to 0 and
        // the i-counter is set to one more than the row it begun with.
        // Setting the xcounter and ocounter both to 0 as the line is changing.
        if (k == col_2) {
            rowstart++;
            i = rowstart - 1;
            col_2--;
            k = -1;
            xcounter = 0;
            ocounter = 0;
        }
        k++;
    }
    
    return;
}

// Checking if the game ends in a tie. This takes place when there are no more '*' on the board.
void tieGame(int *wins, int *playmove, int *cols, int *rows, char **board) {
    int i, j, tie = 0, tiegame = 0;
    
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            if (board[i][j] == '*') {
                tiegame++;
            } else {
                tie = -1;
            }
        }
    }
    if (tiegame > 0) {
        return;
    }
    if (tie < 0) {
        printf("Tie game!");
        exit(0);
    }
    return;
}

// Control Panel
int playgame(int argc, char *argv[]) {
    int  rows, cols, wins, playmove, counter = 0; int game_win = 200000;
    char playerCounter;
    
    CLAvalidation(argc);
    // Storing the values from the command line into rows/columns/no.of pieces needed to win
    sscanf(argv[1], "%d", &rows);
    sscanf(argv[2], "%d", &cols);
    sscanf(argv[3], "%d", &wins);
    
    int rowsMinusOne = rows;
    
    char **board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        board[i] = (char*)malloc(cols * sizeof(char));
    }
    
    starboard(board, rows, cols);
    board_create(&rowsMinusOne, &rows, &cols, board);
    // Game is played till a player wins or the game ends in a tie.
    for (int i = 0; i < game_win; i++) {
        playerPiece(&playerCounter, &counter, &rows, &cols, &playmove, board);
        board_create(&rowsMinusOne, &rows, &cols, board);
        tieGame(&wins, &playmove, &cols, &rows, board);
        horizontalwin(&wins, &playmove, &cols, &rows, board);
        verticalwin(&wins, &playmove, &cols, &rows, board);
        Rightdiagonalwin(&wins, &playmove, &cols, &rows, board);
        Leftdiagonalwin(&wins, &playmove, &cols, &rows, board);
    }
    
    return 0;
}

int main(int argc, char *argv[]) {
    playgame(argc, argv);
    
    return 0;
}
