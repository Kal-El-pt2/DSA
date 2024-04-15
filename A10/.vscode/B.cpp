#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, cost;
};

const int MAXN = 2005;

int parent[MAXN];
int ranks[MAXN];

// Find operation with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union operation by rank
void union_sets(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
        if (ranks[root_x] < ranks[root_y]) {
            swap(root_x, root_y);
        }
        parent[root_y] = root_x;
        if (ranks[root_x] == ranks[root_y]) {
            ranks[root_x]++;
        }
    }
}

bool compare(const Edge& a, const Edge& b) {
    return a.cost < b.cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Edge> edges(n);
    for (int i = 0; i < n; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    }

    // Sorting edges by increasing cost
    sort(edges.begin(), edges.end(), compare);

    // Initializing disjoint set
    for (int i = 1; i <= MAXN; ++i) {
        parent[i] = i;
        ranks[i] = 0;
    }

    int min_cost = 0;
    for (const Edge& edge : edges) {
        if (find(edge.u) != find(edge.v)) {
            union_sets(edge.u, edge.v);
            min_cost += edge.cost;
        }
    }

    cout << min_cost << endl;

    return 0;
}
