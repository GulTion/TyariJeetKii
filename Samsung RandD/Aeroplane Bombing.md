---
title: HackerRank
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/aeroplane-bombing/problem
author:
  - "[[Aeroplane Bombing]]"
published: 
created: 2024-12-18
description: Join over 11 million developers in solving code challenges on HackerRank, one of the best ways to prepare for programming interviews.
tags:
  - clippings
status: Pending
explored: true
---
You’ll be given a grid as below:

```
                       0 1 0 2 0
                       0 2 2 2 1
                       0 2 1 1 1
                       1 0 1 0 0
                       0 0 1 2 2
                       1 1 0 0 1
                       x x S x x            
```

In the grid above, 1: This cell has a coin. 2: This cell has an enemy. 0: It contains nothing. The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins. Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move. At each time, the non-highlighted part of the grid will move down by one unit. We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed. If we use a bomb at the very beginning, the grid will look like this:

```
                       0 1 0 2 0
                       0 0 0 0 1
                       0 0 1 1 1
                       1 0 1 0 0
                       0 0 1 0 0
                       1 1 0 0 1
                       x x S x x            
```

As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends. For example, At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin( coins=2). After this, remain at the same position( coins=4). This is the current situation after collecting 4 coins.

0 1 0 2 0 0 1 0 0 0 0 2 2 2 1 -->after using 0 0 0 0 1 x x S x x -->bomb x x S x x Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.

**Input Format**

First line conatins t, number of test cases Next line contains N for each test Next N lines conatin input ( 5 integers )

**Constraints**

$1 < t < 10$
$1 < N < 10$

**Output Format**

For each test output single integer with format #test_number output

**Sample Input 0**
```
5
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0
0 0 0 0 0
1 0 0 0 2
0 0 0 0 0
0 2 0 2 1
0 2 2 2 0
12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1
```


**Sample Output 0**
```
#1 6
#2 3
#3 0
#4 1
#5 9
```


# Approch
## Approach 1

The brute force approach would be considering 3 options (move left, move right and current) for all the rows without considering detonate. If we have N rows, the time complexity would be 3^N.
By considering detonate, we can detonate bomb at any step. This means the time complexity would be N*3^N.
Here, the maximum value would of N is 12.
However, if we consider the top down approach, i.e. collecting the coins as the rows move down, we can prune away the tree paths as the score becomes zero.

SAMPLE CODE (Image 2) 
```cpp
#include <iostream> 
using namespace std; 
int a[13][5], b[5][5];
void detonate(int row){ 
	for (int i = row; i > row - 5; i--){ 
		for (int j = 0; j < 5; j++){ 
			b[row - i][j] = 0; 
			if (i >= 0 && a[i][j] == 2) { 
				b[row - i][j] = 2; 
				a[i][j] = 0; 
			} 
		} 
	} 
} 

void unDetonate(int row){ 
	for (int i = row; i > row - 5; i--){ 
		for (int j = 0; j < 5; j++) { 
			if (i >= 0 && b[row - i][j] == 2) { 
			a[i][j] = 2; 
			} 
		}	 
	} 
}

void getMaxCoins(int pos, int coins, int n, int &maxCoins){
	if (pos < 0 || pos > 4 || coins < 0) 
		return;
	if (a[n - 1][pos] == 2) 
		coins -= 1; 
	else if (a[n - 1][pos] == 1) 
		coins += 1;
	if (n == 1){ 
		if (coins > maxCoins) 
		maxCoins = coins; 
	return; 
	} 
	else{ 
	// 3 options 
	// move right 
	getMaxCoins(pos + 1, coins, n - 1, maxCoins); 
	// move left 
	getMaxCoins(pos - 1, coins, n - 1, maxCoins); 
	// not move 
	getMaxCoins(pos, coins, n - 1, maxCoins); 
	} 
}


int main(){ 
	int t, n, i, j, k, coins, maxCoins; 
	cin >> t; 
	for (i = 0; i < t; i++){ 
		cin >> n; 
		maxCoins = -1; 
		for (j = 0; j < n; j++){ 
			for (k = 0; k < 5; k++){ 
			cin >> a[j][k]; 
			} 
		} 
		for (j = 0; j < 5; j++) 
			a[n][j] = 0; 
		a[n][2] = 3; 
		for (j = n - 1; j > 0 ; j--) {
			coins = -1; 
			//detonate 
			detonate(j); 
			getMaxCoins(2, 0, n, coins); 
			if (coins > maxCoins) 
				maxCoins = coins; 
			unDetonate(j); 
			// undetonate
		} 
		cout << ((maxCoins < 0) ? -1 : maxCoins) << endl; 
	} 
}


// MY CODE


#include <iostream>

using namespace std;

int arr[13][5] = {0};
int maxCoinVal = -1;
//int mem[5][5] = {0};

void detonate(int row){
    for(int r = row; r > row-5; r--){
        if(r>=0){
            for(int j = 0; j < 5; j++){
                if(arr[r][j] == 2)
                    arr[r][j] = -1;
            }
        }
    }    
}

void undetonate(int row){
    for(int r = row; r > row-5; r--){
        if(r>=0){
            for(int j = 0; j < 5; j++){
                if(arr[r][j] == -1)
                    arr[r][j] = 2;
            }
        }
    }    
}

void maxCoins(int row, int col, int coins){
    if(col > 4 || col < 0 || coins < 0) return;
    if(arr[row-1][col] == 1) coins++;
    else if(arr[row-1][col] == 2) coins--;
    if(row == 0){
        if(maxCoinVal < coins){
            maxCoinVal = coins;
        }
        return;
    }
    else{
        maxCoins(row-1, col-1, coins);
        maxCoins(row-1, col+1, coins);
        maxCoins(row-1, col, coins);
    }
    
}

int main()
{
   int test_cases;
   cin >> test_cases;
   for(int t = 0; t < test_cases; t++){
       maxCoinVal = -1;
       cout << "testcase:" << t << endl;
       for(int i = 0; i < 13; i ++){
           for(int j = 0; j < 5; j++){
               arr[i][j] = 0;
           }
       }
       int rows;
       cin >> rows;
       for(int r = 0; r < rows; r++){
           for(int c = 0; c < 5; c++){
                cin >> arr[r][c];
           }
       }
       for(int i = rows-1; i > 0; i--){
           detonate(rows-1);
           maxCoins(rows, 2, 0);
		   maxCoins(rows, 1, 0);
		   maxCoins(rows, 3, 0);
           undetonate(rows-1);
       }
       cout << ((maxCoinVal < 0) ? -1 : maxCoinVal) << endl;
   }
   return 0;
}
```


## Approach 2
```cpp
/*
You’ll be given a grid as below:

                       0 1 0 2 0 --> Non highlighted part
                       0 2 2 2 1
                       0 2 1 1 1
                       1 0 1 0 0
                       0 0 1 2 2
                       1 1 0 0 1
                       x x S x x  -->highlighted yellow
 In the grid above,     
1: This cell has a coin.
2: This cell has an enemy.
0: It contains nothing.
The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move. At each time, the non-highlighted part of the grid will move down by one unit.
We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
If we use a bomb at the very beginning, the grid will look like this:

0 1 0 2 0  --> Non highlighted part
0 0 0 0 1
0 0 1 1 1
1 0 1 0 0
0 0 1 0 0
1 1 0 0 1
x x S x x  --> highlighted yellow
 As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.     
For example,    
At the very first instance, if we want to collect a coin we should move left **( coins=1)**. This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin **( coins=2)** .
After this, remain at the same position **( coins=4)**.
This is the current situation after collecting 4 coins.
0 1 0 2 0                0 1 0 0 0
0 2 2 2 1 -->after using 0 0 0 0 1
x x S x x -->bomb        x x S x x
Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/


#include <iostream>
using namespace std;

int a[100][100];
int n;

bool valid(int r, int c){
  if(r<n && r>=0 && c<5 && c>=0)return true;
  return false;
}

int solve(int r, int c, int power, int effect){

  // base case
  if(r<0)return 0;

  // recursive case
  int ans = 0;
  int p = 0;
  for(int i = -1; i <=1; i++){

    int y = c+i;
    int x = r-1;
    
    if(valid(x,y)){
      // enemy 
      if(a[x][y] == 2){
         if(power == 0 && effect >  0){
            p = solve(x,y,power,effect -1);
         }
         if(power == 1){
           p = solve(x,y,power-1,5);
         }
      }
      // not enemy
      if(a[x][y] == 1 ||a[x][y] == 0){
        if(power == 0)
        p = solve(x,y,power,effect-1);
        else 
        p = solve(x,y,power,5);
      }
    }
    ans = max(ans , p);
  }
   if(a[r][c] == 1)ans++;
   return ans;
}

int main() {
    
    cin>>n;
    for(int i = 0; i<100; i++)for(int j =0; j<100; j++)a[i][j] = 0;
    for(int i =0; i<n; i++){
      for(int j = 0; j<5; j++){
        cin>>a[i][j];
      }
    }
    
    cout<<solve(n,2,1,0)<<endl;
    return 0;
}
```

## Approach 3
```cpp
/*

You’ll be given a grid as below:


    0 1 0 2 0

    0 2 2 2 1

    0 2 1 1 1

    1 0 1 0 0

    0 0 1 2 2

    1 1 0 0 1

    x x S x x


   In the grid above,

  1: This cell has a coin.

  2: This cell has an enemy.

  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
  If we use a bomb at the very beginning, the grid will look like this:


    0 1 0 2 0

    0 0 0 0 1

    0 0 1 1 1

    1 0 1 0 0

    0 0 1 0 0

    1 1 0 0 1

    x x S x x


  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin( coins=2).
  After this, remain at the same position( coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0

    0 2 2 2 1 -->after using 0 0 0 0 1

    x x S x x -->bomb x x S x x


   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.

*/





#include <iostream>

using namespace std;
#define lim 100

int grid[lim][5];
int num_rows;
int maxCoins=0;
bool bombUsed=false;

void go_to(int i, int j, int coins){
    if(j<0 || j>=5){
        //Went out of board
        return;
    }
    if(i==num_rows){
        //Reached the end of grid
        if(coins>maxCoins)
            maxCoins=coins;
        return;
    }
    int flag=0, ctr=0;
    int enemy_coord[25][2];
    if(grid[i][j]==2){
        if(bombUsed==true){
            //Game over here
            if(coins>maxCoins)
                maxCoins=coins;
            return;
        }else{
            //Use the bomb now
            bombUsed=true;
            flag=1;
            for(int x=i; x<min(i+5,num_rows); x++){
                for(int y=0; y<5; y++){
                    if(grid[x][y]==2){
                        enemy_coord[ctr][0]=x;
                        enemy_coord[ctr++][1]=y;
                        grid[x][y]=0;
                    }
                }
            }
        }
    }else if(grid[i][j]==1)
        coins=coins+1;

    go_to(i+1, j+1, coins);
    go_to(i+1, j, coins);
    go_to(i+1, j-1, coins);

    if(flag==1){
        for(int k=0; k<ctr; k++){
            int x=enemy_coord[k][0];
            int y=enemy_coord[k][1];
            grid[x][y]=2;
        }
    }
    return;
}


int main(){
    cin>>num_rows;
    for(int i=0; i<num_rows; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        grid[num_rows-1-i][0]=a;
        grid[num_rows-1-i][1]=b;
        grid[num_rows-1-i][2]=c;
        grid[num_rows-1-i][3]=d;
        grid[num_rows-1-i][4]=e;
    }
    maxCoins=0;
    go_to(0,1,0);
    go_to(0,2,0);
    go_to(0,3,0);
    cout<<"Max_Coins : "<<maxCoins<<endl;
    return 1;
}
```

## Approach 4
```cpp
/*
https://www.careercup.com/question?id=5652067409461248
https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/

http://ideone.com/JXMl4L
https://ide.geeksforgeeks.org/tiyLThcuSN -> Zero
https://ide.geeksforgeeks.org/3Ks1tpOkwn

*https://code.hackerearth.com/ea07cfD?key=1cb190b158c79639d66d35f7dfa8ef7a -> One

Similr Problem - https://ide.codingblocks.com/s/95965


You’ll be given a grid as below:

    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x

In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:

    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x

  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin.
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x

   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> grid, int n, int temp, bool bomb, int &ans)
{
  ans = max(ans, temp);
  int delrow[] = {-1, -1, -1};
  int delcol[] = {-1, 0, 1};
  for (int i = 0; i < 3; i++)
  {
    int nrow = row + delrow[i];
    int ncol = col + delcol[i];

    if (nrow >= 0 && ncol >= 0 && ncol < 5)
    {
      if (grid[nrow][ncol] == 1)
        dfs(nrow, ncol, grid, n, temp + 1, bomb, ans);
      else if (grid[nrow][ncol] == 0)
        dfs(nrow, ncol, grid, n, temp, bomb, ans);
      else if (grid[nrow][ncol] == 2)
      {
        if (bomb == false)
        {
          vector<vector<int>> tempgrid = grid;
          for (int l = nrow; l > nrow - 5 && l >= 0; l--)
          {
            for (int m = 0; m < 5; m++)
            {
              if (grid[l][m] == 2)
                grid[l][m] = 0;
            }
          }
          dfs(nrow, ncol, grid, n, temp, true, ans);
          grid = tempgrid;
        }
      }
    }
  }
  ans = max(ans, temp);
}

int main()
{
  int t;
  cin >> t;
  for (int test_case = 1; test_case <= t; test_case++)
  {
    int ans = 0;
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 2, vector<int>(5));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < 5; j++)
        cin >> grid[i][j];
    }
    for (int j = 0; j < 5; j++)
      grid[n][j] = 0;

    // (-1,-1), (-1,0), (-1,1)
    // pair<int,int> src = {n,n/2+1};

    dfs(n, 2, grid, n, 0, false, ans);
    cout << "#" << test_case << " " << ans << endl;
  }
  return 0;
}


```

##  Approach 5
```cpp
/*
https://www.careercup.com/question?id=5652067409461248
https://www.geeksforgeeks.org/samsung-interview-experience-set-28-campus/

http://ideone.com/JXMl4L
https://ide.geeksforgeeks.org/tiyLThcuSN -> Zero
https://ide.geeksforgeeks.org/3Ks1tpOkwn

*https://code.hackerearth.com/ea07cfD?key=1cb190b158c79639d66d35f7dfa8ef7a -> One

Similr Problem - https://ide.codingblocks.com/s/95965


You’ll be given a grid as below:

    0 1 0 2 0
    0 2 2 2 1
    0 2 1 1 1
    1 0 1 0 0
    0 0 1 2 2
    1 1 0 0 1
    x x S x x

In the grid above,
  1: This cell has a coin.
  2: This cell has an enemy.
  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get 
  maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone 
  will be killed.
  If we use a bomb at the very beginning, the grid will look like this:

    0 1 0 2 0
    0 0 0 0 1
    0 0 1 1 1
    1 0 1 0 0
    0 0 1 0 0
    1 1 0 0 1
    x x S x x

  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the 
  grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. 
  Next, we should move right to collect another coin (coins=2).
  After this, remain at the same position (coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0
    0 2 2 2 1 -->after using 0 0 0 0 1
    x x S x x -->bomb x x S x x

   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/
#include<bits/stdc++.h>
using namespace std;
void updateMatrix(int row,char ** matrix){
    if(row<0){
        return;
    }
    int upLimit=max(0,row-4);
    for(int i=row;i>=upLimit;i--){
        for(int j=0;j<=4;j++){
            if(matrix[i][j]=='2'){
                matrix[i][j]='0';
            }
        }
    }
}
int findMaxPoints(int row,int col,int bombs,char ** matrix){
    if(row<=0 || col<0 || col>=5){
        return 0;
    }
    int answer=0;
    if(row>0 && matrix[row-1][col]!='2'){
        answer=max(answer,(matrix[row-1][col]=='1'?1:0)+findMaxPoints(row-1,col,bombs,matrix));
    }
    if(col>0 && row>0 && matrix[row-1][col-1]!='2'){
        answer=max(answer,(matrix[row-1][col-1]=='1'?1:0)+findMaxPoints(row-1,col-1,bombs,matrix));
    }
    if(col<4 && row>0 && matrix[row-1][col+1]!='2'){
        answer=max(answer,(matrix[row-1][col+1]=='1'?1:0)+findMaxPoints(row-1,col+1,bombs,matrix));
    }

    if(answer==0 && bombs>0){
        updateMatrix(row-1,matrix);
        answer=findMaxPoints(row,col,bombs-1,matrix);
    }

    return answer;
}
int main(){
    int t, row;
    cin >> t;
    int tNo = 0;
    while(t--){
        cin >> row;
        char ** matrix=new char*[row + 2];
        for(int i=0; i<row; i++){
            matrix[i]=new char[5];
            for(int j=0;j<5;j++){
                cin>>matrix[i][j];
            }
        }
        tNo++;
        cout<< "#" << tNo << " : " << findMaxPoints(row,2,1,matrix) << endl;        
    }
    return 0;
}

/* 
No rech top 

#include <iostream>
using namespace std;
int det[5][5];
int mat[13][5];

void detonate(int r)
{
    for(int i=r;i>r-5 && i>=0;i--)
    {
        for(int j=0;j<5;j++)
        {
            det[r-i][j]=0;
            if(mat[i][j]==2)
            {
                det[r-i][j]=2;
                mat[i][j]=0;
            }
        }
    }
}

void undet(int r)
{
    for(int i=r;i>r-5 && i>=0;i--)
        for(int j=0;j<5;j++)
        {
            if( det[r-i][j]==2)
                mat[i][j]=2;
        }
}
void func(int n,int pos,int c,int &max)
{
    if(pos>4||pos<0||c<0)
        return;

    if(mat[n][pos]==2)
        c-=1;
    else if(mat[n][pos]==1)
        c+=1;

    if(n==0)
    {
        if(c>max)
            max=c;
        return;
    }
    else
    {
        func(n-1,pos+1,c,max);
        func(n-1,pos-1,c,max);
        func(n-1,pos,c,max);
    }
}
int main()
{
    int t;
    cin>>t;
    int count=1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>mat[i][j];
        int max=-1,c;
        for(int j=0;j<5;j++)
            mat[n][j]=0;
        mat[n][2]=3;
        for(int j=n;j>=5;j--)
        {
            c=-1;
            detonate(j-1);
            func(n,2,0,c);
            if(c>max)
                max=c;
            undet(j-1);
        }
        if(max<0)
            max=-1;
        cout<<"#"<<count<<" "<<max<<endl;
        count++;
    }
}
*/


#include <iostream>
using namespace std;
int det[5][5];
int mat[13][5];

void detonate(int r){
    for(int i=r;i>r-5 && i>=0;i--){
        for(int j=0;j<5;j++){
            det[r-i][j]=0;
            if(mat[i][j]==2){
                det[r-i][j]=2;
                mat[i][j]=0;
            }
        }
    }
}

void undet(int r){
    for(int i=r;i>r-5 && i>=0;i--)
        for(int j=0;j<5;j++){
            if( det[r-i][j]==2)
                mat[i][j]=2;
        }
}

void func(int n,int pos,int c,int &max){
    if(pos>4||pos<0||c<0)
        return;

    if(mat[n][pos]==2)
        c-=1;
    else if(mat[n][pos]==1)
        c+=1;

    if(n==0){
        if(c>max)
            max=c;
        return;
    }
    else{
        func(n-1,pos+1,c,max);
        func(n-1,pos-1,c,max);
        func(n-1,pos,c,max);
    }
}

int main(){
    int t;
    cin>>t;
    int count=1;
    while(t--){
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
            for(int j=0;j<5;j++)
                cin>>mat[i][j];
        for(int j=0;j<5;j++)
            mat[n][j]=0;
        mat[n][2]=3;

        int max=-1,c;
        for(int j=n;j>=5;j--){
            c=-1;
            detonate(j-1);
            func(n,2,0,c);

            if(c>max)
                max=c;
            
            undet(j-1);
        }

        if(max<0)
            max=-1;
        
        cout<<"#"<<count<<" "<<max<<endl;
        count++;
    }
}

```

## Approach 6
```cpp
/*
You’ll be given a grid as below:

                       0 1 0 2 0 --> Non highlighted part
                       0 2 2 2 1
                       0 2 1 1 1
                       1 0 1 0 0
                       0 0 1 2 2
                       1 1 0 0 1
                       x x S x x  -->highlighted yellow
 In the grid above,     
1: This cell has a coin.
2: This cell has an enemy.
0: It contains nothing.
The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move. At each time, the non-highlighted part of the grid will move down by one unit.
We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
If we use a bomb at the very beginning, the grid will look like this:

0 1 0 2 0  --> Non highlighted part
0 0 0 0 1
0 0 1 1 1
1 0 1 0 0
0 0 1 0 0
1 1 0 0 1
x x S x x  --> highlighted yellow
 As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.     
For example,    
At the very first instance, if we want to collect a coin we should move left **( coins=1)**. This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin **( coins=2)** .
After this, remain at the same position **( coins=4)**.
This is the current situation after collecting 4 coins.
0 1 0 2 0                0 1 0 0 0
0 2 2 2 1 -->after using 0 0 0 0 1
x x S x x -->bomb        x x S x x
Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.
*/


#include <iostream>
using namespace std;

int a[100][100];
int n;

bool valid(int r, int c){
  if(r<n && r>=0 && c<5 && c>=0)return true;
  return false;
}

int solve(int r, int c, int power, int effect){

  // base case
  if(r<0)return 0;

  // recursive case
  int ans = 0;
  int p = 0;
  for(int i = -1; i <=1; i++){

    int y = c+i;
    int x = r-1;
    
    if(valid(x,y)){
      // enemy 
      if(a[x][y] == 2){
         if(power == 0 && effect >  0){
            p = solve(x,y,power,effect -1);
         }
         if(power == 1){
           p = solve(x,y,power-1,5);
         }
      }
      // not enemy
      if(a[x][y] == 1 ||a[x][y] == 0){
        if(power == 0)
        p = solve(x,y,power,effect-1);
        else 
        p = solve(x,y,power,5);
      }
    }
    ans = max(ans , p);
  }
   if(a[r][c] == 1)ans++;
   return ans;
}

int main() {
    
    cin>>n;
    for(int i = 0; i<100; i++)for(int j =0; j<100; j++)a[i][j] = 0;
    for(int i =0; i<n; i++){
      for(int j = 0; j<5; j++){
        cin>>a[i][j];
      }
    }
    
    cout<<solve(n,2,1,0)<<endl;
    return 0;
}

```

## 
```cpp
#include <bits/stdc++.h>
using namespace std;
int cs = 1;
int dfs(int i, int j, bool canBomb, vector<vector<int>> v, int n)
{
    if (i < 0)
        return 0;
    if (v[i][j] == 2)
        return 0;
    int ans = 0;
    if (v[i][j] == 1)
        ans++;
    if (canBomb)
    {
        // we will use the bomb here
        vector<vector<int>> cpy = v;
        for (int p = max(i - 5, 0); p < i; p++)
        {
            for (int q = 0; q < 5; q++)
            {
                if (cpy[p][q] == 2)
                    cpy[p][q] = 0;
            }
        }
        int op1 = 0, op2 = 0, op3 = 0;
        if (j + 1 < 5) // move to the right
            op1 = dfs(i - 1, j + 1, false, cpy, n);
        if (j - 1 >= 0) // move to the left
            op2 = dfs(i - 1, j - 1, false, cpy, n);
        op3 = dfs(i - 1, j, 0, cpy, n); // stay in the current place
        int finalAns1 = max({op1, op2, op3}) + ans;

        // we will not use the bomb
        int op1n = 0, op2n = 0, op3n = 0;
        if (j + 1 < 5)
            op1n = dfs(i - 1, j + 1, true, v, n);
        if (j - 1 >= 0)
            op2n = dfs(i - 1, j - 1, true, v, n);
        op3n = dfs(i - 1, j, 1, v, n);
        int finalAns2 = max({op1n, op2n, op3n}) + ans;
        return max(finalAns1, finalAns2);
    }
    else
    {
        // we can not use the bomb
        int op1n = 0, op2n = 0, op3n = 0;
        if (j + 1 < 5)
            op1n = dfs(i - 1, j + 1, false, v, n);
        if (j - 1 >= 0)
            op2n = dfs(i - 1, j - 1, false, v, n);
        op3n = dfs(i - 1, j, 0, v, n);
        int finalAns2 = max({op1n, op2n, op3n}) + ans;
        return finalAns2;
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(5, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int j = 0; j < 5; j++)
    {
        v[n].push_back(0);
    }
    cout << "#" << cs++ << " " << dfs(n, 2, true, v, n) << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
```


##
```cpp
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

void dfs(int row, int col, int coins, int rowSafe, bool isBombed, int &maxCount, vector<vector<int>> &graph) {
	if (col < 0 || col >= 5 || row < 0) {
		maxCount = max(coins, maxCount);
		return;
	}

	//maxCount = max(coins, maxCount);
	if (graph[row][col] == 1) {
		int newCoins = coins + 1;
		if (isBombed) rowSafe--;
		dfs(row - 1, col, newCoins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col + 1, newCoins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col - 1, newCoins, rowSafe, isBombed, maxCount, graph);
	}
	else if (graph[row][col] == 0) {
		if (isBombed) rowSafe--;
		dfs(row - 1, col, coins, rowSafe, isBombed, maxCount, graph);
		dfs(row - 1, col + 1, coins, rowSafe, isBombed, maxCount, graph);
		
		dfs(row - 1, col - 1, coins, rowSafe, isBombed, maxCount, graph);
	}
	else if (graph[row][col] == 2) {
		if (!isBombed) {
			isBombed = true;
			rowSafe = 4;
			dfs(row - 1, col + 1, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col - 1, coins, rowSafe, isBombed, maxCount, graph);
		}
		else if (rowSafe > 0) {
			rowSafe--;
			dfs(row - 1, col + 1, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col, coins, rowSafe, isBombed, maxCount, graph);
			dfs(row - 1, col - 1, coins, rowSafe, isBombed, maxCount, graph);
		}
		else {
			maxCount = max(coins, maxCount);
			return;
		}
	}


}

int main()
{
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int RowCount;
		int maxCoins = -1;
		cin >> RowCount;
		vector<vector<int>> graph(RowCount + 1, vector<int>(5));
		for (int i = 0; i < RowCount; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> graph[i][j];
			}
		}
		dfs(RowCount - 1, 1, 0, 0, false, maxCoins, graph);
		dfs(RowCount - 1, 2, 0, 0, false, maxCoins, graph);
		dfs(RowCount - 1, 3, 0, 0, false, maxCoins, graph);

		cout << "#" << z << " " << maxCoins << endl;
	}
}
```

## 
```cpp
#include <iostream>
using namespace std;
int a[13][5],b[5][5];

void detonate(int row){
    for(int i=row;i>=row-5;i--){
        for(int j=0;j<5;j++){
            b[row-i][j]=0;
            if(i>=0 && a[i][j]==2){
                a[i][j]=0;
                b[row-i][j]=2;
            }
        }
    }
}

void undetonate(int row){
    for(int i=row;i>=row-5;i--){
        for(int j=0;j<5;j++){
            if(i>=0 && b[row-i][j]==2){
                a[i][j]=2;
            }
        }
    }
}

void getMax(int pos,int coins,int n,int& maxCoins){
   if(pos<0 || pos>4 || coins<0) return;
   if(a[n-1][pos]==1) coins++;
   if(a[n-1][pos]==2) coins--;
   if(n==1){
       if(coins>maxCoins) maxCoins=coins;
       return;
   }
   else{
       getMax(pos-1,coins,n-1,maxCoins);
       getMax(pos+1,coins,n-1,maxCoins);
       getMax(pos,coins,n-1,maxCoins);
   }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        int ans=-1;
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >> a[i][j];
            }
        }
        for(int i=0;i<5;i++) a[n][i]=0;
        a[n][2]=3;
        for(int i=n-1;i>=0;i--){
            int coins=-1;
            detonate(i);
            getMax(2,0,n,coins);
            if(coins>ans) ans=coins;
            undetonate(i);
            // getMax(2,0,n,coins);
            // if(coins>ans) ans=coins;
        }
        if(ans<0) cout << -1 << endl;
        else cout << ans << endl;
    }
}
```
##