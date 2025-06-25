#include<bits/stdc++.h>
using namespace std;

void f(int i, int d, int n){
    if(i==d) {
        if(n<=123)
        cout<<n<<" ";
        return;
    }
    for(int j=0;j<10;++j){
       
        f(i+1, d, 10*n+j);
    }
}
int main(){
    int d;cin>>d;
    f(0, d, 0);
    return 0;
}