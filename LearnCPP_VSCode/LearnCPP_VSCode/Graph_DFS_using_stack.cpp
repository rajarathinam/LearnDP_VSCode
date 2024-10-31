#include "stub.h"
using namespace std;


bool hasRoute(std::vector<std::vector<int>>& graph, int start, int destination)
{
    int n = static_cast<int>(graph.size());
    vector<bool> visited(n, false);
    vector<int> predecessor(n, -1);

    stack<int> S;
    S.push(start);

    while (!S.empty())
    {
        int current = S.top();
        S.pop();
        visited[current] = true;

        if(current == destination) {
            // Print the path by backtracking from the destination
            std::vector<int> path;
            for (int at = destination; at != -1; at = predecessor[at]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());  // Reverse the path to start -> destination

            std::cout << "Path from " << start << " to " << destination << ": ";
            for (int node : path) {
                std::cout << node << " ";
            }
            std::cout << "\n";
            return true;
        }

        for (int neighbour : graph[current])
        {
            if (visited[neighbour] == false)
            {
                S.push(neighbour);
                predecessor[neighbour] = current; //important step
            }
        }    
    }
    return false;
}
void IterativeDFS(std::vector<std::vector<int>>& graph, int start) {
    int n = static_cast<int>(graph.size());
    std::vector<bool> visited(n, false);
    visited[start] = true;
    std::stack<int> S;
    S.push(start);

    while (!S.empty()) {
        int current = S.top();
        S.pop();
        std::cout << current << " ";

        for (int neighbor : graph[current]) {
            if (visited[neighbor] == false) { // Not visited
                S.push(neighbor); // Push to stack
                visited[neighbor] = true; // Make it visited
            }
        }
    }
}


int main()
{
	int n = 4;
	std::vector<std::vector<int>> graph(n);
	graph[0].push_back(1);
	graph[0].push_back(2);
	graph[1].push_back(2);
	graph[1].push_back(0);
	graph[2].push_back(3);
    graph[3].push_back(2);
	graph[2].push_back(1);
	graph[2].push_back(0);
	
	int start = 0;
	IterativeDFS(graph, start);

    if (hasRoute(graph, 1, 3))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }


	return 0;
}