---
title: Samsung ADV：Automatic Fueling Robot-CSDN博客
source: https://blog.csdn.net/weixin_42688573/article/details/124970239
author: 
published: 
created: 2025-02-28
description: "文章浏览阅读583次。Samsung ADV: Automatic Fueling Robot_samsung adv"
tags:
  - clippings
status: Pending
---

Automatic Fueling [Robot](https://so.csdn.net/so/search?q=Robot&spm=1001.2101.3001.7020)

C/C++.JAVA 3S

There are N cars parked in a row in a parking lot.  
On both sides of the parking garage, as it is demonstrated in the picture below, there is a Gasoline and Diesel fueling station installed.  
An automatic fueling robot carries the fuel form the station and fills up the parked cars with fuel.

![[Pasted image 20250308123031.png]]
The cars are divided into two types depending on whether it is a gasoline or Diesel car.  
The automatic robot will be used to provide a cost-free fueling service which is filling up all cars with 1L of each corresponding fuel.  
The robot will move between the two fueling stations as follows.

1. The robot carries 2L of gasoline at the Gasoline station and starts moving from there.
2. The robot can fill up the cars of the same type of gas it carries 1L each.
3. The robot can go back to the fueling, it gets 2L of supply of the corresponding fuel (if the robot has some remaining fuel, it will be discarded.)
4. There is an equal distance of 1 between each fueling station and the cars.

The fuel type of N cars parked in the parking lot will be given.  
Find the minimum moving distance of the automatic fueling robot after it has filled up all cars with 1 fuel each.

\[Example 1\]  
Given the number of total cars N=5 and the order of the parked cars such as G –D – G –D – G, the process of finding the minimum moving distance for fueling all cars is as follows:  
![[Pasted image 20250308123019.png]]
![[Pasted image 20250308123044.png]]
In this case, the total moving distance until the last car is filled up is 12 which is the minimum moving distance.

\[Example 2\]  
Given the total number of cars N=5 and the order of the parked cars such as D- G- G- D- G, the process of finding the minimum moving distance for fueling all cars is as shown below.  
![[Pasted image 20250308123057.png]]
![[Pasted image 20250308123107.png]]
In this case, the total moving distance until the last car is filled up with fuel is 14 which is the minimum moving distance.

\[Constrains\]

1. The number of total cars N is greater than or equal to 2 and less than or equal to 8.(2<=N<=8)
2. The amount of fuel that the robot can carry all at once at a fueling station is 2L.
3. All cars can get filled up with 1L of its corresponding fuel.
4. There is no empty space between each parked car and they are always 1 distance apart.
5. The tow fueling stations are 1 distance apart each from the outer parked car.

\[Input\]  
The first line contains a single integer T- the number of total test cases.  
From the next line on, each test case is given.  
The first line of each case contains N-the number of total cars.  
On the following line, N fuel information of the parked cars will be given as either 1 or 2. (1: Gasoline, 2: Diesel)

\[Output\]  
Print “#t” (without the quotes), leave a blank space and print the answer. ( t refers to the test case number and starts with 1).  
Print minimum moving distance of the automatic fueling robot after it has filled up all cars with 1L fuel each.

\[Input/ Output Example\]

Input Example

```
5
3
2 1 2
5
1 2 1 2 1
5
2 1 1 2 1
8
2 2 1 1 1 2 1 1
8
2 2 2 2 2 2 2 2
```

Output Example

```java
#1 7
#2 12
#3 14
#4 35
#5 41
```

## Approach 1
```cpp
#include<iostream>
#include<climits>
using namespace std;
int n;
int ans=100000;
int a[9];
int vis[9];

// ins 0 is continuing ans refuiling same type of cars until fuel>0 
// ins 1 is going back to the gas station 
// int 2 is going to the disel station

void helper(int n,int dis,int remf,int pind,int cars,int ins,int gas){
    if(n==cars){
        if(ans>dis){
            ans=dis;
        }
        return;
    }
    if(remf<=0) return;
    if(ins==0 && gas==0){
        for(int k=1;k<=n;k++){
            if(vis[k]==0 && a[k]==1){
                vis[k]=1;
                helper(n,dis+abs(pind-k),remf-1,k,cars+1,0,0);
                helper(n,dis+abs(pind-k),2,k,cars+1,1,0);
                helper(n,dis+abs(pind-k),2,k,cars+1,2,0);
                vis[k]=0;
            }
        }
    }
    if(ins==0 && gas==1){
        for(int k=n;k>=1;k--){
            if(vis[k]==0 && a[k]==2){
                vis[k]=1;
                helper(n,dis+abs(pind-k),remf-1,k,cars+1,0,1);
                helper(n,dis+abs(pind-k),2,k,cars+1,1,1);
                helper(n,dis+abs(pind-k),2,k,cars+1,2,1);
                vis[k]=0;
            }
        }
    }
    if(ins==1){
        helper(n,dis+pind,2,0,cars,0,0);
    }
    if(ins==2){
        helper(n,dis+(n+1-pind),2,n+1,cars,0,1);
    }
}
 
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        ans=100000;
        for(int i=0;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        helper(n,0,2,0,0,0,0);
        if(ans==100000){
            helper(n,n+1,2,n+1,0,0,1);
        }
        cout << ans << endl;
    }
}
```

## Approach 2
```cpp
#include <iostream>
#include <time.h>
#include <cstring>
using namespace std;
#define GASOLINE 1
#define DIESAL 2

void initialize(int* arr, int n){
    memset(arr, 0, sizeof(arr[0]) * n);
    return;
}

void generate_neighbours(int* target, int* space, int* visited, int N, int x, int probe, bool gasoline){
    // From gasoline station  robot  has to visit one gasoline car.
    // Similarly from diesal station robot has to visit one diesal car. 
    // From a car, robot  can either go to similar car,
    // or gasoline station,
    // or diesal station.
    if ( x!= 0 && x!= N-1){
        if(probe != 0){
            int check = 0;
            if (gasoline == true) check = GASOLINE;
            else check = DIESAL;
            for(int i=1;i<N-1;i++){
                if(space[i] == check && visited[i] == 0){
                    target[i] = 1;
                }
            }
        }
        if (visited[0] == 0) target[0] = 1;
        if (visited[N-1] == 0) target[N-1] = 1;
    }
    else{
        int check;
        if (x==0) check = GASOLINE;
        else check = DIESAL;
        for(int i=1;i<N-1;i++){
            if(space[i] == check && visited[i] == 0){
                target[i] = 1;
            }
        }
    }
    return;
}

void need_at_gas_stations(int* space, int* visited, int N){
    // if all diesal cars fueled, then visited[N-1] = 1
    // if all gasoline cars fueled, then visited[0] = 1
    bool check = true;
    if(visited[0] == 0){
        for(int i=1;i<N-1;i++){
            if((space[i] == GASOLINE) && visited[i] != 1) {
                check = false;
                break;
            }
        }
        if(check == true) visited[0] = 1; 
    }
    
    check = true;
    if(visited[N-1] == 0){
        for(int i=1;i<N-1;i++){
            if((space[i] == DIESAL) && visited[i] != 1) {
                check = false;
                break;
            }
        }
        if(check == true) visited[N-1] = 1; 
    }
    return;
}

int DFS(int* space, int* visited, int N, int x, int cost, int probe, bool gasoline){
    // Evaluates walking distance for every  possible path
    int* neighbours = new int[N];
    initialize(neighbours, N);

    need_at_gas_stations(space, visited, N);
    
    if (visited[0] == 1 && visited[N-1] == 1) return cost;

    generate_neighbours(neighbours, space, visited, N, x, probe, gasoline);

    if (x == 0 || x == N-1){
        probe = 2;
        if (x==0) gasoline = true;
        else gasoline = false;
    }

    int min_cost = INT32_MAX;

    for(int i=0; i<N; i++){
        if(neighbours[i] == 1){

            int* passing_array = new int[N];
            initialize(passing_array, N);
            for(int j=0; j<N; j++) passing_array[j] = visited[j];

            if (i != 0 && i!= N-1)  passing_array[i] = 1;
            int val = DFS(space, passing_array, N, i, cost + abs(x - i), probe-1, gasoline);
            min_cost = min(min_cost, val);
            delete passing_array;
        }
    }

    return min_cost;
}


int find_optimum(int* space, int N){
    int start = 0;
    int cost = 0;
    int* visited = new int[N];
    initialize(visited, N);

    return DFS(space, visited, N, start, cost, 0, true);
}


int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;

        int* space = new int[n + 2];
        for(int i=1; i<=n; i++){
            cin>>space[i];
        }

        space[0] = 0;
        space[n+1] = 0;
        cout<< find_optimum(space, n+2);
    }
}

```
## Approach 3
Solution

We should always start from the Gasoline station.
Once we fuel any car, we have 3 options to perform.
	1) Fuel next car(gasoline or Diesel car, with all the combinations)
	2) Go to Gasoline station and start refueling 
	3) Go to Diesel station and start fueling. 
Keep updating the distances as we move, once all cars are over, store  result in global variable , if we find optimal distance with the current combination than the previous combinations. 
```cpp
#include<stdio.h>
#include<string.h>
#define MAX 9
int arr[MAX];
int visited[MAX];
int tdistance=99999;
void calc_min(int n,int distance,int rem,int pindex,int cars,int ins, int g_or_d)
{
	int i;
	if(cars==n)
	{
		if(tdistance>distance)
		{
			tdistance=distance;
		}
		return;
	}
	if(rem<=0) return;
	if(ins==0 && g_or_d==0)
	{
		int k;
		for(k=1;k<=n;k++)
		{
			if(!visited[k] &&arr[k]==1)
			{
				visited[k]=1;
				//go to next gas car
				calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,0,0);
				//go to gas station
				calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,1,0);
				//go to diesel station
				calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,2,0);
				visited[k]=0;
			}
		}
	}
	if(ins==0 && g_or_d==1)
	{
		int k;
		for(k=n;k>=1;k--)
		{
			if(!visited[k] && arr[k]==2)
			{
				visited[k]=1;
				//go to next gas car
				calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),rem-1,k,cars+1,0,1);
				//go to gas station
				calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,1,1);
				//go to diesel station
				calc_min(n,distance+(k>pindex ? k-pindex:pindex-k),2,k,cars+1,2,1);
				visited[k]=0;
			}
		}
	}
	if(ins==1)
	{
		//fill gas and recall  
		calc_min(n,distance+(pindex-0),2,0,cars,0,0);
	}
	if(ins==2)
	{
		//fill diesel and recall
		calc_min(n,distance+((n+1)-pindex),2,n+1,cars,0,1);
	}

}
int main(void)
{
	int T, test_case;
	int n;
	int i;
	freopen("inp.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &n);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &arr[i]);
		}
		calc_min(n,0,2,0,0,0,0);
		if( tdistance==99999)
		{
			//May be all cars are diesel cars, go to diesel bunk and fuel it from there
			calc_min(n,n+1,2,n+1,0,0,1);
		}
		printf("Case #%d %d\n", test_case+1,tdistance);
		tdistance=99999;
	}
	getch();
}
```

## Approach 4

Robot has Two Functions in the problem statement
Robot @ Pump 
Fill 2 Units of Fuel
Move in next direction
Increment count 
Robot @ Car
If fuel carried by  robot and car not same
	increment count
If fuel carried by  robot and car is same same
3 decisions
	Don’t fill Fuel, continue to next car
	Fill the fuel and continue to next car
	Fill the fuel and continue backward
Increment count 
Pseudo Algorithm

If it is a Pump
	Fill 2 Units of Fuel
	Move in next direction
		(if Gasoline then move right/Diesel left)
	Increment count
If it is a Car
	If fuel carried by  robot and car not same
		increment count 
		move next
	If fuel carried by  robot and car is same and empty
		if this is last car
			note the count
			return
		Don’t fill Fuel, continue to next spot
		Fill the fuel and continue to next spot
		Fill the fuel and continue backward

Solution is attached:
```cpp
#include <stdio.h>
#include <time.h>
#define GAS 1
#define DIESEL 2
#define NOTHING 0
#define RIGHT 1
#define LEFT -1
#define SPOT 10

int A[SPOT];
int min;
struct Cars {
    int Visited[SPOT];
    int nc;//no of cars
};

void fill(int step,int direction,int fuel,int quantity,int count,int cars_left,struct Cars station)
{    if(count == min)
        return;
    if(step == 0)
    {//GASOLINE station
        fill(1,RIGHT,GAS,2,count+1,cars_left,station);
        return;
    }if(step == SPOT-1)
    {//DIESEL station
        fill(SPOT-2,LEFT,DIESEL,2,count+1,cars_left,station);
        return;
    }if(A[step]==0)
    {//spot not occupied by any car count does not increase
        fill(step+direction,direction,fuel,quantity,count, cars_left,station);
    }
    if(A[step]==fuel&&station.Visited[step]==0&&quantity>0)
    {//fill
        station.Visited[step]=1;
        if(cars_left == 1)
        {    if(count < min)
                min = count;
            return;
        }//go forward
        fill(step+direction,direction,fuel,quantity-1,count+1,cars_left-1,station);
        //go back direction
        fill(step-direction,-(direction),NOTHING,0,count+1,cars_left-1,station);
        //don't fill and go forward
        station.Visited[step]=0;
        fill(step+direction,direction,fuel,quantity,count+1,cars_left,station);
    }
    else
    {//Already filled
        fill(step+direction,direction,fuel,quantity,count+1,cars_left,station);
    }
}

int main()
{
    int T,i;
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    freopen("input.txt", "r", stdin);
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {    struct Cars station;
        int j;
        min = 65530;    //reset  all data
        for(j=0;j<SPOT;j++)
        {    A[j]=0;
            station.Visited[j]=0;
        }//read ip
        scanf("%d",&station.nc);
        for(j=1;j<=station.nc;j++)
        {
            scanf("%d",&A[j]);
        }
        fill(0,RIGHT,GAS,2,0,station.nc,station);
        fill(0,RIGHT,NOTHING,2,0,station.nc,station);
        printf("%d %d\n",i+1,min);
    }
     end = clock();
     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
     printf("%f",cpu_time_used );
    return 0;
}

```