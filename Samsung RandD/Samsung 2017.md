---
title: Solve Challenges
source: https://www.hackerrank.com/contests/codeshala-pps-24/challenges/samsung-2017
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Print the total number of challenges created by hackers.
tags:
  - clippings
status: ""
explored: false
---
## Samsung 2017

locked

- [Problem](https://www.hackerrank.com/contests/codeshala-pps-24/challenges/samsung-2017)
- [Submissions](https://www.hackerrank.com/contests/codeshala-pps-24/challenges/samsung-2017/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/codeshala-pps-24/challenges/samsung-2017/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/codeshala-pps-24/challenges/samsung-2017/forum)

Kim has to deliver refrigerators to N customers. From the office, he is going to visit all the customers and then return to his home. Each location of the office, his home, and the customers is given in the form of integer coordinates (x,y). The distance between two arbitrary locations (x1, y1) and (x2, y2) is computed by |x1-x2| + |y1-y2|, where |x| denotes the absolute value of x; for instance, |3|=|-3|=3. The locations of the office, his home, and the customers are all distinct. You should plan an optimal way to visit all the N customers and return to his home among all the possibilities.

You are given the locations of the office, Mr. Kim’s home, and the customers; the number of the customers. Write a program that, starting at the office, finds a (the) shortest path visiting all the customers and returning to his home. Your program only have to report the distance of the shortest path.

**Input Format**

First line contains single integer denoting the number of customers N.

Second line contains 4 integers denoting the (x1,y1) co-ordinate of office and (x2,y2) co-ordinate of home and after this it contains 2\*N integers denoting the x\[i\] and y\[i\] co-ordinate of N cities.

**Constraints**

1<=N<=15

1<=X,Y<=200

**Output Format**

Single Integer represent the required output.

**Sample Input 0**

```
3
0 0 100 100 5 5 10 10 20 25
```

**Sample Output 0**

```
200
```