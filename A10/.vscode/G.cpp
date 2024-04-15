#include <climits>
#include<iostream>
#include<vector>
#include<queue>
#include<ios>

using namespace std;

const int INF = INT_MAX;
const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
vector<int> dist(MAXN, INF);

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] =0;
    pq.push({0,start});

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if(d > dist[u]){
            continue;
        }

        for(auto& edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});        
    }
    dijkstra(1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}