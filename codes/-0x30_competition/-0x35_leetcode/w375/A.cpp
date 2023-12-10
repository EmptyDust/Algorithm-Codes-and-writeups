#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int cnt = 0;
        for (int num : batteryPercentages)
            if (num > cnt)
                cnt++;
        return cnt;
    }
};