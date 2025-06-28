#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    char cell;
    cin >> n >> m >> k;
    
    map<string, int> dp;

    for (int i = 0; i < n; ++i) {
        string row;
        cin>>row;
        dp[row]++;
    }

    int ans = 0;

    for (auto const& [row , count] : dp) {
        int zero = 0;
        for (char c : row ) zero+=c=='0';

        if (zero <= k && (k - zero) % 2 == 0) 
            ans = max(ans, count);

    }

    cout << ans << endl;

    return 0;
}