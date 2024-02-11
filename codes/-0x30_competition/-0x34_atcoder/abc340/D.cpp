#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int f[MAXN], nxt[MAXN], c[MAXN], cnxt[MAXN];
using pt = pair<int, int>;

struct cmp {
    bool operator()(pt a, pt b) {
        return a.first > b.first;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;cin >> n;
    priority_queue<pt, vector<pt>, cmp> pq;
    pq.push({ 0,0 });
    for (int i = 0;i < n - 1;++i) {
        cin >> c[i] >> cnxt[i] >> nxt[i];
        nxt[i]--;
    }
    memset(f, -1, sizeof f);
    while (!pq.empty()) {
        int cost = pq.top().first;
        int cut = pq.top().second;
        pq.pop();
        if (cut >= n || ~f[cut] && cost >= f[cut])continue;
        f[cut] = cost;
        pq.push({ cost + c[cut],cut + 1 });
        pq.push({ cost + cnxt[cut] ,nxt[cut] });
    }
    cout << f[n - 1];
    return 0;
}