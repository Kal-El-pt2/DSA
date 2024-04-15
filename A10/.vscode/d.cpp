#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000005;

vector<int> adj[MAXN];

int shortestPath(int start, int dest, int parent, int depth) {
    if (start == dest) {
        return depth;
    }
    for (int next_node : adj[start]) {
        if (next_node != parent) {
            int result = shortestPath(next_node, dest, start, depth + 1);
            if (result != -1) {
                return result;
            }
        }
    }
    return -1;
}

void pathPrinter(int start, int dest, int parent, int min_length, vector<int>& temp) {
    temp.push_back(start);
    if (start == dest) {
        return;
    }
    for (int next_node : adj[start]) {
        if (next_node != parent) {
            pathPrinter(next_node, dest, start, min_length, temp);
        }
    }
    if (temp.size() == min_length && temp[min_length -1] == dest) {
        for (int i : temp) {
            cout << i << " ";
        }
    }
}

int main() {
    int v, e, s, d;
    cin >> v >> e >> s >> d;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int min_length = shortestPath(s, d, -1, 0);
    vector<int> path;
    pathPrinter(s, d, -1, min_length, path);
    cout << endl;

    return 0;
}
