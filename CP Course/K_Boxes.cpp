#include <bits/stdc++.h>
using namespace std;

struct TP {
    int i;
    int a;
    int b;
    long long r;
};

struct Compare {
    bool operator()(const TP& x, const TP& y) {
        return x.b > y.b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];

        vector<TP> arr;
        for (int i = 0; i < N; ++i) arr.push_back({i, A[i], B[i], 0});

        sort(arr.begin(), arr.end(), [](const TP& x, const TP& y) { return x.a < y.a; });

        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0;

        for (int i = 0; i < N; ++i) {
            arr[i].r = sum;
            if ((int)q.size() < K) {
                q.push(arr[i].b);
                sum += arr[i].b;
            } else if (!q.empty() && q.top() < arr[i].b) {
                sum -= q.top();
                q.pop();
                sum += arr[i].b;
                q.push(arr[i].b);
            }
        }

        sort(arr.begin(), arr.end(), [](const TP& x, const TP& y) { return x.i < y.i; });
        for (int i = 0; i < N; ++i) cout << arr[i].r << " ";
        cout << '\n';
    }

    return 0;
}
