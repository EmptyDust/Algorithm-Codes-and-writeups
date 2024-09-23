#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n;
    cin >> n;
    i64 score = 1500;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        score += x;
        if (score >= 4000) {
            cout << i;
            return;
        }
    }
    std::cout << -1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;//std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}