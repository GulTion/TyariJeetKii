#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,N; cin>>T;
    while(T--){
        cin>>N;
        vector<int> arr(N, 0);
        for(int i=0;i<N;++i) cin>>arr[i];

        int i=0,ans=0;
        for(int j=0;j<N;++j){
            if((arr[i]+1)<arr[j]){
                i=j;
                // cout<<arr[i]<<" ";
                ++ans;
            }
        }
        cout<<ans+1<<endl;
    }

    return 0;
}