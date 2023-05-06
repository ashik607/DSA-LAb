


// #Problem-9: Write a program to find the
//  shortest path from a graph using Kruskal’s Algorithm
// # Kruskal Algorithm  in Python


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// structure to represent a weighted edge in the graph
class Edge {
public:
    int src, dest, weight;
};

// class to represent a connected, undirected, weighted graph
class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int V) {
        this->V = V;
    }

    // function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        Edge e = {src, dest, weight};
        edges.push_back(e);
    }

    // find the parent of a vertex
    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    // apply union of two vertices
    void applyUnion(int parent[], int rank[], int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    // function to apply Kruskal's algorithm
    void kruskalMST() {
        vector<Edge> result;
        int i = 0, e = 0;
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
            return a.weight < b.weight;
        });
        int parent[V], rank[V];
        for (int v = 0; v < V; v++) {
            parent[v] = v;
            rank[v] = 0;
        }
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);
            if (x != y) {
                e++;
                result.push_back(next_edge);
                applyUnion(parent, rank, x, y);
            }
        }
        cout << "The shortest path:\n";
        for (auto edge : result) {
            cout << edge.src << " - " << edge.dest << ": " << edge.weight << "\n";
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 0, 4);
    g.addEdge(2, 0, 4);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 2, 4);
    g.addEdge(4, 3, 3);
    g.addEdge(5, 2, 2);
    g.addEdge(5, 4, 3);
    g.kruskalMST();
    return 0;
}
