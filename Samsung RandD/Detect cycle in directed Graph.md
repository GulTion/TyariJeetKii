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