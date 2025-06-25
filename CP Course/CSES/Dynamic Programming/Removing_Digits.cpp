#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N; 

    vector<int> dp(N + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j > 0; j /= 10) {
            int digit = j % 10;
            if (digit != 0) {
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }

    cout << dp[N] << endl;
    return 0;
}
