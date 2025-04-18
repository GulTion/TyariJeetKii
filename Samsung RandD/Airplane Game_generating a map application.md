---
title: "Samsung ADV：Airplane Game_generating a map application-CSDN博客"
source: "https://blog.csdn.net/weixin_42688573/article/details/124970517"
author:
published:
created: 2025-02-28
description: "文章浏览阅读575次。Samsung ADV:Airplane Game_generating a map application"
tags:
  - "clippings"
---
# Airplane Game  
There is an airplane game to avoid enemies and gather coins.  
The height of the game map is N and the width is 5. And the game screen consists of game zone and control zone as shown in \[Fig. 1-1\].  
![[Pasted image 20250330194958.png]]

- Game zone: The area in black rectangle in \[Fig. 1-1\]. It always maintains the size 5\*5 and displays a part of the game map.
- Control zone: The area in the blue rectangle in \[Fig. 1-1\]. It is the one line at the bottom where the airplane moves.

There are coins marked as C and enemies marked as R in the game map.  
At the start of the game, the airplane is located at the center point of the control zone.  
And each turn of the game is played under the game rules below, and the game can be finished after every part of the game map moves down.

1-1. The movement of the airplane is made as one of 3 followings.

- Going one column further to the left, going one column further to the right, and staying at current position.
- \[Fig. 1-2\] shows the status of going one column further to the right form \[Fig. 1-1\].

1-2. If necessary, a [bomb](https://so.csdn.net/so/search?q=bomb&spm=1001.2101.3001.7020) can be used before the airplane moves.

- A bomb can be used only once during the game play. It eliminates all of the enemies inside the game zone (5\*5). (It can’t eliminate enemies which are now shown in the game zone.)

2-1. After the plane moves, above part of the game map moves down by 1 line as shown in \[Fig. 1-3\].  
2-2. If the plane meets a coin, the number of gathered coins increases by 1.  
On the other hand, when it meets an enemy, the number of gathered coins decreases by 1.  
2-3. Afterward, all coins and enemies in the control zone disappear as shown in \[Fig. 1-4\].

3. When the number of coin becomes -1, the airplane explodes and the game is over.  
(It is the case that it meets an enemy with no coin.)

When you are given the height of the game map N and arrangement information (the location of coins and enemies), find out the way to attain the maximum number of gathered coins at the end of the game.  
And print the number of coins in that case. If the airplane cannot survive in any other way, output -1.

For example, look at the case that the game map with 7 in height is given as \[Fig. 2\]. (Same as Input Example 1)  
If the game proceeds and ends in a way shown in \[Fig. 2\], the maximum number of coins is attainable.  
 A bomb is used in the second turn.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/3abc6b08d8b69493331383e44c136762.png)  
In the above case, the maximum number of coins attainable at the end of the game is 6 and answer becomes 6.

\[Constraints\]

1. Time limit: 5seconds in case of C/C++/Java to pass all test cases. The number of test cases is less than or equal to 50.
2. The height of the game map (N) is an integer greater than or equal to 5 and less than or equal to 12. (5<=N<=12)
3. The width of the game map is always 5.
4. At the start of the game, the airplane is located at the center point of the control zone.
5. The airplane can go one column further in each turn when moving left or right.
6. A bomb can be used only once during the game plan.
7. The initial number of coin is 0 when the game is started.
8. If the airplane with on coin meets an enemy, the number of coin becomes -1.  
And then the plan explodes, which makes the game over.

\[Output\]  
Print the respective answers for T test cases for T lines in total.  
Each line starts with “#x”, gives one space, and then output the answer. (X is test case number starting form 1)  
The answer is the maximum number of coins gathered at the end of the game, or print -1 if airplane can’t survive under any circumstances.

\[Input/ Output Example\]  
Input

```java
5
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0
0 0 0 0 0
1 0 0 0 2
0 0 0 0 0
2 2 0 2 1
0 2 2 2 0
12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1


```

Output

```java
#1 6
#2 3
#3 -1
#4 0
#5 9

```