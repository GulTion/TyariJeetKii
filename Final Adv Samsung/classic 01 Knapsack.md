---
title: Solve classic 0/1 Knapsack
source: https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: We need more gold!
tags:
  - clippings
status: ""
explored: false
---
## classic 0/1 Knapsack

locked

- [Problem](https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack)
- [Submissions](https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/srin-aadc03/challenges/classic-01-knapsack/forum)

This is the classic & famous knapsack problem : You are a thief carrying a single knapsack with limited (1 <= *S* <= 2000) capacity. The museum you stole had (1 <= *N* <= 2000) artifact that you could steal. Unfortunately you might not be able to steal all the artifact because of your limited knapsack capacity.  

You have to cherry pick the artifact in order to maximize the total value (<= 2000000) of the artifacts you stole.

**Input Format**

On the first line you are given *T* as the test cases available (1 <= *T* <= 20). The next *T* testcases will started with two integer *S* and *N*. *N* lines follow with two integers on each line describing each artifact available at the museum. The first number is the *weight* of the artifact and the next is the *value* of the artifact.

**Output Format**

You should output a single integer on one line : the total maximum value from the best choice of artifacts you stole.

**Sample Input**

```
1  
4 5  
1 8  
2 4  
3 0  
2 5  
2 3  
```

**Sample Output**

```
13
```

**Explanation**

The artifact with value 8 and 5 should be picked, summing up the value to the maximum of 13.