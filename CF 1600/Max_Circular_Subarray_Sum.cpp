#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    int N;cin>>N;

    while(T--){
        int sum=0,maxi=INT_MIN;
        vector<int> arr(N);
        for(int i=0;i<N;i++) cin>>arr[i];

        for(int i=0;i<2*N;i++){
            sum+=max(arr[i%N],0);
            maxi=max(maxi, sum);
        }

        cout<<maxi<<endl;

    }


    return 0;
}