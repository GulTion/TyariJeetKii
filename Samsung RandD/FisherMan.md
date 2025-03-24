---
title: HackerRank
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/fisherman/problem
author:
  - "[[FisherMan]]"
published:
created: 2024-12-18
description: Join over 11 million developers in solving code challenges on HackerRank, one of the best ways to prepare for programming interviews.
tags:
  - clippings
status: ""
explored: false
---
There are $N$ fishing spots and 3 gates. At each gate there are some fishermen waiting to reach the nearest unoccupied fishing spot. (Total no of fisherman $<=N$)

Distance between consecutive spots = distance between gate and nearest spot = $1 m$

Only 1 gate can be opened(other gates after that gate) at a time and all fishermen of that gate must occupy the spots before the next gate is opened.

Distance is calculated as gate to nearest spot + nearest spot to closest vacant spot. Find the total sum of minimum distances need to walk for all the fishermen.

![[Pasted image 20250110234019.png]]

**Input Format**

- Number of fishing spots, $N$ 
- Position of the gates, $G_i, 1 < i < 3$
- Number of fishermen at each gates, $G_{n_i}$

**Constraints**

$1 <= N <= 10$ 
$1 <= G_{i} <= N$
$1 <= G_{n_i} <= 15$

**Output Format**

Output single integer

**Sample Input 0**
```
10
4 6 10
5 2 2
```

**Sample Output 0**
```
18
```
