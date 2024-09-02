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
    int n, m;std::cin >> n >> m;
    std::vector<pii> info(m);
    for (auto& [l, r] : info)std::cin >> l >> r;
    std::vector<int> big, small;//, other;
    ranges::sort(info);
    int cur = 1;
    int leg = 0;
    for (auto& [l, r] : info) {
        while (cur < l) {
            // other.push_back(cur);
            if (leg >= m - leg) {
                small.push_back(cur);
            }
            else {
                big.push_back(cur);
            }
            cur++;
        }
        big.push_back(r);
        small.push_back(l);
        if (leg >= m - leg) {
            for (int i = l + 1;i <= r - 1;++i) {
                small.push_back(i);
            }
        }
        else {
            for (int i = l + 1;i <= r - 1;++i) {
                big.push_back(i);
            }
        }
        cur = r + 1;
        leg++;
    }
    while (cur <= n) {
        // other.push_back(cur);
        if (leg >= m - leg) {
            small.push_back(cur);
        }
        else {
            big.push_back(cur);
        }
        cur++;
    }
    std::vector<int> ans(n + 1);
    int max = n;
    // ranges::sort(other);
    ranges::sort(big);
    ranges::sort(small);
    // for (auto y : other)ans[y] = max, max--;
    for (auto y : big)ans[y] = max, max--;
    for (auto y : small)ans[y] = max, max--;
    Fenwick<int> fw(n);
    i64 ot = 0;
    for (int i = 1;i <= n;++i) {
        ot += i - 1 - fw.sum(ans[i]);
        fw.add(ans[i], 1);
    }
    std::cout << ot << '\n';
    // for (int i = 1;i <= n;++i)
    //     std::cout << ans[i] << " ";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}