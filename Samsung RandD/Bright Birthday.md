---
source: https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges/bright-birthday/problem
explored: false
---


# Bright Birthday
## Problem

Submissions

**Time Limit :**  $C/C++ (1s), Java (2s)$
**Memory Limit :** $256 MB$

Bivas received a colorful gift for his birthday. It is a string $S$ of lowercase English letters. He is delighted and wants to brighten up his room using it.

He knows a set of colors $C$ which consists of names of different colors. The set is fixed and showed below.

$C = \{ \text{"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"} \}$

Now he wishes to use some of the characters from $S$ to make *different* colors and decorate his room on his special day. He wants to choose a subset of $C$ such that all the colors from that subset can be made from using each character of $S$ at most once. All the colors he wishes must be created simultaneously and he cannot use one instance of a character in creating different colors of the chosen subset. *Refer to the sample explanation for further clarity.*

You need to help Bivas find the maximum possible size of the desired subset.

**Input Format**

The first line contains an integer $t$ denoting the number of test cases.

Then follow $t$ lines each consisting of the string $S$ for a test case.

**Constraints**

$1 \le t \le 20$

$1 \le |S| \le 10^5$

**Output Format**

For each testcase print the answer in a separate line.

**Sample Input 0**

```
3
bluehatesred
dergey
nothing
```

**Sample Output 0**

```
3
1
0
```

**Explanation 0**

*   First testcase: You can make the colors "blue", "ash" and "red" together.
*   Second testcase: You can either make "grey" or "red", but not both of them together.
