#include<bits/stdc++.h>
using namespace std;

class Graph {
    map<int, list<int>> g;
    map<int, list<int>> rg;
    int V;
    vector<int> order;
    vector<bool> visit;

public:
    Graph(int n): V{n}, visit(n, false) {}

    void addEdge(int u, int v) {
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    void dfs_handler(int src) {
        visit[src] = true;

        for (int nbr : g[src]) {
            if (!visit[nbr]) dfs_handler(nbr);
        }

        order.push_back(src);
    }

    void dfs() {
        fill(visit.begin(), visit.end(), false);

        for (auto p : g) {
            int node = p.first;
            if (!visit[node]) dfs_handler(node);
        }
    }

    void printOrder() {
        dfs();
        for (int i : order) cout << i << " ";
        order.clear();
    }

    void dfs2_handler(int src) {
        // Start SCC discovery
        visit[src] = true;
        cout << src << " ";

        for (int nbr : rg[src]) {
            if (!visit[nbr]) {
                dfs2_handler(nbr);
            }
        }
    }

    void SSC() {
        // Step 1: DFS to get the finishing order
        dfs();

        // Step 2: Reverse the order for second DFS
        reverse(order.begin(), order.end());

        fill(visit.begin(), visit.end(), false);

        char c = 'A';
        for (int i : order) {
            if (!visit[i]) {
                cout << "SSC " << c << " : ";
                dfs2_handler(i);
                cout << endl;
                c++;  // Move to the next SCC label
            }
        }
    }
};

int main() {
    int V, E, x, y;
    cin >> V >> E;
    Graph g(V);
    while (E--) {
        cin >> x >> y;
        g.addEdge(x, y);
    }

    // Call the SCC detection function
    g.SSC();

    return 0;
}
