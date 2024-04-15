#include<iostream>
#include<vector>
#include<ios>

using namespace std;

const int MAXN = 10000005;

vector<int> adj[MAXN];
int subtree_size[MAXN];

int n;

void dfs(int node, int parent) {
    subtree_size[node] = 1; // Initialize subtree size for current node
    int max_subtree_size = 0; // Initialize maximum subtree size encountered so far

    // Calculate subtree size for each child node
    for (int next_node : adj[node]) {
        if (next_node != parent) {
            dfs(next_node, node);
            subtree_size[node] += subtree_size[next_node]; // Update subtree size for current node
            max_subtree_size = max(max_subtree_size, subtree_size[next_node]); // Update max subtree size
        }
    }

    // Check if current node is a centroid
    max_subtree_size = max(max_subtree_size, n - subtree_size[node]); // Update max subtree size with remaining nodes
    if (max_subtree_size <= n / 2) {
        cout << node << endl; // Output the centroid
        // To find all centroids, you can store them in a vector instead of outputting here.
    }
}

void findCentroid() {
    dfs(1, -1); // Start DFS from any node (here, node 1)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findCentroid();

    return 0;
}
