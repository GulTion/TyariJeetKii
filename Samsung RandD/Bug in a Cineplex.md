---
title: Solve Bug in a Cineplex
source: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/bug-in-a-cineplex
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Basic geometry, binary search
tags:
  - clippings
status: ""
explored: false
---
## Bug in a Cineplex

locked

- [Problem](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/bug-in-a-cineplex)
- [Submissions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/bug-in-a-cineplex/submissions)
- [Discussions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/bug-in-a-cineplex/forum)

**Time Limit:** C/C++(3s), Java(4s), Python(5s)  
**Memory Limit:** 512MB

Masum has planned to watch a movie at the Star Cineplex during his school holidays. He and his friends will visit the Cineplex tomorrow. He loves watching classical movies. Recently he watched an old classical movie named Goopy Gyne Bagha Byne directed by Satyajit Ray in the Cineplex. But he faced some weird problems there. Some portion of the screen wasn't visible from his seat. So he became very upset. He complained to the manager and the manager assured him to fix the problem.

The Cineplex is a 2D place which is set upon the positive side of both axes. The screen stands vertically on the non negative side of Y axis( i.e X = 0 line ) and it can be moved vertically up or down along the non negative side of Y axis. There are N seats placed along the positive X axis where the i'th seat is a line segment with bottom point to be (x<sub>i</sub>, 0) and top point to be (x<sub>i</sub>, y<sub>i</sub>).

A point on the screen P(0, y) is said to be visible from i'th seat if the line connecting P and (x<sub>i</sub>, y<sub>i</sub>) does not intersect with any other seats with X coordinate less than x<sub>i</sub>. Remember if two line segments touch each other will be ignored as intersected.

Now you have to find, What is the minimum height of the screen such that it is fully visible from all seats?

**N.T. Please use double data type.**

**Input Format**

Input starts with an integer T denoting the number of test cases. The first line of each test case contains an integer N the number of seats in the Cineplex. Then the N line each contains two space separated integers x<sub>i</sub>, y<sub>i</sub> denoting the i'th seat.

**Constraints**

**1 <= T <= 10**  

**1 <= N <= 100000**  

**1 <= x<sub>i</sub>, y<sub>i</sub> <= 1000000000  
**

**Output Format**

For each test case print the minimum height from where the screen will be fully visible to all seats. Errors less than 0.00001 will be ignored.

**Sample Input 0**

```
2
2
1 4
2 1
3
1 1
2 1
3 8
```

**Sample Output 0**

```
7.000000
1.000000
```