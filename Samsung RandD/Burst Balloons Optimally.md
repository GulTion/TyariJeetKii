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
status: ""
explored: false
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

## 2
```cpp
#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
int N;


int dp(int start, int end, vector<int> &ballons, vector<vector<int>>&dpMem) {
    if (start > end) return 0;
    if (dpMem[start][end] != -1) return dpMem[start][end];
    int maxAns = INT_MIN;
    for (int i = start; i <= end; i++) {
        int cost;
        if(start-1 ==0 && end+1 == N+1){
        cost = ballons[i] + 
            dp(start, i - 1, ballons, dpMem) + dp(i + 1, end, ballons, dpMem);
        }
        else {
            cost = ballons[start - 1] * ballons[end + 1] + 
            dp(start, i - 1, ballons, dpMem) + dp(i + 1, end, ballons, dpMem);
        }
        
        maxAns = max(cost, maxAns);
    }
    return dpMem[start][end] = maxAns;
}

int main()
{
    cin >> N;
    vector<int> ballons(N+2);
    vector<vector<int>>dpMem(N+2, vector<int>(N+2, -1));
    for (int i = 1; i <= N; i++) {
        cin >> ballons[i];
    }
    ballons[0] = 1;
    ballons[N + 1] = 1;
    int final = dp(1, N, ballons, dpMem);
    cout << final << endl;

}

```

## 3
```cpp
/*
/*
There are n balloons and n bullets and each balloon is assigned with a particular number (point).
Whenever a particular balloon is shot the no of points increases by
1.the multiplication of point assigned to balloon on left and that of right side.
2.point assigned to left if no right exists
3.point assigned to right if no left exists.
4.the point assigned to itself if no other balloon exists.
 
You have to output the maximum no of points possible.
 
Input
1 2 3 4
 
Output
20
*/
#include<bits/stdc++.h>
using namespace std;
int t, n;
long long int ans;
int visited[20];
int fun_left(int i){
    while(i >= 0 and visited[i] == 1)i--;
    return i;
}
int fun_right(int i){
    while(i <= n and visited[i] == 1)i++;
    return i;
}
void fun(vector<int>&v, int count, long long int tmp_ans){
    if(count == n){
        ans = max<long long int>(ans, tmp_ans);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            
            int left = fun_left(i);
            int right = fun_right(i);
            long long tmp = v[left]*v[right];
            if(count == n-1)fun(v, count+1, v[i]+tmp_ans);
            else fun(v, count+1, tmp+tmp_ans);
            
            visited[i] = 0;
        }
    }
}
int main(){
        cin>>n;
        vector<int>v(n+2, 0);
        for(int i = 1; i <= n; i++){
            cin>>v[i];
        }
        v[0] = 1;
        v[n+1] = 1;
        ans = 0;
        memset(visited, 0, sizeof(visited));
        for(int i = 1; i <= n; i++){
            visited[i] = 1;
            int left = fun_left(i);
            int right = fun_right(i);
            fun(v, 1, v[left]*v[right]);
            memset(visited, 0, sizeof(visited));
        }
        if(n == 1)cout<<v[1]<<endl;
        else cout<<ans<<endl;
}

```

## 4
shooting balloon 10

There will be a N Balloons marked with value Bi (where B(i…N)).
User will be given Gun with N Bullets and user must shot N times.
When any balloaon explodes then its adjacent balloons becomes next to each other.
User has to score highest points to get the prize and score starts at 0.
Below is the condition to calculate the score.
When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-I * Bi+1).
When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1.
When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1.
When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi.
Write a program to score maximum points.
Conditions:
Execution time limits 3 seconds.
No of Balloons N, where 1 <= N <= 10
Bi value of the Balloon 1 <= Bi <= 1000.
No two Balloons explode at same time.

Input:
Consists of TC (1 <= TC <= 50).
N – No of Balloons.
B0…..BN  N Balloons with their values .
Output: 
#TC SCORE

Sample Input:
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
 

Sample Output:
#1 20
#2 100
#3 16057
#4 561630
#5 6455522

1)Aim is to find max score
1) Max score depend on points on neighbor, however there is no easy way to find which sequence which gives max score, so only way is to find the all possible sequence can get max out of it.
2) As order matters in sequence for input N we can have N! sequences, ie. nPn ways (1st balloon N ways, 2nd N-1 ways …last balloon 1 ways N*(N-1)(N-2)..2*1= N!
```cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

clock_t start, end;
double cpu_time_used;

int matrix[MAX_SIZE][MAX_SIZE];
int visited_matrix[MAX_SIZE][MAX_SIZE];

int move[4][2] = {
	1, 0,
	-1, 0,
	0, -1,
	0, 1
};

int check_for_level(int dest_x, int dest_y);
int check_for_last_row(int dest_x, int dest_y, int level);

int row = 0;
int col = 0;

int prob(int x)
{
	if (rand() % 100 < x)
		return 1;
	else
		return 0;
}

void init_visited_matrix()
{
	int i, j;
	for (i = 0; i < MAX_SIZE; i++)
	for (j = 0; j < MAX_SIZE; j++)
		visited_matrix[i][j] = 0;
}

void print_matrix(int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
}

int main()
{
	srand(10);
	int i, j, m, n, p, t, ans, loc_x, loc_y;
	int tc = 50;
	start = clock();
	for (t = 0; t < tc; t++)
	{
		m = 20 + rand() % 30;
		n = 20 + rand() % 30;

		//For safety, fill the whole matrix with -1 to start with
		for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = -1;


		//Fill the left corner with 2
		matrix[m - 1][0] = 2;

		//Fill the last line with all 1
		for (i = 1; i < n; i++)
			matrix[m - 1][i] = 1;

		//Pick a random location and fill it with 3
		loc_x = rand() % m;
		loc_y = rand() % n;
		matrix[loc_x][loc_y] = 3;

		//pick a random probability between 40 to 60 to fill with 1
		p = 0 + rand() % 20;

		//fill the rest of the matrix with 1s and 0s with probability p

		for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (-1 == matrix[i][j])
			{
				if (prob(p))
					matrix[i][j] = 1;
				else
					matrix[i][j] = 0;
			}
		}
		row = m;
		col = n;
		//print_matrix(m,n);
		
		ans = check_for_level(loc_x, loc_y);
		
		//printf("Row %d Col %d Loc_x %d Loc_y %d\n", m, n, loc_x, loc_y);
		printf("Case#%d: %d\n", t, ans);

	}
	end = clock();
	cpu_time_used = ((double)(end - start));
	printf("%lf\n", cpu_time_used);
	return 0;
}

int check_for_level(int dest_x, int dest_y)
{
	int level = 1;
	while (1)
	{
		init_visited_matrix();
		visited_matrix[dest_x][dest_y] = 1;
		if (1 == check_for_last_row(dest_x, dest_y, level))
		{
			return level;
		}
		level++;
	}
}

int check_for_last_row(int dest_x, int dest_y, int level)
{
	if (dest_x == row-1)
		return 1;

	int k, temp_x, temp_y;
	for (k = 0; k < (2 + 2 * level); k++)
	{
		if (k < 4)
		{
			temp_y = dest_y + move[k][1];
			temp_x = dest_x + move[k][0];
		}
		else
		{
			temp_y = dest_y;
			temp_x = dest_x + (k/2)*move[k%2][0];
		}
		if (temp_x >= 0 && temp_y >= 0 && temp_x < row && temp_y < col)
		{
			if (matrix[temp_x][temp_y] == 1 && visited_matrix[temp_x][temp_y] == 0)
			{
				visited_matrix[temp_x][temp_y] = 1;
				if (1 == check_for_last_row(temp_x, temp_y, level))
					return 1;
			}
		}
	}
	return 0;
}
```
Complexity

To generate the all sequence O(N!)
To Get the Score for 1 sequence, for each balloon in sequence we need to left and right neighbors worst case need complete traversal in array  so complexity is O(N*N)  
Total complexity is O(N!) * O(N*N)  (note: computation has done at end of each sequence)
50 TC , N<= 10 => 50 *  is O(N! * N*N)  => 50 * 100 * 10! => 5000 * 3628800 => 1.5 * 10^10 this cannot be executed in given 3 sec ( 10^9 instruction per second).
So need to look for optimization

Pseudo code to generate all sequences

INPUT[N]
CHOICE[N] <= -1 //initialize to -1
Permute(0)
Permute(Position)
{
//stop condition
If( all balloon shot )
{
Compute the score for this sequence in CHOICE[]
If score better than previous then store
}
 
For i:0~N-1
{
If (ith balloon not selected // CHOICE[i]==-1)
{
Select ith balloon  // CHOICE[Position]= i 
Permute (Position+1)
Unselect ith balloon// CHOICE[Position]= -1
}
}
}

Optimization
We can see in above algorithm 2 major operation are carried out 1) generate all sequence O(N!) and 2) computing score for each sequence O(N*N)
We cannot optimize the algorithm generate all sequences however we can reduce the computing part further.
Optimization computing part
If can optimize the finding the neighbor to O(1) we can reduce computation part to O(N) which leads our algo to execute in 1.5 * 10^9 which can be achieved in 3 sec.
Alternatively we can compute the score for each chosen balloon to shoot “on the go” here finding neighbor is extra when each time balloon is chosen which can be  O(N) and also reduce 1.5 * 10^9
If we combine 1 and 2 we can further reduce the time to 1.5 * 10^8

Algorithm to get neighbors

Naïve method by O(N):
    Neighbor(chosen)
	For Left: chosen-1~0 if Left th balloon not chosen break;
	For Right: chosen+1~N-1 if right th balloon not chosen break;
	if(Right==N)
		 Right=-1;
	Return   Left and right ;
 Optimized way by O(1)
Keep 2 array left[] and right[] which contain neighbors of each balloon.
Initially neighbor are known, for ith balloon left is i-1 and right is i+1 except that 1st balloon will have no left and last have no right.
When balloon is chosen we can obtain its right and left by O(1)
When a balloon is shot update neighbor  left[i+1]=left[i]  right[i-1]=right[i]
Note:
Instead of calling the new function to get left and right calculating left and right inside the recursive faction will reduce many hidden instructions as to call  new function compiler add many instruction which can be reduced 

Alternate Way

Naïve method by O(N):
    Neighbor(chosen)
	For Left: chosen-1~0 if Left th balloon not chosen break;
	For Right: chosen+1~N-1 if right th balloon not chosen break;
	if(Right==N)
		 Right=-1;
	Return   Left and right ;
 Optimized way by O(1)
Keep 2 array left[] and right[] which contain neighbors of each balloon.
Initially neighbor are known, for ith balloon left is i-1 and right is i+1 except that 1st balloon will have no left and last have no right.
When balloon is chosen we can obtain its right and left by O(1)
When a balloon is shot update neighbor  left[i+1]=left[i]  right[i-1]=right[i]
Note:
Instead of calling the new function to get left and right calculating left and right inside the recursive faction will reduce many hidden instructions as to call  new function compiler add many instruction which can be reduced 

Errors

Error in algorithm to generate permutation
Not optimizing the Computing the score algorithm.
Stop condition in recursive problem 
Selecting greedy methods

Alternative optimized approach(Divide and Conquer) and Dynamic programming

The problem at first doesn't seem like a divide and conquer problem.
Reason: If we select a balloon(for bursting) then our array would be divided into two sub arrays. But these two sub arrays won't be independent sub problems.
Example
Consider 5 balloons B1,.., B5. Bursting B3 divides the array into two sub-array {B1, B2} and {B4, B5}. But these two sub array are not independent of each other ie. score for bursting B4 is dependent on bursting order of {B1, B2}. 

B1    B2    X    B4    B5

Key Insight
To divide the problem into two halves we have to ensure that any action(bursting of balloon) in one half doesn't affect score of the other half.
If we fix a balloon and ensure that we won't burst it until we burst all the balloons to the left of it and all the balloon to the right of it then we can successfully divide the problem into two sub-problems.
Example
Consider the previous case of five balloons. Now instead of bursting B3 we fix that we will burst B3 after all the balloons this makes {B1, B2} and {B4, B5} independent of each other ie score for bursting B4 is now independent of {B1, B2}.

Another way to visualize the divide and conquer approach is that we think of the problem in reverse. The parallel problem would be given a set of n deflated balloons each with a score, choose the order in which you will inflate the balloon. The score for inflating the balloon is equal to product of score attached to the balloons located left and right to the mentioned balloon.

Pseudo Code

Note:
We store the the input score values in the array inp_arr[N+2]. 
The values corresponding to the ith baloon is store at inp_arr[i].
inp_arr[0] = inp_arr[N+1] = 1;

getMaxScore(inp_arr, left_limit, right_limit, N){
	initialize max_score = 0;   //Max Score Value to Be Returned
	for(i: left+1 to right-1){
		initialize curr_score = 0;		
		curr_score = getMaxScore(inp_arr, left, i, N) + getMaxScore(inp_arr, i, right, 	
		if(left == 0 && right == N){
			curr_score += inp_arr[i];
		}
		else{
			curr_score += inp_arr[left]*inp_arr[right];
		}
		//Update max_score value
		if(curr_score> max_score){
			max_score = curr_score;
		}
	}
	return max_score;
}


The above problem can be easily optimized to include memoization using 2 Dimensional DP Matrix.

Execution time for diff approach

For input given in this document.
Generating sequences and computing at end by list for finding neighbor
	Execution time: 0.934000 seconds.
On the way compute
 external call for finding neighbor : Execution time: 1.223000 seconds. 
Inline for finding neighbor: Execution time: 0.657000 seconds.
List for finding neighbor: Execution time: 0.616000 seconds.

Divide and conquer:
-  Execution time: 0.004000 seconds.
with DP:  Execution time: 0.001000 seconds.


## 5
```cpp
/*
There are N Balloons marked with value Bi (where B(i…N)). 
User will be given Gun with N Bullets and user must shot N times. 
When any balloon explodes then its adjacent balloons becomes next to each other. 
User has to score highest points to get the prize and score starts at 0. 
Below is the condition to calculate the score. 
When Balloon Bi Explodes then score will be a product of Bi-1 & Bi+1 (score = Bi-1 * Bi+1). When Balloon Bi Explodes and there is only left Balloon present then score will be Bi-1. When Balloon Bi Explodes and there is only right Balloon present then score will be Bi+1. When Balloon Bi explodes and there is no left and right Balloon present then score will be Bi. Write a program to score maximum points.

Input 4 1 2 3 4

Output

20
*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int ans,n;
vector<int> v;
vector<vector<int>> dp;
int burst(int i, int j)
{
	
	if(i>j) return 0 ;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans= INT_MIN;
	for(int index=i; index<=j;index++)
	{
		int cost=0;
		if(i==1 && j==n)
          cost=v[index]+burst(i,index-1)+burst(index+1,j);

		else cost= v[i-1]*v[j+1] + burst(i,index-1) + burst(index+1,j);

		dp[i][j]= max(dp[i][j],cost);
	}
	return dp[i][j];
}
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	
	v.pb(1);
	int i,x;
	cin>>n;
	ans= INT_MIN;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		v.pb(x);

	}
	v.pb(1);
	dp.assign(n+1,vector<int>(n+1,-1));
	
	cout<<burst(1,n)<<endl;
}
```
## 6
```cpp
#include <stdio.h>

#define SZ 1000

int Dp[SZ][SZ];
int Balloon[SZ];
int N;
int Test_cases,Case;

void init_dp()
{
    for(int i = 0 ; i <= N+2 ; i++){
        for(int j = 0 ; j <= N+2 ; j++){
            Dp[i][j] = 0;
        }
    }
}


/*void print_dp()
{
    for(int i = 0 ;i < N+2 ; i++){
        for(int j = 0 ;j < N+2 ; j++){
            printf("%d ",Dp[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
}

void print_balloon()
{
    printf("%d\n\n",N);
    for(int i = 0 ; i< N ; i++){
        printf("%d ",Balloon[i]);
    }

    printf("\n\n");
}
*/


void solve()
{
    int i,j,k,len;

    init_dp();

    for(len = 1; len <= N ; len++){
        for(i = 0; i <= N-len ; i++){
            j = len+i-1;

            for(k = i ; k <= j ; k++){
                int left = 1;
                int right = 1;

                if(i!= 0){
                    left = Balloon[i-1];
                }

                if(j != N-1){
                    right = Balloon[j+1];
                }

                int before = 0;
                int after = 0;

                if(i != k){
                    before = Dp[i][k-1];
                }
                if(j != k){
                    after = Dp[k+1][j];
                }


                int tmp = before + left * right + after;

                if(tmp > Dp[i][j]){
                    Dp[i][j] = tmp;
                }
            }
        }
    }
}

void take_input()
{
    scanf("%d",&N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d",&Balloon[i]);
    }

}

void print_output()
{

    printf("#%d %d\n",Case, Dp[0][N-1]-1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%d",&Test_cases);

    for(Case = 1 ; Case <= Test_cases; Case++){
        take_input();
        solve();
        //print_dp();
        //print_balloon();

        print_output();
    }
}

```

## 7
```cpp
1.

// https://github.com/s-kachroo/SamsungPractice/blob/master/burst%20balloon%202.cpp

// https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/burst-balloons-1

#include<iostream>

#include<algorithm>

using namespace std;

  

int dp[100][100];

  

int mxPoint(int *arr, int n) {

int i, j, len, k, leftValue, rightValue, before, after;

for (len = 1; len <= n; len++) {

for (i = 0; i <= n-len; i++) {

j = i + len - 1;

for (k = i; k <= j; k++) {

leftValue = rightValue = 1;

before = after = 0;

  

if (i != 0)

leftValue = arr[i-1];

if (j != n-1)

rightValue = arr[j+1];

  

if (i != k) {

before = dp[i][k-1];

}

  

if (j != k) {

after = dp[k+1][j];

}

  

if (leftValue == 1 && rightValue == 1)

dp[i][j] = max(dp[i][j], before + leftValue * arr[k] * rightValue + after);

else

dp[i][j] = max(dp[i][j], before + leftValue * rightValue + after);

}

}

}

return dp[0][n-1];

}

  

int main() {

int i, mx, n;

int arr[100];

cin>> n;

  

for (i = 0; i < n; i++)

cin>> arr[i];

  

mx = mxPoint(arr, n);

cout<< mx << "\n";

return 0;

}

  

2.

  

#include<iostream>

#include<algorithm>

using namespace std;

  

int dp[100][100];

  

int mxPoint(int *arr, int n) {

int i, j, len, k, leftValue, rightValue, before, after;

for (len = 1; len <= n; len++) {

for (i = 0; i <= n-len; i++) {

j = i + len - 1;

for (k = i; k <= j; k++) {

leftValue = rightValue = 1;

before = after = 0;

  

if (i != 0)

leftValue = arr[i-1];

if (j != n-1)

rightValue = arr[j+1];

  

if (i != k) {

before = dp[i][k-1];

}

  

if (j != k) {

after = dp[k+1][j];

}

  

dp[i][j] = max(dp[i][j], before + leftValue * arr[k] * rightValue + after);

}

}

}

return dp[0][n-1];

}

  
  

int main() {

int i, mx, n;

int arr[100];

cin>> n;

  

for (i = 0; i < n; i++)

cin>> arr[i];

mx = mxPoint(arr, n);

cout<< mx << "\n";

return 0;

}

  

3.

  

#include<iostream>

#include<algorithm>

#include<climits>

using namespace std;

  

int main() {

int n, i, j, len;

int k, leftVal, rightVal, before, after;

int dp[100][100];

int arr[100];

cin>> n;

  

for (i = 0; i < n; i++)

cin>> arr[i];

  

for (i = 0; i < n; i++) {

for (j = 0; j < n; j++)

dp[i][j] = 0;

}

  

for (len = 1; len <= n; len++) {

for (i = 0; i <= n-len; i++) {

j = i + len - 1;

  

for (k = i; k <= j; k++) {

leftVal = 1;

rightVal = 1;

before = 0;

after = 0;

  

if (i != 0) {

leftVal = arr[i-1];

}

  

if (j != n-1) {

rightVal = arr[j+1];

}

  

if (i != k)

before = dp[i][k-1];

if (j != k)

after = dp[k+1][j];

  

if (leftVal == 1 && rightVal == 1)

dp[i][j] = max(dp[i][j], before + leftVal * arr[k] * rightVal + after);

else

dp[i][j] = max(dp[i][j], before + leftVal * 1 * rightVal + after);

}

}

}

cout<< dp[0][n-1] << "\n";

  

return 0;

}
```

## 
```cpp
#include<iostream>

using namespace std;

int* balloon;

int n;

int getSum(int left, int right)

{

int maxScore=0;

for(int i=left+1;i<=right-1;i++)

{

int sum=0;

sum=getSum(left,i)+getSum(i,right);

if(left==0&&right==n+1)

{

sum+=balloon[i];

}

else

{

sum+=balloon[left]*balloon[right];

}

if(sum>maxScore)

{

maxScore=sum;

}

}

return maxScore;

}

int main()

{

int tc,count=1;

cin>>tc;

while(tc--)

{

cin>>n;

balloon=new int[n+2];

balloon[0]=balloon[n+1]=1;

for(int i=1;i<=n;i++)

{

cin>>balloon[i];

}

cout<<"#"<<count++<<" "<<getSum(0,n+1)<<endl;

}

system("pause");

return0;

}
```

## 
```cpp
#include <bits/stdc++.h>

using namespace std;

int ans;

  

void calScore(vector<int> balls, int temp)

{

vector<int> tempballs = balls;

if (balls.size() == 1)

{

ans = max(ans, temp + balls[0]);

return;

}

int m = balls.size();

for (int i = 0; i < m; i++)

{

// left and right both

if (i - 1 >= 0 && i + 1 < m)

{

int left = balls[i - 1];

int right = balls[i + 1];

auto it = balls.begin() + i;

balls.erase(it);

calScore(balls, temp + left * right);

balls = tempballs;

}

  

else if (i - 1 >= 0 && i + 1 >= m)

{

int left = balls[i - 1];

auto it = balls.begin() + i;

balls.erase(it);

calScore(balls, temp + left);

balls = tempballs;

}

  

else if (i - 1 < 0 && i + 1 < m)

{

int right = balls[i + 1];

auto it = balls.begin() + i;

balls.erase(it);

calScore(balls, temp + right);

balls = tempballs;

}

}

}

  

int main()

{

/* Enter your code here. Read input from STDIN. Print output to STDOUT */

int t;

cin >> t;

while (t--)

{

int n;

cin >> n;

vector<int> balls;

for (int i = 0; i < n; i++)

{

int a;

cin >> a;

balls.push_back(a);

}

ans = 0;

  

calScore(balls, 0);

cout << ans << endl;

}

return 0;

}
```

## 
```cpp
class Solution {
public:
    int dp[502][502];
    vector<int> balloons;
    int helper(int l,int r,int n){
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=0;
        for(int i=l+1;i<r;i++){
            int curr=helper(l,i,n)+helper(i,r,n);
            if(l==0 && r==n+1){
                curr=curr+balloons[i];
            }else{
                curr=curr+balloons[l]*balloons[r];
            }
            ans=max(ans,curr);
        }
        dp[l][r]=ans;
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        balloons=nums;
        memset(dp,-1,sizeof(dp));
        balloons.insert(balloons.begin(),1);
        balloons.push_back(1);
        int n=nums.size();
        int ans=helper(0,n+1,n);
        return ans;
    }
};
```
##
