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
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (auto& x : a)std::cin >> x, cnt[x]++;
    int mex = 0;
    ranges::sort(a);
    for (auto x : a)if (x == mex)mex++;
    std::vector<int> ans(n + 1);
    ans[0] = 1;
    for (auto [x, c] : cnt)
        if (x < mex)
            ans[c]++;
    for (int i = 1;i <= n;++i)
        ans[i] += ans[i - 1];
    for (int i = n;i >= 0;--i)
        ans[i] = std::min(ans[i], n - i + 1);
    for (auto x : ans)std::cout << x << ' ';
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