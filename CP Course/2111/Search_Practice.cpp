#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,x,Q; cin>>N>>Q;
    vector<int> arr(N);
    for(int &i:arr) cin>>i;

    sort(arr.begin(), arr.end());

    while(Q--){
        int t, n;cin>>t>>n;
        if(t==1){
            auto i = upper_bound(arr.begin(), arr.end(), n);
            cout<<"i: "<<i-arr.begin()<<", e:"<<*i<<endl;
        }else if(t==2){
            auto i = lower_bound(arr.begin(), arr.end(), n);
            cout<<"i: "<<i-arr.begin()<<", e:"<<*i<<endl;
        }else if(t==3){
            bool i = binary_search(arr.begin(), arr.end(), n);
            if(i){
                cout<<n<<" found ;)";
            }else{
                cout<<n<<" not found :("<<endl;
            }

        }
    }

    return 0;
}