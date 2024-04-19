#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 2e5 + 10;
using pt = std::pair<int, int>;
std::vector<int> adj[MAXN];
int color[MAXN];

struct Map {
    std::map<int, int> mp;
    int sum = 0;
    void operator+= (Map& x) {
        sum += x.sum;
        if (x.mp.size() > mp.size())std::swap(x.mp, mp);
        for (auto it : x.mp) {
            int num = it.first;
            int cnt = it.second;
            mp[num] += cnt;
        }
        x.mp.clear();
    }
    bool check() {
        if (sum % mp.size())return false;
        int x = sum / mp.size();
        for (auto it : mp) {
            int num = it.first;
            int cnt = it.second;
            if (cnt != x)return false;
        }
        return true;
    }
}maps[MAXN];

i64 dfs(int x) {
    i64 res = 0;
    for (int nxt : adj[x]) {
        res += dfs(nxt);
        maps[x] += maps[nxt];
    }
    res += maps[x].check();
    return res;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    int c, p;
    for (int i = 1;i <= n;i++) {
        std::cin >> c >> p;
        color[i] = c;
        adj[p].push_back(i);
        maps[i].mp[c]++;
        maps[i].sum++;
    }
    std::cout << dfs(1);
    return 0;
}