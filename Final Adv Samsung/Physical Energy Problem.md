
You have a certain amount of energy and need to travel a specific distance. You can choose from five different speeds to travel, each with its own energy cost and time taken per kilometer.

Your goal is to minimize the total time required to cover the distance, ensuring that you do not exceed the available energy.

### Given

1. An initial amount of energy `H`.
2. A total distance `D` to travel.
3. Five speeds, each with associated:
    - **Cost of traveling 1 km** (energy required per km).
    - **Time taken to travel 1 km** (time required per km).

### Input
- An integer `N` representing the number element in `cost` and `time` array
-   An integer `H` representing the initial amount of energy.
-   An integer `D` representing the total distance to be traveled.
-   A list of five integers representing the energy cost to travel 1 km for each speed.
-   A list of five integers representing the time taken to travel 1 km for each speed.

### Example

#### Input

```
5 15 4
4 5 2 3 6
200 210 230 235 215
```

#### Output
```
830
```

## 2D DP code (@GulTion)
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, H, D;
    cin >> N >> H >> D;

    vector<int> cost(N), time(N);
    for (int i = 0; i < N; i++) cin >> cost[i]; // Energy cost per km
    for (int i = 0; i < N; i++) cin >> time[i]; // Time taken per km

    // DP table: dp[i][j] -> Min time to travel j km with at most i energy
    vector<vector<int>> dp(H + 1, vector<int>(D + 1, INT_MAX));

    // Base case: 0 km requires 0 time for any energy level
    for (int i = 0; i <= H; i++) dp[i][0] = 0;

    for (int j = 1; j <= D; j++) {  // Distance loop
        for (int i = H; i >= 0; i--) {  // Energy loop (reverse for correctness)
            for (int k = 0; k < N; k++) {  // Speed options
                if (i >= cost[k] && dp[i - cost[k]][j - 1] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i - cost[k]][j - 1] + time[k]);
                }
            }
        }
    }

    // Find the minimum time for reaching distance D with any allowed energy
    int result = INT_MAX;
    for (int i = 0; i <= H; i++) result = min(result, dp[i][D]);

    cout << (result == INT_MAX ? -1 : result) << endl; // If not possible, return -1

    return 0;
}

```



```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,H,D;
    cin>>N>>H>>D;
    vector<int> cost(N), speed(N);
    for(int &i:cost) cin>>i;
    for(int &i:speed) cin>>i;

    function<int(int, int)> dfs = [&](int h, int d){
        if(d==D) return 0;
        // if(h>H) return INT_MAX;
        int ans = INT_MAX;
        for(int i=0;i<N;i++){
            if((cost[i]+h)<=H) {
                int res = dfs(cost[i]+h, d+1);
                if(res!=INT_MAX) ans = min(ans, res+speed[i]);}
        }
        return ans;
    };

    cout<<dfs(0, 0);

    return 0;
}
```