---
title: Solve Coprime Query
source: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/coprime-query
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Number theory, Inclusion-exclusion
tags:
  - clippings
status: ""
explored: false
---
## Coprime Query

locked

- [Problem](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/coprime-query)
- [Submissions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/coprime-query/submissions)
- [Discussions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/coprime-query/forum)

**Time Limit:** C/C++(2s), Java(3s), Python(5s)  
**Memory Limit:** 512MB

Given an array of N integers and Q queries. In each query an integer x is given. For each query you've to count the number of coprimes of x in that array.

Remember that two integers x and y are said to be coprime if they have no common divisor other than 1 that means gcd(x, y) = 1.

**Input Format**

In the first line you're given N and Q. Next line contains N space separated integers denoting the elements of the array **a**. Then the following Q lines contain an integer x.

**Constraints**

```
1 <= N, Q, a[i], x <= 200000
```

**Output Format**

For each query print the answer of the query in each line.

**Sample Input 0**

```
5 5
1 2 3 4 5
1
2
3
4
5
```

**Sample Output 0**

```
5
3
4
3
4
```