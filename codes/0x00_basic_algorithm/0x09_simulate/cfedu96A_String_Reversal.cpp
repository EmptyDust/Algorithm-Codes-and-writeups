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
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::vector p(26, std::vector<int>());
    for (int i = 0;i < n;++i) {
        p[s[i] - 'a'].push_back(i);
    }
    std::vector<int> q(n);
    for (auto& vt : p) {
        auto tv = vt;
        std::reverse(tv.begin(), tv.end());
        for (int i = 0;i < vt.size();++i) {
            tv[i] = n - 1 - tv[i];
            q[vt[i]] = tv[i];
        }
    }
    i64 ans = 0;
    Fenwick<int> fw(n);
    for (int i = 0;i < n;++i) {
        // std::cout << q[i] << ' ';
        ans += i - fw.sum(q[i] + 1);
        fw.add(q[i] + 1, 1);
    }
    std::cout << ans;
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