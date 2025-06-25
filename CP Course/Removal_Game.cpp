#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> dp1(n, vector<int>(2, 0));
    vector<vector<int>> dp2(n, vector<int>(2, 0));

    vector<int> arr;

    for(int i=0;i<n;++i) cin>>arr[i];

    int i=0, j=n-1;
    int turn=0;
    while(j>=i){
        if(arr[i]>arr[j]){
            dp1[turn][0] = arr[i];
            dp1[turn][1] = i;
        }
    }
    

    return 0;
}