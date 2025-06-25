#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int T,N,x; cin>>T; ) 
            while(T-- && cin>>N){
            int a=INT_MAX,b=INT_MAX,s=0;
            while(N-- && cin>>x){
                if (a > b) swap(a, b);
                
                if(x<=a) a=x;
                else if(x<=b) b=x;
                else a=x,++s;
            }

            cout<<s<<'\n';
    }
}
