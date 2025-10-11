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
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n + 1);
    Fenwick<i64> fw(n + 1);
    Fenwick<i64> cnt(n + 1);
    i64 msum = 0;
    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        if (a[i] > 0)fw.add(i, a[i]), cnt.add(i, 1);
        else msum += -a[i];
    }
    while (q--) {
        int x, v;std::cin >> x >> v;
        // std::cout << cnt.sum(1) << '\n';
        if (a[x] > 0)fw.add(x, -a[x]), cnt.add(x, -1);
        else msum -= -a[x];
        // std::cout << cnt.sum(1) << '\n';
        a[x] = v;
        if (a[x] > 0)fw.add(x, a[x]), cnt.add(x, 1);
        else msum += -a[x];
        int p = fw.select(msum);
        // std::cout << msum << ' ' << p << '\n';
        std::cout << 1 + cnt.sum(p) << '\n';
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