// name: Haochen Shen
// unikey: hshe8202
// SID: 500021480

// code here
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define black '#'
#define white 'o'
#define off_board 'x'
#define empty '.'
#define board_size 19
#define max_long 16384
#define win_situation 5

// define a board with 19*19
char board[board_size][board_size];
// define actions history
char history[max_long] = "";
// initialize the go board
void initialize_board() {
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            board[i][j] = empty;
        }
    }
}
// end game print
void EndGame(char e) {
    if (e == black) {
        printf("Black wins!\n");
        printf("%s\n", history);
        printf("Thank you for playing!\n");
    }
    else if (e == white) {
        printf("White wins!\n");
        printf("%s\n", history);
        printf("Thank you for playing!\n");
    }
}

int main() {
    int nx = 10; // initial x-coordinate mist hole centre
    int ny = 10; // initial y-coordinate mist hole centre
    char current_player;
    char command[max_long];
    char position[max_long]; // the coordinates of each placing
    // position reference array
    char p[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S'};
    int round = 1;
    int c; // a number to judge if command "place " is correct
    initialize_board();
    // the game is on
    while(1) {
        // check if win
        for (int row = 0; row<board_size; row++) { // check each row
            for (int col = 0; col<board_size-win_situation+1; col++) {
                if (board[row][col] == board[row][col+1] &&
                    board[row][col] == board[row][col+2] &&
                    board[row][col] == board[row][col+win_situation-2] &&
                    board[row][col] == board[row][col+win_situation-1]) {
                    if (board[row][col] == black || board[row][col] == white) {
                        EndGame(board[row][col]);
                        return 0;
                    }
                }
            }
        }
        for (int col = 0; col<board_size; col++) { // check each column
            for (int row = 0; row<board_size-win_situation+1; row++) {
                if (board[row][col] == board[row+1][col] &&
                    board[row][col] == board[row+2][col] &&
                    board[row][col] == board[row+win_situation-2][col] &&
                    board[row][col] == board[row+win_situation-1][col]) {
                    if (board[row][col] == black || board[row][col] == white) {
                        EndGame(board[row][col]);
                        return 0;
                    }
                }
            }
        }
        for (int row = 0; row<board_size-win_situation+1; row++) { // check left diagonal
            for (int col = 0; col<board_size-win_situation+1; col++) {
                if (board[row][col] == board[row+1][col+1] &&
                    board[row][col] == board[row+2][col+2] &&
                    board[row][col] == board[row+win_situation-2][col+win_situation-2] &&
                    board[row][col] == board[row+win_situation-1][col+win_situation-1]) {
                    if (board[row][col] == black || board[row][col] == white) {
                        EndGame(board[row][col]);
                        return 0;
                    }
                }
            }
        }
        for (int row = 0; row<board_size-win_situation+1; row++) { // check right diagonal
            for (int col = board_size-1; col>win_situation-2; col--) {
                if (board[row][col] == board[row+1][col-1] &&
                    board[row][col] == board[row+2][col-2] &&
                    board[row][col] == board[row+win_situation-2][col-(win_situation-2)] &&
                    board[row][col] == board[row+win_situation-1][col-(win_situation-1)]) {
                    if (board[row][col] == black || board[row][col] == white) {
                        EndGame(board[row][col]);
                        return 0;
                    }
                }
            }
        }
        // check if tie
        int e = 1;
        for (int i = 0; i < board_size; i++) {
            if (e == 0) {
                break;
            }
            for (int j = 0; j < board_size; j++) {
                if (board[i][j] == empty) {
                    e = 0;
                    break;
                }
            }
        }
        if (e == 1) {
            printf("Wow, a tie!\n");
            printf("%s\n", history);
            printf("Thank you for playing!\n");
            return 0;
        }
        // input the command
        fgets(command, max_long, stdin);
        size_t len = strcspn(command, "\n"); // find the LF
        if (len < strlen(command)) {
            command[len] = '\0'; // Replaces a LF with an end-of-string symbol
        }
        c = strncmp(command, "place ", 6); // get the string "place " to compare with command. 6 is 6 characters of "place "
        // check the current player
        if (round % 2 == 1) {
            current_player = 'B';
        }
        else{
            current_player = 'W';
        }
        // if command is "who"
        if (strcmp(command, "who") == 0) {
            if (current_player == 'B') {
                printf("B\n");
            }
            else{
                printf("W\n");
            }
        }
        // if command is "resign"
        else if (strcmp(command, "resign") == 0) {
            round += 1;
            // check who resigned
            if (round % 2 == 1) {
                EndGame(black);
                return 0;
            }
            else {
                EndGame(white);
                return 0;
            }
        }
        // if command is "view"
        else if (strcmp(command, "view") == 0) {
            printf("%c%d,",p[nx-1], ny);
            // print the mist hole
            for (int i = -3; i<4; i++) { // the mist hole is 7*7, so, I choose the square which is from mist_centre-3 to mist_centre+3
                for (int j = -3; j<4; j++) {
                    // check if on the board
                    if (nx+j>board_size || nx+j<1 || board_size+1-ny+i>board_size || board_size+1-ny+i<1) {
                        printf("%c", off_board);
                    }
                    else {
                        printf("%c", board[board_size-ny+i][nx-1+j]);
                    }
                }
            }
            printf("\n");
        }
        // if command is "place <C><R>"
        else if (c == 0) {
            // check the format whether valid
            int count = 0;
            for (int i = 0; i<len; i++) { // check how many spaces in command, only one space is allowed
                if (command[i] == ' ') {
                    count += 1;
                }
            }
            if (sscanf(command, "%*s %s", position)!=1 || isspace(command[6]) || command[len-1]==' ' || count>1) { // the sixth character can't be space
                printf("Invalid!\n");
                continue;
            }
            // get y position
            int x;
            int y = 0;
            for (int i = 1; i<strlen(position); i++) {
                y = y*10 + (position[i] - '0'); // make the char to the int number
            }
            // change to numeric coordinates
            for (x = 1; x<board_size+1; x++) {
                if (p[x-1] == position[0]) {
                    if (y<board_size+1 && y>0) {
                        break;
                    }
                }
            }
            // check if the coordinates is on board
            if (x==board_size+1 || y>board_size || y<1 || command[7]=='0') { // the seventh character can't be 0
                printf("Invalid coordinate\n");
                continue;
            }
            // check if occupied
            else if (board[board_size-y][x-1] != empty) {
                printf("Occupied coordinate\n");
                continue;
            }
            else {
                round += 1;
            }
            // update board state
            if (current_player == 'B') {
                board[board_size-y][x-1] = black;
            }
            else{
                board[board_size-y][x-1] = white;
            }
            // get the centre coordinates of mist hole
            nx = 1 + (5*x*x + 3*x + 4) % 19;
            ny = 1 + (4*y*y + 2*y - 4) % 19;
            // put this action into history
            strcat(history, position);
        }
        // if command is "history"
        else if (strcmp(command, "history") == 0) {
            printf("%s\n", history);
        }
        // if command is "term"
        else if (strcmp(command, "term") == 0){
            return 1;
        }
        // the command is invalid
        else {
            printf("Invalid!\n");
            continue;
        }
    }
}