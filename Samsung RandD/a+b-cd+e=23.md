---
title: Solve a+b-c*d+e=23
source: https://www.hackerrank.com/contests/srin-aadc02/challenges/ab-cde23
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: a+b-c*d+e=23
tags:
  - clippings
status: ""
explored: true
---
## a+b-c\*d+e=23

locked

- [Problem](https://www.hackerrank.com/contests/srin-aadc02/challenges/ab-cde23)
- [Submissions](https://www.hackerrank.com/contests/srin-aadc02/challenges/ab-cde23/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/srin-aadc02/challenges/ab-cde23/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/srin-aadc02/challenges/ab-cde23/forum)

One day you fall in love with math without any reason. You play with 5 numbers and you ask yourself : "Is it possible to get number 23 by using given 5 numbers and operator +, -, \* ?".  
For this problem arithmatic expression will be operated from left to right.  
So that means  
5 - 2 \* 4 + 1 -3 = 10

**Note**  
Please use recursive backtracking technique, because write statement 'for' 8 times is too much pain.

**Input Format**

5 integers. Each of them will be between 1 and 50.

**Output Format**

By using 5 numbers and operator - , + , \* , is it possible to get number 23 ?  
If possible print "Possible", else "Impossible".

**Sample Input**

```
1 2 3 4 5
```

**Sample Output**

```
Possible
```

**Explanation**

There are many solutions to get number 23 from number 1 2 3 4 5.  
5 - 2 + 3 \* 4 - 1 = 23  
1 \* 2 + 4 \* 3 + 5 = 23