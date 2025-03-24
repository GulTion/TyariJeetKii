---
title: "Samsung ADV:Tracking the Movement Path（已AC）_三星 adv-CSDN博客"
source: "https://blog.csdn.net/weixin_42688573/article/details/125067072"
author:
published:
created: 2025-02-28
description: "文章浏览阅读553次。Samsung ADV：Tracking the Movement Path（已AC）_三星 adv"
tags:
  - "clippings"
---
Tracking the Movement Path（HashSet！！！！！）  
C/C++/JAVA within 1s, 1MB

Samsung Electronics is currently developing a robot that can explore new areas.  
In order to explore a much wider space, the robot will avoid exploring the same area again which it has already passed. Track its movement path so that the robot does not meet the path it has already passed.

The movement path of the robot consists of the direction DI and distance LI. (1<=i<=K)  
When given as N 10, the robot moves 10M towards the northern direction.  
“N” stands for North, “S” for South, “E” for East and “W” for West.

For instance, if the movement path is given such as E 2, N3, W4, S5, E7, the robot moves as shown in \[Fig.1\]. The red point is the starting point of the robot.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/e259ff9cced1207fe593070865ee6cc3.png)  
In case of the two situations below, the movement paths of the robot meet one another.

1. In \[Fig.2.1\], the path of the robot intersects with an already passed path. The movement path is E 4, N 2, W 2, S 4.
2. In \[Fig.2.2\], the path of the robot overlaps with an already passed path. The movement path is E 3, N 2, S 3, E 3, N 4.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/04bfe1e9d17bb5e58b818623c4f7b18f.png)  
When checking the movement paths as shown in \[fig. 3.1\] and \[Fig. 3.2\], each end parts of the movement paths are eliminated.  
Thus, that way the movement paths do not meet one another.  
The movement path in \[Fig. 3.1\] is E 4, N2, W 4, S 4.  
The movement path in \[Fig. 3.2\] is E 1, N 2, W 4, S 4, E 4, N 2, E 3.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/6386b90f8bf8110aa3e55002b5452ac4.png)  
Given the movement path of the robot, track its path and write a program that, in case a path meets another already passed path, prints the number of the path.  
If the robot does not meet another already passed path, print “-1”.  
Among the given movement paths, if there are several paths which meet another already passed paths, print the number of the fastest path.

In case of \[Fig. 2.1\], the 4th. path meets the 1st. path. Thus, the answer is 4.  
In case of \[Fig. 2.2\], the 6th. path meets the 2nd. path. Thus, the answer is 6.

In case of \[Fig. 3.1\] and \[Fig. 3.2\], the answer to print is “-1”.

\[Constraints\]

1. The number of moveme nt paths(K) is greater than or equal to 1, less than or equal to100.(1<=K<=100)
2. The movement path consists of direction Di and distance Li.(1<=i<=K)
3. Direction Di is N, S, E, W. and N is 1, S is 2, E is 3 and W is 4.
4. Distance Li is an integer which is greater than or equal to 1, less than or equal to 100,000. (1<=Li<=100,000)
5. The direction of the movement path Di is different from its previous direction Di-1.(Di=/Di-1)

\[Input\]  
The first line contains a single integer T—the number of total test cases.(1<=T<=50)  
From the next line on, T test cases are given.  
The first line of each test case contains K—the number of movement paths.  
Throughout the next K lines, two space-separated integers Di and Li—the direction of the movement path, the distance are given respectively.

\[Output\]  
For Test Case T, Print “#T” (without quotes), leave a black space and print the answer.  
(T refers to the test case number and starts with 1).  
The correct answer is the number of the path which meets another already passed path.  
If the robot does not meet another already passed path, print “-1”.

The answers for the test cases given in the sample input are as follows:  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/262f3cc6087da87c50f22d96dd8e2463.png)

```c
Input Example	Output
5
4
3 4
1 2
4 2
2 4
7
3 1
1 2
4 4
2 4
3 4
1 2
3 3
10
3 97
2 90
3 58
1 99
4 80
2 1
3 12
1 73
3 87
4 45
20
3 9
1 77
4 99
2 68
4 41
1 82
3 61
1 28
4 26
2 26
3 6
1 2
3 19
1 5
4 16
1 4
3 82
2 16
4 96
1 24
30
4 23
1 44
3 42
2 68
3 17
1 72
3 62
1 74
4 11
1 26
4 40
1 29
3 41
1 52
4 36
1 37
4 54
2 29
4 87
1 55
4 90
2 81
4 66
2 99
4 7
1 84
3 54
1 94
4 33
2 11	

#1 4
#2 -1
#3 8
#4 17
#5 27

\`\`\`java
import java.util.*;

import java.io.*;

public class Tracking_the_Movement_Path {
    public static int K = 0, ok = 0, start_x = 50, start_y = 50, result = 0;;

    public static int[] move = new int[2]; // 0 方向 1 距离
    public static int[][] dir = { { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } }; // 依次为N,S,E,W四个方向
    public static HashSet<Point> set = new HashSet<Point>();

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(
                new FileReader("C:\\Users\\xyw.wang\\Desktop\\ADV_Data\\Tracking_the_Movement_Path.txt"));
        int T = in.nextInt();
        System.out.println(T);
        for (int i = 0; i < T; i++) {
            K = in.nextInt();
            ok = 0;
            Point now_point = new Point(0, 0);
            for (int j = 0; j < K; j++) {
                move[0] = in.nextInt();
                move[1] = in.nextInt();
                int steps = 1;
                while (steps < move[1] && ok == 0) {
                    now_point = new Point(now_point.x + dir[move[0]][0], now_point.y + dir[move[0]][1]);
                    if (set.contains(now_point)) {
                        ok = 1;
                        System.out.println("#" + (i + 1) + " " + (j + 1));
                    }
                    set.add(now_point);
                    steps++;
                }
                now_point = new Point(now_point.x + dir[move[0]][0], now_point.y + dir[move[0]][1]);
            }
            if (ok == 0) {
                System.out.println("#" + (i + 1) + " -1");
            }
            // 清空set
            set.clear();
        }
    }

    public static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            // 判断类型是否相同
            if (this == o) {
                return true;
            }
            // 空对象或者类型不同
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            // 判断元素是否相等
            Point point = (Point) o;
            if (x != point.x) {
                return false;
            }
            return y == point.y;
        }

        @Override
        public int hashCode() {
            return 311 * x + y;
        }

    }
}

```
```c
1
```