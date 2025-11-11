#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int neig : adj[u]) {
        if (!visited[neig]) {
            dfs(neig);
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
    // Traverse each component
    for (int i = 1; i <= nodes; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    return 0;
}