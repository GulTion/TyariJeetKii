---
title: Solve Endoscope
source: https://www.hackerrank.com/contests/target-samsung-13-nov19/challenges/endoscope
author:
  - "[[HackerRank]]"
published: 
created: 2024-12-18
description: Endoscope
tags:
  - clippings
status: not_implemented
explored: false
---
Raka, a CSE student from IIITG developed an endoscope to explore inner part of ruined water pipes. It is possible explore the inner part of the pipes putting the endoscope into a certain part of the pipe. The endoscope can be moved in the pipes only. Meanwhile, when the pipes are connected to each other, if the length of the endoscope is long enough to explore, it is able to inspect the connected pipe. However, we cannot observe every pipe because the length of the endoscope is limited.

When the map of the ground water pipe, the location where the endoscope to out in, and the length of the endoscope is given, calculate the number of pipe which are available to explore. Length of endoscope means the range upto which endoscope can explore. There are seven kind of pipes, and description for each pipe are shown below

![image](https://s3.amazonaws.com/hr-assets/0/1572975788-3d3aedb280-3be4e11.png)\- 1 
![image](https://s3.amazonaws.com/hr-assets/0/1572975815-05f202e72f-4093851.png) - 2 
![image](https://s3.amazonaws.com/hr-assets/0/1572975836-e801ea0f75-48f567d.png)\- 3 
![image](https://s3.amazonaws.com/hr-assets/0/1572975854-32bbeef565-4f0a4fc.png)\- 4 
![image](https://s3.amazonaws.com/hr-assets/0/1572975880-b4e37f33e7-5b79728.png)\- 5 
![image](https://he-s3.s3.amazonaws.com/media/uploads/623df7e.png) - 6 
![image](https://s3.amazonaws.com/hr-assets/0/1572975914-b7cb24d0d0-6aa528b.png) - 7

Fig 1 Shows an example of a map of ground water pipes. In this case, the height of the map is 5, and the width is 6 If a certain point where the endoscope to put in is given as (2,1), it means the vertical location will be 2, and the horizontal location will be 1, shown as a red highlighted pipe in fig 2. If the length of the endoscope is 1, we can explore only one water pipe which is at the intersection point If the length of the endoscope is 2, we can explore 3 water pipes including a blue highlighted pipe and a red marked pipe with the endoscope Fig-3 . If the length of the endoscope is 3, we can explore 5 water pipes total Fig-4

![image](https://he-s3.s3.amazonaws.com/media/uploads/672fd6c.jpg) 
::Fig-1

![image](https://he-s3.s3.amazonaws.com/media/uploads/ce1a1da.jpg) 
::Fig-2

![image](https://he-s3.s3.amazonaws.com/media/uploads/e6db2ed.jpg) 
::Fig-3

![image](https://he-s3.s3.amazonaws.com/media/uploads/f568964.jpg) 
::Fig-4

**Input Format**

In the first line, T, the number of total test cases are given. From the second line, T test cases are given. In the first line of each test case, N, the height of the map of the groundwater pipes, M, the width, R, the vertical location of the water pipe where to put in the endoscope, C, the horizontal location of it, and the length of the endoscope L are given. In the following N lines, information about the map of the groundwater pipe is given. Each line has M numbers. Each number (from 1 to 7) means the type of water pipe for that point. 0 means there is no water pipe buried in that place.

**Constraints**

Constraints 1≤ T ≤100

1≤ N, M ≤50

0≤ X < N

0≤ Y < M

1≤ L ≤ 20

**Output Format**

Print the respective answer for T test cases in total for T lines. The answer is the number of water pipes which is available to observe using the endoscope.

**Sample Input 0**

```
2 
5 6 2 1 3 
0 0 5 3 6 0 
0 0 2 0 2 0 
3 3 1 3 7 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
5 6 2 2 6 
3 0 0 0 0 3 
2 0 0 0 0 6 
1 3 1 1 3 1 
2 0 2 0 0 2 
0 0 4 3 1 1
```

**Sample Output 0**

```
5
15
```

```cpp

#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
int mat[60][60];
int n,m;
bool upor(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==2||mat[x][y]==5||mat[x][y]==6) return true;
	else return false;
}
bool nich(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==2||mat[x][y]==4||mat[x][y]==7) return true;
	else return false;
}
bool dan(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==3||mat[x][y]==6||mat[x][y]==7) return true;
	else return false;
}
bool bam(int x,int y)
{
	if (mat[x][y]==1||mat[x][y]==3||mat[x][y]==4||mat[x][y]==5) return true;
	else return false;
}

void endo(int x, int y,int len, int vis[60][60])
{
	if(len==0 || mat[x][y] ==0) return;
	vis[x][y]=1;
	vector<pair <int,int> > v;
	if(mat[x][y]==1)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==2)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
	}
	if(mat[x][y]==3)
	{
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==4)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==5)
	{
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
		if(y+1<=m && dan(x,y+1)) v.pb({x,y+1});
	}
	if(mat[x][y]==6)
	{
		if(x+1 <= n && nich(x+1,y)) v.pb({x+1,y});
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});
	}
	if(mat[x][y]==7)
	{
		if((x-1)>=1 && upor(x-1,y) ) v.pb({x-1,y});
		if(y-1 >=1 && bam(x,y-1)) v.pb({x,y-1});

	}


	for(auto i: v)
	{
		int xx = i.first;
		int yy= i.second;
		endo(xx,yy,len-1,vis);
	}

}
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
    int tt;
    cin>>tt;
    while(tt--)
    {
    	int a,b,i,j,len;
    	int vis[60][60];
    	cin>>n>>m>>a>>b>>len;
    	for(i=1;i<=n;i++)
    		for(j=1;j<=m;j++)
    		{
    			cin>>mat[i][j];
    			vis[i][j]=0;
    		}
    		endo(a+1,b+1,len,vis);
    		int count=0;
    		for(i=1;i<=n;i++)
    			for(j=1;j<=m;j++)
    					if(vis[i][j]) count++;
    		cout<<count<<endl;
    }


	return 0;

}
```
# Approuch 2

```cpp
#include <bits/stdc++.h>
#define ll long long
#define pub push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
using namespace std;
bool upor(int i)
{
    return (i == 1 || i == 2 || i == 4 || i == 7);
}
bool niche(int i)
{
    return (i == 1 || i == 2 || i == 5 || i == 6);
}
bool bame(int i)
{
    return (i == 1 || i == 3 || i == 6 || i == 7);
}
bool dane(int i)
{
    return (i == 1 || i == 3 || i == 4 || i == 5);
}
int a[100][100];
bool vis[100][100];
int n, m;
vector<pair<int, int>> vp = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int bfs(int si, int sj, int l)
{
    if (a[si][sj] == 0)
        return 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{si, sj}, 1});
    vis[si][sj] = true;
    int ans = 0;
    while (!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int i = p.first.first;
        int j = p.first.second;
        int c = p.second;
        if (c > l)
            continue;
        ans++;
        // cout << i << " " << j << endl;
        for (int d = 0; d < 4; d++)
        {
            int xi = i + vp[d].first;
            int xj = j + vp[d].second;

            if (valid(xi, xj) && !vis[xi][xj] && a[xi][xj] != 0)
            {
                if (d == 0 && dane(a[i][j]) && bame(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
                else if (d == 1 && bame(a[i][j]) && dane(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
                else if (d == 2 && niche(a[i][j]) && upor(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
                else if (d == 3 && upor(a[i][j]) && niche(a[xi][xj]))
                {
                    vis[xi][xj] = true;
                    q.push({{xi, xj}, c + 1});
                }
            }
        }
    }
    return ans;
}
void solve()
{
    int si, sj, l;
    cin >> n >> m >> si >> sj >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
            cin >> a[i][j];
        }
    }

    cout << bfs(si, sj, l) << endl;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

```