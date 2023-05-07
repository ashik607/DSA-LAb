
// Q8. Write a program to solve the following 0/1 knapsack problem using dynamic programming 
// approach, profits P=(11, 21, 31, 33), weight W=(2, 11, 22, 15), knapsack capacity C=40 
// and no. of items n=4.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack01(vector<int>& W, vector<int>& P, int C, int n) {
    vector<vector<int>> table(n+1, vector<int>(C+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            if (W[i-1] > j) {
                table[i][j] = table[i-1][j];
            } else {
                table[i][j] = max(P[i-1] + table[i-1][j-W[i-1]], table[i-1][j]);
            }
        }
    }

    return table[n][C];
}

int main() {
    vector<int> W = {2, 11, 22, 15};
    vector<int> P = {11, 21, 31, 33};
    int C = 40;
    int n = 4;
    cout << knapsack01(W, P, C, n) << endl;

    return 0;
}
