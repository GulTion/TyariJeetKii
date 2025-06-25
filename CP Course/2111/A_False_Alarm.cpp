#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
       int n, x,i; cin>>n>>x;
       int sum=0;
       while(n--){
        cin>>i; sum<<=1; sum+=i;
       }

       while(sum>=0 && sum%2==0) sum>>=1;

       int b = ceil(log2(sum*1.0));
       if(b<=x) cout<<"YES";
       else cout<<"NO";
       cout<<endl;

    }

    return 0;
}