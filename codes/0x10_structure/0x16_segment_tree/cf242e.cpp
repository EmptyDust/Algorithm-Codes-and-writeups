#include <cstdio>
#include <algorithm>
using namespace std;
int read() {
    char ch = getchar();int num = 0;
    while (ch < '0' || ch>'9')ch = getchar();
    while ('0' <= ch && ch <= '9') { num = num * 10 + ch - '0';ch = getchar(); }
    return num;
}
const int MAXN = 1e5 + 2;
int N, M, a[MAXN];
int cnt[MAXN << 2][20], tag[MAXN << 2];
#define ls(i) i<<1
#define rs(i) (i<<1)|1
void up(int cur) {
    for (int i = 0;i < 20;i++)
        cnt[cur][i] = cnt[ls(cur)][i] + cnt[rs(cur)][i];
}
void buildTree(int L, int R, int cur) {
    if (L == R) {
        for (int i = 0;i < 20;i++)
            if ((a[L] >> i) & 1)cnt[cur][i] = 1;
        return;
    }
    int mid = (L + R) >> 1;
    buildTree(L, mid, ls(cur));
    buildTree(mid + 1, R, rs(cur));
    up(cur);
}
void push_down(int L, int R, int cur) {
    int mid = (L + R) >> 1;
    for (int i = 0;i < 20;i++)
        if ((tag[cur] >> i) & 1) {//区间取反 
            cnt[ls(cur)][i] = (mid - L + 1) - cnt[ls(cur)][i];
            cnt[rs(cur)][i] = (R - mid) - cnt[rs(cur)][i];
        }
    tag[ls(cur)] ^= tag[cur];
    tag[rs(cur)] ^= tag[cur];
    tag[cur] = 0;
}
void update(int L, int R, int cur, int l, int r, int val) {
    if (R < l || r < L)return;
    if (l <= L && R <= r) {
        for (int i = 0;i < 20;i++)//区间取反 
            if ((val >> i) & 1)cnt[cur][i] = (R - L + 1) - cnt[cur][i];
        tag[cur] ^= val;
        return;
    }
    int mid = (L + R) >> 1;
    push_down(L, R, cur);//下传标记 
    update(L, mid, ls(cur), l, r, val);
    update(mid + 1, R, rs(cur), l, r, val);
    up(cur);
}
long long query(int L, int R, int cur, int l, int r) {
    if (R < l || r < L)return 0;
    if (l <= L && R <= r) {
        long long ret = 0, Pow = 1;
        for (int i = 0;i < 20;i++) {//求和 
            ret += Pow * cnt[cur][i];
            Pow <<= 1;
        }
        return ret;
    }
    int mid = (L + R) >> 1;
    push_down(L, R, cur);
    return query(L, mid, ls(cur), l, r) + query(mid + 1, R, rs(cur), l, r);
}
int main() {
    N = read();
    for (int i = 1;i <= N;i++)a[i] = read();
    buildTree(1, N, 1);
    M = read();
    for (int i = 1, opt, L, R;i <= M;i++) {
        opt = read();L = read();R = read();
        if (opt == 1)printf("%lld\n", query(1, N, 1, L, R));
        else update(1, N, 1, L, R, read());
    }
    return 0;
}