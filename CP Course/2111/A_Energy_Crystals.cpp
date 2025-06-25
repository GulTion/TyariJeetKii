#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,x; cin>>t;
    while(t--){
        int sum=1; cin>>x;
        while(x){
            x/=2;
            ++sum;
        }
        cout<<(2*sum -1)<<endl;

    }
}