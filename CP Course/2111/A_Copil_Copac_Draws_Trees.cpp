#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Adjacency list to store pairs of {neighbor, edge_index}
vector<pair<int, int>> adj[200005];
int max_readings;

// DFS to calculate the number of readings for each node
void dfs(int u, int p, int current_readings, int parent_edge_idx) {
    // Update the overall maximum readings needed
    max_readings = max(max_readings, current_readings);

    // Iterate over all neighbors of the current vertex u
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int edge_idx = edge.second;

        // Skip the parent node
        if (v == p) {
            continue;
        }

        // Apply the recurrence relation to find the readings for the child v
        int child_readings = current_readings;
        if (edge_idx < parent_edge_idx) {
            child_readings++;
        }

        // Recurse for the child node
        dfs(v, u, child_readings, edge_idx);
    }
}

void solve() {
    int n;
    cin >> n;

    // Clear adjacency list for the current test case
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    // Read edges and build the adjacency list
    // The i-th edge read has index i
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    // Reset max_readings for the current test case
    max_readings = 0;

    // Start DFS from vertex 1.
    // dfs(u, parent, current_readings, parent_edge_index)
    // For the root (vertex 1):
    // - parent is 0 (or any invalid node)
    // - it's available in reading 1
    // - its parent's edge index is 0 (base case)
    dfs(1, 0, 1, 0);

    cout << max_readings << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}