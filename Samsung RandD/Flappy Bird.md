---
title: Solve Flappy Bird
source: https://www.hackerrank.com/contests/code-the-next/challenges/flappy-bird
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Score as many points as possible with minimum number of screen taps in Flappy Bird.
tags:
  - clippings
status: ""
explored: false
---

> [!Warning] Incomplete
> latex text is not present, go to `source` link for original question

## Flappy Bird

locked

- [Problem](https://www.hackerrank.com/contests/code-the-next/challenges/flappy-bird)
- [Submissions](https://www.hackerrank.com/contests/code-the-next/challenges/flappy-bird/submissions)
- [Leaderboard](https://www.hackerrank.com/contests/code-the-next/challenges/flappy-bird/leaderboard)
- [Discussions](https://www.hackerrank.com/contests/code-the-next/challenges/flappy-bird/forum)
- [Editorial](https://www.hackerrank.com/contests/code-the-next/challenges/flappy-bird/editorial)

> Flappy Bird was a side-scrolling mobile game featuring 2D retro style graphics. The objective was to direct a flying bird, named "Faby", who moves continuously to the right, between sets of Mario-like pipes. If the player touches the pipes, they lose. Faby briefly flaps upward each time that the player taps the screen; if the screen is not tapped, Faby falls because of gravity; each pair of pipes that he navigates between earns the player a single point. - From Wikipedia, the free encyclopedia

![image](https://s3.amazonaws.com/hr-assets/0/1496313684-a41e94b312-imgonline-com-ua-twotoone-E6PPxmcS23RG.jpg)

1. We can regard Faby as a point who is initially at where is an integer between 1 and 70 inclusive which is chosen by the player. We can regard the \-th lower pipe as an axis-aligned rectangle with and as its two opposite corners and the \-th upper pipe as an axis-aligned rectangle with and as its two opposite corners.
2. Faby will always have a horizontal velocity of , which means the coordinate of Faby is always at time . Faby will have a vertical velocity 0 initially.
3. The player can only tap the screen at time where is an integer and the player can tap at most once at time . If the player taps, then Faby's vertical velocity increases by 1, otherwise, it decreases by 1.
4. Suppose that Faby is at at time and Faby's vertical velocity is during time and at time , then Faby will fly unit upwards in that 1 unit time, i.e., Faby fly from to .
- If Faby touches the ground (), or Faby touches any pipe ( is inside any rectangle or on the border of any rectangle) then Faby dies.
- If , Faby will be relocated to , i.e., Faby cannot fly out of the screen. If Faby is inside any rectangle after relocating, then it dies; otherwise, the vertical velocity will be changed to 0.
5. The player will get one point after passing though a pair of pipes. If the Faby is at a position with , then we say that Faby has passed the pair of pipes and the player has scored points.

For example, in the right diagram above, Faby starts at the position as chosen by the player. There are in total four pipes, two lower pipes and two upper pipes. For \= , the coordinates of the top-left and bottom-right points of the lower pipe are: and and that of the upper pipe are: and . For \= , the coordinates of the top-left and bottom-right points of the lower pipe are: and and that of the upper pipe are: and .

Boleyn is addicted to Flappy Bird recently, and he wants to know the maximum score he can get and the minimum number of screen taps to reach such a score.

**Input Format**

The first line contains an integer , the number of pipes. The next line contains space separated integers where the \-th integer contains an integer .

**Constraints**

**Output Format**

You should print two integers, the maximum possible score and the minimum number of screen taps to reach such score, separated by one space.

**Sample Input 0**

```
2
40 30
```

**Sample Output 0**

```
2 14
```

**Explanation 0**

According to the input, there are two pipes of length 40 and 30 respectively.

*Bottom Pipe 1* has upper left coordinate of and lower right coordinate of \= and

*Upper Pipe 1* has upper left coordinate of and lower right coordinate of \= and

*Bottom Pipe 2* has upper left coordinate of and lower right coordinate of \= and

*Upper Pipe 2* has upper left coordinate of and lower right coordinate of \= and

![image](https://s3.amazonaws.com/hr-assets/0/1497960568-172c0beaaf-FlappyFinal2.png)

The following table shows the optimal solution.

| $x$ | $y$ | $v_y$ | tap |
| --- | --- | ----- | --- |
| 0   | 70  | 0     | yes |
| 1   | 70  | 0     | no  |
| 2   | 69  | \-1   | no  |
| 3   | 67  | \-2   | no  |
| 4   | 64  | \-3   | no  |
| 5   | 60  | \-4   | no  |
| 6   | 55  | \-5   | yes |
| 7   | 51  | \-4   | yes |
| 8   | 48  | \-3   | yes |
| 9   | 46  | \-2   | yes |
| 10  | 45  | \-1   | yes |
| 11  | 45  | 0     | no  |
| 12  | 44  | \-1   | yes |
| 13  | 44  | 0     | no  |
| 14  | 43  | \-1   | no  |
| 15  | 41  | \-2   | no  |
| 16  | 38  | \-3   | no  |
| 17  | 34  | \-4   | yes |
| 18  | 31  | \-3   | yes |
| 19  | 29  | \-2   | yes |
| 20  | 28  | \-1   | yes |
| 21  | 28  | 0     | yes |
| 22  | 29  | 1     | yes |
| 23  | 31  | 2     | yes |
| 24  | 34  | 3     | no  |
| 25  | 36  | 2     | no  |
| 26  | 37  | 1     | no  |
| 27  | 37  | 0     | no  |
| 28  | 36  | \-1   | no  |
| 29  | 34  | \-2   | no  |
| 30  | 31  | \-3   |     |

The table shows the position of Faby at time , , and is the vertical speed during time to time . The last column indicates whether we should tap at time .

**Sample Input 1**

```
7
1 59 30 59 1 59 1
```

**Sample Output 1**

```
6 46
```