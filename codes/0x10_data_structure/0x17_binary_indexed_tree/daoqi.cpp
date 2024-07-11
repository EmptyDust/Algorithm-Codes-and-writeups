#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;

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

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> a(n + 1), mp(n + 1);
    Fenwick<i64> fw(n);

    for (int i = 1;i <= n;++i) {
        std::cin >> a[i];
        mp[a[i]] = i;
    }

    int q;std::cin >> q;
    std::vector<i64> ans(q);
    std::vector<a3> qs(q);
    for (int i = 0;i < q;++i) {
        int l, r;std::cin >> l >> r;
        qs[i] = { l,r,i };
    }
    std::ranges::sort(qs);

    std::vector<a3> ls;
    std::map<int, int> vis;
    std::function<void(int, int, int, int)> cal = [&](int a, int b, int sum, int cnt) {
        if (a + b != sum || vis[a])return;
        vis[a] = vis[b] = 1;
        if (a > b)std::swap(a, b);
        if (a != b && 1 <= a && b <= n)
            ls.push_back({ a,b,cnt });
        cal((sum - a) / 2, (sum - a) / 2 + a, sum, cnt + 1);
        cal((sum - b) / 2, (sum - b) / 2 + b, sum, cnt + 1);
        };

    for (int i = 1;i <= n + n - 1;++i) {
        cal(i / 2, i / 2, i, 1);
        vis.clear();
    }

    for (auto& [a, b, c] : ls) {
        a = mp[a];
        b = mp[b];
        if (a > b)std::swap(a, b);
        fw.add(b, c);
    }
    std::ranges::sort(ls);

    for (int i = 1, j = 0, k = 0;i <= n;++i) {//j:l k:q
        while (j < ls.size() && ls[j][0] < i) {
            fw.add(ls[j][1], -ls[j][2]);
            j++;
        }
        while (k < qs.size() && qs[k][0] == i) {
            ans[qs[k][2]] = fw.sum(qs[k][1]);
            k++;
        }
    }

    for (i64 x : ans)std::cout << x << '\n';

    return 0;
}