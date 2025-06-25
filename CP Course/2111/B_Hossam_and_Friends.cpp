#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        int N,M,x,y; cin>>N>>M;
        vector<int> arr(N+2);

        for(int i = 1 ; i <= N ; ++i)
            arr[i] = N;

        while(M--){
            cin>>x>>y;x,y;
            if(x > y) swap(x, y);
            arr[x] = min(arr[x], y-1);   
        }

        for(int i = N - 1 ; i ; --i)
            arr[i] = min(arr[i], arr[i + 1]);
    

        long long sum=N;
        for(int i=1;i<=N;i++) {
            // cout<<arr[i]<<" ";
            sum+=arr[i]-i;
        };

        cout<<sum<<endl;
    }
}