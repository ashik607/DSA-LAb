

// Q13:- The eight queen’s puzzle is the problem of placing eight chess queens on an 8×8 
// chessboard so that no two queens attack each other. Thus, a solution requires that no two 
// queens share the same row, column, or diagonal. The eight queen’s puzzle is an example 
// of the more general n-queens problem of placing n queens on an n×n chessboard, where 
// solutions exist for all natural numbers n with the exception of 2 and 3. Write a program to 
// solve the n-queens problem.


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class QueenChessBoard {
public:
    QueenChessBoard(int size) : size(size) {
        columns.resize(size);
    }

    void place_in_next_row(int column) {
        columns.push_back(column);
    }

    int remove_in_current_row() {
        int last_column = columns.back();
        columns.pop_back();
        return last_column;
    }

    bool is_this_column_safe_in_next_row(int column) {
        int row = columns.size();
        for (int queen_row = 0; queen_row < row; ++queen_row) {
            int queen_column = columns[queen_row];
            if (column == queen_column) {
                return false;
            }
            if (abs(column - queen_column) == row - queen_row) {
                return false;
            }
        }
        return true;
    }

    void display() {
        for (int row = 0; row < size; ++row) {
            for (int column = 0; column < size; ++column) {
                if (column == columns[row]) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

private:
    int size;
    vector<int> columns;
};

void solve_queen(int size) {
    QueenChessBoard board(size);
    int number_of_solutions = 0;

    int row = 0;
    int column = 0;
    while (true) {
        while (column < size) {
            if (board.is_this_column_safe_in_next_row(column)) {
                board.place_in_next_row(column);
                row += 1;
                column = 0;
                break;
            } else {
                column += 1;
            }
        }
        if (column == size || row == size) {
            if (row == size) {
                board.display();
                number_of_solutions += 1;
                board.remove_in_current_row();
                row -= 1;
            }
            try {
                int prev_column = board.remove_in_current_row();
                row -= 1;
                column = prev_column + 1;
            } catch (const out_of_range& e) {
                break;
            }
        }
    }
    cout << "Number of solutions: " << number_of_solutions << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    solve_queen(n);
    return 0;
}
