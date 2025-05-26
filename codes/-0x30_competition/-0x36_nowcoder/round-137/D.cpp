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
    std::vector<int> a(n), fix(n), pre(n), suf(n), ok(n);
    for (auto& x : a)std::cin >> x;
    {
        std::vector<int> mex(n);
        int c = 0;
        for (int i = 0;i < n;++i) {
            mex[a[i]] = 1;
            if (mex[c]) fix[i] = 1, ok[a[i]] = 1;
            while (c < n && mex[c]) {
                suf[c] = i;
                c++;
            }
        }
    }
    {
        std::vector<int> mex(n);
        int c = 0;
        for (int i = n - 1;i >= 0;--i) {
            mex[a[i]] = 1;
            if (mex[c]) fix[i] = 1, ok[a[i]] = 1;
            while (c < n&& mex[c]) {
                pre[c] = i;
                c++;
            }
        }
    }
    int max = 0;
    for (int i = n - 1;i > 0;--i) {
        if (!fix[i] && i + 1 < suf[a[i]] && max > a[i]) {
            // std::cout << i << '\n';
            for (int j = a[i] + 1;j < n;++j)if (!ok[j]) {
                // std::cout << j << '\n';
                a[i] = j;
                ok[j] = 1;
                fix[i] = 1;
                break;
            }
            for (int j = 0;j < i;++j) {
                ok[a[j]] = 1;
                fix[j] = 1;
            }
            std::set<int> pos;
            for (int j = i + 1;j < n;++j) {
                if (!fix[j])pos.insert(j);
            }
            for (int j = 0;j < n;++j)if (!ok[j]) {
                auto it = pos.lower_bound(pre[j]);
                pos.erase(it);
                int p = *it;
                assert(p < suf[j]);
                a[p] = j;
                ok[j] = 1;
                fix[p] = 1;
            }
            for (auto& x : a)std::cout << x << " ";
            return;
        }
        if (!fix[i])max = std::max(max, a[i]);
    }
    std::cout << -1;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}