#include <bits/stdc++.h>
using namespace std;
int arr[100];
int m[100];
int main() {
	int t; cin>>t;
    while(t--){
        bool el = false;
        memset(arr, 0, 100);
        memset(m, 0, 100);

        int n,x; cin>>n;
        for(int i=0;i<n;++i) cin>>arr[i];
        

        if(x==1){
            cout<<-1<<endl;
        }else{
            for(int i=1;i<n;++i){
                if(arr[i-1]!=arr[i]){
                    el = true;
                }
            }

            if(el){
                cout<<2<<endl;
            }else cout<<-1<<endl;

        }


    }

}
