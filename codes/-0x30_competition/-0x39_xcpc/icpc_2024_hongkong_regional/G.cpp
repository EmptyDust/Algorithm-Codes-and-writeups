#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 1e7;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

std::vector factor(N + 1, std::vector<int>());

i64 res = 0;
struct Trie {
    int ch[N][26 + 1], cnt[N], idx = 0;
    // std::map<char, int> mp;
    void insert(std::string s, std::vector<int>& ans) {
        int u = 0;
        for (int i = 0; i < s.length(); i++) {
            int v = s[i] - 'a';
            if (!ch[u][v]) ch[u][v] = ++idx;
            u = ch[u][v];
            cnt[u]++;

            for (auto fac : factor[cnt[u]]) {
                res ^= ans[fac] * fac;
                ans[fac]++;
                res ^= ans[fac] * fac;
            }
        }
    }
    void Clear() {
        for (int i = 0; i <= idx; i++) {
            cnt[i] = 0;
            for (int j = 0; j <= 26; j++) {
                ch[i][j] = 0;
            }
        }
        idx = 0;
    }
} trie;

void solve()
{
    std::vector<int> ans(500001, 0);
    trie.Clear();

    int n;  std::cin >> n;
    res = 0;    
    for (int i = 1;i <= n;i++) {
        std::string s;  std::cin >> s;
        trie.insert(s, ans);
        std::cout << res << " ";
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;

    // trie.init();

    for (int i = 1;i <= 500000;i++)
        for (int j = i;j <= 500000;j += i)
            factor[j].push_back(i);

    while (t--) {
        solve();
        std::cout << '\n';
    }
}