#include<bits/stdc++.h>
using namespace std;

void dfs(map<int, vector<int>> &m,vector<int> &cd, int k, int u, int p){
    if(k==0) return;
    for(int v:m[u]){
        if(p==v) continue;
        
        dfs(m,cd,k-1,v,u);
    }
}

int solve(){
    int n, k, x,y; cin>>n>>k;
    int N=n;
    // cout<<n<<k<<endl;
    map<int, vector<int>> m;
    while(--n){
        cin>>x>>y; x--; y--;
        // cout<<x<<" "<<y<<": ";
        m[x].push_back(y);
        m[y].push_back(x);
    }
    n=N;

    vector<int> cd(n);
    for(int i=0;i<=n;i++) cd[i]=m[i].size();

    // for(int i:cd) cout<<i<<" ";
    return 0;
}
int main(){
    int t; cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}