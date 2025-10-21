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

std::bitset<4096> Sb, Mb;

void print(int x) {
    std::string s;
    while (x) {
        s += (x % 2 ? '1' : '0');
        x /= 2;
    }
    ranges::reverse(s);
    std::cout << s;
}

void solve() {
    std::string S, D, M;
    std::cin >> S >> D >> M;
    if (D.length() >= 11) {
        print(M.length());
        return;
    }
    ranges::reverse(S);
    ranges::reverse(D);
    ranges::reverse(M);
    int d = 0;
    for (int i = 0;i < D.length();++i) {
        if (D[i] == '1') d += 1 << i;
    }
    if (d > M.length()) {
        print(M.length());
        return;
    }
    if (d <= S.length()) {
        std::cout << "Infinite money!";
        return;
    }
    for (int i = 0;i < S.length();++i) Sb[i] = S[i] == '1';
    for (int i = 0;i < M.length();++i) Mb[i] = M[i] == '1';
    int ans = 0;
    int Mlen = M.length();
    while (Mlen >= d) {
        Mb >>= d;
        int b = 0;
        Mlen = 0;
        for (int i = 0;i < 4096;++i) {
            b += Sb[i] + Mb[i];
            Mb[i] = b % 2;
            b >>= 1;
            if (Mb[i])Mlen = i + 1;
        }
        ans += d;
        // std::cout << Mb << '\n';
    }
    ans += Mlen;
    print(ans);
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}