---
title: "Solve Flip Columns"
source: "https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns"
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: "Flip"
tags:
  - "clippings"
---
## Flip Columns

locked

- [Problem](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns)
- [Submissions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns/submissions)
- [Discussions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/flip-columns/forum)

A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum number of rows having all 1’s.

for eg, n=3, m=3,

```
        1 0 0

        1 0 1

        1 0 0
```

if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2 rows with all 1’s.

if k=3, then we will toggle column 2 thrice and we will get row 2 with 1 1 1 i.e. all 1’s so answer is 1 as there is 1 row with all 1’s.

**Input Format**

n,m,k space separated n lines each conatining m numbers(1/0)

**Constraints**

**1 < n,m < 15, 1 < k < 7**

**Output Format**

Maximum rows

**Sample Input 0**

```
3 3 2
1 0 0
1 0 1
1 0 0
```

**Sample Output 0**

```
2
```

**Explanation 0**

if k=2, then we will toggle column 2 and 3 once and we will get rows 1 and 3 with 1 1 1 and 1 1 1 i.e. all 1’s so answer is 2 as there are 2 rows with all 1’s.