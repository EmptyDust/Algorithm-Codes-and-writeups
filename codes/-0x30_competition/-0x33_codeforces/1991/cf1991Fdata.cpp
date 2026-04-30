
#include <bits/stdc++.h>
#include <ctime>
#include <iostream>
#include <random>
#define int long long
using namespace std;
using pt = pair<int, int>;
constexpr int MAXN = 1e5 + 5;
mt19937 rnd(time(0));

int rangeRand(int L, int R)
{
    int res = (int)((1.0 * rnd() / UINT_MAX) * (R - L + 1)) + L;
    return res;
}
signed main()
{
    int T = 1;
    int max = 0;
    while (T--) {
        int n = 200000, k;
        // cin >> n;

        k = rangeRand(1, n);
        vector<int> mp;
        for (int i = 0; i < n; ++i)
            mp.push_back(rangeRand(-1000, 1000));
        vector<int> s(mp.size());
        int sum = 0;
        for (int i = 0, pre = 0;i < n;++i) {
            sum += mp[i];
            max = std::max(max, i - pre);
            if (sum < 0)sum = 0, pre = i;
        }
        cout << n << " " << k << endl;
        for (int i = 0; i < n; ++i)
            cout << mp[i] << " ";
    }
    // std::cout << max;
}