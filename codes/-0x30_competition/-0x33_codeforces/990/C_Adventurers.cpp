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

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T& v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
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
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<pii> p(n);
    std::vector<int> num;
    for (auto& [x, y] : p) {
        std::cin >> x >> y;
        num.push_back(y);
    }
    ranges::sort(num);
    num.erase(std::unique(num.begin(), num.end()), num.end());
    Fenwick<int> fl(n), fr(n);
    ranges::sort(p);
    for (auto& [x, y] : p) {
        y = std::lower_bound(num.begin(), num.end(), y) - num.begin();
        fr.add(y, 1);
    }

    int k = 0;
    pii ap = { 0,0 };
    for (int i = 0;i < n;++i) {
        auto [x, y] = p[i];
        fl.add(y, 1);
        fr.add(y, -1);
        if (i + 1 < n && x == p[i + 1].first)continue;
        while (1) {
            if (i + 1 < 2 * (k + 1))break;
            if (n - i - 1 < 2 * (k + 1))break;
            int yl = std::max(fl.select(k), fr.select(k));
            int yr = std::min(fl.select(i - k), fr.select(n - 1 - i - 1 - k));
            // if (x == -1)std::cout << yl << ' ' << yr << ' ' << k << '\n';
            if (yl >= yr)break;
            k++;
            ap = { x + 1,num[yr] };
        }
    }
    std::cout << k << '\n';
    std::cout << ap.first << ' ' << ap.second << '\n';
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