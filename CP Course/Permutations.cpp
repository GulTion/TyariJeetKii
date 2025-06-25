#include<bits/stdc++.h>
using namespace std;
int icalled=0;
int f(int n, int mask, vector<vector<int>> &dp){
    int i = __popcount(mask);
    if(i==n) return 1;
    if(dp[i][mask]!=-1) return dp[i][mask];
    
    ++icalled;
    int sum=0;
    for(int j=0;j<n;++j){
        if(!(mask&(1<<j)))
            sum += f(n, mask|(1<<j),dp);
    }
    return dp[i][mask]=sum;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));

    cout<<f(n,0, dp)<<endl;
    cout<<icalled<<endl;
    return 0;
}