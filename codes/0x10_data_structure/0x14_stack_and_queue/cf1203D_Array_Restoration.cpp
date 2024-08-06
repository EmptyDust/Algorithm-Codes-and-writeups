#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    int n, q;std::cin >> n >> q;
    std::vector<int> a(n);
    for (int& x : a)std::cin >> x;
    bool ok = std::count(a.begin(), a.end(), q);
    std::vector<int> last(n, -1);
    std::map<int, int> mp;
    for (int i = n - 1;i >= 0;--i) {
        if (mp.count(a[i]))
            last[i] = mp[a[i]];
        else mp[a[i]] = i;
    }
    std::stack<int> stk;
    for (int i = 0;i < n;++i) {
        if (a[i] == 0) {
            if (!ok) {
                a[i] = q;
                ok = true;
            }
            continue;
        }
        if (!stk.empty() && stk.top() > a[i]) {
            std::cout << "NO";
            return 0;
        }
        if (!stk.empty() && stk.top() == a[i] && last[i] == -1) {
            stk.pop();
        }
        if (last[i] != -1 && (stk.empty() || stk.top() < a[i])) {
            stk.push(a[i]);
        }
    }
    if (!ok) {
        std::cout << "NO";
        return 0;
    }
    for (int i = 1;i < n;++i) {
        if (a[i] == 0)a[i] = a[i - 1];
    }
    for (int i = n - 2;i >= 0;--i) {
        if (a[i] == 0)a[i] = a[i + 1];
    }
    std::cout << "YES\n";
    for (int x : a)std::cout << x << ' ';
    return 0;
}