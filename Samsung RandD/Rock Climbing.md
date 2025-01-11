---
title: Solve Challenges
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Print the total number of challenges created by hackers.
tags:
  - clippings
status: ""
---
## Rock Climbing

locked

- [Problem](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing)
- [Submissions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing/submissions)
- [Discussions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing/forum)

Raka wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially. It's impossible to move horizontally in case '-' is not consecutive in the same height level. The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing . The total distance of movement is not important. There is more than one path from the starting point to the destination point. Output: The minimum level of difficulty of all rock climbing paths level.

Hint: Start with difficulty level 0 and then keep increasing it one by one. **Raka always starts from bottom left position.**

![image](https://s3.amazonaws.com/hr-assets/0/1573304582-ca04649e3a-RockClimbing.png)

**Input Format**

First line contains n,m number of rows, columns respectively Next n lines each containg m integers. interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

**Constraints**

1 <= N,M <= 10

**Output Format**

Single interger "level"

**Sample Input 0**

```
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1
```

**Sample Output 0**

```
2
```