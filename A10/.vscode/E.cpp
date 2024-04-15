#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100001];
int in_degree[100001];

vector<int> topologicalSort(int n) {
    vector<int> order;
    queue<int> q;

    // Initialize in-degree array
    for (int i = 1; i <= n; ++i) {
        for (int v : adj[i]) {
            ++in_degree[v];
        }
    }

    // Push vertices with in-degree 0 into the queue
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // Perform topological sorting
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            --in_degree[v];
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If the topological sorting is valid, return the order
    if (order.size() == n) {
        return order;
    } else {
        return {};
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input the requirements and construct the graph
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    // Perform topological sorting
    vector<int> order = topologicalSort(n);

    // Output the result
    if (order.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
