---
title: Samsung ADV：Tunnel Construction_imagine there is an area the size of h by v (h * v-CSDN博客
source: https://blog.csdn.net/weixin_42688573/article/details/124969630?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-124969630-blog-124970239.235^v43^pc_blog_bottom_relevance_base5&spm=1001.2101.3001.4242.2&utm_relevant_index=4
author: 
published: 
created: 2025-02-28
description: 文章浏览阅读325次。Samsung ADV：Tunnel Construction_imagine there is an area the size of h by v (h * v) and the plan is to const
tags:
  - clippings
explored: true
---
Tunnel Construction (C/C++/Java 3s)  
Imagine there is an area the size of H by V (H\*V) and the plan is to construct N tunnels toward the horizontal direction.  
![在这里插入图片描述](https://i-blog.csdnimg.cn/blog_migrate/57328625a54c56442e8d288c86b0876b.png)

The uppercase letters S, C, R, M in the picture above denote the following:

`s[v][h]`

S\[v\]\[h\] denotes the hardness of the v-th (vertical), h-th (horizontal) area.

1. C1, C2  
C1, C2 is used when computing the construction cost for the v-th , h-th area.  
In case excavator 1 is used: S\[v\]\[h\] \*C1  
In case excavator 2 is used: S\[v\]\[h\] \*C2


2. R1, R2
Construction is only possible for 1 area per day.  
If the same excavator is used two days in a row, an additional cost will occur.

Additional cost for excavator 1: R1  
Additional cost for excavator 2: R2

3. 
  M1, M2
  
When the tunnel under construction is complete, the two excavators can move to the next construction site.  
A moving cost is going to occur which can be computed as follows:  
(M1²+M2²) \*D  
\*D refers to the vertical distance and for the sake of safety, it must be greater than or equal to 2.  
For instance, if the excavator moves for the 2nd-vertical position to the 5th vertical position, D is 3.

Given N, H, V, S, C, R, M  
＞Find the minimum value for the total construction cost.

**\[Constraints\]**

  1<=N<=5, 3<=H<=500, (N*2-1)<= V<=15
  
  1<=S<=300, 1<=C<=200, 1<=R<=500, 1<=M<=300

  The distance between the tunnels D must be greater than or equal to 2. (2<=D)

  The excavators can move to the next construction site after the construction of one tunnel is complete.

  When construction the first tunnel, there is no moving cost.

  The tow excavators must move together to the same vertical location.


**\[Example 1\]**  
N=1, H=3, V=1  
![[Pasted image 20250301015003.png]]

Cost will be minimum if excavators are used according to the order 1->2->1, which results in (42*4)+(99*4)+(3\*4)=576

**\[Example 2\]**  
N=1, H=5, V=1  
![[Pasted image 20250301015011.png]]

Cost will be minimum if excavators are used according to the order 2->1->2->2->2, which results in (11*2)+(1*7)+(2*3)+(1*2+6)+(4\*2+6)=57

**\[Example 3\]**  
N=2, H=5, V=4  
![[Pasted image 20250301015021.png]]

The minimum construction cost for each tunnel is (starting from the top order) 57, 92, 45, 388.

If tunnel 1 and tunnel 3 are constructed, the correct answer is 57+(3*3+5*5)\*2+45=170

**\[Input\]**  
The first line contains a single integer T-the number of total test cases.  
Form the next line on, each test case will be given.  
The first line of each test case contains N, H, V.  
Throughout the following V lines, the hardness value of the construction area will be given.  
The next line contains C1, R1, M1 and the last line contains C2, R2, M2.

**\[Output\]**  
Print ‘#t’ (without the quotes) for test case t, leave a blank space and print the answer.  
(t refers to the test case number and starts with 1)



**input.txt**
5
1 3 1
42 3 99
4 19 3
4 1 5
1 5 1
1 4 1 3 11
7 2 3
2 6 4
2 5 4
1 4 1 3 11
13 5 1 4 11
1 2 3 4 5
99 2 47 3 31
7 2 3
2 6 5
1 4 1
1 2 3 4
7 3 3
2 9 4
3 256 7
150 120 63 3 48 129 133 123 116 110 127 67 21 93 122 1 144 167 2 77 77 92 47 160 28 151 98 90 96 104 107 98 98 52 129 123 64 79 151 111 93 161 117 91 87 129 13 137 29 86 154 134 147 77 105 113 117 64 95 3 68 42 144 149 118 135 134 82 166 5 133 102 19 75 109 122 72 14 19 161 133 79 76 81 16 89 54 151 4 20 160 166 18 135 150 138 130 131 162 125 164 125 19 7 28 63 107 153 91 153 142 62 39 20 15 155 77 58 115 126 44 59 118 141 99 16 104 16 158 57 45 148 101 80 9 145 99 126 59 90 158 108 103 110 95 32 28 21 154 40 114 157 79 129 19 12 88 16 157 1 25 2 145 107 85 79 24 78 69 39 153 66 88 107 86 76 88 144 154 91 114 63 157 12 35 34 7 125 103 128 101 16 162 6 120 145 64 29 55 134 154 52 56 32 132 111 126 71 160 5 98 38 115 78 89 18 122 116 125 145 27 75 44 95 151 126 17 95 85 163 38 48 153 75 139 163 142 37 164 113 76 40 46 152 24 103 140 47 98 3 161 151 48 80 131 3
100 94 142 144 95 80 116 61 57 86 159 120 33 112 120 154 143 91 161 17 69 152 135 114 77 136 10 89 14 23 152 116 93 124 93 133 8 77 145 85 33 116 4 160 61 113 119 90 160 144 16 135 20 136 120 60 54 167 51 155 16 22 101 112 69 142 136 91 10 113 23 143 70 111 151 155 47 87 97 82 6 104 52 62 142 96 80 78 143 62 27 65 139 56 26 41 15 159 147 140 16 80 88 117 110 126 3 129 78 43 103 71 145 148 133 82 167 136 41 89 77 2 74 93 141 28 140 162 74 58 146 55 76 59 87 39 140 61 128 107 45 90 89 95 28 4 87 129 1 61 6 161 135 146 46 166 141 146 6 33 136 79 64 27 47 41 114 75 100 107 112 121 35 94 156 103 153 81 128 125 45 96 127 129 156 139 167 103 3 79 59 122 44 34 67 150 16 130 137 132 121 23 2 37 11 60 143 46 5 35 64 85 72 144 53 33 86 131 48 42 13 25 8 67 22 154 46 121 133 12 63 86 12 155 48 3 94 83 2 84 119 135 33 9 52 159 120 122 132 91 60 142 35 11 81 13
116 110 111 76 57 56 151 152 164 63 74 24 151 158 125 82 50 27 97 88 93 163 66 110 143 136 34 157 127 167 3 140 24 28 110 93 46 67 124 83 28 84 48 162 4 72 15 134 33 78 79 163 32 78 76 123 160 59 59 51 21 46 18 137 89 143 41 149 91 11 126 41 161 100 88 94 150 85 83 18 125 128 57 4 83 118 109 159 138 167 56 87 144 136 109 62 7 104 65 101 115 91 136 158 48 45 105 130 18 10 51 114 166 31 37 164 119 66 70 147 116 151 60 48 59 16 166 110 98 41 32 104 48 132 75 68 56 33 141 122 46 97 13 2 80 24 152 87 20 163 137 129 86 46 80 36 98 71 93 124 59 97 24 23 16 159 12 147 63 21 123 126 90 127 113 107 5 95 162 72 27 47 64 81 156 68 73 9 99 109 132 9 38 127 146 55 80 94 125 76 41 149 145 38 157 40 129 54 140 101 85 108 55 58 48 122 152 112 159 115 22 2 75 43 8 3 129 146 7 155 129 108 105 69 22 53 45 73 92 11 156 56 164 38 117 29 62 70 85 122 51 58 73 158 46 45
154 107 130 1 24 125 124 97 61 148 30 148 57 97 166 115 84 118 138 24 164 158 57 89 149 19 91 123 154 141 154 75 110 39 63 13 99 117 8 7 130 62 75 95 61 113 160 41 72 88 2 121 7 7 25 74 94 144 77 95 99 51 149 127 98 41 9 160 30 105 30 142 80 112 79 82 63 78 100 40 113 19 143 70 165 96 100 164 111 108 131 6 47 147 153 66 27 106 65 116 84 134 83 104 1 167 167 154 1 124 75 130 57 72 76 101 57 50 159 167 154 111 106 148 72 87 102 2 117 4 161 32 31 132 62 74 103 146 18 147 82 106 130 105 136 65 13 130 167 153 57 97 19 31 42 96 48 28 5 12 145 52 19 128 8 75 8 32 9 17 107 115 78 110 10 27 67 52 117 2 148 20 56 141 159 58 145 152 14 155 148 45 103 116 16 134 84 84 143 72 95 131 165 105 62 51 5 32 152 104 82 12 56 165 30 154 73 130 44 138 45 148 128 56 67 75 93 39 93 161 157 52 55 148 149 48 82 114 118 95 73 39 28 11 46 59 126 69 45 166 92 64 119 88 116 38
62 155 84 59 82 25 121 36 1 39 45 131 78 73 56 26 71 62 167 135 74 78 67 155 50 59 137 131 145 15 25 157 69 58 78 60 52 167 16 130 92 27 65 101 96 103 8 84 29 77 134 115 165 125 91 150 39 26 122 59 4 72 80 152 55 109 92 63 48 166 26 108 11 50 11 154 113 76 164 49 22 14 28 33 108 63 103 165 152 156 6 57 9 159 79 30 128 70 138 15 11 74 19 156 154 154 74 44 113 158 133 57 39 81 76 166 165 25 26 88 112 155 23 57 5 109 2 39 123 53 120 146 151 69 100 20 72 101 52 14 74 150 26 138 22 162 20 32 28 103 20 2 60 77 20 12 8 87 128 100 53 88 30 77 111 157 23 133 28 69 152 62 145 77 103 99 91 24 142 21 163 86 24 9 86 84 7 65 133 86 158 2 123 143 27 121 6 113 77 154 110 145 152 142 113 67 157 15 129 115 108 32 129 129 86 102 70 125 125 144 100 163 125 44 82 13 122 72 14 136 31 119 117 163 52 58 89 109 35 72 159 25 10 129 56 117 161 22 136 126 102 4 58 4 8 62
133 157 25 154 118 27 100 4 37 10 75 8 63 119 122 125 158 97 70 122 77 159 15 46 67 157 59 83 94 62 133 26 62 26 2 41 29 84 32 151 4 48 11 82 88 148 41 129 161 19 100 48 57 37 159 87 119 75 113 13 26 49 32 151 11 83 43 131 100 96 131 82 78 20 101 80 18 43 101 153 107 125 40 36 130 161 77 135 144 13 139 145 47 111 142 23 98 28 4 142 151 18 31 49 129 150 117 134 38 49 108 98 67 127 88 95 64 62 93 147 42 150 103 84 7 55 120 161 131 91 128 147 160 107 16 84 13 40 90 30 110 132 89 6 52 123 167 28 27 82 116 119 56 13 66 91 100 20 121 159 133 70 48 14 115 46 144 55 40 10 12 3 119 3 144 61 167 152 62 163 158 149 56 125 25 13 46 152 81 42 82 153 18 147 100 123 8 47 49 95 103 23 62 50 26 157 41 146 159 37 118 73 158 91 139 2 98 165 156 71 11 153 118 115 142 16 40 16 25 19 44 152 44 55 81 22 156 128 99 84 98 47 31 164 33 104 124 130 76 108 134 43 14 46 48 20
84 52 113 22 87 72 113 71 90 167 40 89 5 6 82 74 40 32 138 53 58 6 122 164 83 86 111 84 18 149 138 52 139 11 128 26 82 10 51 47 156 63 96 110 65 21 86 117 17 117 154 26 141 17 19 158 88 134 44 63 88 86 92 63 17 164 119 28 109 98 133 98 36 92 141 134 164 156 94 86 122 14 62 75 21 90 36 74 46 153 81 40 116 73 96 114 121 160 83 163 19 72 40 94 14 57 14 100 102 166 126 24 158 113 166 161 141 101 114 80 32 71 101 132 70 128 42 102 64 93 105 10 76 56 158 3 51 33 127 63 75 26 108 16 52 114 3 59 48 29 97 15 133 19 136 71 79 64 132 94 44 142 163 139 108 110 91 165 2 148 73 43 50 90 20 18 11 5 95 33 19 146 73 58 28 82 14 55 76 95 10 67 45 162 25 79 9 122 148 166 29 38 77 139 93 59 43 123 163 144 129 72 63 123 72 125 44 155 57 27 129 21 28 4 37 156 163 110 142 11 80 151 57 60 26 45 71 111 65 34 48 80 47 19 101 127 67 34 156 15 110 156 39 119 87 18 
169 302 8
183 209 3	


**Output**
#1 576
#2 57
#3 170
#4 34
#5 11017631



## Approach 1
```cpp

#include <stdio.h>
int S[16][501];
int N,H,V;
int ans[16];
int final_min_cost= 60000000;// VERY_LARGE(taken around 60000000)
int new_cost;
int main()
{
	int i,j,k1,k2,v,T,test_case;
	int C1,C2,R1,R2,M1,M2;
	int max=60000000;// VERY_LARGE(60000000)
	int cost=0;
	int n1,n2,n3,n4,n5;
	scanf("%d",&T);
	for(test_case=1;test_case<=T;test_case++)
	{
		for(i=0;i<16;i++)
		{
			for(j=0;j<501;j++)
				S[i][j]=0;
		}
		for(i=0;i<16;i++)
			ans[i]=0;
		final_min_cost= 60000000;
		scanf("%d%d%d",&N,&H,&V);
		for(i=1;i<=V;i++)
		{
			for(j=1;j<=H;j++)
				scanf("%d",&S[i][j]);
		}
		scanf("%d%d%d",&C1,&R1,&M1);
		scanf("%d%d%d",&C2,&R2,&M2);

		// all inputs scanned..
		//Logic starts here
		for(v=1;v<=V;v++)  // for all the possible tunnels, find the min cost
		{
			max= 60000000;
			for(k1=0;k1<=H;k1++) // k1=0 means machine 1 works for 0 days
			{
				k2=H-k1; // k2 indicates the number of days machine 2 will work
				for(i=0;i<=k1;i++)
					cost = cost + (S[v][i]*C1);
				for(j=H;j>k1;j--)
					cost = cost + (S[v][j]*C2);
				// we have to add the cost for consecutive work.. that will be based on the number of days machine 1 and 2 have to work.. ie. k1 and k2
				if(k1>k2)// machine 1 has to work for more days than machine 2
					cost= cost + ((k1-k2-1)*R1);
				else if (k2>k1)// machine 2 has to work for more days than machine 1
					cost= cost + ((k2-k1-1)*R2);
				// this can be inferred from the example they have shown.. no need to take the combinations... since min cost will come if machines work alternate
				if(max>=cost)
					max=cost;
				cost=0; // for next iteration.
			}
			ans[v]=max; // for every possible tunnel, find the min cost
		}
		// we have to find the combination for N number of tunnels out of V possible tunnels such that cost is min
		if(N==1)
		{
			for(n1=1;n1<=V;n1++)
			{
				if(final_min_cost>=ans[n1])
					final_min_cost=ans[n1];
			}
		}
		else if(N==2)// 2 tunnels
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=V;n2++)
				{
					new_cost= ans[n1]+ans[n2]+ (M1*M1 + M2*M2)*(n2-n1);
					if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
				}
			}

		}
		else if(N==3) 
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=(V-((N-2)*2));n2++) // notice that n2<= V-((N-2)*2)... for n1 it is (N-1)
				{
					for(n3=n2+2;n3<=V;n3++)
					{
						new_cost= ans[n1]+ans[n2]+ ans[n3] + (M1*M1 + M2*M2)*(n3-n1); // last ie. n3 minus first ie. n1 (n3-n1)
						if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
					}
				}
			}
		}
	//	similarly... go for (N==4) and (N==5) // using nested loops :)
		else if(N==4)
		{
			for(n1=1;n1<=(V-((N-1)*2));n1++)
			{
				for(n2=n1+2;n2<=(V-((N-2)*2));n2++)
				{
					for(n3=n2+2;n3<=(V-((N-3)*2));n3++)
					{
						for(n4=n3+2;n4<=V;n4++)
						{
							new_cost= ans[n1]+ans[n2]+ ans[n3] + ans[n4] + (M1*M1 + M2*M2)*(n4-n1); // last ie. n4 minus first ie. n1 (n4-n1)
						if(final_min_cost>=new_cost)
						final_min_cost= new_cost;
						}
					}
				}
			}
		}
		else if (N==5)
		{
			//similar code
		}
		//in place of nested loops, you can find some other way to cover all the cases

			printf("#%d %d\n",test_case,final_min_cost);
	}
	return 0;
}
```



## Approach 2

```cpp
#include<iostream>
using namespace std;
int T, n, h, v, c1, r1, m1, c2, r2, m2;
int tunnels[16][501] = { 0 };
int tunnel_cost[16] = { 0 };
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		cin >> n >> h >> v;
		for (int i = 0; i < 16; i++){
			for (int j = 0; j < 501; j++){
				tunnels[i][j] = 0;
			}
		}
		for (int i = 0; i < 16; i++){
			tunnel_cost[i] = 0;
		}
		for (int i = 0; i < v; i++){
			for (int j = 0; j < h; j++){
				cin >> tunnels[i][j];
			}
		}
		cin >> c1 >> r1 >> m1 >> c2 >> r2 >> m2;

		for (int a = 0; a < v; a++){
			int max_cost = 99999999;
			for (int i = 0; i <= h; i++){
				int cost = 0;
				for (int j = 0; j < i; j++){
					cost += tunnels[a][j] * c1;
				}
				for (int k = i; k < h; k++){
					cost += tunnels[a][k] * c2;
				}
				int m1_days = i;
				int m2_days = h - i;
				if (m1_days>m2_days){
					cost = cost + r1*(m1_days - m2_days - 1);
				}
				else if (m1_days == m2_days){
					cost += 0;
				}
				else{
					cost = cost + r2*(m2_days - m1_days - 1);
				}
				//cout << i << ": " << cost << endl;
				if (cost < max_cost)
					max_cost = cost;
			}
			tunnel_cost[a] = max_cost;
			//cout << tunnel_cost[a] << endl;
		}
		int res = 9999999;
		if (n == 1){

			for (int a = 0; a < v; a++){
				if (tunnel_cost[a] < res)
					res = tunnel_cost[a];
			}
		}
		if (n == 2){
			for (int a = 0; a < v - 2; a++){
				for (int b = a + 2; b < v; b++){
					int temp = tunnel_cost[a] + tunnel_cost[b] + (m1*m1 + m2*m2)*(b - a);
					if (temp < res)
						res = temp;
				}
			}
		}
		if (n == 3){
			for (int a = 0; a < v - 4; a++){
				for (int b = a + 2; b < v - 2; b++){
					for (int c = b + 2; b < v; c++){
						int temp = tunnel_cost[a] + tunnel_cost[b] + tunnel_cost[c] + (m1*m1 + m2*m2)*(c - a);
						if (temp < res)
							res = temp;
					}
				}
			}
		}
		if (n == 4){
			for (int a = 0; a < v - 6; a++){
				for (int b = a + 2; b < v - 4; b++){
					for (int c = b + 2; b < v - 2; c++){
						for (int d = c + 2; d < v; d++){
							int temp = tunnel_cost[a] + tunnel_cost[b] + tunnel_cost[c] + tunnel_cost[d] + (m1*m1 + m2*m2)*(d - a);
							if (temp < res)
								res = temp;
						}
					}
				}
			}
		}
		if (n == 5){
			for (int a = 0; a < v - 8; a++){
				for (int b = a + 2; b < v - 6; b++){
					for (int c = b + 2; b < v - 4; c++){
						for (int d = c + 2; d < v - 2; d++){
							for (int e = d + 2; e < v; e++){
								int temp = tunnel_cost[a] + tunnel_cost[b] + tunnel_cost[c] + tunnel_cost[d] + tunnel_cost[e] + (m1*m1 + m2*m2)*(e - a);
								if (temp < res)
									res = temp;
							}
						}
					}
				}
			}
		}
		cout << "#" << t << " " << res << endl;
	}
	return 0;
}
```

## Approach 3
```cpp
#include <iostream>
using namespace std;
int N;
int H;
int V;
int ** matrix;
int * tunnel_cost;
int C!,R1,C2,R2,M1,M2;
int min_cost=2000000000;

void getMinTunnelCost(int tunnel){
	for(int i=0;i<H;i++){
		int working_days_M1=i;
		int working_days_M2=H-i;
		
		int cost;
		for(int j=0;j<working_days_M1;j++){
			cost +=matrix[tunnel][j]*C1;
		}
		for(int j=0;j<working_days_M2;j++){
			cost +=matrix[tunnel][H-j-1]*C2;
		}
		
		int add_cost=0;
		if(working_days_M1 > working_days_M2){
			add_cost=(working_days_M1-working_days_M2-1)*R1;
		}
		else(working_days_M2 > working_days_M1){
			add_cost=(working_days_M2-working_days_M1-1)*R2;
		}
		else{
			add_cost=0;
		}
		
		cost=cost+add_cost;
		if(tunnel_cost[tunnel] > cost){
			tunnel_cost[tunnel] = cost;
		}
	}
}

int abs(int x){
	if(x>0)
		return x;
	return(-1*x);
}

void select_tunnel(int tunnel, int cost, int left, bool* visited){
	if(left==0){
		if(cost < min_cost){
			min_cost=cost;
		}
		return;
	}
	
	visited[tunnel]=true;
	
	for(int i=0;i<V;i++){
		if(visited[i] && abs(tunnel-i)>= 2){
			select_tunnel(i,(cost+tunnel_cost[i]+(((M1*M1)+(M2*M2))*(abs(tunnel-i)))),left-1,visited);
		}
	}
}

int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>N;
		cin>>H;
		cin>>V;
		
		matrix = new int*[V];
		for(int i=0;i<V;i++){
			matrix[i] = new int[H]; 
		}
		for(int i=0;i<V;i++){
			for(int j=0;j<H;j++){
				cin>>matrix[i][j];
			}
		}
		cin>>C1;
		cin>>R1;
		cin>>M1;
		cin>>C2;
		cin>>R2;
		cin>>M2;
		
		tunnel_cost = new int[V];
		for(int i=0;i<V;i++){
			getMinTunnelCost(i);
		}
		
		bool* visited = new bool[V];
		
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				visited[j]=false;
			}
			select_tunnel(i,tunnel_cost[i],N-1,visited);
		}
		
		cout<<min_cost<<endl;
		min_cost=2000000000;
	}
	system("pause");
	return 0;
}
```

## 