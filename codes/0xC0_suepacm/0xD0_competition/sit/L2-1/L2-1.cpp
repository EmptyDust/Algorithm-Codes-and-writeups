#include <bits/stdc++.h>
#define int long long
using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        return a > b;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    queue<int> que;
    stack<int> stk;
    priority_queue<int> g_pq;
    priority_queue<int, vector<int>, cmp> l_pq;
    int opt, v;
    bool q, s, l, g;
    q = s = l = g = true;
    int op1, op2;
    op1 = op2 = 0;
    for (int i = 0;i < n;++i) {
        cin >> opt >> v;
        if (opt == 1) {
            if (q)que.push(v);
            if (s)stk.push(v);
            if (l)l_pq.push(v);
            if (g)g_pq.push(v);
            op1++;
        }
        if (opt == 2) {
            if (q)if (que.empty() || v != que.front())q = false;
            if (q)que.pop();
            if (s)if (stk.empty() || v != stk.top())s = false;
            if (s)stk.pop();
            if (l)if (l_pq.empty() || v != l_pq.top())l = false;
            if (l)l_pq.pop();
            if (g)if (g_pq.empty() || v != g_pq.top())g = false;
            if (g)g_pq.pop();
            op2++;
        }
    }
    cout << op1 << ' ' << op2 << '\n';
    cout << (q ? "Yes" : "No") << '\n';
    cout << (s ? "Yes" : "No") << '\n';
    cout << (g ? "Yes" : "No") << '\n';
    cout << (l ? "Yes" : "No") << '\n';
    return 0;
}