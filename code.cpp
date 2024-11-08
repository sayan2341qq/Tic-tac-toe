#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "\n\n";
    cout << "    Player 1 (X)  -  Player 2 (O)\n";
    cout << "    ------------------------\n";
    cout << "         |     |     \n";
    cout << "      " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    
    cout << "    _____|_____|_____\n";
    cout << "         |     |     \n";
    cout << "      " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "    _____|_____|_____\n";
    cout << "         |     |     \n";
    cout << "      " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "         |     |     \n";
    cout << "    ------------------------\n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return current_player;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return current_player;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return current_player;
    }

    return 0;
}

void swapPlayer() {
    if (current_player == 1) {
        current_player = 2;
        current_marker = 'O';
    } else {
        current_player = 1;
        current_marker = 'X';
    }
}

void game() {
    cout << "\nTic-Tac-Toe Game!\n";
    cout << "Player 1, choose your marker: X or O: ";
    char marker_p1;
    cin >> marker_p1;

    while (marker_p1 != 'X' && marker_p1 != 'O') {
        cout << "Invalid choice. Please choose X or O: ";
        cin >> marker_p1;
    }

    current_player = 1;
    current_marker = marker_p1;

    drawBoard();

    int player_won = 0;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << current_player << ", it's your turn. Enter your slot (1-9): ";
        int slot;
        cin >> slot;

        while (slot < 1 || slot > 9 || !placeMarker(slot)) {
            if (slot < 1 || slot > 9) {
                cout << "Invalid slot! Please choose a number between 1 and 9: ";
            } else {
                cout << "Slot already taken! Try a different slot: ";
            }
            cin >> slot;
        }

        drawBoard();

        player_won = checkWin();

        if (player_won == 1) {
            cout << "Player 1 (X) wins! Congratulations!\n";
            break;
        } else if (player_won == 2) {
            cout << "Player 2 (O) wins! Congratulations!\n";
            break;
        }

        swapPlayer();
    }

    if (player_won == 0) {
        cout << "It's a draw!\n";
    }
}

int main() {
    game();
    return 0;
}
