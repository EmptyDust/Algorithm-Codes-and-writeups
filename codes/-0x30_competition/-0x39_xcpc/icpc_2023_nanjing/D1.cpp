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

/*
7
1 2 4 3 7 6 5

7 1 2 3 4 6 5
1 7 2 3 4 6 5
1 2 7 3 4 6 5
1 2 3 7 4 6 5
1 2 3 4 7 6 5
1 2 3 4 6 7 5
1 2 3 4 5 6 7
*/

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    i64 ans = 0;
    for (int& x : a)std::cin >> x;
    Fenwick<int> fw(n);
    int max = a[0];
    std::vector<int> b(n + 1);
    int cnt = 0;
    std::vector<i64> res(n);
    i64 add = 0;
    for (int i = 1;i < n;++i){
        if (max == a[i]){
            add++;
            res[i] = ans;
            continue;
        }
        ans++;
        if (max < a[i]){
            if (!b[max]){
                fw.add(max, 1);
                b[max] = 1;
                cnt++;
            }
            ans++;
            ans += add; add = 0;
            max = a[i];
        }
        else {
            ans += cnt - fw.sum(a[i]);
            if (!b[a[i]]){
                fw.add(a[i], 1);
                b[a[i]] = 1;
                cnt++;
            }
        }
        if (add)add++;
        res[i] = ans;
    }
    for (int i = 0;i < n;++i)
        std::cout << res[i] << " \n"[i == n - 1];
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