#include <iostream>
#include <limits>
#include <cstdlib>
#include <windows.h>
using namespace std;

// x & o board
void display_board(char board[]) {
    system("cls");
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << "      |     |      \n";
    cout << "   " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "   \n";
    cout << " _____|_____|_____\n";
    cout << "      |     |      \n";
    cout << "   " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "   \n";
    cout << " _____|_____|_____\n";
    cout << "      |     |      \n";
    cout << "   " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "   \n";
    cout << "      |     |      \n";
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
    int player1_wins = 0;
    int player2_wins = 0;
    int choice;
    char mark;
    bool play_again = true; 
    while (play_again) {

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
    } else if (choice == 8 && board[7] == '8') {
        board[7] = mark;
    } else if (choice == 9 && board[8] == '9') {
        board[8] = mark;
    } else {
        cout << "Invalid move, try again.\n";
        Sleep(1000);
        continue;
    }

    game_over = is_game_over(board);

    if (game_over) {
        // winner
        display_board(board);
        if (player == 2) {
            cout << "Player 2 wins!\n";
            player2_wins++;
        } else {
            cout << "Player 1 wins!\n";
            player1_wins++;
        }
        char again;
        cout << "Do you want to play again? (Y/N): ";
        cin >> again;
        if (toupper(again) == 'Y') {
            // reset game
            for (int i = 0; i < 9; i++) {
                board[i] = '1' + i;
            }
            player = 1;
            game_over = false;
        } else if(toupper(again) == 'N'){
        	cout<<"\nPlayer 1 won: "<<player1_wins<<" times"<<" & Player 2 won: "<<player2_wins<<" times";
        	Sleep(1000);
            exit(0);
        }
        else {
        	cout<<"Invalid move. Run the code again";
        	Sleep(700);
        	exit(0);
		}
    } else if (player == 1) {
        player = 2;
    } else {
        player = 1;
    }
  }
}
return 0;
}

