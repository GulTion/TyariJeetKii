---
explored: true
---

Four 5G base station towers needs to be installed in a  Landscape which is divided as hexagon cells as shown in Fig below, which also contains number of people living in each cell. Need to find four cells  to install the 5G towers which can cover maximum number of people  combining all four cells, with below conditions
Only one tower can be placed in a cell
Each of the four chosen cell should be neighbor to atleast one of the remaining 3 cells. 
All four cells should be connected  (like  one island)

## For Example

### Input 

![[Pasted image 20250301010840.png]]

### Output
Square of  Maximum number of people covered by 4 towers (Fig 2)

![[Pasted image 20250301010900.png]]

## Approach

There can be a variety of approaches to get solution to this question. But for all kinds of approach, one thing is common, that we need to
find a path of size 4 for every point in the space. 

1. I start from the first point, marking it as visited.
2. Generate all possible neighbours for the point. Note that this is not a normal graph. It is a hexagonally
designed graph, hence the neighbour generation differs. 
    
    [ Hint : neighbour generation differs, depending on whether the column number is odd or even]

3. Selecting the best neighbour (the neighbour with the highest value)
4. Adding the best neighbour to the branch, marking it visited and reducing the depth of probing (tells me that I have already visited 2 points
hence I have to stop after 2 more points).

    Since the final solution can be a tree as well, hence pure DFS or BFS cannot be applied. Hence, once a neighbour is selected we again have
    to quest for a new neighbour if probing length isn't zero such that the best neighbour can come from the neighbours of any visited point in the
    previously generated path.

5. Now searching for a new neighbour, considering every point in the already generated path again. 
6. Repeating 1-5 for every single point in the space, and hence finally landing to the best solution.

**Input**
Input.txt - 
6
3 4
150 450 100 320
120 130 160 110
10 60 200 220
1 4
10 20 30 40
3 5
300 410 150 55 370 
120 185 440 190 450 
165 70 95 420 50 
5 5
356 55 41 453 12 
401 506 274 506 379 
360 281 421 311 489 
425 74 276 371 164 
138 528 461 477 470 
3 13
197 51 443 274 47 552 160 96 501 102 469 318 308 
516 128 506 471 381 418 328 517 380 78 569 58 90 
113 238 179 444 541 27 444 62 264 93 245 353 37 
11 7
292 182 586 607 259 190 239 
511 716 425 367 511 462 714 
593 713 231 60 118 442 82 
626 577 579 682 136 176 681 
240 23 410 193 230 729 109 
453 231 287 383 444 578 409 
729 401 408 330 213 574 54 
684 224 75 62 660 472 227 
606 37 473 487 222 185 476 
84 477 158 94 141 484 122 
616 333 302 626 29 99 674

**Output**
1276900
10000
225000
3748096
3928324
7236100
## Approuch 1
```cpp
#include <iostream>
#include <cstring>
using namespace std;
#define DEPTH 4

int dir_ref[6][2] = {
    { 1, 0},
    { 0, 1},
    { 0,-1},
    {-1, 0},
};

int even_ref[2][2] = {
    { 1, -1},
    { 1,  1}
};

int odd_ref[2][2] = {
    {-1, -1},
    {-1,  1}
};

int find_best_neighbour(int** space, int** visited,int& best_x, int& best_y, int x, int y, int row, int col, bool isodd){
    // selects best neighbour for a given point
    int temp = -1;
    for(int i=0; i<4; i++){
        int neighbour_x, neighbour_y;
        neighbour_x = x + dir_ref[i][0];
        neighbour_y = y + dir_ref[i][1];

        if( (0<= neighbour_x && neighbour_x < row) &&
            (0<= neighbour_y && neighbour_y < col) &&
            (space[neighbour_x][neighbour_y] != 0) &&
            (visited[neighbour_x][neighbour_y] == 0)){
            
            if (space[neighbour_x][neighbour_y] > temp){

                temp = space[neighbour_x][neighbour_y];
                best_x = neighbour_x;
                best_y = neighbour_y;
            }
        }
    }

    if(! isodd){

        for(int i=0;i<2;i++){
            int neighbour_x, neighbour_y;
            neighbour_x = x + even_ref[i][0];
            neighbour_y = y + even_ref[i][1];

            if( (0<= neighbour_x && neighbour_x < row) &&
                (0<= neighbour_y && neighbour_y < col) &&
                (space[neighbour_x][neighbour_y] != 0) &&
                (visited[neighbour_x][neighbour_y] == 0)){
                
                if (space[neighbour_x][neighbour_y] > temp){

                    temp = space[neighbour_x][neighbour_y];
                    best_x = neighbour_x;
                    best_y = neighbour_y;
                }
            }
        }
    }

    else if(isodd){
        for(int i=0;i<2;i++){
            int neighbour_x, neighbour_y;
            neighbour_x = x + odd_ref[i][0];
            neighbour_y = y + odd_ref[i][1];

            if( (0<= neighbour_x && neighbour_x < row) &&
                (0<= neighbour_y && neighbour_y < col) &&
                (space[neighbour_x][neighbour_y] != 0) &&
                (visited[neighbour_x][neighbour_y] == 0)){
                
                if (space[neighbour_x][neighbour_y] > temp){

                    temp = space[neighbour_x][neighbour_y];
                    best_x = neighbour_x;
                    best_y = neighbour_y;
                }
            }
        }
    }

    return temp;
}

int branching(int** space, int** visited, int row, int col, int d, int score){
    // selects the best neighbour for an already half visited path
    if (d == 0){
        return score;
    }

    int x, y;
    int temp = -1;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){

            if(visited[i][j] == 1){
                // finding the best neighbour for i,j
                int t_x, t_y; 
                int t = find_best_neighbour(space, visited, t_x, t_y, i, j, row, col, j%2);

                if ( t > temp){
                    // if best neighbour of i,j is better
                    // than best neighbour of previous i,j 
                    // then changing the final neighbour selection
                    temp = t; 
                    x = t_x;
                    y = t_y;
                }

            }
        }
    }

    visited[x][y] =1;
    score += space[x][y];

    return branching(space, visited, row, col, d-1, score);
}

int finding_optimum(int ** space, int row, int col){ 
    // finds optimum path of size DEPTH
    int optimum = 0;
    int** visited = new int*[row];
    for(int i=0; i<row; i++){
        visited[i] = new int[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            
            if(space[i][j] != 0){
                
                for(int k=0; k<row; k++){
                    memset(visited[k], 0, col * sizeof(*visited[0])); 
                    // Starting with a new visited array for every point
                }

                visited[i][j] = 1;
                int score;
                int value = branching(space, visited, row, col, DEPTH-1, score=space[i][j]); 
                // Finds the best score when starting with the point i,j
                // Such that if we know the best score for every single i,j we know the best
                // score for the entire space.
                optimum = max(optimum, value);
            
            }

            else continue;
        }
    }

    return (optimum * optimum);
}

int main(){
    int t; cin>>t;
    while(t--){
        int row, col;
        cin>>row>>col;

        int** space = new int*[++row];
        for(int i=0;i<row;i++){
            space[i]  = new int[col];
            memset(space[i], 0, col * sizeof(*space[0]));
        }

        for(int i=0;i<row-1;i++){
            for(int j=0;j<col;j++){

                if(j%2 == 0) cin>> space[i][j];

                else cin>> space[i+1][j];
            }
        }

        cout<<finding_optimum(space, row, col)<<endl;
        
    }
}

```

## Approuch 2
```cpp
#include <iostream>

using namespace std;

int cell[16][16] = {0};
int visited[16][16] = {0};
int odd[2][6] = {{0,0,-1,1,1,1}, {-1,1,0,-1,0,1}};
int even[2][6] = {{0,0,-1,-1,-1,1}, {-1,1,-1,0,1,0}};
int maxVal = 0, n, m;
int isValid(int i, int j){
    if(i<0 || j<0 || i>=n || j>=m) return 0;
    else return 1;
}

void findScore(int x, int y, int count, int currVal){
    if(count == 4){
        if (currVal > maxVal)
            maxVal = currVal;
        return;
    }
    
    int nx, ny;
    for(int i = 0; i < 6; i++){
        if(y%2 == 0){
            nx = x + even[0][i];
            ny = y + even[1][i];
        }
        else{
            nx = x + odd[0][i];
            ny = y + odd[1][i];
        }
        
        if((isValid(nx, ny) == 1) && (visited[nx][ny] == 0)){
            visited[nx][ny] = 1;
            findScore(x, y, count+1, currVal + cell[nx][ny]);
            findScore(nx, ny, count+1, currVal + cell[nx][ny]);
            visited[nx][ny] = 0;
        }
    }
    
}

int main(void)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++){
		int i, j;
		cin >> n;
        cin >> m;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				cin >> cell[i][j];
			}
		}
		for (i = 0; i < 16; i++){
			for (j = 0; j < 16; j++){
				visited[i][j] = 0;
			}
		}
		maxVal = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				visited[i][j] = 1;
				findScore(i, j, 1, cell[i][j]);
				visited[i][j] = 0;
			}
		}
		printf("%d\n", maxVal*maxVal);
	}

	return 0;
}
```
## approuch 3
```cpp
#include<iostream>
using namespace std;
 
int n,m;
int a[100][100];
int vis[100][100];
 
int dx[] = {-2,-1,1,2,1,-1};
int dy[] = {0,1,1,0,-1,-1};
 
bool valid(int r, int c){
  return (r<2*n && r>=0 && c<m && c>=0);
}
 
int sidha(int i, int j){
  if(valid(i-1,j-1) && valid(i-1,j+1) && valid(i+2,j)){
     return (a[i][j] + a[i-1][j-1] + a[i-1][j+1] + a[i+2][j]);
  }
  else return -1;
}
 
int ulta(int i, int j){
   if(valid(i+1,j-1) && valid(i+1,j+1) && valid(i-2,j)){
     return a[i][j] + a[i+1][j-1] + a[i+1][j+1] + a[i-2][j];
  }
  else return -1;
}
 
int dfs(int r, int c, int power){
 
  if(power == 0)return 0;
 
  vis[r][c] = 1;
 
  int ans = 0;
  for(int i = 0; i<6; i++){
 
    int x = r + dx[i];
    int y = c + dy[i];
 
    if(vis[x][y] == 0 && valid(x,y)){
 
      vis[x][y] = 1;
      int temp = dfs(x,y,power -1);  
      vis[x][y] = 0;
 
       ans = max(temp,ans);
 
    }
  }
 
  vis[r][c] = 0;
 
  ans += a[r][c];
  return ans;
}
 
int main(){
   
   cin>>n>>m;
    for(int i = 0; i<2*n;i+=2){
        for(int j =0; j<m; j++){
            if(!(j%2))
            cin>>a[i][j];
            else
            cin>>a[i+1][j];
        }        
    }
 
   int ans = -1;
   for(int i = 0; i<2*n; i++){
     for(int j =0; j<m; j++){
       if(a[i][j] ){
         
         int temp = dfs(i,j,4);
         int temp2 = ulta(i,j);
         int temp3 = sidha(i,j);
         int temp1 = max(temp2, temp3);
         ans = max(max(temp,temp1),ans);
       }
     }
   }
   
    cout<<ans<<endl;
   
  return 0;
}
```
##