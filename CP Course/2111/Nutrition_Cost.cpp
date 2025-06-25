#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while (T--) {
         int N, C;
    cin >> N >> C;

    vector<int> A(N),B(N),mc(N + 1, 101);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) mc[A[i]] = min(mc[A[i]], B[i]);

    long long sum = 0;
    for (int i = 1; i <= N; ++i) sum += max(0, C - mc[i]);
    cout << sum << endl;
    }

    return 0;
}