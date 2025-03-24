---
explored: true
---

## Approuch 1
```cpp
#include<iostream>
#include<climits>
using namespace std;
int n;
int tc[25];
int th[25];
int ans;
 
void dfs(int i,int a,int b,int c,int cost){
    if(cost>ans) return;
    int tot=a+b+c;
    if(i==n-1){
        if(tot<th[i]) cost+=tc[i];
        if(cost<ans) ans=cost;
        return;
    }
    dfs(i+1,a,b,c,cost+tc[i]);
    dfs(i+1,a+th[i],b,c,cost+2*tc[i]);
    if(tot>th[i]){
        if(th[i]>b+c) a=tot-th[i];
        if(th[i]>c) b=th[i]-c>=b?0:b+c-th[i];
        dfs(i+1,0,a,b,cost);
    }
} 
 
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ans=100000;
        for(int i=0;i<n;i++){
            cin >> th[i] >> tc[i];
        }
        dfs(0,0,0,0,0);
        cout << ans << endl;
    }
}
```


## approauch 4

```cpp

#include <iostream>
int N, cc[25], t[25], min_cost = 10000007;

void dfs(int p, int a, int b, int c, int cost)
{
int asum = a+b+c;
if (cost > min_cost) return;
if (p == N-1)
{
if (asum < t[p]) cost += cc[p];
if (cost < min_cost) min_cost = cost;
return;
}
dfs(p+1, a, b, c, cost+cc[p]);
dfs(p+1, a+t[p], b, c, cost+2*cc[p]);
if (asum >= t[p])
{
if (t[p] > b+c) a = asum-t[p];
if (t[p] > c) b = t[p]-c>=b ? 0 : b-t[p]+c;
dfs(p+1, 0, a, b, cost);
}
}
int main()
{
std::cin >> N;
for (int i = 0; i < N; ++i)
	std::cin >> t[i] >> cc[i];
dfs(0, 0, 0, 0, 0);
std::cout << min_cost << std::endl;
return 0;
} 
/////////////////

#include <stdio.h>
#include<time.h>
// no.of.toll gate(between 5 and 20, cost at toll gate, total hire available at tollgate, minimum cost
int N, tc [22], th[22], min_cost = 1000000;
void dfs(int tp, int bp3, int bp2, int bp1, int cc);
int main()
{
 int i, TC;
 clock_t start, end;
 double cpu_time_used;
 
 printf("No.of.TC? "); scanf("%d", &TC);
 start = clock();
 while( TC-- )
 {
 scanf("%d", &N); 
 for ( i = 0; i < N; ++i)
  scanf("%d %d", &th[i], & tc [i]);

 
 dfs(0, 0, 0, 0, 0);
 printf("\nMinCost= %d\n\n", min_cost );
 min_cost = 1000000; //some large number
 }
 end = clock();
 cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
 printf("fun() took %f seconds to execute \n", cpu_time_used);
 getch();
return 0;
}
```


## approach 3
```cpp
#include<iostream>
using namespace std;
 
int n;
int cost[25];
int mens[25];
 
int ans;
 
void solve(int index, int one, int two, int three, int total){
    
    // optimization
    if(total > ans)return;
    
    int menAvailable = one + two + three;
    
    // base case
    if(index == n-1){
        if(menAvailable >= mens[n-1])
        ans = min(ans, total);
        else 
        ans = min(ans, total + cost[n-1]);
        return;
    }
    
    // recursive case
    // hire the men
    solve(index + 1, one + mens[index], two, three, total + 2*cost[index]);
    //pay the cost
    solve(index + 1, one, two, three, total + cost[index]);
    // fight the men 
    if(menAvailable >= mens[index]){
        if(two + three < mens[index])one = menAvailable - mens[index];
        if(three < mens[index])two = (two + three <= mens[index]) ? 0 : two - mens[index] + three;
        solve(index + 1, 0, one, two, total);
    }
    
}
 
int main(){
    
    cin>>n;
   
    for(int i = 0; i<n; i++)
    cin>>mens[i]>>cost[i];
    
    ans = 1000000;
    
    solve(0,0,0,0,0);
    cout<<ans<<endl;
    return 0;
}
```