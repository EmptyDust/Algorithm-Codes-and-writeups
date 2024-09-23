#include <bits/stdc++.h>
using namespace std;
using a3 = array<int, 3>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), c;
    for (auto& num : a)
        std::cin >> num;
    vector<a3> b;
    for (int r = 0; r < n; r++)
    {
        vector<int> arr;
        for (int l = r; l >= 0; l--)
        {
            arr.push_back(a[l]);
            std::sort(arr.begin(), arr.end());
            int idx = (r - l + 2) / 2 - 1;
            b.push_back({ l, arr[idx], r });
        }
    }
    // std::sort(b.begin(), b.end(), [&](const auto& a1, const auto& a2){
    //         if(a1[2] == a2[2])
    //             return a1[0] < a2[0];
    //         return a1[2] < a2[2];
    // });

    for (auto [l, val, r] : b)
        cout << l << ' ' << val << ' ' << r << '\n';

    for (int r = 0; r < n; r++)
    {
        vector<int> tmp;
        for (int l = r; l >= 0; l--)
        {
            int cnt = 0;
            for (auto [le, val, ri] : b)
            {
                if (le >= l && ri <= r)
                    tmp.push_back(val),
                    cnt++;
            }
            std::sort(tmp.begin(), tmp.end());
            c.push_back(tmp[(cnt + 1) / 2 - 1]);
        }
    }
    std::sort(c.begin(), c.end());
    std::cout << c[(c.size() + 1) / 2 - 1];
}