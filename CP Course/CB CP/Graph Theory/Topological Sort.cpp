#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Graph {
    map<int, list<int>> l;
    vector<bool> visited;
    list<int> ordering;
    vector<int> indegree;

public:
    void addEdge(int u, int v) {
        l[u].push_back(v); 
    }

    Graph(int N) {
        // Correctly initialize visited for all nodes, not just those in the adjacency list.
        visited.resize(N, false); 
        indegree.resize(N);
    }

    void dfs_helper(int src) {
        visited[src] = true;
        for (auto nbr : l[src]) {
            if (!visited[nbr]) {
                dfs_helper(nbr);
            }
        }
        ordering.push_front(src);
    }

    void dfs(int V) { // Need to know total number of vertices
        // Reset visited for all nodes before starting DFS
        fill(visited.begin(), visited.end(), false); 
        
        // Iterate through all possible vertices, not just those with outgoing edges
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs_helper(i);
            }
        }
    }

    void printTopologicalOrder(int V) {
        dfs(V);
        for (auto i : ordering) {
            cout << i << " ";
        }
        cout << endl;
        ordering.clear();
    }
};

int main(int argc, char const* argv[]) {
    int V, E, u, v;
    cin >> V >> E;

    Graph g(V);
    while (E--) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printTopologicalOrder(V);

    return 0;
}