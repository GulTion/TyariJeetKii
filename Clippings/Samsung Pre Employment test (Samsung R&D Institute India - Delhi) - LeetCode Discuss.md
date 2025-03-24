---
title: "Samsung Pre Employment test (Samsung R&D Institute India - Delhi) - LeetCode Discuss"
source: "https://leetcode.com/discuss/interview-question/3444311/Samsung-Pre-Employment-test-(Samsung-RandD-Institute-India-Delhi)"
author:
  - "[[LeetCode]]"
published:
created: 2025-02-23
description: "Level up your coding skills and quickly land a job. This is the best place to expand your knowledge and get prepared for your next interview."
tags:
  - "clippings"
---
Went for Samsung Pre Employment test.  
Test time was 10:30 AM - 2:30 PM  
I have to visit Samsung R&D Institute India – Delhi | SRI-Delhi for this test.

1 DSA question asked.  
Question = connect numbers  
You are given an array of numbers A = \[a0, a1, a2, a3, .... , aN\]  
You can connect a number a\[i\] with a\[j\] where i < j.  
To connect 2 numbers the last digit of first number should be equal to first digit of second number. (refer to below examples).  
A valid number is if the number first digit is same as last digit.  
Find the length of max number which is valid.  
1<= N <= 100,000  
1 <= a\[i\] <= 10^9

example 1 : \[14, 123, 323, 321, 431, 53635\]  
output = 9  
explanation : valid numbers are = 14431 after joining a0 with a4, 123321 (a1 with a3), 123323321 (a1, a2, a3)  
example 2 : \[12, 13, 14, 15\]  
output = 0  
example 3 = \[14, 13, 22, 19\]  
output = 2  
explanation : 22 is the valid number as first digit of number is same as last digit of number.