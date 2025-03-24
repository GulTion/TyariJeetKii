---
title: "Samsung ADV: MEX Sequence_samsung adv 算法-CSDN博客"
source: "https://blog.csdn.net/weixin_42688573/article/details/125051437"
author:
published:
created: 2025-02-28
description: "文章浏览阅读366次。Samsung ADV: MEX Sequence_samsung adv 算法"
tags:
  - "clippings"
---
## Samsung ADV: MEX Sequence

最新推荐文章于 2024-10-31 14:24:31 发布

![](https://csdnimg.cn/release/blogv2/dist/pc/img/original.png)

[DayDayUper\_\_\_](https://blog.csdn.net/weixin_42688573 "DayDayUper___") ![](https://csdnimg.cn/release/blogv2/dist/pc/img/newCurrentTime2.png) 于 2022-05-30 18:20:01 发布

版权声明：本文为博主原创文章，遵循 [CC 4.0 BY-SA](http://creativecommons.org/licenses/by-sa/4.0/) 版权协议，转载请附上原文出处链接和本声明。

When a set of non-negative integers is given, mex (minimum excluded) is the smallest number among the numbers not included in the given set.  
For example, mex(∅)=0, mex({1,2})=0, mex({0,2})=1, mex({0,1,2,4,6})=3.  
When a natural number K is provided, there is [sequence](https://so.csdn.net/so/search?q=sequence&spm=1001.2101.3001.7020) gK, (see below).  
 g(K,i) = 0 (0 ≤ i < K)  
 g(K,i) = mex({g(K,i-⌊i/K⌋), ⋯, g(K,i-1) }) ( i ≥ K)(the mex of the numbers before a total of ⌊i/K⌋ numbers)

Given the two integers, N and K, you are required to write a program that finds out g(K,N).

\[Input\]  
The first line contains TC, the number of test cases.  
The first line in each test case contains two space-separated integers, N and K (1≤ N,K ≤ 109).

\[Output\]  
For each test case, print ‘#x’ (x represents a test case number and starts from 1).  
For each test case, print g(K,N).  
Input Example  
5  
9 2  
10 3  
11 4  
12 5  
999999999 1000 // Number of TCs  
// 1st TC, N = 9, K = 2

Output Example  
#1 2  
#2 2  
#3 2  
#4 1  
#5 350805 // 1st TC result