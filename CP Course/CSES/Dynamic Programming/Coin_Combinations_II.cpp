#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int C, N;
    cin >> C >> N;
    vector<int> coins(C);
    for (int i = 0; i < C; i++) cin >> coins[i];

    vector<vector<int>> dp(C + 1, vector<int>(N + 1, 0));

    // Base case: there's 1 way to make sum 0 with any number of coins
    for (int i = 0; i <= C; i++) dp[i][0] = 1;

    for (int c = C - 1; c >= 0; --c) {
        for (int i = 0; i <= N; ++i) {
            // ways without current coin
            dp[c][i] = dp[c + 1][i];
            // ways with current coin if possible
            if (i - coins[c] >= 0) {
                dp[c][i] = (dp[c][i] + dp[c][i - coins[c]]) % MOD;
            }
        }
    }

    cout << dp[0][N] << endl;
    return 0;
}
