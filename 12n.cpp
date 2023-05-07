
// Q12:- Write a program to find 
// the all pair shortest path from a graph using Floyd warshall’s
// Algorithm.


#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    vector<vector<double>> graph = {
        {0, 3, INFINITY, 7},
        {8, 0, 2, INFINITY},
        {5, INFINITY, 0, 1},
        {2, INFINITY, INFINITY, 0}
    };
    int num_nodes = graph.size();

    vector<vector<double>> distance(num_nodes, vector<double>(num_nodes, 0));

    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            distance[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < num_nodes; k++) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    cout << "All Pair Shortest Path Distance Matrix: " << endl;
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (distance[i][j] == INFINITY) {
                cout << "INF ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
