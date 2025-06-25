#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s_year;
        cin >> s_year;
        
        int n_val = stoi(s_year);

        double sqrt_n_double = sqrt(static_cast<double>(n_val));
        
        int root_candidate_int = static_cast<int>(round(sqrt_n_double));
        
        if (static_cast<long long>(root_candidate_int) * root_candidate_int == n_val) {
            cout << 0 << " " << root_candidate_int << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}