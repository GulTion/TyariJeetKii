
A company has to produce IOT products of different models,
Each product requires cpus,memories and boards. After production of models, some spare equipments may be left.
In these, cpus and memories can be sold as spare parts but boards cannot be sold.
Due to manufacturing constraints maximum 3 models can be produced.
Each product can be sold at the cost of its model.
Given N different models.
D cpus with price d each.
E memories with price e each.
F boards.

Input:-
T number of testcases, followed by testcases,
Each test case consists of
D total  number of cpus available.
E total number of memories available.
F total number of boards available.
N number of models followed by N lines consisting of
ai, bi, ci and pi where ai is the number of cpus,bi number of memories, ci number of boards
required for producing one unit of that model and pi is the selling price of the one unit of that model.

Output:-
Print the testcase number followed by the Maximum profit that can be made.

Note:- Maximum profit can also be attained without any production that is by just selling  its components.

Constraints:-
1 ≤ N ≤ 8,  1 ≤ D,E,F ≤ 100,  1 ≤ d,e ≤ 10,  1 ≤ ai,bi,ci ≤ 5,  1 ≤ pi ≤ 100

Complexity
----------------------

Simply question is :
	we need to choose up to 3 out of 8 (0-3)products, 
Answer = Value of products+ remaining CPU*CPU_COST+remaining MEMORY*MEM_COST

Lets try to calculate complexity for brute force approach.

1.We need to choose max 3 out of 8 products, so for that complexity is 8c3=56

2. (taking product-1 out of chosen products from 0 to MAX possible if we take only this product)*(taking product-1 out of chosen products from 0 to MAX possible if we take only this product)*(taking product-1 out of chosen products from 0 to MAX possible if we take only this product) = (100*100*100)
 
So final complexity is  = 8c3*100*100*100 < 10^9.

3. So If complexity is less than 10^9 we can freely go ahead


Input:
--------
7
2 2 2 1 1
1
2 2 2 6
5 10 10 1 1       
2
2 1 1 8
1 1 1 6
10 10 10 2 1      
1
1 2 2 3
4 6 4 2 1         
4
2 4 2 9
1 3 1 7
2 1 1 8
1 2 2 6
40 80 60 1 3      
7
3 2 2 56
5 4 2 12
3 5 3 65
1 2 5 78
5 5 2 85
4 2 3 76
5 5 1 48
100 100 100  6 10      
8
3 3 1 74
2 3 1 41
3 2 1 64
2 2 3 68
2 2 2 71
2 3 2 66
2 3 3 84
3 3 1 48 
100 100 100 1 1
8
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

Output:

#1 6
#2 35
#3 30
#4 21
#5 1338
#6 3550
#7 200

--------------------------------------------
Time taken including input reding.
#1  time = 0.002
#2 time = 0.002
#3 time = 0.001
#4 time = 0.003
#5 time = 0.064
#6 time = 0.203
#7 time = 0.001

Precautions to take care:
--------------------------------

1.Question asked is we need to choose up to 3 out of 8 products, means we can choose no product also and sell all individual components.

2. When choosing a product we need to check whether the component I am spending for this product worth more than if I sell individual products, if not ignore product completely

3.When we apply 3 for loops to generate 8c3 combination, we need to consider N<3 also

4. Always calculate time roughly before selecting approach as explained above.


## Approuch 1
```cpp

#include<stdio.h>
int D, E, F, d, e, n;
int mat_model[9][4];
int max_model[9];
int check(int a,int b,int c,int i,int j,int k){
	int retVal = 0;
	if (((mat_model[a][0] * i) + (mat_model[b][0] * j) + (mat_model[c][0] * k)) > D ||
		((mat_model[a][1] * i) + (mat_model[b][1] * j) + (mat_model[c][1] * k)) > E ||
		((mat_model[a][2] * i) + (mat_model[b][2] * j) + (mat_model[c][2] * k)) > F){
		return 0;
	}
	int remD = D - ((mat_model[a][0] * i) + (mat_model[b][0] * j) + (mat_model[c][0] * k));
	int remE = E - ((mat_model[a][1] * i) + (mat_model[b][1] * j) + (mat_model[c][1] * k));
	retVal = (mat_model[a][3] * i) + (mat_model[b][3] * j) + (mat_model[c][3] * k) + remD*d + remE*e;
	return retVal;
}
int compute(int a, int b, int c){
	int val = 0;
	for (int i = 0; i < max_model[a]+1; i++){
		for (int j = 0; j < max_model[b]+1; j++){
			for (int k = 0; k < max_model[c]+1; k++){
				int cost = check(a, b, c, i, j, k);
				if (cost>val){
					val = cost;
				}
			}
		}
	}
	return val;
}
int process(){
	int ans = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				int value = compute(i, j, k);
				if (value>ans){
					ans = value;
				}
			}
		}
	}
	return ans;
}
int main(){
	int T;
	freopen("Text.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++){
		scanf("%d%d%d%d%d%d", &D, &E, &F, &d, &e, &n);
		for (int i = 0; i < n; i++){
			scanf("%d%d%d%d", &mat_model[i][0], &mat_model[i][1], &mat_model[i][2], &mat_model[i][3]);
		}
		for (int i = 0; i < n; i++){
			int x = D / mat_model[i][0];
			int y = E / mat_model[i][1];
			int z = F / mat_model[i][2];
			if (x < y&&x < z){
				max_model[i] = x;
			}
			else if (y < x&&y < z){
				max_model[i] = y;
			}
			else{
				max_model[i] = z;
			}
		}
		printf("#%d %d\n", test_case, process());
	}

}
```


## Approch 2
```cpp
#include<iostream>
using namespace std;
int MEM;
int CPU;
int BOARD;
int CPU_SP;
int MEM_SP;
int N;
int max_profit =-1;
class Product{
	public:
	    
		 int cpus;
		 int mem;
		 int boards;
		 int sp;
		 
		 Product(){}
		 
		 Product(int a,int b,int c,int d)
		 {
			 cpus=a;
			 mem=b;
			 boards=c;
			 sp=d;
		 }
};
Product* model;

int* max_production;

int get_max(Product p)
{
	int count =0;
	int memory = MEM;
	int cpus = CPU;
	int boards = BOARD;
	
	while(p.mem <= memory && p.cpus <= cpuss && p.boards <= boardss)
	{
		memory = memory - p.mem;
		cpuss = cpuss - p.cpus;
		boardss = boardss - p.boards;
		
		count++;
	}
	return count;
}

void getCost(int* product_array,int* max_array,int size)
{
	if(size == 1)
	{
		Product p = model[product_array[0]];
		
		for(int i = 1;i<=max_array[0];i++)
		{
			int profit = 0;
			int temp1 = CPU;
			int temp2 = MEM;
			
			profit = profit + (i*(p.sp));
			temp1 = temp1 - (i*(p.cpus));
			temp2 = temp2 - (i*(p.mem));
			
			profit = profit + ((CPU_SP)*temp1) + ((MEM_SP)*temp2);
			
			if(profit>max_profit)
			{
				
				max_profit = profit;
				
			}
			
		}
	}
	
	else if(size == 2)
	{
		for(int i = 1;i<= max_array[0];i++)
		{
			Product p = model[product_array[0]];
			
			for(int j=1;j<=max_array[1];j++)
			{
				Product q = model[product_array[1]];
				
				int profit = 0;
				int temp1 =CPU;
				int temp2 = MEM;
				int temp3 =BOARD;
				
				temp1 = temp1 - (i*(p.cpus)) - (j*(q.cpus));
				temp2 = temp2 - (i*(p.mem)) - (q.mem));
				temp3 = temp3 - (i*(p.boards)) - (j*(q.boards));
				
				if(temp1 >= 0 && temp2 >= 0 && temp3 >=0)
				{
					profit = profit + (i*(p.sp)) + (j*(q.sp));
					
					profit = profit + ((CPU_SP)*temp1) + ((MEM_SP)*temp2);
					
					if(profit > max_profit)
					{
						max_profit = profit;
						
					}
				}
			}
		}
	}
	
	else if(size == 3)
	{
		for(int i = 1;i<= max_array[0];i++)
		{
			Product p = model[product_array[0]];
			
			for(int j=1;j<=max_array[1];j++)
			{
				Product q = model[product_array[1]];
				for(int k=1;k<max_array[2];k++)
				{
					Product r = model[product_array[2]];
					
					int profit = 0;
					int temp1 = CPU;
					int temp2 = MEM;
				    int temp3 =BOARD;
					
					temp1 = temp1 - (i*(p.cpus)) - (j*(q.cpus)) - (k*(r.cpus));
					temp2 = temp2 - (i*(p.mem)) - (j*(q.mem)) - (k*(r.mem));
					temp3 = temp3 - (i*(p.boards)) - (j*(q.boards))- (k*(r.boards));
					
					if(temp1 >= 0 && temp2 >= 0 && temp3 >=0)
					{
						
						profit = profit + (i*(p.sp))+(j*(q.sp))+(k*(r.sp));
						
						profit = profit + ((CPU_SP)*temp1) + ((MEM_SP)*temp2);
						
						if(profit > max_profit)
						{
							
							max_profit = profit;
						}
					}
				
				}
		}
		}
	}
}


void choose_util(int product_no,int count,bool* visited,int nos)
{
	visited[product_no] = true;
	
	if(count == 0)
	{
		
		int product_array[3];
		int max_array[3];
		
		for(int i=0; i<3 ;i++)
		{
			max_array[i] = -1;
			product_array[i] = -1;
		}
		
		int product_array_size =0;
		
		for(int i=0; i< N ;i++)
		{
			if(visited[i])
			{
				product_array[product_array_size] = i;
				product_array_size++;
			}
		}
		
		for(int i =0 ; i < product_array_size;i++)
		{
			max_array[i] = max_production[product_array[i]];
		}
		
		getCost(product_array , max_array , product_array_size);
		
		
		
		
		
		
		
	}
	
	else
	{
		for(int i = product_no + 1; i< N ;i++)
		{
			if(!visited[i])
			{
				choose_util(i,count - 1, visited,nos);
			}
			
		}
		
	}
	visited[product_no] = false;
}

void choose(int no_of_products)
{
	bool* visited = new bool[N];
	for(int i = 0;i < N;i++)
	{
		visited[i] = false;
	}
	
	if(no_of_products == 0)
	{
		int profit = 0;
		profit= profit + (CPU)*(CPU_SP)+(MEM)*(MEM_SP);
		
		if(profit > max_profit)
		{
			max_profit = profit;
		}
		return;
	}
	if(no_of_products <= N)
		
		{
			
			for(int i=0; i< N;i++)
			{
				if(!visited[i])
				{
					choose_util(i,no_of_products - 1,visited ,no_of_products);
				}
			}
		}
}

int main()
{
	int T;
	cin>> T;
	for(int i=1;i <= T;i++)
	{
		cin>>CPU;
		cin>>MEM:
		cin>>BOARD;
		cin>>CPU_SP;
		cin>>MEM_SP;
		cin>>N;
		
		model = new Product[N];
		
		int a,b,c,d;
		
		for(int i=0;i<N;i++)
		{
			cin>>a;
			cin>>b;
			cin>>c;
			cin>>d;
			model[i] = Product(a,b,c,d);
		}
		max_production = new int[N];
		for(int i=0;i < N;i++)
		{
			max_production[i] = get_max(model[i]);
		}
		for(int i=0; i<=3 ;i++)
		{
			choose(i);
		}
		 cout<<"#"<<i<<" "<<max_profit <<endl;
		 max_profit = -1;
	}
	system("pause");
	return 0;
}
		
		
						

	
	
```