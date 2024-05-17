//Q7: Display the data stored in a given graph using the Breadth -First Search Algorithm.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    Graph(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int src) {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};

int main() {
    Graph abc(13);
    abc.addEdge(0, 12);
    abc.addEdge(0, 2);
    abc.addEdge(1, 9);
    abc.addEdge(2, 6);
    abc.addEdge(2, 4);
    abc.addEdge(3, 10);
    abc.addEdge(4, 5);

    abc.BFS(0);

    return 0;
}