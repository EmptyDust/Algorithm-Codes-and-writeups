#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxt = 25142;

signed main() {
    ios::sync_with_stdio(false);
    int prices[7] = { 288,536,324,264,530,180,180 };
    int nums[7] = { 0 };
    int sum = maxt;
    for (nums[0] = 0;nums[0] * prices[0] <= sum;++nums[0]) {
        sum = maxt - nums[0] * prices[0];
        for (nums[1] = 0;nums[1] * prices[1] <= sum;++nums[1]) {
            sum = maxt - nums[0] * prices[0] - nums[1] * prices[1];
            for (nums[2] = 0;nums[2] * prices[2] <= sum;++nums[2]) {
                sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2];
                for (nums[3] = 0;nums[3] * prices[3] <= sum;++nums[3]) {
                    sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                        - nums[3] * prices[3];
                    for (nums[4] = 0;nums[4] * prices[4] <= sum;++nums[4]) {
                        sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                            - nums[3] * prices[3] - nums[4] * prices[4];
                        for (nums[5] = 0;nums[5] * prices[5] <= sum;++nums[5]) {
                            sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                                - nums[3] * prices[3] - nums[4] * prices[4] - nums[5] * prices[5];
                            for (nums[6] = 0;nums[6] * prices[6] <= sum;++nums[6]) {
                                sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                                    - nums[3] * prices[3] - nums[4] * prices[4] - nums[5] * prices[5] - nums[6] * prices[6];
                                if (nums[0] == 6 && nums[1] == 1 && nums[2] == 1 && nums[3] == 1 && nums[4] == 3 && nums[5] == 1 && nums[6] == 114)
                                    cout << sum;
                                if (sum == 0) {
                                    cout << sum << ' ';
                                    for (int num : nums)cout << num << ' ';
                                    cout << '\n';
                                }
                                sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                                    - nums[3] * prices[3] - nums[4] * prices[4] - nums[5] * prices[5];
                            }
                            sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                                - nums[3] * prices[3] - nums[4] * prices[4];
                        }
                        sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2]
                            - nums[3] * prices[3];
                    }
                    sum = maxt - nums[0] * prices[0] - nums[1] * prices[1] - nums[2] * prices[2];
                }
                sum = maxt - nums[0] * prices[0] - nums[1] * prices[1];
            }
            sum = maxt - nums[0] * prices[0];
        }
        sum = maxt;
        cout << nums[0] << endl;
    }
    return 0;
}