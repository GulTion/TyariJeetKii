---
title: Solve Challenges
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing
author:
  - "[[HackerRank]]"
published:
created: 2024-12-18
description: Print the total number of challenges created by hackers.
tags:
  - clippings
status: ""
explored: true
---
## Rock Climbing

locked

- [Problem](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing)
- [Submissions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing/submissions)
- [Discussions](https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/rock-climbing/forum)

Raka wants to climb a rock from a starting point to the destination point. Given a map of the rock mountain which N = height, M = width. In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially. It's impossible to move horizontally in case '-' is not consecutive in the same height level. The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing . The total distance of movement is not important. There is more than one path from the starting point to the destination point. Output: The minimum level of difficulty of all rock climbing paths level.

Hint: Start with difficulty level 0 and then keep increasing it one by one. **Raka always starts from bottom left position.**

![image](https://s3.amazonaws.com/hr-assets/0/1573304582-ca04649e3a-RockClimbing.png)

**Input Format**

First line contains n,m number of rows, columns respectively Next n lines each containg m integers. interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

**Constraints**

1 <= N,M <= 10

**Output Format**

Single interger "level"

**Sample Input 0**

```
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1
```

**Sample Output 0**

```
2
```

##
```cpp
// /*
// Raka wants to climb a rock from a starting point to the destination point.
// Given a map of the rock mountain which N = height, M = width.
// In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially.
// It's impossible to move horizontally in case '-' is not consecutive in the same height level.
// The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing .
// The total distance of movement is not important. There is more than one path from the starting point to the destination point.
// Output: The minimum level of difficulty of all rock climbing paths level.

// Hint: Start with difficulty level 0 and then keep increasing it one by one. Raka always starts from bottom left position.

// image

// Input Format

// First line contains n,m number of rows, columns respectively Next n lines each containg m integers. interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

// Constraints

// 1 <= N,M <= 10

// Output Format

// Single interger "level"

// Sample Input 0

// 5 8
// 1 1 1 1 0 0 0 0
// 0 0 0 3 0 1 1 1
// 1 1 1 0 0 1 0 0
// 0 0 0 0 0 0 1 0
// 1 1 1 1 1 1 1 1

// Sample Output 0

// 2

// */

#include <bits/stdc++.h>
using namespace std;

int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, 1, 0, -1};

bool dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, int level, int n, int m)
{
    vis[row][col] = 1;
    if (grid[row][col] == 3)
    {
        return true;
    }

    for (int i = 1; i <= level; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nrow = row + i * delrow[j];
            int ncol = col + delcol[j];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] != 0)
            {
                if (dfs(nrow, ncol, grid, vis, level, n, m))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        
        if (grid[n - 1][0] == 3)
        {
            cout << 0 << endl;
            return 0;
        }
        int j = 0;
        bool flag = true;
        while (j < m and grid[n - 1][j] == 1)
        {
            j++;
            if (j < m and grid[n - 1][j] == 3)
            {
                cout << 0 << endl;
                flag=false;
                break;
            }
        }
        if(flag==false)
        {
            continue;
        }

        int level = 1;
        while (1)
        {
            vector<vector<int>> vis(n, vector<int>(m, 0));

            if (dfs(n - 1, 0, grid, vis, level, n, m))
            {
                break;
            }
            level++;
        }
        cout << "#" << i << " " << level << endl;
    }
    return 0;
}

```

##
```cpp
/*

Raka wants to climb a rock from a starting point to the destination point.
Given a map of the rock mountain which N = height, M = width.
In the map, character '-' is the possible foot place spot (where he can climb). He can freely move up/down at vertical spots which '-' exists sequentially.
It's impossible to move horizontally in case '-' is not consecutive in the same height level.
The maximum height of moving from the starting point to the destination point is the level of difficulty of rock climbing .
The total distance of movement is not important. There is more than one path from the starting point to the destination point.
Output: The minimum level of difficulty of all rock climbing paths level.

Hint: Start with difficulty level 0 and then keep increasing it one by one. Raka always starts from bottom left position.

image

Input Format

First line contains n,m number of rows, columns respectively Next n lines each containg m integers. interger 3 represenets goal point, interger 1 represent '-', 0 represent "no step".

Constraints

1 <= N,M <= 10

Output Format

Single interger "level"

Sample Input 0

5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1

Sample Output 0

2

*/

#include <bits/stdc++.h>
using namespace std;

void dfs(pair<int, int> src, pair<int, int> dest, vector<vector<int>>& graph, vector<vector<int>> vis, int &ans, int temp, int n, int m)
{
    int row = src.first;
    int col = src.second;
    if (row == dest.first && col == dest.second)
    {
        // cout<<"mai yaha pahuch gaya"<<endl;
        // cout<<temp<<endl;
        ans = min(ans, temp);
        return;
    }
    vis[row][col] = 1;

    int nrow, ncol;
    // going horizontally
    nrow = row;
    // two cases : left or right
    // 1. right
    if (col + 1 < m)
    {
        ncol = col + 1;
        if (!vis[nrow][ncol] && graph[nrow][ncol] != 0)
        {
            vis[nrow][ncol] = 1;
            dfs({nrow, ncol}, dest, graph, vis, ans, temp, n, m);
            // vis[nrow][ncol]= 0;
        }
    }
    // 2. left
    if (col - 1 >= 0)
    {
        ncol = col - 1;
        if (!vis[nrow][ncol] && graph[nrow][ncol] != 0)
        {
            vis[nrow][ncol] = 1;
            dfs({nrow, ncol}, dest, graph, vis, ans, temp, n, m);
            // vis[nrow][ncol]= 0;
        }
    }

    // going vertically
    // two cases : up or down
    // 1. Up
    ncol = col;
    int cnt = 0;
    if (row - 1 >= 0)
    {
        for (int i = row - 1; i >= 0; i--)
        {

            if (!vis[i][ncol] && graph[i][ncol] != 0)
            {
                vis[i][ncol] = 1;
                dfs({i, ncol}, dest, graph, vis, ans, max(cnt + 1, temp), n, m);
                // cnt=0;
                // vis[i][ncol]=0;
            }
            // else{
            cnt++;
            // }
        }
    }
    int cnt2 = 0;
    if (row + 1 < n)
    {
        for (int i = row + 1; i < n; i++)
        {

            if (!vis[i][ncol] && graph[i][ncol] != 0)
            {
                vis[i][ncol] = 1;
                dfs({i, ncol}, dest, graph, vis, ans, max(temp, cnt2 + 1), n, m);
                // cnt2=1;
                // vis[i][ncol]=0;
            }
            // else{
            cnt2++;
            // }
        }
    }
    return;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n, vector<int>(m));
        pair<int, int> dest;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == 3)
                {
                    dest.first = i;
                    dest.second = j;
                }
            }
        }
        pair<int, int> src = {n - 1, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = INT_MAX;
        dfs(src, dest, graph, vis, ans, 0, n, m);
        cout << ans << endl;
    }
    return 0;
}

```
##
```cpp

DFS with recursion
BFS can also be used with increase in code complexity
Few people solved it with Backtracking as well (not advised though)
If the visited array is marked as “steps_count” under consideration, then we need not initialize the visited array with 0 for every “step_count”.
Attached is DFS solution with TC generation as well as timing calculation

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

Errors

Executed DFS from source and destination both at the same “step_count”.
This can lead to error as it can now jump 2*step_count.
Did not change the visited array properly after incrementing the “step_count”
Tried to jump only the current “step_count” in consideration.
You should consider all the steps from 0 to “step_count” in every loop.

```

##
```cpp
#include <iostream>
using namespace std;
int** matrix;
bool** visited;
int min_jump=2000000000;
int M;
int N;

bool isSafe(int x,int y){
	if(x>=0 && x<M && y>=0 && y<N)
		return true;
	return false;
}

void solve_util(int x, int y, bool** visited, int jump_size){
	visited[x][y]=true;
	if(matrix[x][y]=3){
		if(jump_size < min_jump){
			min_jump = jump_size;
		}
	}
	else{
		if(isSafe(x,y+1) && matrix[x][y+1] == 1 || matrix[x][y+1] == 3 && !visited[x][y+1]){
			solve_util(x,y+1,visited,jump_size);
		}
		if(isSafe(x,y-1) && matrix[x][y-1] == 1 || matrix[x][y-1] == 3 && !visited[x][y-1]){
			solve_util(x,y-1,visited,jump_size);
		}
		
		int nearest_vert_jump = -1;
		for(int i=x-1;i>=0;i--){
			if(matrix[i][y] == 1 || matrix[i][y] == 3){
				nearest_vert_jump=i;
				break;
			}
		}
		if(nearest_vert_jump != -1 && !visited[nearest_vert_jump][y]){
			int jump_size_current=(x-nearest_vert_jump);
			if(jump_size_current > jump_size){
				solve_util(nearest_vert_jump,y,visited,jump_size_current);
			}
			else{
				solve_util(nearest_vert_jump,y,visited,jump_size);
			}
		}
		
		int nearest_down_jump = -1;
		for(int i=x+1;i<M;i++){
			if(matrix[i][y] == 1 || matrix[i][y] == 3){
				nearest_down_jump=i;
				break;
			}
		}
		if(nearest_down_jump != -1 && !visited[nearest_down_jump][y]){
			int jump_size_current=(nearest_down_jump-x);
			if(jump_size_current > jump_size){
				solve_util(nearest_down_jump,y,visited,jump_size_current);
			}
			else{
				solve_util(nearest_down_jump,y,visited,jump_size);
			}
		}
	}
	visited[x][y]=false;
}

void solve(int x, int y, int jump_size_min){
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=false;
		}
	}
	solve_util(x.y.visited,jump_size_min);
}

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T;i++){
		cin>>M;
		cin>>N;
		matrix = new int* M;
		visited = new bool* [M];
		
		for(int i=0;i<M;i++){
			matrix[i] = new int[N];
			viisted[i] = new bool[N];			
		}
		
		for(int i=0;i<M;i++){
			for(int j=0;j<N;j++){
				cin>>matrix[i][j];
			}
		}
		
		solve(M-1,0,-1);
		cout<<"#"<<i<<min_jump<<endl;
		min_jump=2000000000;
	}
	system("pause");
	return 0;
}
```
