#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e18;
using pt = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> pos, neg, zero;
    for (int i = 0;i < n;++i) {
        int num;cin >> num;
        if (num > 0)pos.push_back(num);
        else if (num < 0)neg.push_back(num);
        else zero.push_back(num);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());
    if (pos.empty() && neg.empty() || n == 1) {
        cout << 0;
        return;
    }
    if (pos.empty() && zero.empty()) {
        int w = neg[0];
        int sum;
        if (neg.size() > 2)sum = accumulate(neg.begin() + 1, neg.end(), (int)0) + neg.back();
        else sum = neg.back() + neg.front();
        cout << abs(sum - w);
        return;
    }
    if (pos.empty()) {
        int sum;
        if (neg.size() > 1) {
            sum = accumulate(neg.begin(), neg.end(), (int)0) + neg.back();
        }
        else if (zero.size() == 1) {
            sum = neg[0];
        }
        else {
            sum = neg[0] * 2;
        }
        cout << abs(sum);
        return;
    }
    if (neg.empty() && zero.empty()) {
        int w = pos[0];
        int sum;
        if (pos.size() > 2)sum = accumulate(pos.begin() + 1, pos.end(), (int)0) + pos.back();
        else sum = pos[0] + pos[1];
        cout << abs(sum - w);
        return;
    }
    if (neg.empty()) {
        int sum;
        if (pos.size() > 1) {
            sum = accumulate(pos.begin(), pos.end(), (int)0) + pos.back();
        }
        else if (zero.size() == 1) {
            sum = pos[0];
        }
        else sum = pos[0] * 2;
        cout << abs(sum);
        return;
    }
    if (pos.size() > 1 && neg.size() > 1) {
        int possum = accumulate(pos.begin(), pos.end(), (int)0) + pos.back();
        int negsum = accumulate(neg.begin(), neg.end(), (int)0) + neg.back();
        cout << abs(possum - negsum);
        return;
    }
    if (pos.size() == 1 && neg.size() == 1) {
        int possum = pos[0];
        int negsum = neg[0];
        int sum = abs(possum - negsum);
        if (zero.size() > 1)
            possum *= 2, negsum *= 2;
        else if (zero.size() == 1)
            possum > abs(negsum) ? possum : negsum *= 2;
        cout << abs(possum - negsum);
        return;
    }
    int possum = pos.size() > 1 ? accumulate(pos.begin(), pos.end(), (int)0) + pos.back() : pos[0];
    int negsum = neg.size() > 1 ? accumulate(neg.begin(), neg.end(), (int)0) + neg.back() : neg[0];
    if (zero.size() == 0) {
        cout << abs(possum - negsum);
        return;
    }
    if (pos.size() == 1) {
        cout << abs(negsum - possum * 2);
    }
    else cout << abs(negsum * 2 - possum);
}

signed main() {
    ios::sync_with_stdio(false);
    std::cin.tie(0), cout.tie(0);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}