---
title: Solve Panjul's Numbers
source: https://www.hackerrank.com/contests/srin-aadc01/challenges/panjuls-numbers
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: What's in the bag?
tags:
  - clippings
status: ""
explored: false
---
## Panjul's Numbers

locked

- [Problem](https://www.hackerrank.com/contests/srin-aadc01/challenges/panjuls-numbers)
- [Submissions](https://www.hackerrank.com/contests/srin-aadc01/challenges/panjuls-numbers/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/srin-aadc01/challenges/panjuls-numbers/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/srin-aadc01/challenges/panjuls-numbers/forum)

Panjul gives to Juminten a bag of natural numbers \[1, 2, 3 ... N\] and then he removes K numbers A<sub>1</sub>, A<sub>2</sub> ... A<sub>K</sub> from the bag. He now asks Juminten to find the P<sup>th</sup> smallest number in the bag.

**Input Format**

First line contains T, the number of test cases. Each test case consists of N, K and P followed by K integers in next line denoting the array A.  
  

**Constraint**  
1 ≤ T ≤ 10  
1 ≤ N ≤ 10<sup>9</sup>  
0 ≤ K ≤ min(N, 10<sup>5</sup>)  
1 ≤ P ≤ N  

**Output Format**

For each test case, print P'th smallest number in the bag. If no such number exists output -1.

**Sample Input**

2  
4 1 2  
1  
5 2 4  
1 3  

**Sample Output**

3  
\-1  

**Explanation**

Explanation  
Test case 1: Remaining numbers are \[2, 3, 4\]. 3 is the 2nd smallest remaining numbers.  
Test case 2: Remaining numbers are \[2, 4, 5\]. 4th smallest remaining number doesn't exist.