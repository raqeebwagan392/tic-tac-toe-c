#include <stdio.h>

char board[3][3];
char current_marker;
int current_player;

void initialize_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '1' + i * 3 + j;
}

void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

int place_marker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return 1;
    } else {
        return 0;
    }
}

int check_winner() {
    // Check rows & columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

void swap_player_and_marker() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");

    initialize_board();
    current_marker = 'X';
    current_player = 1;
    int move_count = 0;

    print_board();

    while (1) {
        int slot;
        printf("Player %d (%c), enter your move (1-9): ", current_player, current_marker);
        scanf("%d", &slot);

        if (slot < 1 || slot > 9) {
            printf("Invalid slot. Try again.\n");
            continue;
        }

        if (!place_marker(slot)) {
            printf("Slot already taken. Try again.\n");
            continue;
        }

        move_count++;
        print_board();

        if (check_winner()) {
            printf("Player %d wins! ??\n", current_player);
            break;
        }

        if (move_count == 9) {
            printf("It's a draw! ??\n");
            break;
        }

        swap_player_and_marker();
    }

    return 0;
}
