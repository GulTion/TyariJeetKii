#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T, N, X; cin>>T;
    while(T--){
        cin>>N>>X;
        vector<int> arr(N+1, 0);
        for(int i=1;i<=N;i++){
            int x = X^i;
            if(x==0){
                arr[i]=X;
            }else{
                if((x|X)==X) arr[i]=x;
            }

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}
