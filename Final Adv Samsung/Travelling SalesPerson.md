---
title: HackerRank
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/travelling-salesman-4/problem
author:
  - "[[Travelling SalesPerson]]"
published: 
created: 2024-12-18
description: Join over 11 million developers in solving code challenges on HackerRank, one of the best ways to prepare for programming interviews.
tags:
  - clippings
status: Complete
explored: true
---
Given a matrix M of size N where M[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.

Example: Input: 2 2 0 111 112 0 3 0 1000 5000 5000 0 1000 1000 5000 0 Output: 223 3000

**Input Format**

Input: The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the matrix then in the next line are N*N space separated values of the matrix M.

**Constraints**
- $1<=T<=15$ 
- $1<=N<=12$ 
- $1<=M[][]<=10000$

**Output Format**

Output: For each test case print the required result denoting the min cost of the tour in a new line.

**Sample Input 0**

```
2
2
0 111
112 0
3
0 1000 5000
5000 0 1000
1000  5000  0
```

**Sample Output 0**

```
223
3000
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int solve(){
    int n; cin>>n;
    
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));

    for(auto &v:g) for(int &i:v) cin>>i;

    function<int(int, int)> dfs = [&](int v, int mask)->int{
        int j=__builtin_popcount(mask);
        if(j==n) return g[v][0];
        if(dp[v][mask]!=-1) return dp[v][mask];
        
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
            if(!(mask&(1<<i)))
               ans=min(ans, dfs(i, mask|(1<<i))+g[v][i]);
               
        return dp[v][mask] = ans;
    };

    return dfs(0,1);
}
int main(){
    int t; cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    
    return 0;
}
```