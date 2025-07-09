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
status: ReDone
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

## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
    int distance(Point &p){
        return abs(x-p.x)+abs(y-p.y);
    }
};
struct WarmHole
{
    Point a, b;
    int dist;
};

int solve(){
    int N; cin>>N;
    vector<WarmHole> hole(N);

    Point src; cin>>src.x>>src.y;
    Point dest; cin>>dest.x>>dest.y;
    for(int i=0;i<N;i++){
        Point u; cin>>u.x>>u.y; hole[i].a = u;
        Point v; cin>>v.x>>v.y; hole[i].b = v;
        int dist; cin>>dist; hole[i].dist = dist;
    }

    int min_dist = INT_MAX;
    function<int(int, Point&)> dfs = [&](int mask, Point &src){
        int i = __builtin_popcount(mask);
        int res = src.distance(dest);

        int cost1, cost2;
        for(int i=0;i<N;i++){
            if(!(mask&(1<<i))){
                cost1 = src.distance(hole[i].a) + hole[i].dist + dfs(mask|(1<<i), hole[i].b);
                cost2 = src.distance(hole[i].b) + hole[i].dist + dfs(mask|(1<<i), hole[i].a);
                res = min(res, min(cost1, cost2));
            }
        }

        return res;
    };

    return dfs(0, src);
}
int main(){
    int t; cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}
```

