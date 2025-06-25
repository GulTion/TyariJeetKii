#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin>>T;
    int N, K;
    string S;
    while(T--){
        cin >> N >> K;
        cin >> S;

        int a = 0; 
        int b = 0; 
        for(auto i : S){
            if (i == '1') {
                a++;
            } else {
                b++;
            }
        }
        
        int k = abs(a - b);
        k >>= 1;
        
        if (K < k || (K - k) % 2 != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}