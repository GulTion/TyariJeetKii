#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    vector<int> a(N, 0), b(N,0); 
    for(int i=0;i<N;++i) cin>>a[i];
    for(int i=0;i<N;++i) cin>>b[i];

    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
    
    for(int i=a[0];i<=b[0];i++) ++dp[0][i];

    for(int i=1;i<N;++i){
        for(int j=a[i];j<=b[i];++j){
            
        }
    }


    return 0;
}