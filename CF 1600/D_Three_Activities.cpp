#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        vector<int> a(N),b(N),c(N);
        for(int i=0;i<N;i++){
            cin>>a[i];
        }
        for(int i=0;i<N;i++){
            cin>>b[i];
        }
        for(int i=0;i<N;i++){
            cin>>c[i];
        }

        for(int i=0;i<N;i++){
            vector<int> t{a[i],b[i],c[i]};
            a[i]=*max_element(t.begin(), t.end());
        }

        sort(a.begin(), a.end());

        cout<<a[N-1]+a[N-2]+a[N-3]<<endl;
    }
    


    return 0;
}