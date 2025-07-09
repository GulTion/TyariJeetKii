---
explored: true
---



Samsung wants to explore some of the rare elements for its semiconductor manufacturing.
Scientists use one vehicle to explore the region in order to find the rare elements.
The vehicle can move only in explored region where roads have already been constructed.
The vehicle cannot move on unexplored region where roads are not there.
In the current situation, rare elements are present in explored region only.
Unexplored regions do not contain any rare elements.

Square region is provided for exploration.
Roads are represented by 1 and where roads are not present that area is represented by 0.
Rare elements will only be on the roads where regions have already been explored.
Vehicle can move in four directions – up, down, left and right.

The shortest path for vehicle to a rare element position is called Moving Path.
The longest of the paths to all rare elements from a region called Longest Distance.

Scientists need to construct one research center so that the research center will be at the position where
the longest path to the rare elements will be shortest.
This is called Shortest Longest Distance.

Image 9

In the above picture (Fig. 1), Red, Blue and Green area represents Rare Element area.
(2, 2) is represented as Red, (2, 8) is represented as Blue and (7, 8) is represented as Green. So there are three rare elements.

If research center is constructed at (4, 4) then distance to Red rare element will be 4,
distance to Blue rare element will be 6 and distance to Green rare element will be 7. So the Longest distance will be 7.

Image 10

Now using the same region (Fig. 2), if research center is constructed at (4, 5) then distance to Red rare element will be 5, distance to Blue rare element will be 5 and distance to Green rare element will be 6. So the Longest distance will be 6.
So when research center is constructed at (4, 5) then the longest distance will be shortest. And the value of the Shortest Longest Distance will be 6. This will be the output.
There can be multiple locations from where the shortest longest distance can be same. For example if research center is constructed at (5, 5) then still the Shortest Longest distance will be 6.
So write a program to find the Shortest Longest Distance.

Constraints:
The region provided will be square region i.e. NxN (where 5 <=  N <= 20).
There can be minimum of 2 rare elements and maximum of 4 rare elements, i.e. 2 <= C <= 4.
Roads are represented by 1 while no road area is represented by 0.
Vehicle can move only on roads in explored area.
The rare elements will only be present where road are there. Rare elements will not be present where roads are not present.
Vehicle can move in UP, DOWN, LEFT and RIGHT directions.
The starting index for rare element is considers as 1.


Input:
First line will be the number of test cases. Second line will indicate region area (N) and number of rare elements (C). Next C lines will contain the position of rare elements. After that N lines will provide the region details where to tell where roads are present and where roads are not present.

Output:
Output #testcase followed by space and then shortest longest distance.
*/

**Input**
```

5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
```

**Output**
```
#1 1
#2 2
#3 2
#4 12
#5 15
```

## Approach 1
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, c;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> c;
        vector<pair<int, int>> rare;
        for (int i = 0; i < c; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            rare.push_back({a, b});
        }
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        }
        vector<vector<int>> finalDist(n, vector<int>(n, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        for (auto gem : rare)
        {
            int r = gem.first;
            int c = gem.second;
            vector<vector<int>> dist(n, vector<int>(n, 0));
            vector<vector<int>> vis(n, vector<int>(n, 0));
            queue<pair<int, int>> q;
            q.push({r, c});
            dist[r][c] = 0;
            vis[r][c] = 1;

            while (!q.empty())
            {
                auto g = q.front();
                int row = g.first;
                int col = g.second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                    {
                        vis[nrow][ncol] = 1;
                        dist[nrow][ncol] = dist[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][j] > finalDist[i][j])
                        finalDist[i][j] = dist[i][j];
                }
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                auto it = find(rare.begin(), rare.end(), make_pair(i, j));
                if (finalDist[i][j] && (it != rare.end()))
                    ans = min(ans, finalDist[i][j]);
            }
        }
        cout << ans << endl;
    }
}
```

## Approach 2
```cpp
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct node {
	int x, y, cost;
};

void bfs(int startx, int starty, vector<vector<int>>&graph, vector<vector<int>>&visited, int &N, int E, int &maxCost) {
	queue<node> grids;
	node start;
	start.x = startx;
	start.y = starty;
	start.cost = 0;
	visited[startx][starty] = 1;
	grids.push(start);
	while (!grids.empty()) {
		node top = grids.front();
		grids.pop();
		if (E <= 0) break;
		if (graph[top.x][top.y] == 2) {
			maxCost = max(maxCost, top.cost);
			E--;
		}
		if (top.x - 1 >= 0 && !visited[top.x - 1][top.y] && (graph[top.x - 1][top.y] == 1 || graph[top.x - 1][top.y] == 2)) {
			visited[top.x - 1][top.y] = 1;
			node temp;
			temp.x = top.x - 1;
			temp.y = top.y;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}

		if (top.x + 1 <N && !visited[top.x + 1][top.y] && (graph[top.x + 1][top.y] == 1 || graph[top.x + 1][top.y] == 2)) {
			visited[top.x + 1][top.y] = 1;
			node temp;
			temp.x = top.x + 1;
			temp.y = top.y;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}

		if (top.y - 1 >= 0 && !visited[top.x][top.y-1] && (graph[top.x][top.y-1] == 1 || graph[top.x][top.y-1] == 2)) {
			visited[top.x][top.y-1] = 1;
			node temp;
			temp.x = top.x;
			temp.y = top.y-1;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}

		if (top.y + 1 <N && !visited[top.x][top.y + 1] && (graph[top.x][top.y + 1] == 1 || graph[top.x][top.y+1] == 2)) {
			visited[top.x][top.y + 1] = 1;
			node temp;
			temp.x = top.x;
			temp.y = top.y + 1;
			temp.cost = top.cost + 1;
			grids.push(temp);
		}
	}
}

int main(){
	int T;
	cin >> T;
	while (T--) {
		int minCost = 9999999;
		int N, E;
		cin >> N >> E;
		vector<vector<int>>graph(N + 1, vector<int>(N + 1));
		for (int i = 0; i < E; i++) {
			int j, k;
			cin >> j >> k;
			graph[j - 1][k - 1] = 2;
		}

		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}

		for (int i = 0; i < N;i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1) {
					vector<vector<int>>visited(N + 1, vector<int>(N + 1, 0));
					int maxCost = -1;
					bfs(i,j,graph,visited,N,E,maxCost);
					minCost = min(minCost, maxCost);
				}
			}
		}

		cout << minCost << endl;
	}
}


```

## Approach 3
```cpp

#include<iostream>
using namespace std;
 
struct node{
   int x;
   int y;
   int level;
};
 
node q[1000];
int front = 0, back = 0;
 
void init(){
  front = back = 0;
}
 
void push(int x, int y, int level){
  q[back].x = x;
  q[back].y = y;
  q[back].level = level;
  back++;
}
node pop(){
   return q[front++];
}
bool empty(){
  return (front == back);
}
 
 
int a[100][100];
int rare[4][2];
int c;
int n;
 
bool valid(int r, int c){
  return (r>=0 && r<n && c>=0 && c<n);
}
 
int vis[100][100];
 
int xx[] = {-1,0,1,0};
int yy[] = {0,1,0,-1};
 
int bfs(int sx,int sy,int dx,int dy){
 
    push(sx,sy,0);
    vis[sx][sy] = 1;
   
    while(!empty()){
 
        node temp = pop();
        if(temp.x == dx && temp.y == dy)return temp.level;
   
        for(int i = 0; i<4; i++){
 
            int valx = temp.x + xx[i];
            int valy = temp.y + yy[i];
            int lvl = temp.level + 1;
 
            if(valid(valx,valy)){
                if(a[valx][valy] == 1 && vis[valx][valy] == 0){
                    push(valx,valy,lvl);
                    vis[valx][valy] = 1;
                }
            }
        }
    }
   
}
 
 
int main(){
 
   
  int t; cin>>t;
  while(t--){
     cin>>n;
     cin>>c;
   
     init();
   
    for(int i =0; i<c; i++){
       int x,y;cin>>x>>y;
       /*  indexing is so fucking important*/
       x--;y--;
       rare[i][0] = x;
       rare[i][1] = y;
    }
   
    for(int i = 0; i<n; i++){
      for(int j =0; j<n; j++){
        cin>>a[i][j];
      }
    }
   
    int ans = 10000;
   
    for(int i =0; i<n; i++){
      for(int j =0; j<n; j++){
         int temp;
        if(a[i][j] == 1){
            temp = 0;
            
            for(int k = 0; k<c; k++){
                /*  fucking don't forgot to empty the queue */
                init();
              for(int l =0; l<100; l++)for(int m =0; m<100; m++)vis[l][m] = 0;
               int res = bfs(i,j,rare[k][0],rare[k][1]);
               temp = max(res,temp);
            }
            /* if k bahar mt likhio pehle galti se likh dia tha */
             ans = min(ans,temp);
        }
       
      }
    }
     cout<<ans<<endl;
  }
   
  return 0;
}
```

## approach 4
```cpp
#include <iostream>
using namespace std;
int rareElements[4][2];
int region[20][20];
int c,n,longestDist;
int shortestLongestDist=2000000;

struct node{
	int x;
	int y;
	int level;
	struct node *next; 
};

class queue{
	node *front;
	node *rear;
	
	public:
		queue(){
			front=rear=NULL;
		}
		void push(int a, int b, int level){
			node *p = new node;
			if(front == NULL){
				front=p;
				rear=p;
			}
			else{
				node *q=front;
				while(q->next!= NULL){
					q=q->next;
				}
				q->next=p;
			}
			p->x=a;
			p->y=b;
			p->l=level;
			p->next=NULL;
		}
		
		void pop(int &x,int &y, int &l){
			if(front == NULL)
				cout<<"Empty Queue";
			node *p;
			x=p->x;
			y=p->y;
			l=p->l;
			front=p->next;
			delete p;
		}
		
		bool isEmpty(){
			if(front == NULL)
				return true;
			return false;
		}
};

void findDist(int a, int b, int x, bool visited[20][20]){
	queue q;
	int d=0;
	q.push(a,b,d);
	visited[a][b]=true;
	
	while(!q.empty()){
		int s,t,level;
		q.pop(s,t,level);
		
		if(s == x && t == y){
			if(level>longestDist)
				longestDist=level;
			return;
		}
		
		if(region[s+1][t] != 0 && (s+1) < n && visited[s+1][t] == false){
			q.push(s+1,t,level+1);
			visited[s+1][t]=true;
		}
		if(region[s-1][t] != 0 && (s-1) >= 0 && visited[s-1][t] == false){
			q.push(s-1,t,level+1);
			visited[s-1][t]=true;
		}
		if(region[s][t+1] != 0 && (t+1) < n && visited[s][t+1] == false){
			q.push(s,t+1,level+1);
			visited[s][t+1]=true;
		}
		if(region[s][t-1] != 0 && (t-1) >= 0 && visited[s][t-1] == false){
			q.push(s,t-1,level+1);
			visited[s][t-1]=true;
		}
	}
}

int main(){
	int t;
	cin>>t;
	int testcase=1;
	while(t--){
		shortestLongestDist=2000000;
		int a,b;
		cin>>n;
		cin>>c;
		for(int i=0;i<c;i++){
			cin>>a;
			cin>>b;
			rareElements[i][0]=a-1;
			rareElements[i][1]=b-1;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>region[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				longestDist=0;
				for(int k=0;k<c;k++){
					bool visited[20][20]={false};
					if(region[i][j]!=0){
						findDist(i,j,rareElements[k][0],rareElements[k][1],visited);
					}
				}
				if(longestDist<shortestLongestDist && longestDist != 0){
					shortestLongestDist = longestDist;
				}
			}
		}
		cout<<"#"<<testcase++<<" "<<shortestLongestDist<,endl;
	}
	return 0;
}

```
## approach 5
```cpp
#include<iostream>
using namespace std;
int n,c;
int ans=100000;
class queue{
    int q[100000];
    int front=0;
    int back=0;
    public:
    bool empty(){
        if(front-back==0) return true;
        return false;
    }
    int top(){
        if(back-front==0) return -1;
        return q[front];
    }
    void push(int x){
        if(back<100000) q[back++]=x;
    }
    void pop(){
        front++;
    }
};

int min(int a,int b){
    if(a>b) return b;
    else return a;
}

int max(int a,int b){
    if(a>b) return a;
    return b;
}

bool valid(int i,int j,int** matrix){
    if(i<0 || i>=n || j<0 || j>=n || matrix[i][j]==0) return false;
    return true;
}

void bfs(int** mat,int** vis,int** res,int x,int y){
    queue q;
    q.push(x);
    q.push(y);
    int temp=100000;
    while(!q.empty()){
        int i=q.top();q.pop();
        int j=q.top();q.pop();
        int cnt=0;
        for(int k=0;k<c;k++){
            if(vis[res[k][0]][res[k][1]]>0) cnt++;
        }
        if(cnt>=c) return;
        int val=vis[i][j];
        if(valid(i+1,j,mat)){
            vis[i+1][j]=val+1;
            q.push(i+1);
            q.push(j);
        }
        if(valid(i-1,j,mat)){
            vis[i-1][j]=val+1;
            q.push(i-1);
            q.push(j);
        }
        if(valid(i,j+1,mat)){
            vis[i][j+1]=val+1;
            q.push(i);
            q.push(j+1);
        }
        if(valid(i,j-1,mat)){
            vis[i][j-1]=val+1;
            q.push(i);
            q.push(j-1);
        }
    }
}

void clear(int** vis){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j]=0;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>c;
        int **matrix;
        int **vis;
        queue q;
        int **res=new int*[c];
        for(int i=0;i<c;i++){
            res[i]=new int[2];
            cin >> res[i][0] >> res[i][1];
            res[i][0]--;
            res[i][1]--;
        }
        matrix=new int*[n];
        vis=new int*[n];
        for(int i=0;i<n;i++){
            matrix[i]=new int [n];
            vis[i]=new int[n];
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
                vis[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    bfs(matrix,vis,res,i,j);
                    int temp=0;
                    for(int k=0;k<c;k++){
                        temp=max(temp,vis[res[k][0]][res[k][1]]);
                    }
                    ans=min(temp,ans);
                    clear(vis);
                }
            }
        }
        cout << ans << endl;
    }
}
```
## approach 6
```cpp
#include <iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;
int N, E;

struct points {
	int x, y, cost;
};

int BFS(int x, int y, int cost, vector<vector<int>> graph, vector<vector<bool>> visited, int N, int E) {
	int maxCost = -1;
	points temp;
	temp.x = x;
	temp.y = y;
	temp.cost = cost;
	queue<points> grid;
	grid.push(temp);
	visited[x][y] = 1;
	while (!grid.empty()) {
		if (E == 0) break;
		points top = grid.front();
		grid.pop();
		if (graph[top.x][top.y] == 2) {
			maxCost = max(maxCost, top.cost);
			E--;
		}
		if (top.x - 1 >= 0 && (graph[top.x - 1][top.y] == 1 || graph[top.x - 1][top.y] == 2) && !visited[top.x - 1][top.y]) {
			visited[top.x - 1][top.y] = 1;
			points temp2;
			temp2.x = top.x - 1;
			temp2.y = top.y;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}

		if (top.x + 1 < N && (graph[top.x + 1][top.y] == 1 || graph[top.x + 1][top.y] == 2) && !visited[top.x + 1][top.y]) {
			visited[top.x + 1][top.y] = 1;
			points temp2;
			temp2.x = top.x + 1;
			temp2.y = top.y;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}

		if (top.y - 1 >= 0 && (graph[top.x][top.y - 1] == 1 || graph[top.x][top.y - 1] == 2) && !visited[top.x][top.y - 1]) {
			visited[top.x][top.y - 1] = 1;
			points temp2;
			temp2.x = top.x;
			temp2.y = top.y - 1;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}

		if (top.y + 1 < N && (graph[top.x][top.y + 1] == 1 || graph[top.x][top.y + 1] == 2) && !visited[top.x][top.y + 1]) {
			visited[top.x][top.y + 1] = 1;
			points temp2;
			temp2.x = top.x;
			temp2.y = top.y + 1;
			temp2.cost = top.cost + 1;
			grid.push(temp2);
		}
	}
	return maxCost;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int minCost = INT_MAX;
		cin >> N >> E;
		vector<vector<int>> elements(E + 1, vector<int>(E + 1));
		vector<vector<int>> graph(N + 1, vector<int>(N + 1));
		vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, 0));
		for (int i = 0; i < E; i++) {
			cin >> elements[i][0] >> elements[i][1];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < E; i++) {
			graph[elements[i][0] - 1][elements[i][1] - 1] = 2;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][j] == 1) {
					int cost = BFS(i, j, 0, graph, visited, N, E);
					minCost = min(minCost, cost);
				}
			}
		}
		cout << minCost << endl;
	}
}
```

## approach 7
```cpp
#include<bits/stdc++.h>
using namespace std;
int t, n, c;
int rare[5][2];
int arr[100][100];
int visi[100][100];
struct node{
	int x, y, level;
};
int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};
bool valid(node tmp){
	if(tmp.x >= 0 and tmp.y >= 0 and tmp.x < n and tmp.y < n)return true;
	return false;
}
int bfs(int sx, int sy, int dx, int dy){
	queue<node>q;
	node tmp;
	tmp.x = sx;     tmp.y = sy;     tmp.level = 0;
	q.push(tmp);
	visi[tmp.x][tmp.y] = 1;
	while(!q.empty()){
		tmp = q.front();
		if(tmp.x == dx and tmp.y == dy)break;
		q.pop();
		for(int i = 0; i < 4; i++){
			node new_tmp;
			new_tmp.x = x[i] + tmp.x;
			new_tmp.y = y[i] + tmp.y;
			new_tmp.level = tmp.level + 1;
			if(valid(new_tmp) and arr[new_tmp.x][new_tmp.y] == 1 and visi[new_tmp.x][new_tmp.y] == 0){
				q.push(new_tmp);
				visi[new_tmp.x][new_tmp.y] = 1;
			}
		}
	}
	return tmp.level;
}
int main(){
	cin>>t;
	for(int test_case = 1; test_case <= t; test_case++){
		cin>>n>>c;
		for(int i = 0; i < c; i++){
			int x, y;
			cin>>x>>y;
			rare[i][0] = x-1;
			rare[i][1] = y-1;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin>>arr[i][j];
			}
		}
		int ans = 1000000;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int tmp;
				if(arr[i][j] == 1){
					//check all possibilities
					tmp = 0;
					for(int k = 0; k < c; k++){
						memset(visi, 0, sizeof(visi));
						int res = bfs(i, j, rare[k][0], rare[k][1]);
						tmp = max(tmp, res);	
					}
				}
				ans = min(ans, tmp);
			}
		}
		cout<<'#'<<test_case<<" "<<ans<<endl;
	}
}
```
## approach 8

```cpp
// https://github.com/s-kachroo/SamsungPractice/blob/master/research%20team.cpp

#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

int n, graph[100][100];
int maxDist[100][100];

bool inLimit(int r, int c) {
    return ((r >= 1 && r <= n) && (c >= 1 && c <= n));
}

void bfs(int dist[][100], int r, int c) {
    int i;
    dist[r][c] = 0;
    queue< pair<int, int> > q;
    q.push(make_pair(r, c));

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};

        for (i = 0; i < 4; i++) {
            int newX = r + x[i];
            int newY = c + y[i];

            if (inLimit(newX, newY) && dist[newX][newY] == -1 && graph[newX][newY] != 0) {
                dist[newX][newY] = dist[r][c] + 1;
                q.push(make_pair(newX, newY));
            }
        }
    }
}

int main() {
    int t, i, j, k, item, x, y, ans;
    int dist[100][100];

    cin>> t;
    while (t--) {
        cin>> n >> item;
        vector< pair<int, int> > p;

        for (i = 0; i < item; i++) {
            cin>> x >> y;
            p.push_back(make_pair(x, y));
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cin>> graph[i][j];
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                maxDist[i][j] = -1;
        }

        ans = INT_MAX;
        for (i = 0; i < item; i++) {
            x = p[i].first;
            y = p[i].second;
            for (j = 1; j <= n; j++) {
                for (k = 1; k <= n; k++) 
                    dist[j][k] = -1;
            }

            bfs(dist, x, y);
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= n; y++) {
                    maxDist[x][y] = max(maxDist[x][y], dist[x][y]);
                }
            }
        }

        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (maxDist[x][y] != -1) {
                    ans = min(ans, maxDist[x][y]);
                }
            }
        }
        cout<< ans << "\n";
    }

    return 0;
}

```
## approach 9

```cpp
/*
    Approach-1
    1-> Run BFS from every point on road->
    2-> Find distance of all the rare-elements from that point and store its maximum->
    3-> Return the minimum of all the Maximums calculated->
*/
#include<stdio.h>

struct co_ord{
    int x;
    int y;
    int cost;
};


class Queue{
public:
    int START, END, SIZE;
    int q[2000][3];
    Queue(){
        this->START=0;
        this->END=0;
        this->SIZE=0;
        for(int i=0; i<2000; i++){
            this->q[i][0]=0;
            this->q[i][1]=0;
            this->q[i][2]=0;
        }
    }

    int isEmpty(){
        if(this->SIZE==0){
            return 1;
        }else{
            return 0;
        }
    }

    void enqueue(int x, int y, int cost){
        this->q[this->END][0]=x;
        this->q[this->END][1]=y;
        this->q[this->END][2]=cost;
        this->END+=1;
        this->SIZE+=1;
    }

    co_ord dequeue(){
        int x = this->q[this->START][0];
        int y = this->q[this->START][1];
        int cost = this->q[this->START][2];
        this->START+=1;
        this->SIZE-=1;
        co_ord val = {x, y, cost};
        return val;
    }
};


class Solution{
public:
    int num_rows, num_cols, num_rare;
    int matrix[20][20], rare_loc[5][2], visited[20][20], dist[5], costs[400];
    Solution(){
        this->num_rows = 0;
        this->num_cols=0;
        this->num_rare=0;
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                this->matrix[i][j]=0;
                this->visited[i][j]=0;
            }
        }
        for(int i=0; i<5; i++){
            this->dist[i]=0;
            this->rare_loc[i][0]=0;
            this->rare_loc[i][1]=0;
        }
        for(int i=0; i<400; i++){
            this->costs[i]=-1;
        }
    }


    void reset(){
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                this->visited[i][j]=0;
            }
        }
    }

    int driver(){
        for(int i=0; i<this->num_rare; i++){
            int x= this->rare_loc[i][0];
            int y= this->rare_loc[i][1];
            this->matrix[x][y]=2;
        }
        for(int x=0; x<this->num_rows; x++){
            for(int y=0; y<this->num_cols; y++){
                if(matrix[x][y]!=0){
                    reset();
                    this->costs[20*x+y] = DFS(x, y);
                }
            }
        }
        int min_cost = 5000;
        for(int i=0; i<400; i++){
            if(this->costs[i]!=-1 && this->costs[i]<min_cost){
                min_cost=this->costs[i];
            }
        }
        if(min_cost==5000){
            return 0;
        }else{
            return min_cost;
        }
    }


    int DFS(int x, int y){
        int max_cost=0;
        Queue q;
        q.enqueue(x, y, 0);
        this->visited[x][y]=1;
        while(!q.isEmpty()){
            co_ord c = q.dequeue();
            int x = c.x;
            int y = c.y;
            int cost = c.cost;

            if(matrix[x][y]==2){
                if(cost>max_cost){
                    max_cost=cost;
                }
            }

            if((x-1 >= 0) && (this->visited[x-1][y]==0) && (this->matrix[x-1][y]!=0)){
                q.enqueue(x-1, y, cost+1);
                this->visited[x-1][y]=1;
            }
            if((y-1 >= 0) && (this->visited[x][y-1]==0) && (this->matrix[x][y-1]!=0)){
                q.enqueue(x, y-1, cost+1);
                this->visited[x][y-1]=1;
            }
            if((x+1<this->num_rows) && (this->visited[x+1][y]==0) && (this->matrix[x+1][y]!=0)){
                q.enqueue(x+1, y, cost+1);
                this->visited[x+1][y]=1;
            }
            if((y+1<this->num_cols) && (this->visited[x][y+1]==0) && (this->matrix[x][y+1]!=0)){
                q.enqueue(x, y+1, cost+1);
                this->visited[x][y+1]=1;
            }

        }
        return max_cost;
    }
};


int main(){
    int T;
    scanf("%d", &T);
    while(T>0){
        T--;
        int n_r, n_c, n_rare;
        scanf("%d %d %d", &n_r, &n_c, &n_rare);
        Solution s;
        s.num_rows = n_r;
        s.num_cols = n_c;
        s.num_rare = n_rare;
        for(int i=0; i<n_r; i++){
            for(int j=0; j<n_c; j++){
                scanf("%d", &s.matrix[i][j]);
            }
        }
        for(int i=0; i<n_rare; i++){
            scanf("%d %d", &s.rare_loc[i][0], &s.rare_loc[i][1]);
        }
        int result = s.driver();
        for(int i=0; i<n_r; i++){
            for(int j=0; j<n_c; j++){
                printf("%d\t",s.costs[20*i+j]);
            }
            printf("\n");
        }
        printf("\n\n%d\n", result);
    }
    return 1;
}

```

## approach 10
```cpp
//Advance
//Research Center
//Solved
//Vai

#include <stdio.h>

#define SZ 21

int Dist[SZ][SZ][5];
int Grid[SZ][SZ];
int N, M,C;
int X[5], Y[5];
int Ans;
int Test_cases, Case;


void take_input()
{
	int i, j;

	scanf("%d %d %d", &N, &M, &C);

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			scanf("%d", &Grid[i][j]);
		}
	}

	for (i = 0; i < C; i++){
		scanf("%d %d", &X[i], &Y[i]);
	}

}

void dfs(int i, int j, int k, int cost)
{
	if (Dist[i][j][k] > cost){
		Dist[i][j][k] = cost;
	}

	else{
		return;
	}

	//up
	if (i - 1 >= 0 && Grid[i-1][j] == 1){
		dfs(i - 1, j, k, cost + 1);
	}


	//left

	if (j - 1 >= 0 && Grid[i][j - 1] == 1){
		dfs(i, j - 1, k, cost + 1);
	}

	//right

	if (j + 1 < M && Grid[i][j + 1] == 1){
		dfs(i, j + 1, k, cost + 1);
	}

	//down

	if (i + 1 < N && Grid[i + 1][j] == 1){
		dfs(i + 1, j, k, cost+1);
	}
}

void solve_case()
{
	int i, j, k,mx=-1;
	int x, y,centerdist,cardist;

	Ans = N*M;

	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			for (k = 0; k < C; k++){
				Dist[i][j][k] = N*M;
			}
		}
	}


	for (k = 0; k < C; k++){
		dfs(X[k], Y[k], k, 0);
	}

	//Marking rarepoint
	for (k = 0; k < C; k++){
		Grid[X[k]][Y[k]] = 2;
	}


	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			if (Grid[i][j] == 1){
				for (x = 0; x < N; x++){
					for (y = 0; y < M; y++){
						if (Grid[x][y]){
							mx = 0;

							for (k = 0; k < C; k++){
								centerdist = (Dist[i][j][k]);
								cardist = Dist[x][y][k];

								if (centerdist < cardist){
									if (centerdist > mx){
										mx = centerdist;
									}
								}
								else{
									if (cardist > mx){
										mx = cardist;
									}
								}
							}

							if (mx < Ans){
								Ans = mx;
							}

						}
					}
				}
			}
		}
	}
}


void print_output()
{
	printf("#%d %d\n", Case, Ans);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &Test_cases);

	for (Case = 1; Case <= Test_cases; Case++){
		take_input();
		solve_case();
		print_output();
	}
}

```

```cpp
Research_Item.cpp
 #include<iostream>
 #include<vector>
 #include<queue>
 #include<climits>
 using namespace std;
 int n,k;
 vector<pair<int,int> > v;
 int matrix[25][25],visited[25][25],dist[25][25];
 int dx[]={1,-1,0,0};
 int dy[]={0,0,1,-1};

void clear()
{
   for(int i=1;i<=n;i++)
   {
    for(int j=1;j<=n;j++)
    {
        dist[i][j]=INT_MAX;
    }
   }
}
int bfs(int x,int y)
 {
    queue <pair<int,int> > q;
    dist[x][y]=0;
    q.push({x,y});
    while(q.size())
    {
       auto z=q.front();
       q.pop();
       x=z.first, y=z.second;

       for(int i=0;i<4;i++)
       {
          int xx=x+dx[i];
          int yy=y+dy[i];
          if(xx>=1 && xx<=n && yy>=1 && yy<=n && matrix[xx][yy] && dist[xx][yy]> dist[x][y]+1)
          {
            dist[xx][yy]=dist[x][y]+1;
            q.push({xx,yy});
          }
       } 
    }
    int maxi=0;
    for(auto i: v)
    {
        x=i.first,y=i.second;
        maxi=max(maxi,dist[x][y]);
    }

    return maxi;

 }
 void solve()
 {
    v.clear();
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>matrix[i][j];
            dist[i][j]=INT_MAX;
        }
    }
    int mini=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(matrix[i][j])
            {
                int val=bfs(i,j);
                mini=min(mini,val);
                clear();
            }
            
        }
    }
    cout<<mini<<endl;


 }
 int main()
 {
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }

    return 0;
 }
```