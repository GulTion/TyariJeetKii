#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, N, A, B, C, D;
	cin >> t;
	while (t--) {
		cin >> N >> A >> B >> C >> D;
		int res = 0;
		for (int z = 0; z <= N; z++) {
			int o = N - z;
			res = max({res, A*z + B*o + C*z*o, A*z + B*o + D*z*o});
		}
		cout << res << endl;
	}
}
