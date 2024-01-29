#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e5 + 10;
int nums[MAXN];

void cal(int& x) {
    int cnt = 0;
    for (int i = 2;i <= sqrt(x);++i)while (x % i == 0)
        x /= i, cnt++;
    x = (cnt + (x != 1)) % 2;
}

#define c2(x) x * (x - 1) / 2

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, x;cin >> n >> x;
    cal(x);
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        cal(nums[i]);
    }
    bool f = 0;
    if (x) {
        bool pre = 0;
        int ans = 0, cnt = 0;
        for (int i = 0;i < n;++i) {
            if (nums[i] && pre)ans += cnt * 2, cnt = 0;
            else if (num[i])ans += cnt, pre = true, cnt = 0;
            else cnt++;
        }
    }
    cout << endl;
    cout << c2(cnt);
    return 0;
}