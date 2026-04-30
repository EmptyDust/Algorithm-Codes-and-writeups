
#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

bool check(std::string& s, std::string& t, int p) {
    int cnt = 0;
    for (int _ = 0;_ < n / p;++_) {
        int i = _ * p, j = 0;
        for (;i < (_ + 1) * p;++i, ++j) {
            if (s[i] != t[j])cnt++;
            if (cnt > 1)return false;
        }
    }
    return true;
}

void solve() {
    std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<int> p;
    for (int i = 1;i <= std::sqrt(n);++i)if (n % i == 0) {
        p.push_back(i);
        if (i != n / i);
        p.push_back(n / i);
    }
    std::sort(p.begin(), p.end());
    for (int x : p) {
        std::string t = s.substr(0, x);
        if (check(s, t, x)) {
            std::cout << x;
            return;
        }
        t = s.substr(n - x, x);
        if (check(s, t, x)) {
            std::cout << x;
            return;
        }
    }
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