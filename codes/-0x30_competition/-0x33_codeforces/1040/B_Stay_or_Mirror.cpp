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

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }

    void add(int x, const T& v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T& k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<i64> a(n + 1), pre(n + 1), suf(n + 2), ans(n + 1);
    for (int i = 1;i <= n;++i) std::cin >> a[i];
    Fenwick<i64> fw1(n), fw2(2 * n), fw(2 * n);
    for (int i = 1;i <= n;++i) {
        pre[i] = i - 1 - fw1.sum(a[i] - 1);
        fw1.add(a[i], 1);
    }
    // fw2.add(1, 1);
    // fw2.add(2, 1);
    // for (int i = n;i >= 1;--i) {
    //     suf[i] = suf[i + 1] + n - i - fw2.sum(a[i] - 1);
    //     fw2.add(a[i], 1);
    // }
    for (int i = n;i >= 1;--i) {
        i64 res1 = fw2.sum(a[i] - 1) + pre[i];
        i64 res2 = fw2.sum(2 * n - a[i] - 1);
        // std::cout << res1 << ' ' << res2 << '\n';
        if (res1 < res2) {
            fw2.add(a[i], 1);
            ans[i] = a[i];
        }
        else {
            fw2.add(2 * n - a[i], 1);
            ans[i] = 2 * n - a[i];
        }
    }
    // for (auto x : ans)std::cout << x << ' ';
    i64 out = 0;
    for (int i = 1;i <= n;++i) {
        out += i - 1 - fw.sum(ans[i] - 1);
        fw.add(ans[i], 1);
    }
    std::cout << out;
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