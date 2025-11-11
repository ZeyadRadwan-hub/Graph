#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int neig : adj[u]) {
            if (!visited[neig]) {
                visited[neig] = true;
                q.push(neig);
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    adj.assign(nodes + 1, {});
    visited.assign(nodes + 1, false);
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    bfs(1);  // Start from node 1
    return 0;
}