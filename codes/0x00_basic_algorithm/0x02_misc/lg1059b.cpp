#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, tmp;cin >> n;
    map<int, int> mp;
    while (n--) {
        cin >> tmp;
        mp[tmp]++;
    }
    cout << mp.size() << '\n';
    for (auto [num, cnt] : mp)
        cout << num << ' ';
    return 0;
}