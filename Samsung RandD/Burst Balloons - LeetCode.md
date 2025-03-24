---
title: Burst Balloons - LeetCode
source: https://leetcode.com/problems/burst-balloons/description/
author:
  - "[[LeetCode]]"
published:
created: 2024-12-18
description: "Can you solve this real interview question? Burst Balloons - You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.Return the maximum coins you can collect by bursting the balloons wisely. Example 1:Input: nums = [3,1,5,8]Output: 167Explanation:nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167Example 2:Input: nums = [1,5]Output: 10 Constraints: * n == nums.length * 1 <= n <= 300 * 0 <= nums[i] <= 100"
tags:
  - clippings
status: ""
explored: false
---
You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array `nums`. You are asked to burst all the balloons.

If you burst the i<sup>th</sup> balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return *the maximum coins you can collect by bursting the balloons wisely*.

**Example 1:**

```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

**Example 2:**

```
Input: nums = [1,5]
Output: 10
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `0 <= nums[i] <= 100`

## 
```cpp
/*
https://www.youtube.com/watch?v=IFNibRVgFBo - Tushar Roy



int maxCoins(vector<int>& nums) {
    /* O(n^3) Time and O(n^2) Space */
    int size = nums.size();
    if(size == 0)
        return 0;
        
    int i, j, k;
    vector< vector<int> > dp(size, vector<int>(size, 0));
       
    for(int len = 1; len <= size; len++){
        for(i = 0; i <= size - len; i++){
            j = len + i - 1;
            for(k = i; k <= j; k++){ 
                /* Left/Right Value has default 1 but holds prev and after ballon value if k is in middle */
                int leftValue  = 1;
                int rightValue = 1;
                    
                if(i != 0)
                    leftValue  = nums[i-1];
                if(j != size-1)
                    rightValue = nums[j+1];
                        
                /* Before and After - current k balloon is last to burst select the left side and right side to burst */
                int before = 0;
                int after  = 0;
                    
                if(i != k)
                    before = dp[i][k-1];
                if(j != k)
                    after  = dp[k+1][j];
                    
                dp[i][j] = max(dp[i][j], 
                         leftValue * nums[k] * rightValue + before + after);
            }   
        }
    }    
    return dp[0][size-1];
}

```

## 
```cpp
/*

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] –> [3,5,8] –> [3,8] –> [8] –> [] coins = 3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167

*/



#include <iostream>
using namespace std;

#define lim 500
int bal[lim];
int dp[lim][lim];
int n;


int solution(){
    for(int len=1; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j=i+len-1;
            for(int k=i; k<=j; k++){
                int leftVal=1;
                int rightVal=1;

                if(i!=0){
                    leftVal=bal[i-1];
                }
                if(j!=n-1){
                    rightVal=bal[j+1];
                }

                int before=0;
                int after=0;
                if(i!=k){
                    before=dp[i][k-1];
                }
                if(j!=k){
                    after=dp[k+1][j];
                }
                dp[i][j]=max(dp[i][j], before+after+(leftVal*rightVal*bal[k]));
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        bal[i]=x;
    }
    cout<<solution()<<endl;
}

```