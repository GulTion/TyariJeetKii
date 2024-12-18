---
title: "Solve Challenges"
source: "https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1"
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: "Print the total number of challenges created by hackers."
tags:
  - "clippings"
---
## Burst Balloons Optimally

locked

- [Problem](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1)
- [Submissions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1/submissions)
- [Discussions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1/forum)

There are N Balloons marked with value Bi (where B(i…N)). User will be given Gun with N Bullets and user must shot N times. When any balloon explodes then its adjacent balloons becomes next to each other. User has to score highest points to get the prize and score starts at 0. Below is the condition to calculate the score. When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-1 \* Bi+1). When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1. When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1. When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi. Write a program to score maximum points.

Input 4 1 2 3 4

Output

20

**Input Format**

First line N Next line array of N integers

**Constraints**

1 < N < 10

**Output Format**

Single integer

**Sample Input 0**

```
4
1 2 3 4
```

**Sample Output 0**

```
20
```