#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

std::istream& operator>>(std::istream& is, u128& n) {
    std::string s;is >> s;
    n = 0;
    for (char i : s) n = n * 10 + i - '0';
    return is;
}
std::ostream& operator<<(std::ostream& os, u128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

void solve() {
    auto decode = [](char ch) {
        if ('a' <= ch && ch <= 'z') return ch - 'a';
        return ch - 'A' + 26;
        };
    auto encode = [](int x) {
        if (x < 26) return char(x + 'a');
        return char(x - 26 + 'A');
        };
    int n;std::cin >> n;
    std::vector<u128> rand(n * n + 1);
    for (int i = 0;i <= n * n;++i) rand[i] = rng();
    std::vector g1(n, std::vector<int>());
    std::vector<int> d1(n);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            int x = i * j / n, y = i * j % n;
            if (x != 0) {
                d1[x]++;
                g1[x].push_back(y);
                g1[y].push_back(x);
                // std::cout << x << ' ' << y << '\n';
            }
            d1[y]++;
        }
    }
    std::vector<u128> hash1(n);
    for (int i = 0;i < n;++i) {
        hash1[i] += 114514 * rand[d1[i]];
        for (auto v : g1[i]) {
            hash1[i] += 1919810 * rand[d1[v]];
        }
        // std::cout << hash1[i] << ' ';
    }
    // std::cout << '\n';
    std::vector g2(n, std::vector<int>());
    std::vector<int> d2(n);
    for (int i = 0;i < n * n;++i) {
        std::string s;std::cin >> s;
        int x = decode(s[0]);
        d2[x]++;
        if (s.length() == 2) {
            int y = decode(s[1]);
            d2[y]++;
            g2[x].push_back(y);
            g2[y].push_back(x);
            // std::cout << x << ' ' << y << '\n';
        }
    }
    std::vector<u128> hash2(n);
    for (int i = 0;i < n;++i) {
        hash2[i] += 114514 * rand[d2[i]];
        for (auto v : g2[i]) {
            hash2[i] += 1919810 * rand[d2[v]];
        }
        // std::cout << hash2[i] << ' ';
    }
    // std::cout << '\n';
    std::vector<int> vis(n);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) if (!vis[j] && hash1[i] == hash2[j]) {
            std::cout << encode(j);
            vis[j] = 1;
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