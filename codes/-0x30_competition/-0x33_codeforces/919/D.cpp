#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e18;
int qrys[(int)1e6], zbs[(int)1e6], ans[(int)1e6];
using pt = pair<int, int>;
using pv = pair<int, vector<int>>;

void solve() {
    int n, q;cin >> n >> q;
    vector<pv> pvs;
    pvs.push_back({ 0,{} });
    int s = 0;bool f = true;
    while (n--) {
        int op, num;cin >> op >> num;
        if (!f)continue;
        pv& lst = pvs[pvs.size() - 1];
        int& lnum = lst.first;
        vector<int>& vec = lst.second;
        if (op == 1) {
            vec.push_back(num);
            s++;
        }
        if (op == 2) {
            s *= num;
            if (s > MAXN) {
                f = false;
                continue;
            }
            if (vec.empty())
                lnum *= num;
            else
                pvs.push_back({ num,{} });
        }
    }
    for (int i = 0;i < q;++i)cin >> qrys[i];
    iota(zbs, zbs + q, 0);
    sort(zbs, zbs + q, [&](int a, int b) {return qrys[a] < qrys[b];});
    int qi = 0, sz = 0;
    for (pv nums : pvs) {
        vector<int> vec = nums.second;
        int mul = nums.first + 1;
        int vs = vec.size();
        sz += vs;
        while (mul * vs >= qrys[zbs[qi]]) {

            qi++;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}