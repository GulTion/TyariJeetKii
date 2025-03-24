---
explored: true
---

You want to cut a piece of paper by a certain fixed rule to make some pieces of white or 
blue colored square paper with various sizes.  
 
If the size of the entire paper is N×N (N = 2^K; 1 <= K <= 7; K = natural number), the cutting rules
are as below.
 
‘If the entire piece of paper is not colored the same, cut the middle part horizontally and vertically 
to divide it into the same sized four pieces of paper, 
(N/2)×(N/2), as with I, II, III, IV in < FIG. 2 >. 

For each I, II, III and IV, cut and divide again in the same way if one entire piece of paper 
is not colored the same, and make them into the same sized four pieces of paper. Continue until each and 
every piece of paper has only one color of white or blue.’
 
When you finish, < FIG. 3 > shows the first division of < FIG. 1 > and < FIG. 4 > 
shows the final version of 9 pieces of white paper and 7 pieces of blue paper of various sizes.
 
If the length of an edge of the first given piece of paper, N, and 
the color information (white or blue) inside each square are given, create a calculation program
 that assesses how many white/blue pieces of paper are.
 
Time limit: 1 second (java: 2 seconds) 
 
[Input]
 
Input may include many test cases. The number of test cases, T, is given on the first line of input and then the amount of T of test cases is given in a line. (T <= 30)
The length of an edge of the first given piece of paper, N, is given for the first line of each test case.
From the next line through to the amount of N lines, the color information is given separately as blanks. 0 indicates white and 1 indicates blue.
 
[Output]
 
For each test case, you should print "Case #T" in the first line where T means the case number. 
 
For each test case, you should output the number of white pieces of paper and blue pieces of paper separately as blanks on the first line of each test case.
 
[I/O Example]
Input 
2
8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1 
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
 
 
16
1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1
1 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 1 1 1 0 0 1 0 0 1
1 1 0 0 1 0 0 1 0 0 1 0 1 1 1 0
0 1 1 1 0 0 1 1 0 0 1 0 0 1 1 1
1 0 1 1 0 0 0 1 0 1 0 1 0 0 1 1
1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 0
1 1 0 1 0 1 0 0 1 0 1 1 1 0 0 1
1 1 1 1 1 1 0 0 1 0 1 1 0 1 1 0
1 0 0 1 1 1 0 0 0 0 1 1 1 1 0 0
1 0 0 1 1 1 1 0 0 0 1 1 0 1 0 1
1 1 1 0 1 1 0 0 1 1 1 1 1 1 0 1
1 1 1 1 1 1 0 0 0 0 1 1 1 1 0 0
1 1 1 1 1 1 0 1 1 1 1 1 1 1 0 0
1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 0
1 1 0 0 1 1 0 0 0 1 1 1 1 0 0 0
 
 
 
Output
 
Case #1
9 7
 
Case #2
88 99



Solution : 
## Approuch 1
```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
const int maxn = 129;
int white = 0, blue = 0;

bool checkSame(bool arr[maxn][maxn], int sti, int stj, int size)
{
	bool color = arr[sti][stj];
	for(int i = sti; i < sti + size; i++){
		for(int j = stj; j < stj + size; j++){
			if(arr[i][j] != color){
				return false;
			}
		}
	}
	return true;
}

void solve(bool arr[maxn][maxn], int size, int sti, int stj)
{
	bool same = checkSame(arr, sti, stj, size);
	
	if(!same){
		solve(arr, size / 2, sti, stj);
		solve(arr, size / 2, sti + size/2, stj);
		solve(arr, size / 2, sti, stj + size/2);
		solve(arr, size / 2, sti + size/2, stj + size/2);
	}
	else{
		(arr[sti][stj]) ? ++blue : ++white ;
	}
}

int main()
{
	int test ;
	cin >> test ;
	for(int l = 1; l <= test; l++){
		white = 0;
		blue = 0;
		int size ;
		cin >> size;
		bool arr[maxn][maxn];
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				cin >> arr[i][j] ;
			}
		}
		solve(arr, size, 0, 0);
		cout << "Case #" << l << endl;
		cout << white << " " << blue << endl;
	}
	return 0;
}
```

## Approch Prefix sum
// optimized approach using prefix sum of matrix
```cpp
#include <iostream>
using namespace std;
const int maxn = 129;
int white = 0, blue = 0;
void solve(int arr[maxn][maxn], int size, int si,int sj)
{
    if( size == 0)
    return;
    int sum = arr[size + si - 1][size + sj - 1];
    if(sj - 1 >= 0)
    sum -= arr[size + si - 1][sj - 1];
    if(si - 1 >= 0)
    sum -= arr[si - 1][sj + size - 1];
    if( si - 1 >= 0 && sj - 1 >= 0)
    sum += arr[si - 1][sj - 1];
    if(si == 4 && sj == 1)
    cout<<sum<<endl;
    if(sum == 0)
    {
       // cout<<si<<"white"<<sj<<" "<<size<<" "<<white<<endl;
        white++;
        return;
    }
    if(sum == size * size)
    {
     //cout<<si<<"blue"<<sj<<" "<<size<<" "<<blue<<endl;
     blue++;
     return;
    }
    solve(arr, size / 2, si, sj);
    solve(arr, size / 2,  si + size/2, sj);
    solve(arr, size / 2, si, sj + size/2);
    solve(arr, size / 2, si + size / 2, sj + size / 2);
}
int main() {
    int test ;
	cin >> test ;
	for(int l = 1; l <= test; l++){
		white = 0;
		blue = 0;
		int size ;
		cin >> size;
		int arr[maxn][maxn];
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
                int a;
                cin>>a;
                if( i == 0 && j == 0)
                 arr[i][j] = a;
                else if( i == 0)
                arr[i][j] = a + arr[i][j - 1];
                else if( j == 0)
                arr[i][j] = a + arr[i - 1][j];
                else
                arr[i][j] = a + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
			}
		}
		solve(arr, size, 0, 0);
		cout << "Case #" << l << endl;
		cout << white << " " << blue << endl;
	}
	return 0;
}

```

## Apruch 3
```cpp

#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #define mod 1000000007
// #define all(v) v.begin(),v.end()
// #define endl '\n'

bool check(int row, int col, int n, vector<vector<int>> matrix)
{
    set<int>s;
    for(int i=row;i<row+n;i++){
        for(int j=col;j<col+n;j++){
            s.insert(matrix[i][j]);
        }
    }
    if(s.size()==1){
        return true;
    }
    else{
        return false;
    }
}

void f(int row, int col, int n, vector<vector<int>> matrix,pair<int,int> &p)
{
    if(check(row,col,n,matrix)){
        if(matrix[row][col]==1){
            p.first= p.first+1;
        }
        else{
            p.second = p.second + 1;
        }
        return;
    }
    else{
        n=n/2;
        // divide into 4 parts
        f(row,col,n,matrix,p);
        f(row+n,col,n,matrix,p);
        f(row,col+n,n,matrix,p);
        f(row+n,col+n,n,matrix,p);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;while(t--){
        int n;
        cin>>n;
        vector<vector<int>> matrix(n,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }

        int blue=0;
        int white=0;
        pair<int,int> p;
        p.first=blue;
        p.second=white;
        f(0,0,n,matrix,p);
        cout<<p.second<<" "<<p.first<<endl;
    }
}



```