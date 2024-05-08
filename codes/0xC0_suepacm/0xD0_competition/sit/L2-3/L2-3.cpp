#include <bits/stdc++.h>
#define int __int128
using namespace std;
inline int rd() { int x = 0;char ch;bool f = true;for (ch = getchar();!isdigit(ch);ch = getchar())if (ch == '-')f ^= f;for (;isdigit(ch);ch = getchar())x = (x << 3) + (x << 1) + (ch ^ 48);return f ? x : -x; }
inline void wr(int x) { if (x < 0)putchar('-'), x = -x;if (x > 9)wr(x / 10);putchar(x % 10 + 48); }

int ansx = 1E9, ansi = 1E9;

void solve(int left, int cnt) {
    if (cnt > ansx)return;
    if (left < 10) {
        if (ansx == cnt)ansi = min(ansi, left);
        if (ansx > cnt)ansx = cnt, ansi = left;
        return;
    }
    int right = 0, pos = 1;
    while (left >= 10) {
        right += (left % 10) * pos;
        left /= 10, pos *= 10;
        solve(right + left, cnt + 1);
    }
}

signed main() {
    int num = rd();
    solve(num, 0);
    wr(ansx);
    cout << ' ';
    wr(ansi);
    return 0;
}