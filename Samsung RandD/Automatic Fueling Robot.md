---
title: Samsung ADV：Automatic Fueling Robot-CSDN博客
source: https://blog.csdn.net/weixin_42688573/article/details/124970239
author: 
published: 
created: 2025-02-28
description: "文章浏览阅读583次。Samsung ADV: Automatic Fueling Robot_samsung adv"
tags:
  - clippings
status: Complete
explored: true
---
There are $N$ cars parked in a row in a parking lot.  
On both sides of the parking garage, as it is demonstrated in the picture below, there is a Gasoline and Diesel fueling station installed.  
An automatic fueling robot carries the fuel form the station and fills up the parked cars with fuel.

![[Pasted image 20250308123031.png]]
The cars are divided into two types depending on whether it is a gasoline or Diesel car.  
The automatic robot will be used to provide a cost-free fueling service which is filling up all cars with 1L of each corresponding fuel.  
The robot will move between the two fueling stations as follows.

1. The robot carries 2L of gasoline at the Gasoline station and starts moving from there.
2. The robot can fill up the cars of the same type of gas it carries 1L each.
3. The robot can go back to the fueling, it gets 2L of supply of the corresponding fuel (if the robot has some remaining fuel, it will be discarded.)
4. There is an equal distance of 1 between each fueling station and the cars.

The fuel type of N cars parked in the parking lot will be given.  
Find the minimum moving distance of the automatic fueling robot after it has filled up all cars with 1 fuel each.

\[Example 1\]  
Given the number of total cars N=5 and the order of the parked cars such as G –D – G –D – G, the process of finding the minimum moving distance for fueling all cars is as follows:  
![[Pasted image 20250308123019.png]]
![[Pasted image 20250308123044.png]]
In this case, the total moving distance until the last car is filled up is 12 which is the minimum moving distance.

\[Example 2\]  
Given the total number of cars N=5 and the order of the parked cars such as D- G- G- D- G, the process of finding the minimum moving distance for fueling all cars is as shown below.  
![[Pasted image 20250308123057.png]]
![[Pasted image 20250308123107.png]]
In this case, the total moving distance until the last car is filled up with fuel is 14 which is the minimum moving distance.

\[Constrains\]

1. The number of total cars N is greater than or equal to 2 and less than or equal to 8.(2<=N<=8)
2. The amount of fuel that the robot can carry all at once at a fueling station is 2L.
3. All cars can get filled up with 1L of its corresponding fuel.
4. There is no empty space between each parked car and they are always 1 distance apart.
5. The tow fueling stations are 1 distance apart each from the outer parked car.

\[Input\]  
The first line contains a single integer T- the number of total test cases.  
From the next line on, each test case is given.  
The first line of each case contains N-the number of total cars.  
On the following line, N fuel information of the parked cars will be given as either 1 or 2. (1: Gasoline, 2: Diesel)

\[Output\]  
Print “#t” (without the quotes), leave a blank space and print the answer. ( t refers to the test case number and starts with 1).  
Print minimum moving distance of the automatic fueling robot after it has filled up all cars with 1L fuel each.

\[Input/ Output Example\]

Input Example

```
5
3
2 1 2
5
1 2 1 2 1
5
2 1 1 2 1
8
2 2 1 1 1 2 1 1
8
2 2 2 2 2 2 2 2
```

Output Example

```java
#1 7
#2 12
#3 14
#4 35
#5 41
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> arr(n); // 0-based for cars [0 to n-1]
    for (int &x : arr) cin >> x;

    int ans = INT_MAX;

    function<void(int, int, int, int, int, int)> dfs = [&](int mask, int dist, int remf, int pos, int ins, int gas) {
        if (__builtin_popcount(mask) == n) {
            ans = min(ans, dist);
            return;
        }
        if (remf <= 0) return;

        // Serve cars of same fuel type
        if (ins == 0) {
            if (gas == 0) {
                for (int i = 0; i < n; ++i) {
                    if (!(mask & (1 << i)) && arr[i] == 1) {
                        int newMask = mask | (1 << i);
                        int d = abs(pos - (i + 1)); // car at position i+1
                        dfs(newMask, dist + d, remf - 1, i + 1, 0, 0);
                        dfs(newMask, dist + d, 2, i + 1, 1, 0);
                        dfs(newMask, dist + d, 2, i + 1, 2, 0);
                    }
                }
            } else {
                for (int i = n - 1; i >= 0; --i) {
                    if (!(mask & (1 << i)) && arr[i] == 2) {
                        int newMask = mask | (1 << i);
                        int d = abs(pos - (i + 1));
                        dfs(newMask, dist + d, remf - 1, i + 1, 0, 1);
                        dfs(newMask, dist + d, 2, i + 1, 1, 1);
                        dfs(newMask, dist + d, 2, i + 1, 2, 1);
                    }
                }
            }
        }

        // Refill from gas station
        else if (ins == 1) {
            dfs(mask, dist + pos, 2, 0, 0, 0);
        }
        // Refill from diesel station
        else if (ins == 2) {
            dfs(mask, dist + (n + 1 - pos), 2, n + 1, 0, 1);
        }
    };

    // Start from gas side
    dfs(0, 0, 2, 0, 0, 0);
    // If no path, try from diesel side
    if (ans == INT_MAX)
        dfs(0, n + 1, 2, n + 1, 0, 1);

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}

```