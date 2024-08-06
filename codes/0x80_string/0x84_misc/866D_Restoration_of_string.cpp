#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

std::vector<int> get_next(std::string& t) {
    std::vector<int> next(t.size());
    next[0] = -1;
    for (int i = 0, j = -1; i < (int)t.size();) {
        if (j == -1 || t[i] == t[j]) {
            ++i, ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    return next;
}

bool kmp(std::string& s, std::string& t) {
    if (t.length() > s.length())return false;
    auto next = get_next(t);

    for (int i = 0, j = 0; i < (int)s.size() && j < (int)t.size();) {
        if (j == -1 || s[i] == t[j]) {
            ++i, ++j;
        }
        else
            j = next[j];
        if (j == (int)t.size())return true;
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::vector<int> next(26, -1), exist(26);
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        if (s.length() > 26) {
            std::cout << "NO";
            return 0;
        }
        std::vector<int> cnt(26);
        for (char ch : s)cnt[ch - 'a']++, exist[ch - 'a']++;
        for (int x : cnt)if (x > 1) {
            std::cout << "NO";
            return 0;
        }
        for (int i = 0;i < s.length() - 1;++i) {
            int c = s[i] - 'a';
            int cn = s[i + 1] - 'a';
            if (next[c] != -1) {
                if (next[c] != cn) {
                    std::cout << "NO";
                    return 0;
                }
            }
            else {
                next[c] = cn;
            }
        }
    }
    std::vector<int> vis(26), start(26, 1);
    for (int i = 0;i < 26;++i) {
        if (!exist[i])
            start[i] = 0;
        if (next[i] != -1)
            start[next[i]] = 0;
    }
    std::string ans;
    for (int i = 0;i < 26;++i)if (start[i]) {
        int x = i;
        vis[i]++;
        ans += (char)(i + 'a');
        while (next[x] != -1) {
            x = next[x];
            vis[x]++;
            if (vis[x] > 1) {
                std::cout << "NO";
                return 0;
            }
            ans += (char)(x + 'a');
        }
    }
    for (int i = 0;i < 26;++i)if (exist[i] && !vis[i]) {
        std::cout << "NO";
        return 0;
    }
    std::cout << ans;

    return 0;
}