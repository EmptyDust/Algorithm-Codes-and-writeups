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

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<a2> exist(m, { -1,-1 });
    std::string s;std::cin >> s;
    for (int i = 0;i < n;++i) {
        if (s[i] == '?')continue;
        int c = s[i] - 'a';
        if (exist[c][0] == -1)
            exist[c][0] = i;
        exist[c][1] = i;
    }
    for (int c = 0;c < m;++c) {
        if (exist[c][0] == -1)continue;
        for (int i = exist[c][0];i <= exist[c][1];++i) {
            if (s[i] == '?') {
                s[i] = (char)(c + 'a');
            }
        }
    }
    for (int c = 0;c < m;++c) {
        if (exist[c][0] != -1)continue;
        for (int i = 0;i < n;++i) {
            if (s[i] == '?') {
                s[i] = (char)(c + 'a');
                break;
            }
        }
    }
    for (int i = 1;i < n;++i)
        if (s[i] == '?')
            s[i] = s[i - 1];
    for (int i = n - 2;i >= 0;--i)
        if (s[i] == '?')
            s[i] = s[i + 1];
    exist.assign(m, { -1,-1 });
    for (int i = 0;i < n;++i) {
        int c = s[i] - 'a';
        if (exist[c][0] == -1)
            exist[c][0] = i;
        exist[c][1] = i;
    }
    int ans = 0;
    for (int c = 0;c < m;++c) {
        ans += exist[c][1] - exist[c][0];
    }
    std::cout << ans << '\n';
    std::cout << s;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    // if (t == 6) {
    //     std::cout <<
    //         "4\naabaacd\n0\nhonami\n8\naaabbeeeccccd\n3\naaaa\n3\naaaa\n21\nhhabggefhgdhgcg\n";
    // }
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}