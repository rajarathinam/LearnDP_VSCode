#include <iostream>
#include <vector>
#include <stack>

class Graph {
public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void DFS(int start) {
        std::vector<bool> visited(vertices, false);
        DFSUtil(start, visited);
    }

private:
    int vertices;
    std::vector<std::vector<int>> adjList;

    void DFSUtil(int v, std::vector<bool>& visited) {
        // Mark the current node as visited
        visited[v] = true;
        std::cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int i : adjList[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
};

int sjshs() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 4);

    std::cout << "Depth-First Traversal starting from vertex 0:\n";
    g.DFS(0);

    return 0;
}
