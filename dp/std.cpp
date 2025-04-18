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
    int n, T;
    std::cin >> n >> T;
    std::vector<int> a;
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        while (x--) {
            a.push_back(i + 1);
        }
    }

    while (T--) {
        i64 ans = 0;
        int L, R;std::cin >> L >> R;
        auto b = std::vector<int>(a.begin() + L - 1, a.begin() + R);
        std::vector<int> idx(b.size());
        std::iota(idx.begin(), idx.end(), 0);
        // for (int& x : b)std::cout << x << " ";
        do {
            Fenwick<int> fw(n);
            for (int i = 0;i < b.size();++i) {
                ans += fw.sum(b[idx[i]] - 1);
                fw.add(b[idx[i]], 1);
            }
            for(int i = 1;i<n;++i){

            }
        } while (std::next_permutation(idx.begin(), idx.end()));
        std::cout << ans << '\n';
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