#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<string> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int p, q, k = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> p >> q;
        if (p == 0) //向左
        {
            if (a[k] == 0)
                k = (k + n - q) % n;
            else if (a[k] == 1)
                k = (k + n + q) % n;
        }
        else if (p == 1) //向右
        {
            if (a[k] == 0)
                k = (k + n + q) % n;
            else if (a[k] == 1)
                k = (k + n - q) % n;
        }
        // std::cout << k << " ";
    }
    cout << b[k];
    return 0;
}