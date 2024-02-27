#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int nums[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    cout.precision(15);
    double win;cin >> win;
    double lose = 1 - win;
    cout << win * win * lose * lose * lose + lose * lose * win * win * win;
    return 0;
}