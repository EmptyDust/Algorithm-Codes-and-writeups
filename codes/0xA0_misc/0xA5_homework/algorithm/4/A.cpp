#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, L;std::cin >> n >> L;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int cur_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (cur_sum + a[i] <= L) {
            cur_sum += a[i];
            ans++;
        }
        else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}