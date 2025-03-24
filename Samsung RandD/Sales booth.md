Samsung wants to introduce the promotions in mobile sale.  They want to setup a booth to sell mobile phones.  They will club all areas of same mobile model with 1 single booth.   In areas (marked zero), where Samsung mobile is not established, they will consider selling the mobiles that are famous in adjacent areas of higher configuration.  
We are given N*N matrix which can have a number between 0 and 5.

5	5	1	4	4
4	0	2	4	2
5	0	0	2	0
5	4	3	0	1
1	3	3	2	1

5	5	1	4	4
4	5	2	4	2
5	5	5	2	2
5	4	3	3	1
1	3	3	2	1

In this case, 11 independent clusters are formed. This means 11 booths have to be setup.


We need to consider selling the mobile that are famous in adjacent areas. In below case, count is like this:
S3 mobile – 3
S2 mobile – 2
S1 mobile – 2

As S3 is famous in neighboring area, so S3 will be considered for selling at this location.

0	0	2	0
4	3	0	1
3	3	2	1

Problem Analysis:
We need to find clusters of Samsung mobiles around the place where Samsung mobile is not established yet ( marked 0 in matrix). After finding clusters, we can choose the famous handset of higher configuration. 

Let’s take below example, 

5	5		
4	0	2	
5	0	0	2
5	4	3	 
 	3	3	

While calculating for 0 located at (1,1) position in matrix, we need to find clusters around all the 0s which are connected with each other. For this group of 0, we can find clusters of Samsung mobiles around it and replace these 0s with famous mobile having highest configuration.

We can calculate cluster using BFS or DFS.  For above case, we will find below clusters around these 0s:

S5 Mobile – 4 (Marked in Orange )
S4 Mobile -  2 (marked in red)
S3 Mobile – 3
S2 Mobile – 2
S1 Mobile - 0

Highest configuration famous mobile is S5; hence we can replace these 0s with S5 mobile.

5	5		
4	5	2	
5	5	5	2
5	4	3	 
 	3	3	

Approaches to the problem of traversal:

1)	Recursive Depth-first Search:
Find clusters around “Zero” or “Group of Zeros” which are connected using recursive DFS approach. Its simple approach using recursive Calls. However, it would be little slow as compare to other two approaches. DFS solution is given by Sasi. (Source: from sasi folder)

// GalaxyYesSix.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N 100

char adjM[MAX_N + 1][MAX_N + 1];
char resM[MAX_N + 1][MAX_N + 1];
char visitedZ[MAX_N][MAX_N];
char visitedN[MAX_N][MAX_N];
char visitedRepZ[MAX_N][MAX_N];
char visitedRes[MAX_N][MAX_N];

#define TOP(i,j,x,y) (x=i-1,y=j);
#define LEFT(i,j,x,y) (x=i,y=j-1);
#define RIGHT(i,j,x,y) (x=i,y=j+1);
#define BOTTOM(i,j,x,y) (x=i+1,y=j);

#define DFS_Z_SUB_COND	if(( x >=0 && x < N ) && ( y >= 0 && y < N))\
{ \
if ((adjM[x][y] == 0) && (!visitedZ[x][y])) \
{\
	applyDFS_Z_Sub(x, y); \
}\
							else if ((adjM[x][y] != 0) && (!visitedN[x][y])) \
{\
	applyDFS_N(x, y, adjM[x][y]); \
}\
}

#define DFS_N_COND( adjMat, num, funcDFS, visited)	if(( x >=0 && x < N ) && ( y >= 0 && y < N))\
{\
if ((adjMat[x][y] == (num)) && (!visited[x][y]))\
{\
	funcDFS(x, y, (num)); \
}\
}

#define DFS_Z_REPLACE_COND(num, resMat)	if(( x >=0 && x < N ) && ( y >= 0 && y < N))\
{\
if ((resMat[x][y] == 0) && (!visitedRepZ[x][y]))\
{\
	applyDFS_Z_replace(x, y, (num)); \
}\
}

int maxArr[MAX_N + 1];
int N;
int boothCnt;

int findMaxElem()
{
	int i;
	int max = 0;
	int num;
	for (i = 1; i <= MAX_N; i++)
	{
		if (maxArr[i] >= max)
		{
			max = maxArr[i];
			num = i;
		}
	}

	return num;
}

void applyDFS_Z_replace(int i, int j, int num)
{
	int x, y;
	visitedRepZ[i][j] = 1;
	resM[i][j] = num;

	//Top
	TOP(i, j, x, y)
		DFS_Z_REPLACE_COND(num, resM)

		//Left
		LEFT(i, j, x, y)
		DFS_Z_REPLACE_COND(num, resM)

		//Right
		RIGHT(i, j, x, y)
		DFS_Z_REPLACE_COND(num, resM)

		//Bottom
		BOTTOM(i, j, x, y)
		DFS_Z_REPLACE_COND(num, resM)
}


void applyDFS_N(int i, int j, int elem)
{
	int x, y;

	visitedN[i][j] = 1;
	maxArr[elem]++;

	//Top
	TOP(i, j, x, y)
		DFS_N_COND(adjM, elem, applyDFS_N, visitedN)

		//Left
		LEFT(i, j, x, y)
		DFS_N_COND(adjM, elem, applyDFS_N, visitedN)

		//Right
		RIGHT(i, j, x, y)
		DFS_N_COND(adjM, elem, applyDFS_N, visitedN)

		//Bottom
		BOTTOM(i, j, x, y)
		DFS_N_COND(adjM, elem, applyDFS_N, visitedN)
}

void applyDFS_Z_Sub(int i, int j)
{
	int x, y;
	visitedZ[i][j] = 1;

	//Top
	TOP(i, j, x, y)
		DFS_Z_SUB_COND

		//Left
		LEFT(i, j, x, y)
		DFS_Z_SUB_COND

		//Right
		RIGHT(i, j, x, y)
		DFS_Z_SUB_COND

		//Bottom
		BOTTOM(i, j, x, y)
		DFS_Z_SUB_COND
}

void applyDFS_Z_Main()
{
	int i, j;
	int maxElem = 0;
	int p, q;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (adjM[i][j] == 0 && !visitedZ[i][j])
			{
				applyDFS_Z_Sub(i, j);
				maxElem = findMaxElem();
				applyDFS_Z_replace(i, j, maxElem);
				for (p = 0; p<N; p++)
				{
					for (q = 0; q<N; q++)
					{
						visitedN[p][q] = 0;
					}
				}

				for (p = 1; p <= N; p++)
					maxArr[p] = 0;

			}
		}
	}
}

void applyDFS_Count_Booths_Sub(int i, int j, int num)
{
	int x, y;
	visitedRes[i][j] = 1;

	//Top
	TOP(i, j, x, y)
		DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)

		//Left
		LEFT(i, j, x, y)
		DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)

		//Right
		RIGHT(i, j, x, y)
		DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)

		//Bottom
		BOTTOM(i, j, x, y)
		DFS_N_COND(resM, num, applyDFS_Count_Booths_Sub, visitedRes)
}

void applyDFS_Count_Booths()
{
	int i, j;
	int maxElem = 0;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (!visitedRes[i][j])
			{
				applyDFS_Count_Booths_Sub(i, j, resM[i][j]);
				boothCnt++;
			}
		}
	}
}


int main()
{
	int T;
	int testCase, i, j;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (testCase = 1; testCase <= T; testCase++)
	{
		scanf("%d", &N);

		for (i = 0; i<N; i++)
		{
			for (j = 0; j<N; j++)
			{
				scanf("%d", &adjM[i][j]);
				resM[i][j] = adjM[i][j];
				visitedN[i][j] = 0;
				visitedZ[i][j] = 0;
				visitedRepZ[i][j] = 0;
				visitedRes[i][j] = 0;
			}
			maxArr[i] = 0;
		}

		boothCnt = 0;

		applyDFS_Z_Main();
		applyDFS_Count_Booths();

		printf("\r\n #%d: %d", testCase, boothCnt);
	}
}

2)	DSF using Stack (Non Recursive):
We can avoid recursive function calls by implementing our own stack. 

STACK s
visited[ ]
DFS(v)
         push( s, v )
         WHILE NOT isEmpty( s ) 
                  v ← pop(s)
                  IF NOT visited[v]
                           visit( v )
                           FOR each w in adjacency( v )  //adjacent in UP, RIGHT, DOWN, LEFT  dir
                                                  IF NOT visited[w] and Value is same as previous Node
                                                              push(s, w)


3)	Breadth-First Search:
We can find clusters around Zeros using BFS approach as well. BFS would need queue implementation.  

BFS(G,v) // Graph G, Starting point of search v
	Generate queue
	Insert the starting point v to the queue
	Indicate the point v as visited
	WHILE queue is not empty
		t ← return the first element of queue
		FOR every line connected to t
			u ← neighboring point of t  
			If u is not visited point, and value is same as pervious Node
			insert u into queue, and indicate as visited


#define _CRT_SECURE_NO_WARNINGS
#define MAX 105
int N;
char map[MAX][MAX];
char res[MAX][MAX];

char visited[MAX][MAX];
int count[10];

int M_x[] = { -1, 0, +1, 0 };
int M_y[] = { 0, 1, 0, -1 };

//for storing 0 locations
int Qx[10000], Qy[10000], front, rear;
void enqueue(int x, int y) { ++rear, Qx[rear] = x; Qy[rear] = y; }
void dequeue(int*x, int*y) { ++front, *x = Qx[front]; *y = Qy[front]; }
int queue_empty() { return front == rear; }

//for BFS processing of 0s
int Qzx[10000], Qzy[10000], frontz, rearz;
void enqueue_zero(int x, int y) { ++rearz, Qzx[rearz] = x; Qzy[rearz] = y; }
void dequeue_zero(int*x, int*y) { ++frontz, *x = Qzx[frontz]; *y = Qzy[frontz]; }
int zero_queue_empty() { return frontz == rearz; }

//for BFS processing of Non Zero clusters
int Qnzx[10000], Qnzy[10000], frontNZ, rearNZ;
void enqueue_non_zero(int x, int y) { ++rearNZ, Qnzx[rearNZ] = x; Qnzy[rearNZ] = y; }
void dequeue_non_zero(int*x, int*y) { ++frontNZ, *x = Qnzx[frontNZ]; *y = Qnzy[frontNZ]; }
int non_zero_queue_empty() { return frontNZ == rearNZ; }

main_bfs.cpp

#include <stdio.h>
int is_safe(int x, int y)
{
	if (x < N && x >= 0 && y >= 0 && y < N && !visited[x][y])
		return 1;

	return 0;
}
int Answer;
void reset_visited()
{
	int i, j;
	for (i = 0; i < N; i++)
	for (j = 0; j < N; j++)
		visited[i][j] = 0;

}
int find_max()
{
	int max = 0;
	int idx = -1;
	int i, j;

	for (i = 0; i < 10; i++)
	{
		if (count[i] >= max)
		{
			max = count[i];
			idx = i;
		}
	}

	return idx;

}

void BFS_Non_Zero(int x, int y, char map[][MAX])
{
	int i, j;
	int X, Y;
	int NextX, NextY;

	
	
	enqueue_non_zero(x, y);
	

	while (!non_zero_queue_empty())
	{
		dequeue_non_zero(&X, &Y);
		count[map[X][Y]]++;
		visited[X][Y] = 1;

		for (i = 0; i < 4; i++)
		{
			NextX = X + M_x[i];
			NextY = Y + M_y[i];
			if (is_safe(NextX, NextY))
			{
				if (map[X][Y] == map[NextX][NextY])
				{
					enqueue_non_zero(NextX, NextY);
				}
			}

		}
	}
}
void BFS_Zero(int x, int y)
{
	int i, j;
	int NextX, NextY;
	int X, Y;

	
	enqueue(x, y);
	enqueue_zero(x, y);

	while (!zero_queue_empty())
	{
		dequeue_zero(&X, &Y);
		visited[X][Y] = 1;

		for (i = 0; i < 4; i++)
		{
			NextX = X + M_x[i];
			NextY = Y + M_y[i];

			if (is_safe(NextX, NextY))
			{
				if (map[NextX][NextY] != 0)
				{
					BFS_Non_Zero(NextX, NextY, map);
				}
				else
				{
					enqueue_zero(NextX, NextY);
					enqueue(NextX, NextY);
				}
			}

		}
	}

}
int solve_util()
{
	int i, j, k;
	int x, y;
	int result;
	char max;
	for (i = 0; i < N; i++)
	{

		for (j = 0; j < N; j++)
		{
			reset_visited();
			front = rear = -1;
			frontz = rearz = -1;
			frontNZ = rearNZ = -1;

			if (res[i][j] == 0 && !visited[i][j])
			{
				BFS_Zero(i, j);
				max = find_max();

				while (!queue_empty())
				{
					dequeue(&x, &y);
					res[x][y] = max;
				}

				for (k = 0; k < 10; k++)
				{
					count[k] = 0;
				}
				
			}

		
		}
	}

	result = 0;
	reset_visited();
	for (i = 0; i < N; i++)
	{

		for (j = 0; j < N; j++)
		{
			if (!visited[i][j])
			{

				BFS_Non_Zero(i, j,res);
				result++;
			}
		}

	}

	return result;
}

int main(void)
{
	int T, test_case;
	int i, j;

	freopen("input.txt", "r", stdin);


	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &N);
	
		for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			res[i][j] = map[i][j];
		}
		


		Answer = solve_util();

		// Print the answer to standard output(screen).
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}

sample_input

3
5
5 5 1 4 4 
4 0 2 4 2
5 0 0 2 0 
5 4 3 0 1
1 3 3 2 1
10
1 3 5 1 4 0 0 4 2 1
1 1 2 1 1 0 5 0 2 1
5 0 2 0 4 4 4 0 1 1
0 2 2 4 0 5 4 2 1 3
1 1 2 2 2 3 3 2 1 1
5 1 1 2 0 3 3 2 2 1
3 1 1 1 0 0 1 2 2 5
3 1 4 1 2 0 4 0 0 5
4 0 3 3 1 3 3 0 0 1
5 0 3 1 4 3 3 1 2 3
20
0 2 1 0 1 3 3 3 3 4 4 1 1 1 4 1 1 4 1 4
0 2 3 5 1 2 3 3 3 3 4 2 1 3 2 2 1 1 1 3
0 2 1 5 1 2 2 2 0 3 2 3 4 2 1 3 3 0 1 1
1 5 4 5 1 2 5 5 5 5 2 5 5 2 0 0 3 3 5 4
1 0 5 5 3 5 3 0 4 5 5 5 1 0 1 1 3 4 0 0
4 5 3 4 4 5 3 3 0 0 3 3 1 3 1 3 2 5 0 0
3 2 0 0 0 3 4 1 1 1 1 3 5 2 1 3 1 4 0 5
2 2 0 2 3 3 3 0 1 5 1 3 5 2 5 3 4 4 0 5
3 4 0 1 1 1 0 4 4 4 4 1 5 0 4 5 3 4 4 4
3 2 0 1 4 4 3 0 0 0 3 5 1 0 1 4 1 3 4 4
0 3 1 1 1 1 1 1 2 2 3 3 1 0 5 4 4 4 4 4
4 2 5 3 4 4 4 1 2 5 5 5 4 1 1 1 4 1 0 5
4 2 5 1 4 2 5 2 0 1 5 2 4 1 4 1 1 0 0 0
1 2 3 0 1 4 2 2 4 1 1 0 4 4 4 5 4 1 0 0
3 2 0 1 1 1 2 1 3 1 0 4 1 4 4 2 4 3 3 0
3 3 5 4 1 1 1 1 3 2 4 4 4 4 4 3 3 3 3 4
4 3 1 1 1 1 1 1 1 3 2 2 0 5 4 4 4 5 0 0
3 3 2 0 5 0 3 3 1 3 2 4 0 4 0 4 4 2 4 4
1 4 4 3 4 5 2 4 4 4 4 4 0 5 0 4 0 3 1 0
5 4 4 5 2 3 3 0 0 5 2 4 3 3 2 3 4 4 5 0

Sample Output:

#1: 11
#2: 31
#3: 130