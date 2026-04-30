#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 3e5;
int n;
string s;
bool lights[MAXN];
int nxt[MAXN];
int cnts[MAXN];
vector<int> ans, tmpv;

int count(int x) {
    int tmp = x;
    bool f = true;
    if (lights[tmp])
        f = !f;
    if (!f)
        tmpv.push_back(tmp);
    tmp = nxt[tmp];
    while (tmp != x) {
        if (lights[tmp])
            f = !f;
        if (!f)
            tmpv.push_back(tmp);
        tmp = nxt[tmp];
    }
    if (!f)return -1;
    return 1;
}

void clear(int x) {
    while (cnts[x]) {
        cnts[x]--;
        x = nxt[x];
    }
}

void solve() {
    cin >> n >> s;
    for (int i = 0;i < n;++i)cnts[i] = 0;
    for (int i = 0;i < n;++i) {
        cin >> nxt[i];
        nxt[i]--;
        cnts[nxt[i]]++;
        if (s[i] == '1')lights[i] = 1;
        else lights[i] = 0;
    }

    vector<int> leaves;
    for (int i = 0;i < n;++i)if (cnts[i] == 0)leaves.push_back(i);
    for (int x : leaves) {
        bool f = true;
        while (cnts[x] == 0) {
            if (lights[x])
                f = !f;
            if (!f)
                ans.push_back(x);
            x = nxt[x];
            cnts[x]--;
        }
        if (!f)lights[x] = !lights[x];
    }

    for (int i = 0;i < n;++i)if (cnts[i] && lights[i]) {
        tmpv.clear();
        int a = count(i);
        if (a == -1) {
            cout << -1;
            return;
        }
        vector<int> tmpa(tmpv);
        tmpv.clear();
        count(nxt[i]);
        if (tmpa.size() < tmpv.size())
            for (int num : tmpa)ans.push_back(num);
        else
            for (int num : tmpv)ans.push_back(num);
        clear(i);
    }
    cout << ans.size() << '\n';
    for (int num : ans)cout << num + 1 << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        ans.clear();
        solve();
        cout << '\n';
    }
    return 0;
}