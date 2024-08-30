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
    std::vector<int> tag(n + 1);
    std::vector<int> big(n + 1), small(n + 1);//, other;
    ranges::sort(info);
    std::vector<pii> cur;
    int prex = 0;
    auto work = [&]() {
        if (cur.empty())return;
        int maxl = 0, minr = inf;
        for (auto [l, r] : cur) {
            maxl = std::max(maxl, l);
            minr = std::min(minr, r);
        }
        int p = cur.front().first, s = prex;
        for (int i = p;i <= maxl;++i)small[i] = 1;
        for (int i = minr;i <= s;++i)big[i] = 1;
        };
    for (auto [l, r] : info) {
        if (prex < l) {
            work();
            cur.clear();
        }
        prex = std::max(prex, r);
        cur.push_back({ l,r });
    }
    work();
    std::vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1;i <= n;++i)pre[i] = pre[i - 1] + small[i];
    for (int i = n;i >= 1;--i)suf[i] = suf[i + 1] + big[i];
    for (int i = 1;i <= n;++i) {
        if (!small[i] && !big[i]) {
            if (pre[i] >= suf[i])small[i] = 1;
            else big[i] = 1;
        }
        if (small[i] && big[i]) {
            std::cout << -1 << '\n';
            return;
        }
    }
    std::vector<int> ans(n + 1);
    int max = n;
    // ranges::sort(big);
    // ranges::sort(small);
    // for (auto y : big)ans[y] = max, max--;
    // for (auto y : small)ans[y] = max, max--;
    for (int i = 1;i <= n;++i) {
        if (big[i]) {
            ans[i] = max;
            max--;
        }
    }
    for (int i = 1;i <= n;++i) {
        if (small[i]) {
            ans[i] = max;
            max--;
        }
    }
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