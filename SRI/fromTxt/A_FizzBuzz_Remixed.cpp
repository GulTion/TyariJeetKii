#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        int a = N/15;
        int r = N%15;
        r = (r>2)?3:r+1;
        cout<<a*3+r<<endl;
    }
    return 0;
}