#include <bits/stdc++.h>

using namespace std;

void dfs(char ** arr, int M, int N, int r, int c){
    if(r>=M||c>=N||r<0||c<0||arr[r][c]!='.'){
        return;
    }

    arr[r][c]='#';

    dfs(arr, M,N,r-1,c);
    dfs(arr, M,N,r,c-1);

    dfs(arr, M,N,r+1,c);
    dfs(arr, M,N,r,c+1);

}

int main(){
    int M,N;
    cin>>M>>N;
    
    char** arr = new char*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new char[N];
    }

    for(int i=0;i<M;i++) for(int j=0;j<N;j++) cin>>arr[i][j];

    int rooms=0;
    for(int i=0;i<M;i++) for(int j=0;j<N;j++){
        if(arr[i][j]=='.'){
            dfs(arr, M,N,i,j);
            ++rooms;
        }
    }
    cout<<rooms;
    return 0;
}