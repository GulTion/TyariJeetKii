#include<bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
int main(){
    long long n,a,b,t;cin>>n;a=1, b=0;
    while(--n){
        t = ((2LL * a) % MOD + b) % MOD;
        b = (3LL * a ) % MOD;
        a = t;
    }
    cout<<b;
    
    return 0;
}