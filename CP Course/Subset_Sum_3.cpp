#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	int n,x,sum=0;
	  
    cin >> n;
    int _0 = 0;
    int _1 = 0;
    int _2 = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int rem = x % 3;
        if (rem == 0) _0++;
        else if (rem == 1) _1++;
        else _2++;
    }

    if (_0 > 0 ||(_1 > 0 && _2 > 0) ||_1 >= 3 ||_2 >= 3) cout << "Yes\n";
    else cout << "No\n";
}
	}
	
