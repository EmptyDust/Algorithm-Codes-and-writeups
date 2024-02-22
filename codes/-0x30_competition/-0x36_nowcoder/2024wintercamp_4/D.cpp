#include <bits/stdc++.h>
#define int long long 
#define op first
#define num second
using namespace std;
constexpr int MAXN = 2e5 + 10, mod = 1e9 + 7;
int nums[MAXN];
using pt = pair<int, int>;
int n;

int cal(int x) {
    int cnt = 1, lim = min((int)sqrt(x), x / n);

    for (int i = 2;i <= lim;++i)if (x % i == 0) {
        if (i <= x / n)cnt++;// cout << i << ' ';
        if (x / i <= x / n)cnt++;// cout << x / i << ' ';
        if (i == x / i && i <= x / n)cnt--;
    }
    //cout << '\n';
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    int sum = 0;
    for (int i = 0;i < n;++i)cin >> nums[i], sum += nums[i];
    cout << cal(sum);
    return 0;
}