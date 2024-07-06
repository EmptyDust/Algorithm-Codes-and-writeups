#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e5 + 100;

int m, n, k, p;
struct node {
    int pre, suf;
    bool del = false;
}nodes[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int front = 0;
    nodes[0] = { -1,n };
    for (int i = 1;i < n;++i) {
        cin >> k >> p;k--;
        node& cut = nodes[i];
        if (p) {
            cut.pre = k;
            cut.suf = nodes[k].suf;
            nodes[k].suf = i;
            if (cut.suf != n)
                nodes[cut.suf].pre = i;
        }
        else {
            cut.suf = k;
            cut.pre = nodes[k].pre;
            nodes[k].pre = i;
            if (cut.pre != -1)
                nodes[cut.pre].suf = i;
            else front = i;
        }
    }
    cin >> m;
    while (m--) {
        cin >> k;k--;
        node& cut = nodes[k];
        if (!cut.del) {
            cut.del = true;
            if (cut.pre != -1)
                nodes[cut.pre].suf = cut.suf;
            if (cut.suf != n)
                nodes[cut.suf].pre = cut.pre;
            if (front == k)front = cut.suf;
        }
    }
    while (front != n) {
        cout << front + 1 << ' ';
        front = nodes[front].suf;
    }
    return 0;
}