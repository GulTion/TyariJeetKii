#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        float x,y;
        vector<int> arr(n);
        for(int &i:arr) cin>>i;

        y = (2*arr[0] - arr[1])/(n+1)*1.0;
        x = arr[0] - n*y;

        bool f = true;
        if(x<0 || y < 0) f=false;
        for(int i=1;i<=n&&f;++i){
            if(((i*x)+(n-i+1)*y)!=arr[i-1]){
                f = false; break;
            }
        }

        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        // cout<<x<<" "<<y<<endl;
    }
}