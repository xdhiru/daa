#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int prim() {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> key(n, 999999);  // Manual maximum value
        vector<int> parent(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        key[0] = 0;
        pq.push(make_pair(0, 0));

        int mstCost = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            mstCost += key[u];

            for (auto v : adj[u]) {
                if (!visited[v.first] && v.second < key[v.first]) {
                    key[v.first] = v.second;
                    parent[v.first] = u;
                    pq.push(make_pair(v.second, v.first));
                }
            }
        }

        return mstCost;
    }
};

int main() {
    Graph abc(13);
    abc.addEdge(0, 1, 10);
    abc.addEdge(0, 2, 6);
    abc.addEdge(0, 3, 5);
    abc.addEdge(1, 3, 15);
    abc.addEdge(2, 3, 4);
    abc.addEdge(2, 4, 2);
    abc.addEdge(3, 4, 1);

    cout << "Minimum Spanning Tree Cost: " << abc.prim() << endl;

    return 0;
}
