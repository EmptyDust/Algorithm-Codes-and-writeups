#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN = 100010;

int n, m, l;

struct meal
{
    int index;
    int v;
    int nxt = 0;
}a[MAXN], b[MAXN];

struct query {
    int ai;
    int bi;
    int sum;
    bool operator()(query a, query b) {
        return a.sum < b.sum;
    }
};

priority_queue < query, vector<query>, query> pq;
vector<int> ph[MAXN];

void pt(int x, int y) {
    if (x >= n || y >= m || x < b[y].nxt || y < a[x].nxt)
        return;
    query tmp;
    tmp.ai = x;
    tmp.bi = y;
    tmp.sum = a[x].v + b[y].v;
    pq.push(tmp);
    a[x].nxt++;
    b[y].nxt++;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> l;
    for (int i = 0;i < n;++i) {
        a[i].index = i;
        cin >> a[i].v;
    }
    for (int i = 0;i < m;++i) {
        b[i].index = i;
        cin >> b[i].v;
    }
    while (l--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        ph[x].push_back(y);
    }
    sort(a, a + n, [&](meal a, meal b) {return a.v > b.v;});
    sort(b, b + m, [&](meal a, meal b) {return a.v > b.v;});
    for (int i = 0;i < n;++i)
        sort(ph[i].begin(), ph[i].end());
    pt(0, 0);
    while (!pq.empty()) {
        int cai = pq.top().ai;
        int cbi = pq.top().bi;
        int ca = a[cai].index;
        int cb = b[cbi].index;
        auto lb = lower_bound(ph[ca].begin(), ph[ca].end(), cb);
        if (lb == ph[ca].end() || *lb != cb) {
            cout << pq.top().sum;
            return 0;
        }
        pt(cai, cbi + 1);
        pt(cai + 1, cbi);
        pq.pop();
    }
    return 0;
};