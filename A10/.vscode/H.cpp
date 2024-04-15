#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

struct Edge {
    int from, to;
    long long weight;
};

vector<Edge> edges;

void addEdge(int from, int to, long long weight) {
    edges.push_back({from, to, weight});
}

bool negativeCycle(int n) {
    vector<long long> dist(n + 1, INF);
    dist[1] = 0; // Start from node 1

    for (int i = 0; i < n - 1; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    // Check for negative cycles
    for (const Edge& edge : edges) {
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
            return true; // Negative cycle detected
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    if (negativeCycle(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
