#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (int& x : a)std::cin >> x;
    ranges::sort(a);
    int j = 0;
    for (int i = 0;i < n;++i) {
        while (j < a[i]) {
            if (mp[j % k]) {
                mp[j % k]--;
                j++;
            }
            else {
                std::cout << j;
                return;
            }
        }
        mp[a[i] % k]++;
    }
    while (1) {
        if (mp[j % k]) {
            mp[j % k]--;
            j++;
        }
        else {
            std::cout << j;
            return;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}