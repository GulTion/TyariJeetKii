#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100001;
int dp[N];

int main(){
    int t, k, a, b;
    cin >> t >> k;

    dp[0] = 1;
    for(int i = 1; i < N; ++i) {
        if(i < k) dp[i] = dp[i - 1];
        else dp[i] = (dp[i - 1] + dp[i - k]) % MOD;
    }

    // Prefix sum for fast range queries
    for(int i = 1; i < N; ++i) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    while(t--){
        cin >> a >> b;
        cout << (dp[b] - dp[a - 1] + MOD) % MOD << endl;
    }

    return 0;
}
