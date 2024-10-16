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
    std::vector<std::string> exsit;
    for (int i = 0;i < n;++i) {
        int c;std::cin >> c;
        bool e = false;
        for (int _ = 0;_ < c;++_) {
            std::string s;std::cin >> s;
            bool ok = false;
            for (int j = 0;j < (int)s.length() - 2;++j) {
                if (s.substr(j, 3) == "bie") {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                for (auto& t : exsit)if (s == t) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                exsit.push_back(s);
                std::cout << s << "\n";
                e = true;
            }
        }
        if (!e)std::cout << "Time to play Genshin Impact, Teacher Rice!" << '\n';
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