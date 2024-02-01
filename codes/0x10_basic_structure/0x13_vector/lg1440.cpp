#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e6 + 100;
#define num first
#define pos second
int nums[MAXN];

int m, n;
using pt = pair<int, int>;

struct cmp {
    bool operator()(pt a, pt b) {
        return a.num > b.num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;++i)cin >> nums[i];
    priority_queue<pt, vector<pt>, cmp> pq;
    cout << 0 << '\n';
    pq.push({ nums[0],0 });
    for (int i = 1;i < n;++i) {
        while (pq.top().pos < i - m)pq.pop();
        cout << pq.top().num << '\n';
        pq.push({ nums[i],i });
    }
    return 0;
}