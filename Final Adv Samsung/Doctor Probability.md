A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

#### Sample Input

```
2
6 10 40
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 10
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5
```

#### Sample Output

```
6 0.774000
3 0.700000
```


```cpp
/*



2
6 10 40 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5
6 10 10 
1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 0.774000  
3 0.700000
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int source, int time, double prob,vector< pair <int,double> > v[20],vector<double> &ans)
{
	if(time<=0)
	{

		ans[source]+=prob;
		//cout<<prob<<endl;
		return;
	}

	for(auto it : v[source])
	{
		if(it.second!= 0.0)
		{
			int newSource = it.first;
		double p = it.second;

		prob= p*prob;
		dfs(newSource,time-10,prob,v,ans);
		prob/= p;
		}

	}
}

void solve()
{
	int n,e,t,i,x,y,node;
	double p;
	vector< pair <int,double> > v[20];
	vector<double> ans(20,0.0);


	cin>>n>>e>>t;
	for(i=1;i<=e;i++)
	{
		cin>>x>>y>>p;
		v[x].push_back({y,p});
	}
	
	dfs(1,t,1.0,v,ans);
	double maxi=0.0;
	for(i=1;i<=n;i++)
	{
		//cout<<ans[i]<<endl;
		if(maxi<ans[i])
		{
			maxi= ans[i];
			node=i;
		}
	}
	cout<<node<<" "<<fixed<<setprecision(6)<<ans[node]<<endl;
}
main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	int tt;
	cin>>tt;
	while(tt--)
	{
		solve();
	}
}
```

# CODE 2
```cpp
#include<iostream>
#include<vector>

using namespace std;
double finalAns = -1.0;
int finalIndex = -1;

void solve(int n, int time, vector<vector<double>> &grid) {
	vector<vector<double>> sol(100, vector<double>(100, 0.0));
	sol[0][1] = 1.0;
	for (int i = 2; i <= n; i++) {
		sol[0][i] = 0;
	}
	for (int i = 0; i < time; i++) {
		for (int k = 1; k <= n;k++) {
			sol[i + 1][k] = 0;
		}
		for (int j = 1; j <= n; j++) {
			if (sol[i][j]) {
				for (int k = 1; k <= n; k++) {
					if (grid[j][k]) {
						sol[i + 1][k] += sol[i][j] * grid[j][k];
					}
				}
			}
		}
	}
	for (int i = 1; i <= n;i++) {
		if (sol[time][i] > finalAns) {
			finalAns = sol[time][i];
			finalIndex = i;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		int n, e, time;
		cin >> n >> e >> time;
		time = time / 10;
		vector<vector<double>> grid(n + 2, vector<double>(n + 2, 0.0));
		for (int i = 0; i < e; i++) {
			int u, v;
			double x;
			cin >> u >> v >> x;
			grid[u][v] = x;
		}

		solve(n, time, grid);

		cout << "#" << z << " " << finalIndex << " " << finalAns << endl;
	}
}
```