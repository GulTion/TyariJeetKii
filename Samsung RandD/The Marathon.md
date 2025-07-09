---
title: Solve The Marathon
source: https://www.hackerrank.com/contests/code-the-next/challenges/the-marathon
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: How many streets are there such that if we start from the middle of any of them we will be able to walk as long as we like.
tags:
  - clippings
status: ""
explored: false
---

A marathon is going to be held in the beautiful city of  Hackerland. Hackerland is a city of $n$ junctions and $m$ streets where all streets are unidirectional. In the marathon, people have to follow the direction of streets. People can walk the same street several times.

For example, in the diagram below, Hackerland $7$ contains junctions and $7$ streets. Junctions $1$ and $3$ are not connected to any other junctions in the city. There are two unidirectional streets that connect junctions $7$ and $2$. Junction $7$ is linked to  $5$, but not vice versa. Junctions $2$ and $4$ are linked to each other by two separate unidirectional streets.  

![image](https://s3.amazonaws.com/hr-assets/0/1496144167-512565d999-marat.png)

The marathon is due to start from the middle of any street. The officials want to know how many such streets from where the marathon can commence such that the people can walk infinitely.  

**Input Format**
The first line contains an integer $t$, the number of test cases.

The first line of each testcase contains two positive integers $n$ and $m$, number of junctions and number of streets. Junctions are denoted by integers in range $[1, n]$.

Each of the next $m$ lines describes a street, $a$ $b$, a unidirectional street from junction $a$ to junction $b$. A junction is not connected to itself. There may be several streets connecting the same pair of junctions. All the junctions in the city are not necessarily connected.

**Constraints**
- $1 \leq t \leq 20$
- $1 \leq n \leq 1.4\times10^5$
- $2 \leq m \leq 1.4\times10^5$
- $1 \leq a,b \leq n,a \neq b$
  
**Output Format**
For each test case print the number of streets, such that if we start the marathon from the middle of any of them people have the chance to walk as long as they like.

**Sample Input**
```
1
7 7
7 2
7 5
7 2
2 4
4 2
6 7
4 6
```

**Sample Output**
```
6
```

**Explanation**

![image|center](https://s3.amazonaws.com/hr-assets/0/1496144183-16dd7967cd-marat.png) 
If someone starts walking from the middle of the street connecting junctions **4 -> 6**, they can keep walking the loop consisting of **6->7->2->4->6**. If we start traveling from the middle of the street connecting junctions **7 -> 5**, once we reach *junction 5*, we can't go anywhere else and thus our walk ends. If people start from the middle of any other street, they can keep walking infinitely. So the answer is **6**.