#include<bits/stdc++.h>
#define int long long 
using namespace std;
#define x first
#define y second
constexpr int MAXN = 6e6;
using pt = pair<int, int>;
pt nums[MAXN];
int nmi = 0;

signed main() {
    ios::sync_with_stdio(false);
    int n, q;cin >> n >> q;
    while (n) {
        nums[nmi++] = { n,0 };
        n--;
    }
    int op;
    while (q--) {
        cin >> op;
        if (op == 1) {
            char dir;cin >> dir;
            pt& cut = nums[nmi - 1];
            if (dir == 'U')nums[nmi] = { cut.x,cut.y + 1 };
            if (dir == 'R')nums[nmi] = { cut.x + 1,cut.y };
            if (dir == 'L')nums[nmi] = { cut.x - 1,cut.y };
            if (dir == 'D')nums[nmi] = { cut.x,cut.y - 1 };
            nmi++;
        }
        if (op == 2) {
            int i;cin >> i;
            pt& cut = nums[nmi - i];
            cout << cut.x << ' ' << cut.y << '\n';
        }
    }
    return 0;
}