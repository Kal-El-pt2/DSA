#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countConnectedComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n + 1);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Assuming undirected graph
    }

    vector<bool> visited(n + 1, false);
    int connectedComponents = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            ++connectedComponents;
        }
    }

    return connectedComponents;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int components = countConnectedComponents(n, edges);
    cout << components << endl;

    return 0;
}
