---
title: HackerRank
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem
author:
  - "[[Travelling SalesPerson]]"
published:
created: 2024-12-18
description: Join over 11 million developers in solving code challenges on HackerRank, one of the best ways to prepare for programming interviews.
tags:
  - clippings
status: ""
explored: false
---
Given a matrix M of size N where M[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.

Example: Input: 2 2 0 111 112 0 3 0 1000 5000 5000 0 1000 1000 5000 0 Output: 223 3000

**Input Format**

Input: The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix then in the next line are N*N space separated values of the matrix M.

**Constraints**
- $1<=T<=15$ 
- $1<=N<=12$ 
- $1<=M[][]<=10000$

**Output Format**

Output: For each test case print the required result denoting the min cost of the tour in a new line.

**Sample Input 0**

```
2
2
0 111
112 0
3
0 1000 5000
5000 0 1000
1000  5000  0
```

**Sample Output 0**

```
223
3000
```