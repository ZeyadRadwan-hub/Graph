#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adj;  // {node, weight}
vector<int> dis;

void dijkstra(int src) {
    int n = adj.size();
    dis.assign(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[src] = 0;
    pq.push({ 0, src });
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dis[u]) continue;
        for (auto& edge : adj[u]) {
            int v = edge.first, c = edge.second;
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
                pq.push({ dis[v], v });
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    adj.assign(nodes + 1, {});
    for (int i = 0; i < edges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({ to, weight });
        // For undirected: adj[to].push_back({from, weight});
    }
    dijkstra(1);  // Start from node 1
    for (int i = 1; i < nodes; ++i) {
        if (dis[i] == INT_MAX) {
            cout << i << ": INF ";
        }
        else {
            cout << i << ": " << dis[i] << " ";
        }
    }
    cout << endl;
    return 0;
}