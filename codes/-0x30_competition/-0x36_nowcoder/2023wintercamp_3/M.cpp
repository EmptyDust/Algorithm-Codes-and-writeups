#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    vector<int> cnt(36, 0);
    int n;cin >> n;
    for (int i = 0;i < n;++i) {
        cin >> nums[i];
        cnt[nums[i] % 36]++;
    }
    int ans = 0;
    for (int j = 0;j < 36;++j)if (cnt[j]) {
        for (int i = 0;i < n;++i) {
            vector<int> num;
            int tmp = nums[i];
            while (tmp) {
                num.push_back(tmp % 10);
                tmp /= 10;
            }
            reverse(num.begin(), num.end());
            int x = j;
            for (int y : num) {
                x = (x * 10 + y) % 36;
            }
            if (!x) {
                ans += cnt[j];
                if (j == nums[i] % 36)ans--;
            }
        }
    }
    cout << ans;
    return 0;
}