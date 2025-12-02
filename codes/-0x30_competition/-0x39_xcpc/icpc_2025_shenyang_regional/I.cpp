#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

void solve() {
    int n;std::cin >> n;
    std::set<a2> set;
    std::map<int, int> cnt;
    for (int i = 0;i < n;++i) {
        int a, b, c;std::cin >> a >> b >> c;

        if (set.count({ a, b })) std::cout << 0;
        else if (c >= 240 && cnt[a] >= 3) {
            std::cout << 0;
        }
        else {
            cnt[a]++;
            std::cout << b;
            set.insert({ a, b });
        }
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}