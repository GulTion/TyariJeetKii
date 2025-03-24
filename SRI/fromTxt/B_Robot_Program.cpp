#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n, x;
    long long k;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>x>>k;
        cin>>s;
        int sum=0;
        int atz = 0;
        int ate=0;
        for(int i=0;i<n;i++){
            sum+=s[i]=='L'?-1:1;
            if(sum==0&&atz==0){
                atz=i+1;
            }
            if((x+sum)==0&&ate==0){
                ate=i+1;
            }
            if(ate!=0&&atz!=0){
                break;
            }

        }

        if(atz==0&&ate!=0){
            cout<<1<<endl;
        }else if(ate==0){
            cout<<0<<endl;
        }else if(atz!=0&&ate!=0){
            cout<<1+(k-ate)/atz<<endl;
        }
       

        
    }
    return 0;
}