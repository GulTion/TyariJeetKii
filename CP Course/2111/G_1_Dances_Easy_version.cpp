#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, An, Bn; cin>>T;
    while(T-- ){
        cin>>An>>Bn;
        vector<int> A(An+1, 1), B(Bn, 0);
        for(int i=1;i<=An;++i) cin>>A[i];
        for(int i=0;i<Bn;++i) cin>>B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int sum=0;
        for(int i=0, j=0; i<An && j<Bn;){
            if(A[i]<B[j]) ++i, ++j;
            else if(A[i]>=B[j]) ++sum, ++j;
        }

        cout<<sum<<endl;


    }

    return 0;
}