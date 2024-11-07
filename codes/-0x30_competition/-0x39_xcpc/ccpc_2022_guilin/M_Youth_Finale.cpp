#include<bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

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

void solve(){
    int n, m;std::cin >> n >> m;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    std::string op;std::cin >> op;
    Fenwick<i64> fw(n);
    i64 cnt = 0;
    for (int i = 0;i < n;++i){
        cnt += i - fw.sum(a[i]);
        fw.add(a[i], 1);
    }
    int j = 0, add = 1;
    std::cout << cnt << '\n';
    for (auto ch : op){
        if (ch == 'R'){
            cnt = 1ll * n * (n - 1) / 2 - cnt;
            add *= -1;
            j += add;
            if (j == n)j = 0;
            if (j == -1)j = n - 1;
        }
        else{
            cnt = cnt - (a[j] - 1) + (n - a[j]);
            j += add;
            if (j == n)j = 0;
            if (j == -1)j = n - 1;
        }
        std::cout << cnt % 10;
    }
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--){
        solve();
        std::cout << '\n';
    }
    return 0;
}