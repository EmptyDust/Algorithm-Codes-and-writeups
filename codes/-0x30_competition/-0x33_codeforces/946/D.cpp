#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

void solve() {
    int sz;
    std::cin >> sz;
    std::string t;
    std::cin >> t;
    int x = std::count(t.begin(), t.end(), 'N') + std::count(t.begin(), t.end(), 'S');
    int y = std::count(t.begin(), t.end(), 'W') + std::count(t.begin(), t.end(), 'E');
    if (x % 2 || y % 2) {
        std::cout << "NO";
        return;
    }
    std::vector<int> n, s, w, e;
    for (int i = 0;i < sz;++i) {
        switch (t[i])
        {
        case 'N':
            n.push_back(i);
            break;
        case 'S':
            s.push_back(i);
            break;
        case 'W':
            w.push_back(i);
            break;
        case 'E':
            e.push_back(i);
            break;
        }
    }
    std::string ans(sz, 'a');
    for (int i = 0;i < std::min(n.size(), s.size());++i) {
        if (i & 1)ans[n[i]] = ans[s[i]] = 'H';
        else ans[n[i]] = ans[s[i]] = 'R';
    }
    for (int i = 0;i < std::min(w.size(), e.size());++i) {
        if (i & 1)ans[w[i]] = ans[e[i]] = 'R';
        else ans[w[i]] = ans[e[i]] = 'H';
    }
    for (int i = std::min(n.size(), s.size());i < n.size();++i) {
        if (i & 1)ans[n[i]] = 'H';
        else ans[n[i]] = 'R';
    }
    for (int i = std::min(n.size(), s.size());i < s.size();++i) {
        if (i & 1)ans[s[i]] = 'H';
        else ans[s[i]] = 'R';
    }
    for (int i = std::min(w.size(), e.size());i < w.size();++i) {
        if (i & 1)ans[w[i]] = 'R';
        else ans[w[i]] = 'H';
    }
    for (int i = std::min(w.size(), e.size());i < e.size();++i) {
        if (i & 1)ans[e[i]] = 'R';
        else ans[e[i]] = 'H';
    }
    if (std::count(ans.begin(), ans.end(), 'R') == ans.size() or std::count(ans.begin(), ans.end(), 'H') == ans.size()) {
        std::cout << "NO";
        return;
    }
    std::cout << ans;
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