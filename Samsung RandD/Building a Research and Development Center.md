---
title: Solve Building a Research and Development Center
source: https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Samsung wants to build a new R&D center and operate it smoothly.
tags:
  - clippings
status: ""
explored: false
---
## Building a Research and Development Center

locked

- [Problem](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center)
- [Submissions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center/submissions)
- [Discussions](https://www.hackerrank.com/contests/srbd-code-contest-2022-round-1/challenges/building-a-research-and-development-center/forum)

**Time Limit** C++(1s), Java(1s), Python(5s)  
**Memory Limit:** 512MB  
  
**Samsung** wants to build a new R&D center in Bangladesh with `N` employees. The employees are numbered from `0` to `N - 1`. Now Samsung hires `N` employees. Given a **0-indexed** integer array `hires` which contains employee IDs sorted in decreasing order of their seniority level and all the employee IDs will be distinct.

Now Samsung wants to implement `3` types of changes to run the R&D center successfully. Can you handle `Q` queries of the following types and help **Samsung** to build the new R&D center and their system?

- **Type 1:** There will be `2` employee IDs `A` & `B` - meaning `A` & `B` form a team. If `A` or `B` belong to any team then these `2` teams will form a new team or they already belong to the same team then you don't have to form any team because they already belong in the same team.
- **Type 2:** Given an employee ID `X`, employee `X` has been promoted to the next level.
- **Type 3:** Now given an employee ID `Y`, you have to check who is the most senior employee in `Y` employee's team and return his employee ID. If there are multiple same level employees in the team then the employee with greater employee ID will be preferred.

**Input Format**

In the first line you're given `N` and `Q`. The next line contains `N` space separated integers denoting the elements of the `hires` array. Then next `Q` lines each will contain any of the given `3` types of changes.

**Constraints**

- 1 <= `N` <= 10^5
- 0 <= `hires[i]` <= N - 1
- 1 <= `Q` <= 10^5
- 0 <= `A`, `B`, `X`, `Y` <= N - 1

**Output Format**

Answer the type `3` query and each answer will be seperated by a new line.

**Sample Input 0**

```
5 6
0 1 2 3 4
1 0 3
1 2 4
2 0
3 1
1 1 0
3 2
```

**Sample Output 0**

```
1
2
```