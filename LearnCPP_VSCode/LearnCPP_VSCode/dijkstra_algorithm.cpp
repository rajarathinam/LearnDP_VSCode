#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

void dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

int cidn() {
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    // Adding edges
    graph[0].push_back({ 1, 10 });
    graph[0].push_back({ 4, 5 });
    graph[1].push_back({ 2, 1 });
    graph[1].push_back({ 4, 2 });
    graph[2].push_back({ 3, 4 });
    graph[3].push_back({ 0, 7 });
    graph[4].push_back({ 1, 3 });
    graph[4].push_back({ 2, 9 });
    graph[4].push_back({ 3, 2 });

    int src = 0;
    dijkstra(graph, src);

    return 0;
}
