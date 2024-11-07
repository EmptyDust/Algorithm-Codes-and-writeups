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

void solve() {
    int n, m, k, w;
    std::cin >> n >> m >> k >> w;
    std::vector<int> a(n), b(m);
    for (int& x : a)std::cin >> x;
    for (int& x : b)std::cin >> x;
    b.push_back(w + 1);b.push_back(0);m++;
    ranges::sort(a);ranges::sort(b);
    std::vector<int> tmp, ans;
    bool ok = true;
    auto work = [&](int l, int r){
        // std::cout << l << ' ' << r << '\n';
        // for (int x : tmp)std::cout << x << ' ';
        // std::cout << '\n';
        if (tmp.empty())return;
        std::vector<int> res;
        int cur = 0;
        for (int x : tmp){
            if (cur <= x){
                cur = x + k;
                res.push_back(x);
            }
        }
        std::reverse(res.begin(), res.end());
        cur = r;
        for (int& x : res){
            if (x + k <= cur)break;
            x = cur - k;
            cur = x;
        }
        if (res.back() <= l){
            ok = false;
        }
        else for (auto x : res)ans.push_back(x);
        tmp.clear();
        return;
        };
    for (int i = 0, j = 0;i < m && ok;++i){
        while (j < n && a[j] < b[i + 1]){
            tmp.push_back(a[j]);
            j++;
        }
        work(b[i], b[i + 1]);
    }
    if (!ok){
        std::cout << -1;
        return;
    }
    std::cout << ans.size() << '\n';
    for (int x : ans)std::cout << x << " ";
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