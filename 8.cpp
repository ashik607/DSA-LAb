

// #Problem-8: Write a program to solve 𝑛 queen's 
// # problem using backtracking

#include <iostream>
using namespace std;

const int MAX = 10;

int N, board[MAX][MAX];

int is_attack(int i, int j) {
    // checking if there is a queen in row or column
    for (int k = 0; k < N; k++) {
        if (board[i][k] == 1 || board[k][j] == 1)
            return 1;
    }

    // checking diagonals
    for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
            if ((k + l == i + j) || (k - l == i - j)) {
                if (board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen(int n) {
    // if n is 0, solution found
    if (n == 0)
        return 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            /* checking if we can place a queen here or not
             * queen will not be placed if the place is being attacked
             * or already occupied
             */
            if ((!is_attack(i, j)) && (board[i][j] != 1)) {
                board[i][j] = 1;
                // recursion
                // whether we can put the next queen with this arrangement or not
                if (N_queen(n - 1) == 1)
                    return 1;
                board[i][j] = 0;
            }
        }
    }
    return 0;
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> N;

    // NxN matrix with all elements 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    N_queen(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
