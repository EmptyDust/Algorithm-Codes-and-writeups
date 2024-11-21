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
    int n;std::cin >> n;
    std::string s;std::cin >> s;
    std::vector<int> p;
    int cnt = 1;
    for (int i = 1;i < n;++i) {
        if (s[i] == s[i - 1])cnt++;
        else {
            p.push_back(cnt);
            cnt = 1;
        }
    }
    if (p.size() && s.front() == s.back()) {
        p[0] += cnt;
    }
    else p.push_back(cnt);
    bool a = false, b = false;
    for (int i = 0;i < p.size();i += 2)if (p[i] != 1)a = true;
    for (int i = 1;i < p.size();i += 2)if (p[i] != 1)b = true;
    if (a && b) {
        std::cout << "NO";
        return;
    }
    if (p.size() <= 2) {
        std::cout << "YES";
        return;
    }
    int even = 0;
    for (int i = 0;i < p.size();++i) {
        if (p[i] % 2 == 0) {
            even++;
        }
    }
    if (even != 1) {
        std::cout << "NO";
        return;
    }
    std::cout << "YES";
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