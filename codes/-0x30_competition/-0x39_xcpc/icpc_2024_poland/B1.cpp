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

char H[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };

int cal(std::string s) {
    int a = 0;
    for (char ch : s) {
        a *= 16;
        for (int i = 0;i < 16;++i)if (H[i] == ch) {
            a += i;
            break;
        }
    }
    return a;
}
const int UP = ((1 << 12) - 2);

void solve() {
    int x;std::cin >> x;
    std::vector<int> p;
    std::string s;
    while (std::cin >> s) {
        p.push_back(cal(s));
    }
    // for (auto x : p)std::cout << x << ' ';
    while (p.size() <= UP)p.push_back(0);
    p.push_back(x);
    // std::cout << (p.size()) << ' ' << (1 << 12) << '\n';
    assert(((int)p.size()) == (1 << 12));
    int IP = 0;
    while (IP < UP) {
        int a = p[IP], b = p[IP + 1];
        int bit = p[a >> 4] >> (a & 15) & 1;
        if (bit != (p[b >> 4] >> (b & 15))) {
            p[b >> 4] ^= 1 << (b & 15);
            // std::cout << (b >> 4) << ' ' << (b & 15) << ' ';
        }
        int c = p[IP + 2];;
        IP = c;
    }
    // std::cout << IP << '\n';
    std::cout << p.back() << '\n';
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