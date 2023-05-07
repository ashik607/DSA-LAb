


// Q10:- Kruskal's algorithm is a
//  greedy algorithm in graph theory that finds a minimum spanning 
// tree for a connected weighted graph. 
// Implement Kruskal’s algorithm and find the 
// minimum spanning tree for the following graph.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) {
        V = vertices;
        graph = vector<vector<int>>(V);
    }

    void add_edge(int u, int v, int w) {
        graph.push_back({u, v, w});
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void apply_union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot] += 1;
        }
    }

    void kruskal_algo() {
        vector<vector<int>> result;
        int i = 0, e = 0;
        sort(graph.begin(), graph.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        vector<int> parent(V), rank(V, 0);
        for (int node = 0; node < V; node++) {
            parent[node] = node;
        }
        while (e < V - 1) {
            int u = graph[i][0];
            int v = graph[i][1];
            int w = graph[i][2];
            i = i + 1;
            int x = find(parent, u);
            int y = find(parent, v);
            if (x != y) {
                e = e + 1;
                result.push_back({u, v, w});
                apply_union(parent, rank, x, y);
            }
        }
        for (auto& edge : result) {
            cout << edge[0] << " - " << edge[1] << ": " << edge[2] << endl;
        }
    }
};

int main() {
    Graph g(6);
    g.add_edge(0, 1, 4);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 0, 4);
    g.add_edge(2, 0, 4);
    g.add_edge(2, 1, 2);
    g.add_edge(2, 3, 3);
    g.add_edge(2, 5, 2);
    g.add_edge(2, 4, 4);
    g.add_edge(3, 2, 3);
    g.add_edge(3, 4, 3);
    g.add_edge(4, 2, 4);
    g.add_edge(4, 3, 3);
    g.add_edge(5, 2, 2);
    g.add_edge(5, 4, 3);
    g.kruskal_algo();
    return 0;
}
