#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& arr, int i, int j) {
    long long p = -1;
    for (int k = i; k <= j; ++k) {
    long long c = arr[k], n = p + 1;
    if (c < n) return false;
    p = (c == n || c > 2 * n) ? n : c;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int &x : arr) cin >> x;
        int s = 0;
        for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
        s+=check(arr, i,j);
        
        cout << s << endl;
    }
    return 0;
}