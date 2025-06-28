---
title: Solve Challenges
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Print the total number of challenges created by hackers.
tags:
  - clippings
status: Complete
explored: true
---
## Burst Balloons Optimally

locked

- [Problem](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1)
- [Submissions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1/submissions)
- [Discussions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1/forum)

There are $N$ Balloons marked with value $B_i$ (where B(i…N)). User will be given Gun with $N$ Bullets and user must shot $N$ times. When any balloon explodes then its adjacent balloons becomes next to each other. User has to score highest points to get the prize and score starts at $0$. Below is the condition to calculate the score. When Balloon $B_i$ Explodes then score will be a product of $B_{i-1}$ & $B_{i+1}$ ($score = B_{i-1} * B_{i+1}$). When Balloon $B_i$ Explodes and there is only left Balloon present then score will be $B_{i-1}$. When Balloon $B_i$ Explodes and there is only right Balloon present then score will be $B_{i+1}$. When Balloon $B_i$ explodes and there is no left and right Balloon present then score will be $B_i$. Write a program to score maximum points.


**Input Format**

First line $N$ Next line array of $N$ integers

**Constraints**

$1 < N < 10$

**Output Format**

Single integer

**Sample Input 0**

```
4
1 2 3 4
```

**Sample Output 0**

```
20
```

**Sample Input:**
with T test case
```
5
4
1 2 3 4
5
3 10 1 2 5
7
12 48 28 21 67 75 85
8
245 108 162 400 274 358 366 166
10
866 919 840 944 761 895 701 912 848 799
```
 

**Sample Output:**
```
#1 20
#2 100
#3 16057
#4 561630
#5 6455522
```
## Approuch 1
```cpp
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(int left, int right, vector<int> &nums, int &N, vector<vector<int>> &dp) {
	if (left > right) return 0;
	if (dp[left][right] != -1) return dp[left][right];
	int maxAns = -1;
	for (int i = left; i <= right; i++) {
		int cost;
		if (left - 1 == 0 && right + 1 == N + 1) {
			cost = nums[i] + solve(left, i - 1, nums, N,dp) + solve(i + 1, right, nums, N, dp);
		}
		else {
			cost = nums[left-1] * nums[right+1] + solve(left, i - 1, nums, N, dp) + solve(i + 1, right, nums, N, dp);
		}
		maxAns = max(maxAns, cost);
	}
	return dp[left][right] = maxAns;

}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N + 2);
	vector<vector<int>> dp(N + 2, vector<int>(N + 2, -1));
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}
	nums[0] = 1;
	nums[N + 1] = 1;
	cout << solve(1, N, nums, N, dp) << endl;
}


```






