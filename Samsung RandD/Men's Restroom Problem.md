---
status: Complete
---


## Problem Description

In a restroom with a certain number of stalls, visitors prefer to maximize their distance from already occupied stalls. The strategy is to occupy the middle of the longest sequence of unoccupied stalls.

Given the number of stalls, simulate the process of visitors entering the restroom and occupying stalls according to the described strategy.

## Input

-   The input consists of a single integer representing the number of stalls.

### Example

#### Input

```
10 10
```

#### Output

```
_ _ _ _ X _ _ _ _ _
_ _ _ _ X _ _ X _ _
_ X _ _ X _ _ X _ _
_ X _ _ X _ _ X X _
_ X _ _ X X _ X X _
_ X X _ X X _ X X _
_ X X _ X X _ X X X
_ X X _ X X X X X X
_ X X X X X X X X X
X X X X X X X X X X
```

## Output Format

-   Each line represents the stalls' status after each visitor occupies a stall.
-   Use `_` for unoccupied stalls and `X` for occupied stalls.

## Approach 1 (No Space)
```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        while (k--)
        {
            int mxLen = 0, lastIdx, cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (v[i] == 0)
                    cnt++;
                else
                    cnt = 0;
                if (cnt >= mxLen)
                {
                    mxLen = cnt;
                    lastIdx = i;
                }
            }
            int s = lastIdx - mxLen + 1;
            int md = (lastIdx + s) / 2;
            v[md] = 1;
        }
        for (int i = 0; i < n; i++)
            cout << v[i];
        cout << endl;
    }
    return 0;
}

```

## Approuch 2 (GulTion's) (With Queue)
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<char> arr(n, '_');
    queue<pair<int, int>> q;
    q.push({0, n});
    while(!q.empty()&&k>=0){
        auto [a,b]=q.front();
        q.pop();
        if(a>b) continue;
        for(char c:arr) cout<<c;cout<<endl;
        k--;
        int c=(a+b)>>1;
        arr[c]='X';
        q.push({a,c-1});
        q.push({c+1,b});
    }

    return 0;
}

```