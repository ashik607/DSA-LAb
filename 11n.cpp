

// Q11:- Write a program to find 
// the shortest path from a directed weighted multistage graph 
// using dynamic Algorithm.


#include<bits/stdc++.h>

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Graph {
public:
    int vertices;
    unordered_map<int, vector<int>> edges;
    unordered_map<pair<int, int>, int, hash_pair> weights;

    Graph(int vertices) {
        this->vertices = vertices;
    }

    void add_edge(int u, int v, int w) {
        // Add an edge to the graph with weight w
        edges[u].push_back(v);
        weights[{u, v}] = w;
    }
};

pair<vector<int>, int> shortest_path(Graph& graph, int source, int destination) {
    // Initialize the distance and parent arrays
    vector<int> distance(graph.vertices, numeric_limits<int>::max());
    distance[source] = 0;
    vector<int> parent(graph.vertices, -1);

    // Perform dynamic programming to find shortest paths
    for (int i = source; i < graph.vertices; i++) {
        for (int j : graph.edges[i]) {
            if (distance[j] > distance[i] + graph.weights[{i, j}]) {
                distance[j] = distance[i] + graph.weights[{i, j}];
                parent[j] = i;
            }
        }
    }

    // Build the shortest path by traversing the parent array
    vector<int> path;
    int node = destination;
    while (node != source) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());

    // Return the shortest path and shortest distance
    return make_pair(path, distance[destination]);
}

int main() {
    Graph g(8);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 2);
    g.add_edge(1, 3, 3);
    g.add_edge(1, 4, 2);
    g.add_edge(2, 3, 1);
    g.add_edge(2, 4, 3);
    g.add_edge(3, 5, 1);
    g.add_edge(4, 5, 2);
    g.add_edge(5, 6, 1);
    g.add_edge(6, 7, 1);

    // Find the shortest path from node 0 to node 7 and print the results
    auto result = shortest_path(g, 0, 7);
    vector<int> path = result.first;
    int distance = result.second;

    cout << "Shortest path:";
    for (int i : path) {
        cout << " " << i;
    }
    cout << endl;

    cout << "Shortest distance from source to destination: " << distance << endl;

    return 0;
}

