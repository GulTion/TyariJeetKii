---
status: not_implemented
---

# Sinkhole Maximization (No STL Version)

## Problem Statement

You are given a large rectangular plot of land represented by an $N \times M$ grid.  Within this plot, there are several sinkholes. Sinkholes can combine. Your task is to find the largest possible *square* area within the plot that contains *at most one* sinkhole.  This square area will be used to occupy the plot.

If multiple square areas have the same maximum size, prioritize the one with the fewest sinkholes. If the number of sinkholes is also the same, any of those maximal squares is acceptable.

Your goal is to output the bottom-left and top-right coordinates of the selected square.  The plot's coordinate system starts at $(1, 1)$ in the bottom-left corner.

## Input Format

*   The first line contains an integer $T$, representing the number of test cases.
*   For each test case:
    *   The first line contains two integers, $N$ and $M$ ($1 \le N, M \le 1000$), representing the dimensions of the plot.
    *   The next line contains an integer $K$ ($1 \le K \le N + M$), representing the number of sinkholes.
    *   The following $K$ lines each contain two integers, $R_i$ and $C_i$ ($1 \le R_i \le N$, $1 \le C_i \le M$), representing the row and column coordinates (respectively) of a sinkhole.  Note that the input uses 1-based indexing (i.e., the top-left cell is (1,1)).

## Output Format

For each test case, output a single line in the following format:

```
#i xb yb xt yt
```

Where:

*   `i` is the test case number (starting from 1).
*   `xb` is the x-coordinate of the bottom-left corner of the selected square.
*   `yb` is the y-coordinate of the bottom-left corner of the selected square.
*   `xt` is the x-coordinate of the top-right corner of the selected square.
*   `yt` is the y-coordinate of the top-right corner of the selected square.

## Constraints

*   $1 \le T \le 100$ (This is a reasonable upper bound for T; it wasn't specified in the original text but a reasonable constraint is helpful. You can change this if needed).
*   $1 \le N, M \le 1000$
*   $1 \le K \le N + M$
*   $1 \le R_i \le N$
*   $1 \le C_i \le M$

## Time and Memory Limits

*   **Time Limit:** 1 second
*   **Memory Limit:** 256 MB

## Example

**Input:**

```
1
6 6
4
1 1
3 3
4 4
6 6
```

**Matrix Representation (for illustration):**

```
0 0 0 0 0 1
0 0 0 0 0 0
0 0 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 0
1 0 0 0 0 0
```
Note: In this representation '1' represents the presence of sinkhole and '0' denotes no sinkhole. The given co-ordinates in the input starts from (1,1) not (0,0)

**Output:**

```
#1 1 4 3 6
```

**Explanation:**

The largest square with at most one sinkhole is of size 3x3.  One such square has its bottom-left corner at (1, 4) and its top-right corner at (3, 6). This square contains no sinkholes. There are other 3x3 squares, but this one works.

## Restrictions

*   **You may NOT use any STL containers.** This includes (but is not limited to) `std::vector`, `std::map`, `std::set`, `std::queue`, `std::stack`, `std::list`, `std::unordered_map`, `std::unordered_set`, etc. You *can* use built-in arrays and `std::cin`/`std::cout`.

## 
```cpp
/*
https://www.geeksforgeeks.org/samsung-competency-test-25-aug-19/
*/
/*
	----IIT(ISM) Dhanbad----
	Author: Siddhant Choudhary
	
	--samsumg coding test--
	
	Q.There is a large plot with various sinkholes present. 
	Since one sinkhole can combine with another sinkhole, it is required to get
	at most one sinkhole while occupying the plot. You have to find the maximum 
	square-area formed with at most one sinkhole present.
	If there are two plots with the same area then print the one with 
	lesser sinkhole present otherwise if the sinkholes are also same then print
	anyone. For each case, you have to print the bottom leftmost coordinate and 
	top rightmost point. Please keep in mind that the plot starts with (1, 1).
	Time limit= 1sec and Memory limit– 256Mb
	Input: First line will give the number of test cases. For each test case, we
	will be given the size of the plot matrix N x M (where 1<=N, M<=1000). Next
	line will give the number of sinkholes present in the matrix K (1<=K<=N+M). 
	Next, K-lines will give the coordinates of the sinkholes.
	Output: For each test case, you have to print the number of the test case
	and the coordinates of the resultant square.
	i.e. #i xb yb xt yt (ith test case, xb=bottomost left x-coordinate, 
	yb=bottomost  left y-coordinate, xt= topmost right x-coordinate,
	yt= topmost right y-coordinate)
	
  *	time complexity of my approach = O(n*m*log(min(m,n))) *
*/
#include<bits/stdc++.h>
using namespace std;
int n, m, k, t;
int xb, yb, xt, yt;
int fun(int dp[1001][1001], int n, int m, int k){
	int msum = INT_MAX;
	for(int i = 0; i <= (n-k); i++){
		for(int j = 0; j <= (m-k); j++){
			int sum = dp[i+k][j+k] - dp[i+k][j] - dp[i][j+k] + dp[i][j];
			
			if(sum < msum){
				msum = sum;
				if(msum <= 1){
					xb = i+k;
					yb = j+1;
					xt = i+1;
					yt = j+k;
				}
			}
		}
	}
	return msum;
}
int a[1001][1001], dp[1001][1001];
int main(){
	cin>>t;
	for(int test_case = 1; test_case <= t; test_case++){
		cin>>n>>m;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				a[i][j] = 0;
			}
		}
		cin>>k;
		for(int i = 0; i < k; i++){
				int rc, cc;
				cin>>rc>>cc;
				a[rc-1][cc-1] = 1;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i-1][j-1];
			}
		}
		int l = 1, r = min(m, n);
		int ones;
		while(l < r){
			int mid = (l+r)/2;
			ones = fun(dp, n, m, mid);
			if(ones > 1)r = mid;
			else l = mid+1;
		}
		cout<<'#'<<test_case<<" "<<xb<<" "<<yb<<" "<<xt<<" "<<yt<<endl;
	}
	return 0;
}
```