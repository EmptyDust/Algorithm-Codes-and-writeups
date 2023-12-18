#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6;


signed main() {
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<vector<int>> nodes(n, vector<int>(4));
    for (int i = 0;i < n;++i) {

        char tmp;
        cin >> tmp >> nodes[i][0] >> nodes[i][1];
        nodes[i][2] = i;
        if (tmp == '+')nodes[i][3] = 1;
        else nodes[i][3] = 0;
    }
    sort(nodes.begin(), nodes.end());
    vector<pair<int, int>> aq;
    for (int i = 1;i < nodes.size();++i) {

    }
    vector<bool> ans(n, false);
    return 0;
}