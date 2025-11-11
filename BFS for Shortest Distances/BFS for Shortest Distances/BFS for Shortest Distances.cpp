#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;
const int INF = 1e9;
vector<int> bfs(int src) {
    int n = adj.size();
    
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    adj.assign(nodes + 1, {});
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    auto dist = bfs(1);
    for (int i = 1; i < nodes; ++i) {
        if (dist[i] == INF) {
            cout << i << ": INF ";
        }
        else {
            cout << i << ": " << dist[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}