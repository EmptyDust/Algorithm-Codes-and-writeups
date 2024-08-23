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

std::vector<std::string> split(std::string& s) {
    std::vector<std::string> ret;ret.push_back("");
    int cnt = 0;
    for (char ch : s) {
        if (ch == '<')cnt++;
        if (ch == '>')cnt--;
        if (ch == ',' && !cnt) {
            ret.push_back("");
            continue;
        }
        ret.back().push_back(ch);
    }
    return ret;
}

std::vector<std::string> split2(std::string& s) {
    std::vector<std::string> ret;ret.push_back("");
    for (char ch : s) {
        if (ch == '.') {
            ret.push_back("");
            continue;
        }
        ret.back().push_back(ch);
    }
    return ret;
}

void solve() {
    //int -1
    //double -2
    std::vector<int> first(3, 0);
    std::vector<int> second(3, 0);
    std::vector<std::string> str{ "","int","double" };
    std::map<std::string, int> mp, type;
    std::function<int(std::string&)> add = [&](std::string& a) {
        if (a == "int")return 1;
        if (a == "double")return 2;
        if (!mp[a]) {
            mp[a] = first.size();
            first.push_back(0);
            second.push_back(0);
            str.push_back(a);
            std::string t = a.substr(5);t.pop_back();
            // std::cout << t << '\n';
            auto p = split(t);
            // for (auto x : p)std::cout << x << '\n';
            first[mp[a]] = add(p[0]);
            second[mp[a]] = add(p[1]);
        }
        return mp[a];
        };
    int n, q;std::cin >> n >> q;
    for (int i = 0;i < n;++i) {
        std::string a, b;std::cin >> a >> b;b.pop_back();
        type[b] = add(a);
        // std::cout << type[b] << '\n';
    }
    while (q--) {
        std::string s;
        std::cin >> s;
        auto vt = split2(s);
        int cur = type[vt[0]];
        // std::cout << cur << '\n';
        for (int i = 1;i < vt.size();++i) {
            if (vt[i] == "first")cur = first[cur];
            else cur = second[cur];
        }
        std::cout << str[cur] << '\n';
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