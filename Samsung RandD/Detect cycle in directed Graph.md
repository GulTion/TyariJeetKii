---
title: HackerRank
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/detect-cycle-in-directed-graph/problem
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Join over 11 million developers in solving code challenges on HackerRank, one of the best ways to prepare for programming interviews.
tags:
  - clippings
status: ""
explored: false
---
Detect and print the cycle in ascending order. If there are multiple cycles, print the cycle with nodes' sum smallest.

**Input Format**

Given number of nodes and edges, N,M Next line contains edges u and v (u->v edge) space separated, 2\*M values

**Constraints**

1 < N < 10

1 < M < 50

**Output Format**

single line node values in sorted order

**Sample Input 0**

```
5 5
1 2 2 4 4 5 5 3 3 2
```

**Sample Output 0**

```
2 3 4 5
```

**Sample Input 1**

```
5 5
2 4 2 3 4 3 1 5 5 1
```

**Sample Output 1**

```
1 5
```

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, E,x,y; cin>>N>>E;
    map<int, vector<int>> g;
    for(int e=0;e<E;++e){
        cin>>x>>y;
        g[x].push_back(y);
    }

    vector<int> minPath, path;
    int minPathSize=INT_MAX;
    function<void(int, int)> dfs = [&](int mask,int u) {
        int n = __builtin_popcount(mask);
        if(n==N) return;

        for(auto v:g[u]){
            if(!(mask&(1<<v))){
                path.push_back(v);
                dfs(mask|(1<<v), v);
                path.pop_back();
            }else{
                if(minPathSize>path.size()){
                    minPath = path;
                    minPathSize = minPath.size();
                }
            }
        }
    };
    
    for(int i=0;i<N;i++)
    dfs(0,i);
    sort(minPath.begin(), minPath.end());
    for(int i:minPath) cout<<i<<" ";
    return 0;
}
```