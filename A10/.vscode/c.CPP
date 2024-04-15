#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

vector<int> adj[MAXN];
int subtree_size[MAXN]; // Store the size of subtree rooted at each node
int total_depth = 0;

void dfs(int node, int parent, int depth) {
    subtree_size[node] = 1; // Initialize subtree size for current node
    total_depth += depth;   // Add the depth of current node to total depth

    for (int next_node : adj[node]) {
        if (next_node != parent) {
            dfs(next_node, node, depth + 1);
            subtree_size[node] += subtree_size[next_node]; // Update subtree size
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Input edges of the tree
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform DFS starting from the root node (assuming root is node 1)
    dfs(1, -1, 0);

    // Output the total sum of depths of all subtree nodes
    cout << total_depth << endl;

    return 0;
}
