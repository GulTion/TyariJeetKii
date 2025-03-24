---
title: Solve Zero Statistica
source: https://www.hackerrank.com/contests/srin-aadc01/challenges/zero-statistica
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: From Zero to Hero!
tags:
  - clippings
status: ""
explored: false
---
## Zero Statistica

locked

- [Problem](https://www.hackerrank.com/contests/srin-aadc01/challenges/zero-statistica)
- [Submissions](https://www.hackerrank.com/contests/srin-aadc01/challenges/zero-statistica/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/srin-aadc01/challenges/zero-statistica/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/srin-aadc01/challenges/zero-statistica/forum)

Given a daily history of the total of Samsung S6 device sold in Indonesia, find out for each particular day : how many days after that day had worse total S6 sold.

**Input Format**

The first line contains a single integer T, denoting the number of test cases. In each test case, the following input will be present:

- First line contains an integer N, where N represents the number of days.
- Next N line contains N integers, where i-th line contains i-th integer, which represents the total S6 sold that day.

**Constraint**  
1 <= T <= 30  
1 <= N <= 10<sup>5</sup>  
1 <= Sold<sub>i</sub> <= 10<sup>6</sup>  
Sold<sub>i</sub> is distinct from i = 0 to N-1

**Output Format**

Output exactly T lines. Each line contains N integer separated by a space, where i-th integer represents the number of future worse selling days after the i-th day, which had less S6 sold.

**Sample Input**

1  
4  
2  
1  
4  
3  

**Sample Output**

1 0 1 0

**Explanation**

In sample input, given T = 1 in first line and N = 4 in next line. In next 4 lines, Total S6 Sold-i for each i-th day are given.

- Total S6 sold at 1st day are 2, future day that had less S6 sold are { 1 }. Therefore the answer for 1st day are 1.
- Total S6 sold at 2nd day are 1, future day that had less S6 sold are { none }. Therefore the answer for 2nd day are 0.
- Total S6 sold at 3rd day are 4, future day that had less S6 sold are { 3 }. Therefore the answer for 3rd day are 1.
- Total S6 sold at 4th day are 3, future day that had less S6 sold are { none }. Therefore the answer for 4th day are 0.