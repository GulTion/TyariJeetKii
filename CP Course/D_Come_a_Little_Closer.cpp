#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void solve() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
        return;
    }

    std::vector<long long> X(n), Y(n);
    std::cin >> X[0] >> Y[0];
    long long mnx = X[0], mxx = X[0], mny = Y[0], mxy = Y[0];

    for (int i = 1; i < n; ++i) {
        std::cin >> X[i] >> Y[i];
        mnx = std::min(mnx, X[i]);
        mxx = std::max(mxx, X[i]);
        mny = std::min(mny, Y[i]);
        mxy = std::max(mxy, Y[i]);
    }

    if (n == 1) {
        std::cout << 1 << std::endl;
        return;
    }

    long long ans = (mxx - mnx + 1LL) * (mxy - mny + 1LL);

    std::vector<long long> ux_vec = X, uy_vec = Y;
    std::sort(ux_vec.begin(), ux_vec.end());
    ux_vec.erase(std::unique(ux_vec.begin(), ux_vec.end()), ux_vec.end());
    std::sort(uy_vec.begin(), uy_vec.end());
    uy_vec.erase(std::unique(uy_vec.begin(), uy_vec.end()), uy_vec.end());

    long long smnx = mnx, smxx = mxx, smny = mny, smxy = mxy;
    if (ux_vec.size() > 1) {
        smnx = ux_vec[1];
        smxx = ux_vec[ux_vec.size() - 2];
    }
    if (uy_vec.size() > 1) {
        smny = uy_vec[1];
        smxy = uy_vec[uy_vec.size() - 2];
    }
    
    int cmnx_cnt = 0, cmxx_cnt = 0, cmny_cnt = 0, cmxy_cnt = 0;
    for(int i = 0; i < n; ++i) {
        if (X[i] == mnx) cmnx_cnt++;
        if (X[i] == mxx) cmxx_cnt++;
        if (Y[i] == mny) cmny_cnt++;
        if (Y[i] == mxy) cmxy_cnt++;
    }

    long long n_rem = n - 1;

    for (int i = 0; i < n; ++i) {
        long long cur_mnx_rem = mnx;
        long long cur_mxx_rem = mxx;
        long long cur_mny_rem = mny;
        long long cur_mxy_rem = mxy;
        
        if (X[i] == mnx && cmnx_cnt == 1) cur_mnx_rem = smnx;
        if (X[i] == mxx && cmxx_cnt == 1) cur_mxx_rem = smxx;
        if (Y[i] == mny && cmny_cnt == 1) cur_mny_rem = smny;
        if (Y[i] == mxy && cmxy_cnt == 1) cur_mxy_rem = smxy;
        
        long long W_rem = cur_mxx_rem - cur_mnx_rem + 1LL;
        long long H_rem = cur_mxy_rem - cur_mny_rem + 1LL;
        long long A_rem = W_rem * H_rem; 

        long long current_move_cost;
        if (A_rem > n_rem) {
            current_move_cost = A_rem;
        } else { 
            current_move_cost = A_rem + std::min(H_rem, W_rem);
        }
        ans = std::min(ans, current_move_cost);
    }
    std::cout << ans << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}