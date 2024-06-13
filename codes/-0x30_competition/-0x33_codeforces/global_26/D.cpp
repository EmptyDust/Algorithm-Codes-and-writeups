#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int n;
using pt = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

std::vector<int> z_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        }
        else {
            z[i] = std::max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    std::string s, t;std::cin >> s;
    int n = s.length();
    int precnt = 0;
    while (precnt < n && s[precnt] == 'a')precnt++;
    if (precnt == n) {
        std::cout << n - 1;
        return;
    }
    t = s.substr(precnt);
    auto zf = z_function(t);
    std::vector<a3> vt;//pos zf prea
    vt.push_back({ precnt, (int)zf.size() ,precnt });
    int cnta = 0;
    for (int i = 1;i < zf.size();++i) {
        if (t[i] == 'a')cnta++;
        else {
            vt.push_back({ i + precnt ,zf[i],cnta });
            cnta = 0;
        }
    }

    std::priority_queue<a3, std::vector<a3>, std::greater<a3>> pq;//nowpos len cnta
    for (int i = 1;i <= (int)zf.size();++i) {
        pq.push({ precnt + i , i , precnt });
    }

    for (auto [pos, zf, prea] : vt) {
        while (pq.size()) {
            auto [nowpos, len, cnta] = pq.top();
            if (nowpos > pos)break;
            pq.pop();
            if (zf < len)continue;
            cnta = std::min({ cnta, prea,pos - nowpos });
            pq.push({ pos + len,len,cnta });
        }
    }

    i64 ans = 0;
    while (pq.size()) {
        auto [nowpos, len, cnta] = pq.top();
        //std::cout << len << ' ' << cnta << '\n';
        ans += cnta + 1;
        pq.pop();
    }
    std::cout << ans;
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