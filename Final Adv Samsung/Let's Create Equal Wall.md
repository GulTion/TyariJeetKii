---
title: Solve Challenges
source: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/lets-create-equal-walls
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Print the total number of challenges created by hackers.
tags:
  - clippings
status: Complete
explored: false
---
## Let's Create Equal Wall

locked

- [Problem](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/lets-create-equal-walls)
- [Submissions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/lets-create-equal-walls/submissions)
- [Discussions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/lets-create-equal-walls/forum)

**Problem Statement**

You have to build a wall using three columns of brick. Each brick has same width but unfortunately their height may vary. You can change the height of a column by removing and discarding its topmost brick any number of times.

Find the maximum possible height of the column such that the wall’s height is not uneven. That means all of the columns are exactly same height. So, you must remove zero or more bricks from the top of zero or more of the three columns until they are all the same height, then return the height.

**Example**

h<sub>1</sub> = \[1,2,1,1\]

h<sub>2</sub> = \[1,1,2\]

h<sub>3</sub> = \[1,1\]

There are 4, 3 and 2 bricks in the three columns, with their heights in the three arrays. Remove the top 2 bricks from h<sub>1</sub> (heights = \[1,2\]) and from h<sub>2</sub> (heights = \[1,1\]) so that the three columns all are the 2 units tall. Return 2 as the answer.

**Note** An empty column is still a column.

**Explanation**

Initially, the columns look like this:

![image](https://s3.amazonaws.com/hr-assets/0/1660293452-22e76254a9-Figure3.jpg)

To equalize their heights, remove the first brick from column 1 and 2 , and then remove the top two bricks from column 3 (shown below).

![image](https://s3.amazonaws.com/hr-assets/0/1660293561-e23fa7284f-Figure4.jpg)

The column heights are reduced as follows:

1. 8 – 3 = 5
2. 9 – 4 = 5
3. 7 -1 – 1 = 5

All three columns now have height = 5, the value to return.

**Input Format**

1. The first line contains three space-separated integers, n<sub>1</sub>, n<sub>2</sub> and n<sub>3</sub>, the numbers of bricks in columns 1, 2 and 3. The subsequent lines describe the respective heights of each brick in a column from top to bottom.
2. The second line contains n<sub>1</sub> space-separated integers, the brick’s heights in column 1. The first element is the top brick of the column.
3. The third line contains n<sub>2</sub> space-separated integers, the brick’s heights in column 2. The first element is the top brick of the column.
4. The second line contains n<sub>3</sub> space-separated integers, the brick’s heights in column 3. The first element is the top brick of the column.

**Constraints**

- **0 < n<sub>1</sub>, n<sub>2</sub>, n<sub>3</sub> <= 10<sup>5</sup>**
- **0 < height of any brick <= 100**

**Output Format**

Print a single integer denoting the maximum height at which all cloumns will be of equal height.

**Sample Input 0**

```
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1
```

**Sample Output 0**

```
5
```

[[Let's Create Equal Wall.cpp]]