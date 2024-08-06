#include <bits/stdc++.h>

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
    int n, k;std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i)std::cin >> a[i];

    std::vector<std::pair<int, std::vector<int>>> ans;
    int idx = 1;
    if (k == 2) {
        if (n == 3 && std::count(a.begin(), a.end(), 2) == 1 && std::count(a.begin(), a.end(), 1) == 2) {
            std::cout << 2 << '\n';
            std::vector<int> res1, res2;
            for (int i = 0;i < n;++i) {
                if (a[i] == 1)res1.push_back(i + 1);
                else res2.push_back(i + 1);
            }
            std::cout << 2 << ' ' << res1[0] << ' ' << res1[1] << '\n';
            std::cout << 2 << ' ' << 5 << ' ' << res2[0] << '\n';
            return;
        }
        if (n == 2 && a[0] == a[1]) {
            std::cout << 1 << '\n';
            std::cout << "2 1 2";
            return;
        }
        if (std::count(a.begin(), a.end(), 2) || std::count(a.begin(), a.end(), 1) == n) {
            std::cout << -1 << "\n";
            return;
        }
        std::vector<pii> piles;
        for (int i = 0;i < n;++i)piles.push_back({ a[i],i + 1 });
        std::sort(piles.begin(), piles.end());
        int p = piles.back().second;piles.pop_back();
        int cur = p;
        while (piles.size()) {
            auto [_, num] = piles.back();
            piles.pop_back();
            ans.push_back({ 2,{cur,num} });
            cur = n + idx * 2;
            idx++;
        }
    }
    else if (k == 3 && std::count(a.begin(), a.end(), 2) == 4 && n == 4) {
        std::cout << "2\n";
        std::cout << "2 1 2\n";
        std::cout << "3 3 4 5\n";
        return;
    }
    else if (k == 3 || k >= 4 && std::count(a.begin(), a.end(), 2) != 4) {
        std::vector<pii> piles;
        std::vector<pii> p2;
        for (int i = 0;i < n;++i) {
            if (a[i] == 2)p2.push_back({ 2,i + 1 });
            else piles.push_back({ a[i],i + 1 });
        }
        std::vector<int> cur;
        while (p2.size()) {
            cur.push_back(p2.back().second);
            p2.pop_back();
            if (cur.size() == 3) {
                ans.push_back({ 3,cur });
                piles.push_back({ 6,n + idx * 2 });
                idx++;
                cur.clear();
            }
        }

        if (cur.size()) {
            for (int x : cur)p2.push_back({ 2,x });
            // std::cout << p2.size();
            while (piles.size() && p2.size() % 3 != 0) {
                p2.push_back(piles.back());
                piles.pop_back();
            }
            if (p2.size() != 3) {
                //这里应当不可能出现
                assert(0);
                return;
            }
            ans.push_back({ 3,{p2[0].second,p2[1].second,p2[2].second} });
            int cnt = 0;
            int sum = 0;
            for (int i = 0;i < 3;++i) {
                cnt += p2[i].first == 3;
                sum += p2[i].first;
            }
            // std::cout << cnt << ' ';
            if (cnt == 0) {
                piles.push_back({ sum,n + idx * 2 });
            }
            else {
                piles.push_back({ cnt * 3,n + idx * 2 - 1 });
                piles.push_back({ sum - cnt * 3,n + idx * 2 });
            }
            idx++;
        }

        std::sort(piles.begin(), piles.end());
        int now = piles.back().second;piles.pop_back();
        while (piles.size()) {
            auto [_, num] = piles.back();
            piles.pop_back();
            ans.push_back({ 2,{now,num} });
            now = n + idx * 2;
            idx++;
        }
    }
    else {
        std::vector<pii> piles;
        std::vector<int> p2;
        for (int i = 0;i < n;++i) {
            if (a[i] == 2)p2.push_back(i + 1);
            else piles.push_back({ a[i],i + 1 });
        }
        ans.push_back({ 4,p2 });
        int now = n + idx * 2;
        idx++;
        while (piles.size()) {
            auto [_, num] = piles.back();
            piles.pop_back();
            ans.push_back({ 2,{now,num} });
            now = n + idx * 2;
            idx++;
        }
    }
    std::cout << ans.size() << '\n';
    for (auto [x, vt] : ans) {
        std::cout << x << ' ';
        for (int y : vt)std::cout << y << ' ';
        std::cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}