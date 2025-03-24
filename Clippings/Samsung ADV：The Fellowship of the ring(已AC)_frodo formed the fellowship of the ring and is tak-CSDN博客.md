---
title: "Samsung ADV：The Fellowship of the ring(已AC)_frodo formed the fellowship of the ring and is tak-CSDN博客"
source: "https://blog.csdn.net/weixin_42688573/article/details/124965032"
author:
published:
created: 2025-02-28
description: "文章浏览阅读845次。ADV:The Fellowship of the ring_frodo formed the fellowship of the ring and is taking the one ring to mordor"
tags:
  - "clippings"
---
ADV：The Fellowship of the ring

Frodo formed the fellowship of the Ring and is taking the one ring to Mordor.

On the way to Mordor, he encounters N groups of orcs, in the order of 1 to N.  
When Frodo bumps into an orc group, he can choose one of the three following options:

Pay the Toll  
He can pay a regular toll and pass by them safely.

Recruit a mercenary  
If he pays the double of the toll, the corresponding orc group gets hired as mercenaries of the Fellowship of the Ring.

If the number of the Fellowship of the Ring members is greater than or equal to the number of orcs, a battle is possible.  
However,

1. Frodo does not count as one of the members of the fellowship of the Ring.
2. A hired mercenary can participate at maximum 3 battles. Even if the orcs are alive after 3 battles, the group gets dispersed.
3. In a battle, independent of the number of orcs, all hired mercenaries participate in the battle.
4. The battle goes on until the orc group gets exterminated. The Fellowship of the Ring, will, as well, loose the same number of soldiers.
5. In the Fellowship of the Ring, soldiers get killed in the order of who got hired first.

#Given N, the number of orc groups and the toll, find the minimum cost to get to Mordor.  
For instance, suppose there are 7 (N=7) orc groups.  
(Yellow stands for the number of orcs in the group and white stands for the toll).

![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/8faa40629129d1027fd757ea3aa79e06.png)

If there are 11(N=11) orc groups, the minimum cost becomes$2370.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/1760998618e2c1c6c4b87c0072118fe7.png)\[Constraints\]

1. 5<=N<=20
2. The number of orcs in each group is greater than or equal to 1 and less than or equal to 1000.
3. The toll of each orc group is each group is greater than or equal to 1 and less than or equal to 1000.

\[Input\]  
The first line contains a single integer T-number of total test cases.  
Below, each test case is given.  
The first line of each test case contains N- the number of orc groups.  
The next N lines contain the number of orcs and the toll, respectively.

\[Output\]  
Print the respective answers for T test case in total for T line.  
Each line starts with “#x”, gives one space, and then output the answer. (X is the test case number starting form 1)

input Output  
5  
7 //Test Case 1, N =7  
10 100  
70 5  
80 15  
20 60  
50 90  
30 80  
10 10  
9 //Test Case 2, N =9  
600 800  
300 400  
300 400  
1000 400  
300 600  
100 300  
600 300  
600 500  
1000 300  
11 //Test Case 2, N =11  
1000 10  
700 900  
400 500  
300 10  
900 900  
300 10  
50 900  
50 900  
700 900  
600 900  
50 10  
20 //Test Case 4, N =20  
896 546  
543 216  
454 310  
408 367  
40 602  
252 582  
954 627  
850 234  
763 479  
232 278  
301 538  
528 508  
936 154  
629 443  
758 336  
432 700  
882 256  
278 738  
517 882  
317 136  
20 //Test Case 5, N =20 410 610  
410 610  
831 909  
675 629  
421 774  
386 869  
544 219  
492 414  
996 557  
499 482  
231 785  
804 978  
304 881  
489 911  
75 315  
927 648  
252 914  
300 396  
937 133  
495 882  
813 717

#1 150  
#2 3000  
#3 2370  
#4 4721  
#5 8231

```java
package adv;

import java.io.FileReader;
import java.util.*;

public class The_Fellowship_of_the_ring_MingXu {
    public static int N, final_money;
    public static int battle[] = new int[3]; // battle[i]为能打i场的人数
    public static int orc_info[][] = new int[1000][2];
    static The_Fellowship_of_the_ring_MingXu out = new The_Fellowship_of_the_ring_MingXu();

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(
                new FileReader("C:\\Users\\xyw.wang\\Desktop\\ADV_Data\\3.The_Fellowship_of_the_ring _test.txt"));

        int T = in.nextInt();
        System.out.println("Input:");
        System.out.println("T:" + T);
        for (int i = 0; i < T; i++) {
            N = in.nextInt();
            System.out.println("N: " + N);
            for (int j = 0; j < N; j++) {
                orc_info[j][0] = in.nextInt();
                orc_info[j][1] = in.nextInt();
                // System.out.println(orc_info[j][0] + " " + orc_info[j][1]);
            }

            // clean data
            final_money = 0;

            dfs(0, 0);
            System.out.println("Output:");
            System.out.println("#" + (i + 1) + " " + final_money);

        }
    }

    private static void dfs(int now_money, int pass_time) {
        // N组兽人全部对付过了
        if (pass_time == N) {
            // System.out.println();
            // System.out.println("_____________now_money=" + now_money);
            // 到目前为止的花费比历史对付策略的花费小，或者，最终的花费没改过，因为是第一次搜到终点。
            if (now_money < final_money || final_money == 0) {
                final_money = now_money;
            }
            return;
        }
        if (now_money >= final_money && final_money != 0) {
            return;
        }
        int next_money = 0;
        for (int i = 0; i < 3; i++) {
            // 即将对付pass_time组兽人
            // 有三种情况
            // 第一种：直接付钱走人，即流程：此次的花费增加，通过这组兽人->对付下一组兽人
            if (i == 0) {
                // System.out.print("付钱 ");
                next_money = now_money + orc_info[pass_time][1];
                dfs(next_money, pass_time + 1);
                continue;
            }
            // 第二种：雇佣兽人为自己的士兵，即流程：此次花费增加，两倍toll->对付下一组兽人
            if (i == 1) {
                // System.out.print("雇佣 ");
                next_money = now_money + orc_info[pass_time][1] * 2;
                int p = orc_info[pass_time][0];
                battle[0] += p;
                dfs(next_money, pass_time + 1);
                battle[0] -= p;
                continue;
            }
            // 第三种：打仗
            if (i == 2) {
                // totalSoldier 表示所有的士兵人数
                int totalSoldier = battle[0] + battle[1] + battle[2];
                // totalOrc 表示 该组兽人的人数
                int totalOrc = orc_info[pass_time][0];
                // 第一种：人数够打
                if (totalSoldier >= totalOrc) {
                    // 为了回溯，暂存三组数值
                    int temp2 = battle[2];
                    int temp1 = battle[1];
                    int temp0 = battle[0];

                    // 战斗，可知战斗次数多的必是先雇佣的，优先消耗
                    int k = 2; // 从战斗数只有一个的开始战斗
                    // int leftOrc = totalOrc;
                    // totalOrc > 0表示剩下的兽人的数量大于零，只有剩下的兽人没有了，才会停止while
                    /*
                     * while (totalOrc > 0) {
                     * // 战斗数最高的先战斗，先减去总兽人数
                     * battle[k] -= totalOrc;
                     * // 此时的totalOrc表示剩下的兽人数
                     * // battle[k]为记录的上一步所剩下的雇佣兵人数
                     * // 如果上一步所剩下的雇佣兵人数小于零，即表示战斗数k对应的雇佣兵不够打
                     * // 则 上一个battle[k]的绝对值就是剩下的雇佣兵人数
                     * // 所以，这一步就是把battle[k]的绝对值赋值给totalOrc供战斗数-1的雇佣兵打
                     * // 如果上一步所剩下的雇佣兵人数大于等于零，即表示战斗数k对应的雇佣兵够打，则结束while
                     * totalOrc = -battle[k];
                     * if (battle[k] < 0) {
                     * battle[k] = 0;
                     * }
                     * k--;
                     * }
                     */
                    while (totalOrc > 0) {
                        if (totalOrc - battle[k] >= 0) {
                            totalOrc -= battle[k];
                            battle[k] = 0;
                        } else {
                            battle[k] -= totalOrc;
                            totalOrc = 0;
                        }
                        k--;
                    }

                    // battle次数+1
                    // 战斗两次一定全部消耗完
                    battle[2] = battle[1];
                    battle[1] = battle[0];
                    battle[0] = 0;

                    dfs(now_money, pass_time + 1);
                    battle[2] = temp2;
                    battle[1] = temp1;
                    battle[0] = temp0;
                }
                // 人数不够，同时执行结束了，不用处理
            }
        }
    }
}

```