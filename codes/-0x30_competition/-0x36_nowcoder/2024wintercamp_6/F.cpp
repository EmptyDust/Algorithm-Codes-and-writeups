#include <bits/stdc++.h>
//#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
char buf[1 << 20], * p1, * p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?0:*p1++)
#define int long long
inline int read() {
    int x = 0, f = 1;char ch = GC;
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = GC; }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48);ch = GC; }
    return x * f;
}

int nums[MAXN], dsu[MAXN];

int get_root(int x) {
    return dsu[x] = (x == dsu[x] ? x : get_root(dsu[x]));
}

void solve() {
    int n = read();
    for (int i = 0;i < n;++i)nums[i] = read();
    iota(dsu, dsu + n, 0);
    unordered_map<int, int> mp, app;
    for (int i = 0;i < n;++i) {
        int cur = nums[i];
        if (app.count(cur)) {
            dsu[get_root(i)] = get_root(app[cur]);
            continue;
        }
        for (int j = 2;j <= sqrt(cur);++j) {
            if (cur % j == 0) {
                while (cur % j == 0)cur /= j;
                if (!mp.count(j)) mp[j] = i;
                dsu[get_root(i)] = get_root(mp[j]);
            }
        }
        if (cur >= 2) {
            if (!mp.count(cur)) mp[cur] = i;
            dsu[get_root(i)] = get_root(mp[cur]);
        }
        app[nums[i]] = get_root(i);
    }
    int x = get_root(0);
    vector<int>a, b;
    for (int i = 0;i < n;++i) {
        if (get_root(i) == x)a.push_back(nums[i]);
        else b.push_back(nums[i]);
    }
    if (b.empty()) {
        printf("-1 -1\n");
        return;
    }
    printf("%d %d\n", a.size(), b.size());
    for (int num : a)printf("%d ", num);
    printf("\n");
    for (int num : b)printf("%d ", num);
    printf("\n");
}

signed main() {
    int q = read();
    while (q--) {
        solve();
    }
    return 0;
}