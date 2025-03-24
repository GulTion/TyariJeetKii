---
title: "Samsung ADV：Samsung Tire(AC)-CSDN博客"
source: "https://blog.csdn.net/weixin_42688573/article/details/125025235"
author:
published:
created: 2025-02-28
description: "Samsung Tire是Samsung公司的一款新产品，它将进行安全测试以确保产品安全。"
tags:
  - "clippings"
---
Samsung Tire  
C/C++/JAVA 3S

Samsung tire is before its launch. Prior to its product launch, it will test the safety of the tire.

In order to launch the tire, the tire must pass N test s in total.  
Each test is constructed of “inflate” and “deflate”.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/9b3a23b68fe66e4eb18de794ea26cbc3.png)

And has the following features:

1. Each test starts with “inflate” first and then “deflate”.
2. As long as all N test cases are executed, the test order can be randomly chosen.

The maximum air pressure of the Samsung tire is K.  
The tire gets damaged, if the inner air pressure of the tire exceeds K or is less than 0.

For instance, given the maximum tire air pressure K=100 and the initial air pressure as 60, the tire in the following two cases will get damaged.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/e707419ec26515108daa44166f972222.png)

Given N, K and N number of test cases, find the test order so that the initial tire air pressure can be minimized.

Print the value of the initial air pressure! (However, if there is no correct answer, print “-1”.)

For instance, suppose there are 3 test cases (N=3) as demonstrated below and the maximum tire air pressure is 100 (K=100).  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/ac5b47464a042ef763de558ab8e56d65.png)  
The order of testing so that the initial tire air pressure can be minimized is shown below which is 15 in this case. (The blue numbers denote the air pressure after either “inflate” or “deflate”.)  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/73b15439521eb88aa2b2c30ffa491549.png)

Below is an example of tire damage, independent of the initial air pressure and the order of testing.  
(N=2, K=100)  
The answer is “-1”.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/f0fdbf718d046aaae96c58c0f75ae7db.png)

\[Constraints\]  
1<=N<=8  
50<=K<=200

\[Input\]  
The first line contains a single integer T-the number of total test cases.  
From the next line on each test case is given.

Each test case consists of 3 lines.  
The first line contains N, K.  
The second line contains the “inflate” value for each test case and the third line contains the “deflate” value for each test case.

\[Output\]  
Print “#t” (without the quotes), leave a blank space and print the answer.  
(T refers to the test case number and starts with 1.)  
\[In/Output Example\]  
Input Example  
5  
3 100  
75 45 80  
30 55 95  
2 100  
65 90  
20 30  
5 150  
35 105 100 45 75  
115 75 55 35 105  
7 150  
70 95 15 65 85 75 55  
105 80 10 90 115 110 45  
8 200  
35 30 50 80 70 15 10 40  
70 20 20 85 65 40 25 50  
Output Example  
#1 15  
#2 -1  
#3 25  
#4 -1  
#5 45

```java
import java.util.*;
import java.io.*;

public class App {
    public static int test[][] = new int[20][2];
    public static int N = 0, K = 0, ok = 0;
    public static int vis[] = new int[20], order[] = new int[20], final_order[] = new int[20];
    public static int initpressure = 0, final_initpressure = 0;

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileReader("C:\\Users\\xyw.wang\\Desktop\\ADV_Data\\SamsungTire.txt"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            N = in.nextInt();
            K = in.nextInt();
            for (int j = 0; j < N; j++) {
                test[j][0] = in.nextInt();
            }
            for (int j = 0; j < N; j++) {
                test[j][1] = in.nextInt();
            }
            ok = 0;
            Arrays.fill(vis, 0);
            Arrays.fill(order, 0);
            initpressure = 0;
            final_initpressure = 0;
            dfs(0, 0);
            if (ok == 1) {
                System.out.println("#" + (i + 1) + " " + final_initpressure);
            } else {
                System.out.println("#" + (i + 1) + " -1");
            }

        }

    }

    private static void dfs(int now_preasure, int testTime) {
        // 递归出口
        // 这一轮的测试全部结束
        if (testTime >= N) {
            // 当前计算出的initpreasure比以往更小，或者，这是第一轮测试结束，final_initpreasure赋第一个真实值。
            if (initpressure < final_initpressure || final_initpressure == 0) {
                final_initpressure = initpressure;
                // ok旨在标记是否能找到一个符合要求的测试序列
                ok = 1;
                for (int i = 0; i < N; i++) {
                    final_order[i] = order[i];
                }
            }
            return;
        }
        // 递归主体
        // 对于这轮的第testTime次测试，有N种测试用例可供选择
        for (int i = 0; i < N; i++) {
            // 如果这个测试用例已经用过了，则换下一个
            if (vis[i] == 1) {
                continue;
            }
            // 如果使用了第i个测试用例的增压之后爆胎了，则换下一个测试用例
            if (test[i][0] + now_preasure > K) {
                continue;
            }
            // 此测试用例可用
            int next_pressure = 0;

            // 预判：tag表示以当前的胎压开始测试，会不会瘪，即最后的胎压会不会小于零
            int dec_presure = test[i][1] - test[i][0] - now_preasure;
            // tag>0表示该测试最后会使得胎压小于零
            if (dec_presure > 0) {
                // 当前计算出的initpressure补上少的这一部分胎压
                initpressure += dec_presure;
                // 判断补上这一部分胎压之后的的initpressure经过当前order序列的顺序测试之后，是否会有异常
                if (!check(initpressure, testTime)) {
                    // 补上胎压之后的initpressure爆胎了，则还原，并尝试下一个测试用例
                    initpressure -= dec_presure;
                    continue;
                }
                // tire完成该测试用例后，正好胎压为零，所以，进行下一个测试的时候从零开始
                next_pressure = now_preasure - test[i][1] + test[i][0] + dec_presure; // 等价于next_pressure=0
                vis[i] = 1;
                order[testTime] = i;
                dfs(next_pressure, testTime + 1);
                order[testTime] = 0;
                vis[i] = 0;
                initpressure -= dec_presure;
            } else {
                // 正常完成测试
                next_pressure = now_preasure - test[i][1] + test[i][0];
                vis[i] = 1;
                order[testTime] = i;
                dfs(next_pressure, testTime + 1);
                order[testTime] = 0;
                vis[i] = 0;
            }
        }
    }

    private static boolean check(int initpressure2, int testTime) {
        for (int i = 0; i < testTime; i++) {
            initpressure2 += test[order[i]][0];
            if (initpressure2 > K) {
                return false;
            }
            initpressure2 -= test[order[i]][1];
        }
        return true;
    }
}

123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100101102103104105106107108109110111
```