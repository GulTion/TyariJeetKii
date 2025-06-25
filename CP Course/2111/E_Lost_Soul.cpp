#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n), b(n);
        for(int &i:a)cin>>i;
        for(int &i:b)cin>>i;

        int mx = 0;
        for(int i=n-1; i>=0; --i)
            if(a[i]==b[i]){ mx=max(mx, i+1);break;}

        for(int i=n-1; i>=1; --i)
            if(a[i]==a[i-1] || b[i]==b[i-1]) { mx=max(mx, i);break;}
        

        map<int, int> ma,mb;

        for(int i=1;i<=n;++i) ma[a[i]]=i,ma[b[i]]=i;

        for(int i=n-1; i>=0; --i){

            int k = max({mx, mb[b[i]]-1, ma[a[i]]-1, ma[b[i]]-1, mb[a[i]]-1});
            if(k+1<i) mx=max(mx, k);
        }


        // if(n>=3)
        // for(int i=n-1; i>=2; --i)
        //     if(a[i]==b[i-2] || b[i]==a[i-2]) { mx=max(mx, i-1);break;}
        
        // if(n>=4)
        // for(int i=n-1; i>=3; --i)
        //     if(a[i]==b[i-3] || b[i]==a[i-3]) { mx=max(mx, i-2);break;}
        
        cout<<mx<<endl;

        




    }
}