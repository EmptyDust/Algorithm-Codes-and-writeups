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
    std::vector<i64> a;
    i64 sum = 0;
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        if (s == "Push") {
            int x;std::cin >> x;
            a.push_back(x);
            sum += x;
        }
        else if (s == "Pop") {
            sum -= a.back();
            a.pop_back();
        }
        else {
            sum = sum * 2;
            if (a.size() <= n)
                a.insert(a.end(), a.begin(), a.end());
        }
        // for (int x : a)std::cout << x << " ";
        sum = (sum % mod + mod) % mod;
        std::cout << sum << '\n';
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