---
title: "Samsung R&D SWC pro interview - LeetCode Discuss"
source: "https://leetcode.com/discuss/interview-question/4946081/Samsung-RandD-SWC-pro-interview"
author:
  - "[[LeetCode]]"
published:
created: 2025-02-23
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
tags:
  - "clippings"
---
Recently gave Samsung R&D bangalore interview .  
First round SWC for working professional.4 hrs coding

Question - find hidden benchmark value

given two arrays A & B (1 < A.length , B.length < 10 ^5 ) (1 <= A\[i\] ,B\[i\]< 10^8 ). Given the number D such that if ( D > A\[i\] , B\[i\] ) benchmark results as 2 and if (D < A\[i\],B\[i\]) benchmark results as 1 for each element .

Determine the value of D such that difference in sum of benchmark values in A & B is maximum .

**Difference is not absolute**

E.g:

A = \[6,7,9,1,2\]  
B = \[4,6,2\]

lets say D is 3 , benchmark values

BenchmarkA = \[2,2,2,1,1\] -> sum = 8  
BenchmarkB = \[2,2,1\] -> sum = 5

difference = 8 - 5 = 3

\*\*We need to find the value of D , such that difference is maximum \*\*

Please comment incase question is not clear .

Solved with brute force method , but could not optimise it as solution was giving TLE (6 secs limit for JAVA / 12 secs for Python) .

Also no standard library is allowed , so sorting also requires to write code .  
Can anyone help me with solution .