#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6;
int nums[MAXN];
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> vec;
    int q;cin >> q;
    while (q--) {
        int op, x;cin >> op >> x;
        if (op == 1)vec.push_back(x);
        else cout << vec[vec.size() - x] << '\n';
    }
    return 0;
}