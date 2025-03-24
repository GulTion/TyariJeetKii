---
title: Solve Challenges
source: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/wear-mask
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
## Wear Mask

locked

- [Problem](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/wear-mask)
- [Submissions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/wear-mask/submissions)
- [Discussions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/wear-mask/forum)

**Time Limit :** C / C++(**1s**), Java(**3s**), Python(**3s**)  
**Memory Limit:** 512MB

---

Samsung R&D Institute Bangladesh (SRBD) is very much concern about wearing mask inside office. So, the SRBD management wants to observe the whole area. SRBD has a floor which looks like a grid, A grid with **W** number of columns & **H** number of rows. So, they want to set some CCTV cameras in the floor / grid. A CCTV camera can cover all it's adjacent cells including itself ( you may consider below picture as an example ).The cost of CCTV camera is much more. So, they want to buy as less camera as possible.

![image](https://s3.amazonaws.com/hr-assets/0/1660240245-41aeb92972-Capture.PNG)

**Input Format**

The first line contains a single integer **T** — the number of test cases.

The first line of each test case contains **W , H** — number of columns & rows of the grid.

**Constraints**

1 <= **T** <= 10^5

1 <= **W , H** <= 10^9

**Output Format**

For each test case, the output should consist of one line showing the minimum number of CCTV cameras that verifies the conditions above.

**Sample Input 0**

```
3
6 6
3 3
9 13
```

**Sample Output 0**

```
4
1
15
```