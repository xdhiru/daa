//Display the data stored in a given graph using the Depth -First Search Algorithm.

#include <iostream>
#include <vector>
#include <stack>
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

    void DFS(int src, vector<bool>& visited) {
        stack<int> s;
        s.push(src);
        visited[src] = true;

        while (!s.empty()) {
            int u = s.top();
            s.pop();
            cout << u << " ";

            for (auto v : adj[u]) {
                if (!visited[v]) {
                    s.push(v);
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

    vector<bool> visited(abc.adj.size(), false);
    abc.DFS(0, visited);

    return 0;
}