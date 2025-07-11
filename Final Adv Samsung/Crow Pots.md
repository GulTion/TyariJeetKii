---
explored: true
status: Complete
---

There are N pots. Every pots has some water in it. They may be partially filled.

Every pot is associated with overflow number O which tell how many minimum no. of stones required

for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K

pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

  

Array of overflow no--. {1,...,On}

Number of pots--n

No of pots to overflow-- k

  

Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1).

So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in

pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.


```cpp
#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1009];
int dp[1009][1009]; // memoization array

int rec(int i, int j) {
    if (j == 1) return a[i] * (n - i + 1);
    if (dp[i][j] != -1) return dp[i][j];

    int res = INT_MAX;
    for (int k = i + 1; k <= n; k++) {
        int cost = rec(k, j - 1) + (k - i) * a[i];
        res = min(res, cost);
    }
    return dp[i][j] = res;
}

void solve(int test_case) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        ans = min(ans, rec(i, m));
    }

    cout << "#" << test_case << " " << ans << endl;
}

int main() {
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        solve(test_case);
    }
    return 0;
}

```



```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int ans = 0;
    int d = n - 1;
    while (k--)
    {
        for (int i = 0; i < n; i++)
        {
            ans += a[d];
            a[i] -= a[d];
        }
        d--;
    }
    cout << ans << endl;
    return 0;
}
```

