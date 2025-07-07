---
title: Solve Warmholes
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/warmholes
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Warmholes
tags:
  - clippings
status: Complete
explored: true
---
# Spacecraft Travel with Wormholes

There is a source ($S$) and a destination ($D$), and a spacecraft has to travel from $S$ to $D$. There are $N$ wormholes between the source and destination.  Each wormhole has the following properties:

*   Each wormhole has an entry and an exit.
*   Each wormhole is bi-directional (one can enter and exit from either end).
*   The time (cost) to cross the wormhole is given.
*   The spacecraft may or may not use the wormholes to reach $D$.

The cost to travel *outside* a wormhole between two points $(x_1, y_1)$ and $(x_2, y_2)$ is given by the Manhattan distance formula:

$$
|x_1 - x_2| + |y_1 - y_2|
$$

The coordinates of $S$ and $D$ are given.  The goal is to find the minimum cost to reach $D$ from $S$.  It's permissible to use any number of wormholes (including zero).

**Note:** It's not mandatory to consider all wormholes.

## Input Format

The first line contains $t$, the number of test cases.

For each test case:

*   Line 1 contains the value of $N$ (the number of wormholes).
*   Line 2 contains the source and destination coordinates: $S_x$, $S_y$, $D_x$, $D_y$.
*   The next $N$ lines contain the wormhole information.  Each wormhole is described by 5 values:
    *   $W_{ix}$, $W_{iy}$ (starting coordinates of the wormhole)
    *   $W_{ox}$, $W_{oy}$ (ending coordinates of the wormhole)
    *   $C_i$ (cost to pass through this wormhole)

## Constraints

*   $1 < t < 10$
*   $1 < N < 6$
*   $-1 < x < 101$
*   $-1 < y < 101$
*   $0 < \text{cost} < 101$

## Output Format

Output a single integer representing the minimum cost.

## Sample Input

```
1
3
0 0 100 100
1 2 120 120 16
2 5 120 100 21
6 8 150 180 16
```

## Sample Output

```
48
```

## Recursive Approach
```cpp
#include <iostream>  // Only for cin and cout

// Custom absolute value function
int my_abs(int x) {
    return (x < 0) ? -x : x;
}

// Custom minimum function
int my_min(int a, int b) {
    return (a < b) ? a : b;
}

// Structure to represent a point
struct Point {
    int x;
    int y;
};

// Structure to represent a wormhole
struct Wormhole {
    Point start;
    Point end;
    int cost;
};

// Calculate Manhattan distance
int calculate_distance(Point p1, Point p2) {
    return my_abs(p1.x - p2.x) + my_abs(p1.y - p2.y);
}

// Recursive function to find minimum cost
void solve(Point current, Point destination, Wormhole wormholes[], int num_wormholes, int current_cost, int visited[], int& min_cost) {

    // Calculate cost to go directly to the destination
    int direct_cost = current_cost + calculate_distance(current, destination);
    min_cost = my_min(min_cost, direct_cost);

    // Explore using each unvisited wormhole
    for (int i = 0; i < num_wormholes; ++i) {
        if (!visited[i]) {
            visited[i] = 1; // Mark as visited

            // Option 1: Enter at start, exit at end
            int cost1 = current_cost + calculate_distance(current, wormholes[i].start) + wormholes[i].cost;
            solve(wormholes[i].end, destination, wormholes, num_wormholes, cost1, visited, min_cost);

            // Option 2: Enter at end, exit at start
            int cost2 = current_cost + calculate_distance(current, wormholes[i].end) + wormholes[i].cost;
            solve(wormholes[i].start, destination, wormholes, num_wormholes, cost2, visited, min_cost);

            visited[i] = 0; // Backtrack: unmark as visited
        }
    }
}

int main() {
    int t;
    std::cin >> t;  // Use std::cin to avoid pulling in the entire std namespace

    while (t--) {
        int n;
        std::cin >> n;

        Point source, destination;
        std::cin >> source.x >> source.y >> destination.x >> destination.y;

        Wormhole wormholes[6]; // Max 6 wormholes
        for (int i = 0; i < n; ++i) {
            std::cin >> wormholes[i].start.x >> wormholes[i].start.y;
            std::cin >> wormholes[i].end.x >> wormholes[i].end.y;
            std::cin >> wormholes[i].cost;
        }

        int visited[6] = {0}; // Keep track of visited wormholes (initialized to all 0s)
        int min_cost = 2147483647;   // Initialize to maximum integer value (instead of INT_MAX)

        solve(source, destination, wormholes, n, 0, visited, min_cost);

        std::cout << min_cost << std::endl;
    }

    return 0;
}
```
## Dijkstra's Approach (Fail)
```cpp
#include <iostream>
using namespace std;
int n;
int x[13];
int y[13];
int w[5];
int g[13][13];
int vis[13];

int abs(int a){
    if(a<0) return -1*a;
    return a;
}

int min(int a,int b){
    if(a<b) return a;
    return b;
}

int minind(int* dist,int k){
    int ans=-1;
    int minval=100000;
    for(int i=0;i<k;i++){
        if(!vis[i] && dist[i]<minval){
            ans=i;
            minval=dist[i];
        }    
    }
    return ans;
}

int dijkstra(int k){
    int dist[k];
    for(int i=0;i<k;i++) dist[i]=100000;
    dist[0]=0;
    for(int i=0;i<k;i++){
        int index=minind(dist,k);
        vis[index]=1;
        for(int j=0;j<k;j++){
            if(!vis[j] && g[index][j]!=0 && dist[j]>dist[index]+g[index][j]){
                dist[j]=dist[index]+g[index][j];
            }
        }
    }
    return dist[1];
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    cin >> n;
	    cin >> x[0] >> y[0] >> x[1] >> y[1] ;
	    int k=2;
	    for(int j=0;j<n;j++){
	        cin >> x[k] >> y[k];
	        k++;
	        cin >> x[k] >> y[k];
	        cin >> w[k-1];
	        k++;
	    }
	    for(int i=0;i<k;i++) vis[i]=0;
	    for(int i=0;i<k;i++){
	        for(int j=i+1;j<k;j++){
	            g[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	            g[j][i]=g[i][j];
	            if(i%2==0 && j==i+1 && i!=0){
	                g[i][j]=min(g[i][j],w[i]);
	                g[j][i]=min(g[j][i],w[i]);
	            }
	        }
	    }
	    cout << dijkstra(k) << endl;
	}
	return 0;
}
```

## Floyd-Warshall Approach (BEST)
```cpp
#include <iostream> // Only for cin and cout

// Custom absolute value function
int my_abs(int x) {
    return (x < 0) ? -x : x;
}

// Custom minimum function
int my_min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        int x[14], y[14]; // Arrays to store coordinates (max 2*6 + 2 = 14)
        int w[6];        // Array to store wormhole costs

        // Read source and destination
        std::cin >> x[0] >> y[0] >> x[1] >> y[1];

        // Read wormhole data
        int k = 2;
        for (int i = 0; i < n; i++) {
            std::cin >> x[k] >> y[k]; // Entry
            k++;
            std::cin >> x[k] >> y[k]; // Exit
            std::cin >> w[i];
            k++;
        }

        int num_nodes = 2 * n + 2;
        int dist[14][14];

        // Initialize the distance matrix
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (i == j) {
                    dist[i][j] = 0; // Distance to itself is 0
                } else {
                    dist[i][j] = 2147483647; // Initialize to a large value (instead of INT_MAX)
                }
            }
        }

        // Set initial distances based on Manhattan distance and wormholes
        for (int i = 0; i < num_nodes; i++) {
            for (int j = i + 1; j < num_nodes; j++) {
                int manhattan_dist = my_abs(x[i] - x[j]) + my_abs(y[i] - y[j]);
                dist[i][j] = dist[j][i] = manhattan_dist;
            }
        }
        for (int i = 0; i < n; ++i) {
            int entry_node = 2 + 2 * i;
            int exit_node = 3 + 2 * i;
            dist[entry_node][exit_node] = my_min(dist[entry_node][exit_node], w[i]);
            dist[exit_node][entry_node] = my_min(dist[exit_node][entry_node], w[i]);
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < num_nodes; k++) {
            for (int i = 0; i < num_nodes; i++) {
                for (int j = 0; j < num_nodes; j++) {
                    // Check for overflow before adding
                    if (dist[i][k] != 2147483647 && dist[k][j] != 2147483647 &&
                        dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Output the shortest distance from source (0) to destination (1)
        std::cout << dist[0][1] << std::endl;
    }
    return 0;
}

```

