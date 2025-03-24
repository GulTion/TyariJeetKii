---
title: Solve Endoscope
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/endoscope
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Endoscope
tags:
  - clippings
status: not_implemented
explored: false
---
Raka, a CSE student from IIITG developed an endoscope to explore inner part of ruined water pipes. It is possible explore the inner part of the pipes putting the endoscope into a certain part of the pipe. The endoscope can be moved in the pipes only. Meanwhile, when the pipes are connected to each other, if the length of the endoscope is long enough to explore, it is able to inspect the connected pipe. However, we cannot observe every pipe because the length of the endoscope is limited.

When the map of the ground water pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of pipe which are available to explore. Length of endoscope means the range upto which endoscope can explore. There are seven kind of pipes, and description for each pipe are shown below

![image](https://s3.amazonaws.com/hr-assets/0/1572975788-3d3aedb280-3be4e11.png)\- 1 
![image](https://s3.amazonaws.com/hr-assets/0/1572975815-05f202e72f-4093851.png) - 2 
![image](https://s3.amazonaws.com/hr-assets/0/1572975836-e801ea0f75-48f567d.png)\- 3 
![image](https://s3.amazonaws.com/hr-assets/0/1572975854-32bbeef565-4f0a4fc.png)\- 4 
![image](https://s3.amazonaws.com/hr-assets/0/1572975880-b4e37f33e7-5b79728.png)\- 5 
![image](https://he-s3.s3.amazonaws.com/media/uploads/623df7e.png) - 6 
![image](https://s3.amazonaws.com/hr-assets/0/1572975914-b7cb24d0d0-6aa528b.png) - 7

Fig 1 Shows an example of a map of ground water pipes. In this case, the height of the map is 5, and the width is 6 If a certain point where the endoscope to put in is given as (2,1), it means the vertical location will be 2, and the horizontal location will be 1, shown as a red highlighted pipe in fig 2. If the length of the endoscope is 1, we can explore only one water pipe which is at the intersection point If the length of the endoscope is 2, we can explore 3 water pipes including a blue highlighted pipe and a red marked pipe with the endoscope Fig-3 . If the length of the endoscope is 3, we can explore 5 water pipes total Fig-4

![image](https://he-s3.s3.amazonaws.com/media/uploads/672fd6c.jpg) 
::Fig-1

![image](https://he-s3.s3.amazonaws.com/media/uploads/ce1a1da.jpg) 
::Fig-2

![image](https://he-s3.s3.amazonaws.com/media/uploads/e6db2ed.jpg) 
::Fig-3

![image](https://he-s3.s3.amazonaws.com/media/uploads/f568964.jpg) 
::Fig-4

**Input Format**

In the first line, T, the number of total test cases are given. From the second line, T test cases are given. In the first line of each test case, N, the height of the map of the groundwater pipes, M, the width, R, the vertical location of the water pipe where to put in the endoscope, C, the horizontal location of it, and the length of the endoscope L are given. In the following N lines, information about the map of the groundwater pipe is given. Each line has M numbers. Each number (from 1 to 7) means the type of water pipe for that point. 0 means there is no water pipe buried in that place.

**Constraints**

Constraints 1≤ T ≤100

1≤ N, M ≤50

0≤ X < N

0≤ Y < M

1≤ L ≤ 20

**Output Format**

Print the respective answer for T test cases in total for T lines. The answer is the number of water pipes which is available to observe using the endoscope.

**Sample Input 0**

```
2 
5 6 2 1 3 
0 0 5 3 6 0 
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
5 6 2 2 6 
3 0 0 0 0 3 
2 0 0 0 0 6 
1 3 1 1 3 1 
2 0 2 0 0 2 
0 0 4 3 1 1
```

**Sample Output 0**

```
5
15
```