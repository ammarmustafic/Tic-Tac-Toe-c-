#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>
#include <ctype.h>
using namespace std;

// x & o board
void display_board(char board[]) {
	system("cls");
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "-----------\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "-----------\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}


bool is_game_over(char board[]) {
    // horizontal win check
    for (int i = 0; i <= 6; i += 3) {
        if (board[i] == board[i + 1] && board[i] == board[i + 2]) {
            return true;
        }
    }
    // vertical win check
    for (int i = 0; i < 3; i++) {
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return true;
        }
    }
    // diagonal win check
    if (board[0] == board[4] && board[0] == board[8]) {
        return true;
    }
    if (board[2] == board[4] && board[2] == board[6]) {
        return true;
    }
    // full board
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    // tie game
    cout<<"Tie game";
    exit(0);
}

int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool game_over = false;
    int player = 1;
    int choice;
    char mark;
    while (!game_over) {
        display_board(board);
        cout << "Player " << player << ", enter a number (1-9): ";
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid move, try again.\n";
            Sleep(1000);
            continue;
        }
        mark = (player == 1) ? 'X' : 'O';
        if (choice == 1 && board[0] == '1') {
            board[0] = mark;
        } else if (choice == 2 && board[1] == '2') {
            board[1] = mark;
        } else if (choice == 3 && board[2] == '3') {
            board[2] = mark;
        } else if (choice == 4 && board[3] == '4') {
            board[3] = mark;
        } else if (choice == 5 && board[4] == '5') {
            board[4] = mark;
        } else if (choice == 6 && board[5] == '6') {
            board[5] = mark;
        } else if (choice == 7 && board[6] == '7') {
            board[6] = mark;
		}  else if (choice == 8 && board[7] == '8') {
        board[7] = mark;
    } else if (choice == 9 && board[8] == '9') {
        board[8] = mark;
    }

    game_over = is_game_over(board);

    if (game_over) {
        // winner
        display_board(board);
        if (player == 1) {
            cout << "Player 2 wins!\n";
        } else {
            cout << "Player 1 wins!\n";
        }
    } else if (player == 1) {
        player = 2;
    } else {
        player = 1;
    }
}
}
