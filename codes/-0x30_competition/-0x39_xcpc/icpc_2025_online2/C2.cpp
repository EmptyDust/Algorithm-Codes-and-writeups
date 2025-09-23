#include <bits/stdc++.h>

using std::cin, std::cout;

#define endl '\n'

using pii = std::pair<int, int>;
using i64 = long long;
using a3 = std::array<int, 3>;
using ld = long double;

const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 b)
{
    i64 ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
}

void slove()
{
    int S;
    std::cin >> S;
    std::vector<int> in(8);
    for (int i = 1; i <= 7; ++i)
        std::cin >> in[i];
    // int a = in[1], b = in[2], c = in[4];
    int t1 = 0;
    for (int i = 1; i <= 6; i++)
        t1 += in[i];
    t1 /= 3;
    // cout << t1 << endl;
    if (t1 - in[1] > in[3] + in[5])
    {
        in[1] += in[3] + in[5];
        in[3] = 0, in[5] = 0;
    }
    if (t1 - in[2] > in[3] + in[6])
    {
        in[2] += in[3] + in[6];
        in[3] = 0, in[6] = 0;
    }
    if (t1 - in[4] > in[5] + in[6])
    {
        in[4] += in[5] + in[6];
        in[5] = 0, in[6] = 0;
    }
    if (in[3])
    {
        int temp = (in[3] + in[1] + in[2]) / 2;
        int rest = (in[3] + in[1] + in[2]) % 2;
        if (in[1] > temp)
            in[2] += in[3];
        else if (in[2] > temp)
            in[1] += in[3];
        else
            in[1] = temp + rest, in[2] = temp;
        in[3] = 0;
    }
    if (in[5])
    {
        int temp = (in[5] + in[1] + in[4]) / 2;
        int rest = (in[5] + in[1] + in[4]) % 2;
        if (in[1] > temp)
            in[4] += in[5];
        else if (in[4] > temp)
            in[1] += in[5];
        else
            in[1] = temp + rest, in[4] = temp;
        in[5] = 0;
    }
    if (in[6])
    {
        int temp = (in[6] + in[2] + in[4]) / 2;
        int rest = (in[6] + in[2] + in[4]) % 2;
        if (in[2] > temp)
            in[4] += in[6];
        else if (in[4] > temp)
            in[2] += in[6];
        else
            in[2] = temp + rest, in[4] = temp;
        in[6] = 0;
    }
    in[3] = in[4];
    int ttt = 1;
    while (ttt--)
    {
        sort(in.begin() + 1, in.begin() + 4);
        if (in[7] <= in[2] - in[1])
        {
            in[1] += in[7];
            break;
        }
        else
            in[7] -= in[2] - in[1], in[1] = in[2];
        sort(in.begin() + 1, in.begin() + 4);
        if (in[7] <= in[3] * 2 - in[1] - in[2])
        {
            int h = in[7] / 2;
            in[1] += h, in[2] += h;
            if (in[7])
                in[1] += in[7], in[7] = 0;
            break;
        }
        else
            in[7] -= (in[3] * 2 - in[1] - in[2]), in[1] = in[3], in[2] = in[3];
        sort(in.begin() + 1, in.begin() + 4);
        int avg = in[7] / 3;
        int rest = in[7] % 3;
        in[1] += avg, in[2] += avg, in[3] += avg;
        in[1] += rest;
        in[7] = 0;
    }
    sort(in.begin() + 1, in.begin() + 4);
    cout << in[1] << '\n';
    // for (int i = 1; i <= 7; i++)
    //     cout << in[i] << ' ';
    // cout << std::format("{} {} {}\n", in[1], in[2], in[4]);
    // cout << endl;
    // cout << std::format("{} {} {}\n", in[3], in[5], in[6]);
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        slove();
    }
}