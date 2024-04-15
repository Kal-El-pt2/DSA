#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1000005;

vector<int> adj[MAXN];
bool visited[MAXN];
int farthest_node;
int max_distance = 0;

void dfs(int node, int prev_node, int distance) {
    visited[node] = true;

    if (distance > max_distance) {
        max_distance = distance;
        farthest_node = node;
    }

    for (int next_node : adj[node]) {
        if (next_node != prev_node && !visited[next_node]) {
            dfs(next_node, node, distance + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    dfs(1, -1, 0); // Start DFS from an arbitrary node (here, 1)

    memset(visited, false, sizeof(visited));
    max_distance = 0;
    dfs(farthest_node, -1, 0); // Start DFS from the farthest node found in the first pass

    cout << max_distance << endl;

    return 0;
}
