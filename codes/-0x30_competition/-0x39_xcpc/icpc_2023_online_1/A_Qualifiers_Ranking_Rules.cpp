#include <bits/stdc++.h>
using i64 = long long;
using pt = std::pair<int, int>;
constexpr int MAXN = 1e6, N = 1e6, mod = 1e9 + 7;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n), b(m), a1, b1, res, ans;
    for (auto& s : a)
        std::cin >> s;
    for (auto& s : b)
        std::cin >> s;
    std::set<std::string> st1, st2;
    for (auto& s : a) {
        if (!st1.count(s)) {
            st1.insert(s);
            a1.push_back(s);
        }
    }
    for (auto& s : b) {
        if (!st2.count(s)) {
            st2.insert(s);
            b1.push_back(s);
        }
    }
    for (int i = 0;i < std::max(a1.size(), b1.size());++i) {
        if (i < a1.size())res.push_back(a1[i]);
        if (i < b1.size())res.push_back(b1[i]);
    }
    std::set<std::string> st3;
    for (auto& s : res) {
        if (!st3.count(s)) {
            st3.insert(s);
            ans.push_back(s);
        }
    }
    for (auto s : ans)std::cout << s << '\n';
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //std::cin >> t;
    while (t--)
    {
        solve();
        std::cout << '\n';
    }
    return 0;
}