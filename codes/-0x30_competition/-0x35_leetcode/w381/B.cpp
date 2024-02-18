#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--, y--;
        vector<int> ret(n, 0);
        for (int i = 0;i < n;++i)for (int j = 0;j < n;++j)if (i != j)
            ret[min({ abs(i - j),abs(i - x) + abs(y - j) + 1,abs(i - y) + abs(x - j) + 1 }) - 1]++;
        return ret;
    }
};