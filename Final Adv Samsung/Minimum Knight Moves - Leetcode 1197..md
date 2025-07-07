---
title: Leetcode 1197. Minimum Knight Moves
source: https://leetcode.ca/all/1197.html
author: 
published: 
created: 2024-12-18
description: Check Java/C++ solution and Company Tag of Leetcode 1197 for free。Unlock prime for Leetcode 1197
tags:
  - clippings
status: Complete
explored: false
---
All contents and pictures on this website come from the Internet and are updated regularly every week. They are for personal study and research only, and should not be used for commercial purposes. Thank you for your cooperation.

In an **infinite** chess board with coordinates from `-infinity` to `+infinity`, you have a **knight** at square `[0,0]`.

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

![](https://assets.leetcode.com/uploads/2018/10/12/knight.png)

Return the minimum number of steps needed to move the knight to the square `[x,y]`.  It is guaranteed the answer exists.

**Example 1:**

```
Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
```

**Example 2:**

```
Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
```

**Constraints:**

- `|x| + |y| <= 300`

